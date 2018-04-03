
// MFCApp.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApp.h"
#include "MainFrm.h"

#include "ChildFrm.h"

#include "stdio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppApp

BEGIN_MESSAGE_MAP(CMFCAppApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCAppApp::OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, &CMFCAppApp::OnFileNew)
END_MESSAGE_MAP()


// CMFCAppApp ����

CMFCAppApp::CMFCAppApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���: 
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApp.AppID.NoVersion"));

	// TODO:  �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMFCAppApp ����

CMFCAppApp theApp;


// CMFCAppApp ��ʼ��

BOOL CMFCAppApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// ʹ�� RichEdit �ؼ���Ҫ  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO:  Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));


	// ��Ҫ���������ڣ��˴��뽫�����µĿ�ܴ���
	// ����Ȼ��������ΪӦ�ó���������ڶ���
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// ������ MDI ��ܴ���
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// ��ͼ���ع��� MDI �˵��Ϳ�ݼ���
	//TODO:  ��Ӹ��ӳ�Ա�����������ض�
	//	Ӧ�ó��������Ҫ�ĸ��Ӳ˵����͵ĵ���
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MFCAppTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MFCAppTYPE));




	// �������ѳ�ʼ���������ʾ����������и���
	pFrame->ShowWindow(m_nCmdShow);
	pFrame->UpdateWindow();
	HIDEWINDOW
	MyCreatDirectory("D://Boxing");
	//MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
	char data[1] = { 0 };
	WriteFile("D://Boxing//1234.txt", data, 1);

	return TRUE;
}

int CMFCAppApp::ExitInstance()
{
	//TODO:  �����������ӵĸ�����Դ
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMFCAppApp ��Ϣ�������

void CMFCAppApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// �����µ� MDI �Ӵ���
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_MFCAppTYPE, m_hMDIMenu, m_hMDIAccel);
}

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CMFCAppApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

//���˴���start

void CMFCAppApp::MyCreatDirectory(std::string str)//�½��ļ���         e.g.:MyCreatDirectory("D://Boxing");
{
	CString   strFolderPath = MyStringToCString(str);
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


LPCTSTR CMFCAppApp::MyCharToLPCTSTR(char* szStrtemp)//char*תLPCTSTR
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



const char* CMFCAppApp::MyCStringToConstChar(CString cstr)//CStringתconst char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100), pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR CMFCAppApp::MyCStringToLPCTSTR(CString cstr)//CStringתLPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string CMFCAppApp::MyCStringToString(CString cstr)//CStringתstring
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString CMFCAppApp::MyStringToCString(std::string str)//stringתCString
{
	CString cstr(str.c_str());
	return cstr;
}

double CMFCAppApp::MyCStringToDouble(CString cstr)//CStringתdouble
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* CMFCAppApp::MyDoubleToChar(double dou)//doubleתchar*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}


CString CMFCAppApp::MyGetTime(std::string str)//��ȡϵͳʱ��       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
{
	CString cstr;
	CTime tm;
	tm = CTime::GetCurrentTime();
	CString cstr_temp(str.c_str());
	cstr = tm.Format(cstr_temp);
	return cstr;
}

void CMFCAppApp::WriteFile(char* writefilename, char* data, int length)
{
	errno_t err_write;
	FILE *fp_write = NULL;
	err_write = fopen_s(&fp_write, writefilename, "wb");
	if (err_write != 0)
	{
		return;//�ļ���ʧ��
	}
	char *p;
	unsigned int i = 0;
	p = data;
	for (i = 0; i<length; i++)
	{
		fprintf_s(fp_write, "%c", *p);
		p++;
	}
	fclose(fp_write);
	return;
}

//���˴���end



