
// ChangeIconDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ChangeIcon.h"
#include "ChangeIconDlg.h"
#include "afxdialogex.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChangeIconDlg 대화 상자



CChangeIconDlg::CChangeIconDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGEICON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_cancel);
	//DDX_Control(pDX, IDC_BUTTON2, m_rect);
	DDX_Control(pDX, IDC_BUTTON2, full_button);
	DDX_Control(pDX, IDC_BUTTON3, m_hide);
}

BEGIN_MESSAGE_MAP(CChangeIconDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChangeIconDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChangeIconDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CChangeIconDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CChangeIconDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CChangeIconDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CChangeIconDlg 메시지 처리기

BOOL CChangeIconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.
	SetWindowText(_T("곰돌이 프로그램"));

	SetDlgItemText(IDC_STATIC1, _T("곰돌이 프로그램"));
	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_cancel.Init(_T("close_button"));
	full_button.Init(_T("full_button"));
	m_hide.Init(_T("hide_button"));



	/*CRect rt;
	GetClientRect(rt);
	rt.left = rt.right - 100;
	rt.bottom = rt.top +100;

	m_cancel.MoveWindow(rt);*/


//	CMyButtion* pMyButton = new ()
//	pMyButton->Init(CRect rt);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CChangeIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CChangeIconDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CChangeIconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChangeIconDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}


void CChangeIconDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (full_button.isMini == TRUE)
	{
		full_button.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP3, NULL, NULL);

		/*RECT rc;
		::GetWindowRect(m_hWnd, &rc);

		::MoveWindow(m_hWnd, rc.left, rc.top, rc.right - rc.left + 100, rc.bottom - rc.top + 100, TRUE);
		m_btnCNT = FALSE;*/

		int windowWidth = GetSystemMetrics(SM_CXSCREEN);
		int windowHeight = GetSystemMetrics(SM_CYSCREEN);
		_style = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
		::GetWindowRect(this->m_hWnd, &_originWindow);
		::SetWindowLong(this->m_hWnd, GWL_STYLE, NULL);
		SetWindowPos(&wndTopMost, 0, 0, windowWidth, windowHeight, NULL);
		ShowWindow(SW_MAXIMIZE);
\
		full_button.isMini = FALSE;
	}
	else if (full_button.isMini == FALSE)
	{
		full_button.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP5, NULL, NULL);
		/*RECT rc;
		::GetWindowRect(m_hWnd, &rc);
		::MoveWindow(m_hWnd, rc.left, rc.top, rc.right - rc.left - 100, rc.bottom - rc.top - 100, TRUE);*/

		::SetWindowLong(m_hWnd, GWL_STYLE, _style);
		SetWindowPos(GetParent(), _originWindow.left, _originWindow.top,
			_originWindow.right - _originWindow.left, _originWindow.bottom - _originWindow.top, NULL);


		full_button.isMini = TRUE;
	}

}


void CChangeIconDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CChangeIconDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CChangeIconDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShowWindow(SW_SHOWMINIMIZED);
	//PostMessage(WM_SHOWWINDOW, FALSE, SW_OTHERUNZOOM);

}
