#include "DMDesignerAfx.h"
#include "TipWnd.h"

bool AttrTipWnd::InitAttr(DMXmlInitAttrPtr ptr)
{
	bool bRet = false;
	do 
	{
		CStringW strType,strName,strValue,strDesc;
		FindChildByNameT<DUIStatic>(L"ds_attr")->SetAttribute(L"text",L"δ֪����");
		FindChildByNameT<DUIStatic>(L"ds_type")->SetAttribute(L"text",strType);
		FindChildByNameT<DUIStatic>(L"ds_name")->SetAttribute(L"text",strName);
		FindChildByNameT<DUIStatic>(L"ds_desc")->SetAttribute(L"text",strDesc);
		if (NULL == ptr)
		{
			break;
		}
	
		g_pAttr->Parse(ptr->m_pAttr,strType,strName,strValue,strDesc);
		FindChildByNameT<DUIStatic>(L"ds_attr")->SetAttribute(L"text",ptr->m_pAttr->GetName());
		FindChildByNameT<DUIStatic>(L"ds_type")->SetAttribute(L"text",strType);
		FindChildByNameT<DUIStatic>(L"ds_name")->SetAttribute(L"text",strName);
		FindChildByNameT<DUIStatic>(L"ds_desc")->SetAttribute(L"text",strDesc);

		bRet = true;
	} while (false);
	return bRet;
}


//AddTipWnd---------------------------------------------------
MultStr g_AddInfo[] = \
{
	{L"window",		 L"�����ؼ�",		L"ϵͳ��������",		L""},
	{L"button",		 L"�����ؼ�",		L"ͨ�õİ�ť",			L""},
	{L"label",		 L"�����ؼ�",		L"��ǩ",				L"��ǩ����Ӧ��Ϣ"},
	{L"group",		 L"�����ؼ�",		L"���",				L""},
	{L"checkbox",	 L"�����ؼ�",		L"ѡ���",				L""},
	{L"link",		 L"�����ؼ�",		L"����",				L""},
	{L"combobox",	 L"�����ؼ�",		L"���Ͽ�",				L""},
	{L"hotkey",		 L"�����ؼ�",		L"�ȼ�",				L""},

	{L"ipaddress",	 L"�����ؼ�",		L"IP��",				L""},
	{L"radiobutton", L"�����ؼ�",		L"��ѡ��",				L""},
	{L"sliderctrl",	 L"�����ؼ�",		L"������",				L""},
	{L"processctrl", L"�����ؼ�",		L"������",				L""},
	{L"tabctrl",	 L"�����ؼ�",		L"Tab�ؼ�",				L""},
	{L"tabpage",	 L"�����ؼ�",		L"Tabҳ",				L"�����ڲ��뵽TabCtrl"},
	{L"richedit",	 L"�����ؼ�",		L"�༭��(֧�ֶ���)",	L""},
	{L"edit",		 L"�����ؼ�",		L"�༭��",				L""},
	{L"listbox",	 L"�����ؼ�",		L"�б��",				L"��ˮƽ������"},
	{L"listboxex",	 L"��չ�ؼ�",		L"��չ�б��",			L""},
	{L"treectrl",	 L"�����ؼ�",		L"���οؼ�",			L""},
	{L"treectrlex",	 L"��չ�ؼ�",		L"��չ���οؼ�",		L""},
	{L"headerctrl",	 L"�����ؼ�",		L"�б�ͷ",				L""},
	{L"listctrlex",	 L"��չ�ؼ�",		L"��չ�б�view",		L""},
	{L"gif",		 L"�����ؼ�",		L"Gif����",				L""},
	{L"pnggif",		 L"�����ؼ�",		L"PngGif�ؼ�",		    L""},
	{L"ie",			 L"�����ؼ�",		L"IE�ؼ�",				L""},
	{L"splitlayout", L"�����ؼ�",		L"SplitLayout�ؼ�",		L"�ָ���������"},
	{L"monthcalctrl", L"�����ؼ�",		L"�����ؼ�",			L""}, 
	{L"scrollwnd",	L"�����ؼ�",		L"�����������ؼ�",		L"�������������������Χ���Ӵ���"}, 
}; 
bool AddTipWnd::InitAdd(CStringW strInfo)
{
	bool bFind = false;
	int nCount = countof(g_AddInfo);
	for (int i=0; i<nCount; i++)
	{
		if (0 == g_AddInfo[i].strOne.CompareNoCase(strInfo))
		{
			FindChildByNameT<DUIStatic>(L"ds_add_text1")->DV_SetWindowText(g_AddInfo[i].strOne);
			FindChildByNameT<DUIStatic>(L"ds_add_text2")->DV_SetWindowText(g_AddInfo[i].strTwo);
			FindChildByNameT<DUIStatic>(L"ds_add_text3")->DV_SetWindowText(g_AddInfo[i].strThree);
			FindChildByNameT<DUIStatic>(L"ds_add_text4")->DV_SetWindowText(g_AddInfo[i].strFour);
			bFind = true;
		}
	}
	if (!bFind)
	{
		FindChildByNameT<DUIStatic>(L"ds_add_text1")->DV_SetWindowText(strInfo);
		FindChildByNameT<DUIStatic>(L"ds_add_text2")->DV_SetWindowText(L"�����ؼ�");
		FindChildByNameT<DUIStatic>(L"ds_add_text3")->DV_SetWindowText(L"�����ؼ�");
		FindChildByNameT<DUIStatic>(L"ds_add_text4")->DV_SetWindowText(L"");
	}
	return true;
}
