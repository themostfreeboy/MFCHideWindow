/*
此MyMFC.h与MyMFC.cpp为JXL所整理改写；
内部含有与MFC相关的各种常用函数及宏定义等；
但由于MFC中类的访问权限等问题，直接include "MyMFC.h"并在其它文件中调用此文件中的函数会产生各种LINK的连接错误；
所以使用此文件时请直接将此文件中的函数复制粘贴到所需要使用的类的成员函数中；
另外MyMFC.cpp文件的属性中预编译头中请设置不使用预编译头。
*/

#ifndef __MYMFC_H
#define __MYMFC_H

#include "string"
#include "atltime.h"

#define HIDEWINDOW ShowWindow(AfxGetMainWnd()->m_hWnd, SW_HIDE);//隐藏主窗口

void MyCreatDirectory(std::string str);//新建文件夹         e.g.:MyCreatDirectory("D://Boxing");
void MyCreatDirectory(CString cstr);//新建文件夹
LPCTSTR MyCharToLPCTSTR(char* szStrtemp);//char*转LPCTSTR
const char* MyCStringToConstChar(CString cstr);//CString转const char*
LPCTSTR MyCStringToLPCTSTR(CString cstr);//CString转LPCTSTR
std::string MyCStringToString(CString cstr);//CString转string
CString MyStringToCString(std::string str);//string转CString
double MyCStringToDouble(CString cstr);//CString转double
const char* MyDoubleToChar(double dou);//double转char*
CString MyGetTime(std::string str);//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
CString MyGetTime(CString cstr);//获取系统时间




#endif
