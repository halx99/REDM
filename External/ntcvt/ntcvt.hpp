#ifndef SIMDSOFT__NTCVT_HPP
#define SIMDSOFT__NTCVT_HPP

#pragma once
#if !defined(WIN32_LEAN_AND_MEAN)
#  define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <string>

namespace ntcvt {
enum code_page
{
  code_page_acp  = CP_ACP,
  code_page_utf8 = CP_UTF8
};

// different with resize, not all of fill new memory with '\0'
namespace buffer_traits
{
template <class _Elem, class _Traits = std::char_traits<_Elem>,
          class _Alloc = std::allocator<_Elem>>
class string : public std::basic_string<_Elem, _Traits, _Alloc>
  {
  public:
#if _MSC_VER > 1900 // VS2017 or later
      using _Alty = std::_Rebind_alloc_t<_Alloc, _Elem>;
      using _Alty_traits = std::allocator_traits<_Alty>;

      using _Scary_val = std::_String_val<std::conditional_t<std::_Is_simple_alloc_v<_Alty>, std::_Simple_types<_Elem>,
          std::_String_iter_types<_Elem, typename _Alty_traits::size_type, typename _Alty_traits::difference_type,
          typename _Alty_traits::pointer, typename _Alty_traits::const_pointer, _Elem&, const _Elem&>>>;
#endif
    // See also afxmfc CString::GetBufferSetLength
    // Why do this hack?
	// stupid: because the default c++ standard resize always fill with '\0'
	// std::string: use memset (usually implemented with SIMD)
	// std::wstring: for loop (slow performance)
	// only works on msvc currently
    _Elem* setnbuf(int len)
    {
      this->reserve(len);
#if _MSC_VER > 1900 // VS2017 or later
      std::_Compressed_pair<_Alty, _Scary_val>* _Myval = (std::_Compressed_pair<_Alty, _Scary_val> *)this;
      _Myval->_Myval2._Mysize = len;
      auto front = &this->front();
      front[len] = '\0';
      return front;
#else
      this->_Eos(len);
      return &this->front();
#endif
    }
  };

  template <typename _Elem> static _Elem* inplaced(std::basic_string<_Elem> & str, int size)
  {
    string<_Elem>& helper = (string<_Elem>&)str;
    return helper.setnbuf(size);
  }
#if defined(_AFX)
  template<typename _Elem> _Elem* inplaced(CStringT < _Elem, StrTraitMFC_DLL<_Elem>>& str, int size) {
      return str.GetBufferSetLength(size);
  }
#endif
}

template<typename _StringContType>
inline _StringContType wcbs2a(const wchar_t* wcb, int len, UINT cp = code_page_acp)
{
  if (len == -1)
    len = lstrlenW(wcb);
  _StringContType buffer;
  int cch;
  if (len > 0 && (cch = ::WideCharToMultiByte(cp, 0, wcb, len, NULL, 0, NULL, NULL)) > 0)
      ::WideCharToMultiByte(cp, 0, wcb, len, buffer_traits::inplaced(buffer, cch), cch, NULL, NULL);
  return buffer;
}

template<typename _StringContType>
inline _StringContType mcbs2w(const char* mcb, int len, UINT cp = code_page_acp)
{
  if (len == -1)
    len = lstrlenA(mcb);
  _StringContType buffer;
  int cch;
  if (len > 0 && (cch = ::MultiByteToWideChar(cp, 0, mcb, len, NULL, 0)) > 0)
    ::MultiByteToWideChar(cp, 0, mcb, len, buffer_traits::inplaced(buffer, cch), cch);

  return buffer;
}

#if _HAS_CXX17
inline std::string from_chars(const std::wstring_view& wcb, UINT cp = code_page_acp)
{
  return wcbs2a<std::string>(wcb.data(), wcb.length(), cp);
}

inline std::wstring from_chars(const std::string_view& mcb, UINT cp = code_page_acp)
{
  return mcbs2w<std::wstring>(mcb.data(), mcb.length(), cp);
}
#else
inline std::string from_chars(const std::wstring& wcb, UINT cp = code_page_acp)
{
  return wcbs2a<std::string>(wcb.c_str(), wcb.length(), cp);
}

inline std::wstring from_chars(const std::string& mcb, UINT cp = code_page_acp)
{
  return mcbs2w<std::wstring>(mcb.c_str(), mcb.length(), cp);
}
#endif

inline std::string from_chars(const wchar_t* str, UINT cp = code_page_acp)
{
    return wcbs2a<std::string>(str, -1, cp);
}

inline std::wstring from_chars(const char* str, UINT cp = code_page_acp)
{
    return mcbs2w<std::wstring>(str, -1, cp);
}

// ntcs or std::string to CStringW
#if defined(_AFX)
inline std::string from_chars(const CStringW& wcb, UINT cp = CP_ACP)
{
    return wcbs2a<std::string>(wcb.GetString(), wcb.GetLength(), cp);
}
namespace afx {
#if _HAS_CXX17
    inline CStringW from_chars(std::string_view mcb, UINT cp = CP_ACP)
    {
        return mcbs2w<CStringW>(mcb.data(), mcb.length(), cp);
    }
#else
    inline CStringW from_chars(const char* str, UINT cp = code_page_acp)
    {
        return mcbs2w<CStringW>(str, -1, cp);
    }
    inline CStringW from_chars(const std::string& mcb, UINT cp = CP_ACP)
    {
        return mcbs2w<CStringW>(mcb.c_str(), mcb.length(), cp);
    }
#endif
}
#endif
}

#endif
