/*
��MyMFC.h��MyMFC.cppΪJXL��������д��
�ڲ�������MFC��صĸ��ֳ��ú������궨��ȣ�
������MFC����ķ���Ȩ�޵����⣬ֱ��include "MyMFC.h"���������ļ��е��ô��ļ��еĺ������������LINK�����Ӵ���
����ʹ�ô��ļ�ʱ��ֱ�ӽ����ļ��еĺ�������ճ��������Ҫʹ�õ���ĳ�Ա�����У�
����MyMFC.cpp�ļ���������Ԥ����ͷ�������ò�ʹ��Ԥ����ͷ��
*/

#ifndef __MYMFC_H
#define __MYMFC_H

#include "string"
#include "atltime.h"

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//����������

void MyCreatDirectory(std::string str);//�½��ļ���         e.g.:MyCreatDirectory("D://Boxing");
LPCTSTR MyCharToLPCTSTR(char* szStrtemp);//char*תLPCTSTR
const char* MyCStringToConstChar(CString cstr);//CStringתconst char*
LPCTSTR MyCStringToLPCTSTR(CString cstr);//CStringתLPCTSTR
std::string MyCStringToString(CString cstr);//CStringתstring
CString MyStringToCString(std::string str);//stringתCString
double MyCStringToDouble(CString cstr);//CStringתdouble
const char* MyDoubleToChar(double dou);//doubleתchar*
CString MyGetTime(std::string str);//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");




#endif