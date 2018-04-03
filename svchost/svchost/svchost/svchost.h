
// svchost.h : svchost Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//����������

#include "resource.h"       // ������
#include "string"
#include "stdio.h"


// CsvchostApp:
// �йش����ʵ�֣������ svchost.cpp
//

class CsvchostApp : public CWinApp
{
public:
	CsvchostApp();


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

	void CsvchostApp::MyCreatDirectory(std::string str);//�½��ļ���         e.g.:MyCreatDirectory("D://Boxing");
	void CsvchostApp::MyCreatDirectory(CString cstr);//�½��ļ���
	LPCTSTR CsvchostApp::MyCharToLPCTSTR(char* szStrtemp);//char*תLPCTSTR
	const char* CsvchostApp::MyCStringToConstChar(CString cstr);//CStringתconst char*
	LPCTSTR CsvchostApp::MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
	std::string CsvchostApp::MyCStringToString(CString cstr);//CStringתstring
	CString CsvchostApp::MyStringToCString(std::string str);//stringתCString
	double CsvchostApp::MyCStringToDouble(CString cstr);//CStringתdouble
	const char* CsvchostApp::MyDoubleToChar(double dou);//doubleתchar*
	CString CsvchostApp::MyGetTime(std::string str);//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
	CString CsvchostApp::MyGetTime(CString cstr);//��ȡϵͳʱ��
	void CsvchostApp::WriteFile(const char* writefilename, char* data, int length);

};

extern CsvchostApp theApp;
