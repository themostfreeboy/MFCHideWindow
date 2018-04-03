
// svchost.h : svchost 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//隐藏主窗口

#include "resource.h"       // 主符号
#include "string"
#include "stdio.h"


// CsvchostApp:
// 有关此类的实现，请参阅 svchost.cpp
//

class CsvchostApp : public CWinApp
{
public:
	CsvchostApp();


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

	void CsvchostApp::MyCreatDirectory(std::string str);//新建文件夹         e.g.:MyCreatDirectory("D://Boxing");
	void CsvchostApp::MyCreatDirectory(CString cstr);//新建文件夹
	LPCTSTR CsvchostApp::MyCharToLPCTSTR(char* szStrtemp);//char*转LPCTSTR
	const char* CsvchostApp::MyCStringToConstChar(CString cstr);//CString转const char*
	LPCTSTR CsvchostApp::MyCStringToLPCTSTR(CString cstr);//CString转LPCTSTR
	std::string CsvchostApp::MyCStringToString(CString cstr);//CString转string
	CString CsvchostApp::MyStringToCString(std::string str);//string转CString
	double CsvchostApp::MyCStringToDouble(CString cstr);//CString转double
	const char* CsvchostApp::MyDoubleToChar(double dou);//double转char*
	CString CsvchostApp::MyGetTime(std::string str);//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
	CString CsvchostApp::MyGetTime(CString cstr);//获取系统时间
	void CsvchostApp::WriteFile(const char* writefilename, char* data, int length);

};

extern CsvchostApp theApp;
