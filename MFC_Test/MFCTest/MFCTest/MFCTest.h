
// MFCTest.h : MFCTest Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "string"


// CMFCTestApp:
// �йش����ʵ�֣������ MFCTest.cpp
//

class CMFCTestApp : public CWinAppEx
{
public:
	CMFCTestApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	void MyCreatDirectory();//�½��ļ���"D://Boxing"
	LPCTSTR CMFCTestApp::MyCharToLPCTSTR(char* szStr);//char*תLPCTSTR
	const char* CMFCTestApp::MyCStringToConstChar(CString cstr);//CStringתconst char*
	LPCTSTR CMFCTestApp::MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	std::string CMFCTestApp::MyCStringToString(CString cstr);//CStringתstring
	CString CMFCTestApp::MyStringToCString(std::string str);//stringתCString
	double CMFCTestApp::MyCStringToDouble(CString cstr);//CStringתdouble
	const char* CMFCTestApp::MyDoubleToChar(double dou);//doubleתconst char*
	CString CMFCTestApp::MyGetTime();//��ȡϵͳʱ��

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTestApp theApp;


