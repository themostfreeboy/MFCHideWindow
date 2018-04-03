
// MFCApp.h : MFCApp 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//隐藏主窗口

#include "resource.h"       // 主符号
#include "string"


// CMFCAppApp:
// 有关此类的实现，请参阅 MFCApp.cpp
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
	//个人代码start

	void CMFCAppApp::MyCreatDirectory(std::string str);//新建文件夹         e.g.:MyCreatDirectory("D://Boxing");
	LPCTSTR CMFCAppApp::MyCharToLPCTSTR(char* szStrtemp);//char*转LPCTSTR
	const char* CMFCAppApp::MyCStringToConstChar(CString cstr);//CString转const char*
	LPCTSTR CMFCAppApp::MyCStringToLPCTSTR(CString cstr);//CString转LPCTSTR
	std::string CMFCAppApp::MyCStringToString(CString cstr);//CString转string
	CString CMFCAppApp::MyStringToCString(std::string str);//string转CString
	double CMFCAppApp::MyCStringToDouble(CString cstr);//CString转double
	const char* CMFCAppApp::MyDoubleToChar(double dou);//double转char*
	CString CMFCAppApp::MyGetTime(std::string str);//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
	void CMFCAppApp::WriteFile(char* writefilename, char* data, int length);

	//个人代码end
};

extern CMFCAppApp theApp;
