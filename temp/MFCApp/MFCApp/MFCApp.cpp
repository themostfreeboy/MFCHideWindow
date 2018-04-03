
// MFCApp.cpp : 定义应用程序的类行为。
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


// CMFCAppApp 构造

CMFCAppApp::CMFCAppApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO:  将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApp.AppID.NoVersion"));

	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的一个 CMFCAppApp 对象

CMFCAppApp theApp;


// CMFCAppApp 初始化

BOOL CMFCAppApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要  AfxInitRichEdit2()	
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO:  应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));


	// 若要创建主窗口，此代码将创建新的框架窗口
	// 对象，然后将其设置为应用程序的主窗口对象
	CMDIFrameWnd* pFrame = new CMainFrame;
	if (!pFrame)
		return FALSE;
	m_pMainWnd = pFrame;
	// 创建主 MDI 框架窗口
	if (!pFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	// 试图加载共享 MDI 菜单和快捷键表
	//TODO:  添加附加成员变量，并加载对
	//	应用程序可能需要的附加菜单类型的调用
	HINSTANCE hInst = AfxGetResourceHandle();
	m_hMDIMenu  = ::LoadMenu(hInst, MAKEINTRESOURCE(IDR_MFCAppTYPE));
	m_hMDIAccel = ::LoadAccelerators(hInst, MAKEINTRESOURCE(IDR_MFCAppTYPE));




	// 主窗口已初始化，因此显示它并对其进行更新
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
	//TODO:  处理可能已添加的附加资源
	if (m_hMDIMenu != NULL)
		FreeResource(m_hMDIMenu);
	if (m_hMDIAccel != NULL)
		FreeResource(m_hMDIAccel);

	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMFCAppApp 消息处理程序

void CMFCAppApp::OnFileNew() 
{
	CMainFrame* pFrame = STATIC_DOWNCAST(CMainFrame, m_pMainWnd);
	// 创建新的 MDI 子窗口
	pFrame->CreateNewChild(
		RUNTIME_CLASS(CChildFrame), IDR_MFCAppTYPE, m_hMDIMenu, m_hMDIAccel);
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CMFCAppApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

//个人代码start

void CMFCAppApp::MyCreatDirectory(std::string str)//新建文件夹         e.g.:MyCreatDirectory("D://Boxing");
{
	CString   strFolderPath = MyStringToCString(str);
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


LPCTSTR CMFCAppApp::MyCharToLPCTSTR(char* szStrtemp)//char*转LPCTSTR
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



const char* CMFCAppApp::MyCStringToConstChar(CString cstr)//CString转const char*
{
	char     *pMBBuffer = (char *)malloc(100);
	const wchar_t  *pWCBuffer = (LPCTSTR)cstr;
	size_t   i = wcslen(pWCBuffer);
	wcstombs_s(&i, pMBBuffer, (size_t)(100), pWCBuffer, (size_t)(100));
	return pMBBuffer;
}

LPCTSTR CMFCAppApp::MyCStringToLPCTSTR(CString cstr)//CString转LPCTSTR
{

	LPCTSTR lpctstr = (LPCTSTR)cstr;
	return lpctstr;
}

std::string CMFCAppApp::MyCStringToString(CString cstr)//CString转string
{
	CT2A xx(cstr);
	std::string str = xx;
	return str;
}

CString CMFCAppApp::MyStringToCString(std::string str)//string转CString
{
	CString cstr(str.c_str());
	return cstr;
}

double CMFCAppApp::MyCStringToDouble(CString cstr)//CString转double
{
	double dou;
	dou = _wtof(cstr);
	return dou;
}


const char* CMFCAppApp::MyDoubleToChar(double dou)//double转char*
{
	char buffer[512];
	sprintf_s(buffer, "%f", dou);
	return buffer;
}


CString CMFCAppApp::MyGetTime(std::string str)//获取系统时间       e.g.:MyGetTime("D://Boxing//%Y%m%d%H%M%S.png");
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
		return;//文件打开失败
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

//个人代码end



