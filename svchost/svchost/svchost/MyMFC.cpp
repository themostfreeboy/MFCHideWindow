#pragma once

#include "MyMFC.h"

void MyCreatDirectory(std::string str)//新建文件夹         e.g.:MyCreatDirectory("D://Boxing");
{
	CString strFolderPath(str.c_str());//string转CString
	if (!PathIsDirectory(strFolderPath))//判断路径是否存在
	{

		//设置属性
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}


void MyCreatDirectory(CString cstr)//新建文件夹
{
	CString strFolderPath = cstr;
	if (!PathIsDirectory(strFolderPath))//判断路径是否存在
	{

		//设置属性
		SECURITY_ATTRIBUTES attribute;
		attribute.nLength = sizeof(attribute);
		attribute.lpSecurityDescriptor = NULL;
		attribute.bInheritHandle = FALSE;

		CreateDirectory(strFolderPath, &attribute);
	}
}


LPCTSTR MyCharToLPCTSTR(char* szStrtemp)//char*转LPCTSTR
{
	char* szStr = new char[512];//为了避免直接对传入的地址进行改动，新申请一个内存并把传入的内容复制
	strcpy_s(szStr, 512, szStrtemp);//复制传入的内容
	WCHAR wszClassName[512];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, wszClassName, sizeof(wszClassName) / sizeof(wszClassName[0]));
	delete szStr;//释放内存
	WCHAR* wszClassNameReturn = new WCHAR[512];//为了避免直接对传出的地址进行改动，新申请一个内存并把传出的内容复制
	wcscpy_s(wszClassNameReturn, 512, wszClassName);//复制传出的内容
	return wszClassNameReturn;
}



const char* MyCStringToConstChar(CString cstr)//CString转const char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100), pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR MyCStringToLPCTSTR(CString cstr)//CString转LPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string MyCStringToString(CString cstr)//CString转string
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString MyStringToCString(std::string str)//string转CString
{
	CString cstr(str.c_str());
	return cstr;
}

double MyCStringToDouble(CString cstr)//CString转double
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* MyDoubleToChar(double dou)//double转char*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}


CString MyGetTime(std::string str)//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString cstr_temp(str.c_str());
	cstr_result = tm.Format(cstr_temp);
	return cstr_result;
}

CString MyGetTime(CString cstr)//获取系统时间
{
	CString cstr_result;
	CTime tm;
	tm = CTime::GetCurrentTime();
	cstr_result = tm.Format(cstr);
	return cstr_result;
}