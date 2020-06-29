//-------------------------------------------------------
// Copyright (c) DuiMagic
// All rights reserved.
// 
// File Name: DMWidgetDef.h 
// File Des: ���ÿؼ��ļ򵥶���
// File Summary: 
// Cur Version: 1.0
// Author:
// Create Data:
// History:
// 		<Author>	<Time>		<Version>	  <Des>
//      guoyou		2015-2-9	1.0			
//--------------------------------------------------------
#pragma once

namespace DM
{
// ----------------------------------------------------
// ���ô��ڶ���
#define      DUINAME_Static     L"label"                       // DUI Static
#define      DUINAME_Group      L"group"                        // DUI Group
#define      DUINAME_CheckBox   L"checkbox"                     // DUI CheckBox
#define      DUINAME_Link       L"link"                         // DUI Link
#define      DUINAME_ComboxBox  L"combobox"                     // DUI Combobox
#define      DUINAME_Button     L"button"                       // DUI Button
#define      DUINAME_HotKey     L"hotkey"                       // DUI HotKey
#define      DUINAME_IPEdit	    L"ipedit"						// DUI IPEdit
#define      DUINAME_IPAddress  L"ipaddress"                    // DUI IPAddress
#define      DUINAME_RadioButton L"radiobutton"					// DUI RadioButton
#define      DUINAME_SliderCtrl L"sliderctrl"					// DUI SliderCtrl
#define      DUINAME_ProcessCtrl L"processctrl"					// DUI ProcessCtrl
#define      DUINAME_TabCtrl    L"tabctrl"                      // DUI TabCtrl
#define      DUINAME_TabPage    L"tabpage"                      // DUI TabPage
#define      DUINAME_TabAnimate L"tabanimate"                   // DUI TabAnimate
#define      DUINAME_ActiveX    L"activex"                      // DUI ActiveX
#define      DUINAME_Flash      L"flash"                        // DUI Flash
#define      DUINAME_IE         L"ie"                           // DUI IE
#define      DUINAME_ScrollBar  L"scrollbar"                    // DUI ScrollBar
#define      DUINAME_Panel	    L"panel"                        // DUI Panel
#define      DUINAME_ScrollView	L"scrollview"                   // DUI ScrollView
#define      DUINAME_RichEdit	L"richedit"                     // DUI RichEdit
#define      DUINAME_Edit	    L"edit"                         // DUI Edit
#define      DUINAME_ListCtrl	L"listctrl"                     // DUI ListCtrl
#define      DUINAME_ListBox	L"listbox"                      // DUI ListBox
#define      DUINAME_ListBoxEx	L"listboxex"                    // DUI ListBoxEx
#define      DUINAME_TreeCtrl	L"treectrl"                     // DUI TreeCtrl
#define      DUINAME_TreeCtrlEx	L"treectrlex"                   // DUI TreeCtrlEx
#define      DUINAME_HeaderCtrl	L"headerctrl"                   // DUI HeaderCtrl
#define      DUINAME_ListCtrlEx	L"listctrlex"                   // DUI ListCtrlEx
#define      DUINAME_Gif     	L"gif"                          // DUI Gif
#define      DUINAME_ScrollBase L"scrollbase"                   // DUI ScrollBase
#define      DUINAME_ScrollWnd  L"scrollwnd"                    // DUI ScrollWnd
#define      DUINAME_ScrollFL   L"scrollfl"                     // DUI ScrollFL
#define      DUINAME_MonthCalCtrl L"monthcalctrl"				// DUI MonthCalCtrl
#define      DUINAME_DateTimeCtrl L"datetimectrl"				// DUI DateTimeCtrl
#define      DUINAME_RectTracker  L"recttracker"				// DUI RectTracker


// ----------------------------------------------------
// scroll
// ״̬:������ͣ������������á���Active
#define    DMSBST_NORMAL                             0							///< ����״̬
#define    DMSBST_HOVER                              1							///< hover״̬
#define    DMSBST_PUSHDOWN                           2							///< ����״̬
#define    DMSBST_DISABLE                            3							///< ����״̬
#define    DMSBST_NOACTIVE							 4							///< �Ǽ���״̬

// ��������ʾ״̬
#define	   DMSB_NULL								 0
#define	   DMSB_HORZ								 1
#define	   DMSB_VERT								 2
#define	   DMSB_BOTH								(DMSB_HORZ|DMSB_VERT)

struct SBSTATEINFO
{
	SBSTATEINFO()
	{
		sbCode = -1;
		nState = 0;
		bVert  = false;
	}
	SBSTATEINFO(LONG obj)
	{
		memcpy(this,&obj,4);
	}
	bool operator !=(const SBSTATEINFO &obj)
	{
		return memcmp(this,&obj,sizeof(SBSTATEINFO))!=0;
	}
	LONG sbCode:16;
	LONG nState:8;
	bool bVert :8;
};

// �ؼ�:�ϼ�ͷ���¼�ͷ����ֱ����������ֱ���ۡ����ͷ���Ҽ�ͷ��ˮƽ��������ˮƽ���ۡ�С�߽�
#define    SB_CORNOR								10
#define    MAKESBSTATE(sbCode,nState,bVert)         MAKELONG((sbCode),MAKEWORD((nState),(bVert)))
#define	   TIMER_SBWAIT								1         // �������������Ķ�ʱ��
#define    TIMER_SBGO								2         // ���������Ķ�ʱ��
}// namespace DM