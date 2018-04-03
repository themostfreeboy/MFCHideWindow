#pragma once

#include "MyMFC.h"

void MyCreatDirectory(std::string str)//�½��ļ���         e.g.:MyCreatDirectory("D://Boxing");
{
	CString strFolderPath(str.c_str());//stringתCString
	if (!PathIsDirectory(strFolderPath))//�ж�·���Ƿ����
	{

		//��������
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}


void MyCreatDirectory(CString cstr)//�½��ļ���
{
	CString strFolderPath = cstr;
	if (!PathIsDirectory(strFolderPath))//�ж�·���Ƿ����
	{

		//��������
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}


LPCTSTR MyCharToLPCTSTR(char* szStrtemp)//char*תLPCTSTR
{
	char* szStr = new char[512];//Ϊ�˱���ֱ�ӶԴ���ĵ�ַ���иĶ���������һ���ڴ沢�Ѵ�������ݸ���
	strcpy_s(szStr, 512, szStrtemp);//���ƴ��������
	WCHAR wszClassName[512];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
	delete szStr;//�ͷ��ڴ�
	WCHAR* wszClassNameReturn = new WCHAR[512];//Ϊ�˱���ֱ�ӶԴ����ĵ�ַ���иĶ���������һ���ڴ沢�Ѵ��������ݸ���
	wcscpy_s(wszClassNameReturn, 512, wszClassName);//���ƴ���������
	return wszClassNameReturn;
}



const char* MyCStringToConstChar(CString cstr)//CStringתconst char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100), pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR MyCStringToLPCTSTR(CString cstr)//CStringתLPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string MyCStringToString(CString cstr)//CStringתstring
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString MyStringToCString(std::string str)//stringתCString
{
	CString cstr(str.c_str());
	return cstr;
}

double MyCStringToDouble(CString cstr)//CStringתdouble
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* MyDoubleToChar(double dou)//doubleתchar*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}


CString MyGetTime(std::string str)//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString cstr_temp(str.c_str());
	cstr_result = tm.Format(cstr_temp);
	return cstr_result;
}

CString MyGetTime(CString cstr)//��ȡϵͳʱ��
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr_result = tm.Format(cstr);
	return cstr_result;
}