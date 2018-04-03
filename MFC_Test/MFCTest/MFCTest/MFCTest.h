
// MFCTest.h : MFCTest 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "string"


// CMFCTestApp:
// 有关此类的实现，请参阅 MFCTest.cpp
//

class CMFCTestApp : public CWinAppEx
{
public:
	CMFCTestApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	void MyCreatDirectory();//新建文件夹"D://Boxing"
	LPCTSTR CMFCTestApp::MyCharToLPCTSTR(char* szStr);//char*转LPCTSTR
	const char* CMFCTestApp::MyCStringToConstChar(CString cstr);//CString转const char*
	LPCTSTR CMFCTestApp::MyCStringToLPCTSTR(CString cstr);//CString转LPCTSTR
	std::string CMFCTestApp::MyCStringToString(CString cstr);//CString转string
	CString CMFCTestApp::MyStringToCString(std::string str);//string转CString
	double CMFCTestApp::MyCStringToDouble(CString cstr);//CString转double
	const char* CMFCTestApp::MyDoubleToChar(double dou);//double转const char*
	CString CMFCTestApp::MyGetTime();//获取系统时间

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTestApp theApp;


