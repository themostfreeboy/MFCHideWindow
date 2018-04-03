
// MFCApp.h : MFCApp Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//����������

#include "resource.h"       // ������
#include "string"


// CMFCAppApp:
// �йش����ʵ�֣������ MFCApp.cpp
//

class CMFCAppApp : public CWinApp
{
public:
	CMFCAppApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
protected:
	HMENU  m_hMDIMenu;
	HACCEL m_hMDIAccel;

public:
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	DECLARE_MESSAGE_MAP()
	//���˴���start

	void CMFCAppApp::MyCreatDirectory(std::string str);//�½��ļ���         e.g.:MyCreatDirectory("D://Boxing");
	LPCTSTR CMFCAppApp::MyCharToLPCTSTR(char* szStrtemp);//char*תLPCTSTR
	const char* CMFCAppApp::MyCStringToConstChar(CString cstr);//CStringתconst char*
	LPCTSTR CMFCAppApp::MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	std::string CMFCAppApp::MyCStringToString(CString cstr);//CStringתstring
	CString CMFCAppApp::MyStringToCString(std::string str);//stringתCString
	double CMFCAppApp::MyCStringToDouble(CString cstr);//CStringתdouble
	const char* CMFCAppApp::MyDoubleToChar(double dou);//doubleתchar*
	CString CMFCAppApp::MyGetTime(std::string str);//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
	void CMFCAppApp::WriteFile(char* writefilename, char* data, int length);

	//���˴���end
};

extern CMFCAppApp theApp;
