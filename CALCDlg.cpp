// CALCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h" 
#include "CALC.h"
#include "CALCDlg.h"
#include "afxdialogex.h"
#include "winuser.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CString EDIT_RESULT;
bool Flag;
int opera;
float number1, number2, number0;
CString str1, str2;
//BOOL SetDlgItemTextA(    //FUNCTION
HWND   hDlg;//PARAMETER

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CCALCDlg dialog



CCALCDlg::CCALCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, EDIT_RESULT(_T(""))
{
	number1 = 0, number2 = 0, number0 = 0;
	str1 = _T("");
	str2 = _T("");
	Flag = true;
	opera = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCALCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, EDIT_RESULT);
}

BEGIN_MESSAGE_MAP(CCALCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CCALCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_B0, &CCALCDlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_B1, &CCALCDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CCALCDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CCALCDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CCALCDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CCALCDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CCALCDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CCALCDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CCALCDlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CCALCDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_B_ADD, &CCALCDlg::OnBnClickedBAdd)
	ON_BN_CLICKED(IDC_B_SUB, &CCALCDlg::OnBnClickedBSub)
	ON_BN_CLICKED(IDC_B_MUL, &CCALCDlg::OnBnClickedBMul)
	ON_BN_CLICKED(IDC_B_DIV, &CCALCDlg::OnBnClickedBDiv)
	ON_BN_CLICKED(IDC_B_EQUAL, &CCALCDlg::OnBnClickedBEqual)
	ON_EN_CHANGE(IDC_EDIT1, &CCALCDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCALCDlg message handlers

BOOL CCALCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCALCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCALCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCALCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*void CCALCDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
}*/


void CCALCDlg::OnBnClickedB0()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("0");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("0");
		EDIT_RESULT = str2;
	}

	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB1()
{
	// TODO: Add your control notification handler code here
	if (true)
	{
		str1 += _T("1");
		EDIT_RESULT = str1;
	}

	else
	{
		str2 += _T("1");
		EDIT_RESULT = str2;
	}

	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB2()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("2");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("2");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB3()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("3");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("3");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB4()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("4");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("4");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB5()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("5");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("5");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB6()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("6");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("6");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB7()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("7");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("7");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB8()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("8");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("8");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedB9()
{
	// TODO: Add your control notification handler code here
	if (Flag == true)
	{
		str1 += _T("9");
		EDIT_RESULT = str1;
	}
	else
	{
		str2 += _T("9");
		EDIT_RESULT = str2;
	}
	UpdateData(FALSE);
}


void CCALCDlg::OnBnClickedBAdd()
{
	// TODO: Add your control notification handler code here
	if (EDIT_RESULT != _T(""))
	{
		number1 = _ttof(EDIT_RESULT);
		Flag = !Flag;
		EDIT_RESULT = _T("");
		opera = 1;
	}
}


void CCALCDlg::OnBnClickedBSub()
{
	// TODO: Add your control notification handler code here
	if (EDIT_RESULT != _T(""))
	{
		number1 = _ttof(EDIT_RESULT);
		Flag = !Flag;
		EDIT_RESULT = _T("");
		opera = 2;
	}
}


void CCALCDlg::OnBnClickedBMul()
{
	// TODO: Add your control notification handler code here
	if (EDIT_RESULT != _T(""))
	{
		number1 = _ttof(EDIT_RESULT);
		Flag = !Flag;
		EDIT_RESULT = _T("");
		opera = 3;
	}
}


void CCALCDlg::OnBnClickedBDiv()
{
	// TODO: Add your control notification handler code here
	if (EDIT_RESULT != _T(""))
	{
		number1 = _ttof(EDIT_RESULT);
		Flag = !Flag;
		EDIT_RESULT = _T("");
		opera = 4;
	}
}


void CCALCDlg::OnBnClickedBEqual()
{
	if (EDIT_RESULT != _T(""))
	{
		number2 = _ttof(EDIT_RESULT);
		Flag = !Flag;
		EDIT_RESULT = _T("");
	}
			if (opera == 1)
			{
				number0 = number1 + number2;
			}
			if (opera == 2)
			{
				number0 = number1 - number2;

			}
			if (opera == 3)
			{
				number0 = number1 * number2;
			}
			if (opera == 4)
			{
				number0 = number1 / number2;
			}
	        EDIT_RESULT.Format(_T("%.1f"),number0);//CONVERSION
			str1 = _T("");
			str2 = _T("");
			SetDlgItemTextA(IDC_EDIT1,_T(EDIT_RESULT));//FOR DISPLY
			
}          

	

 
 void CCALCDlg::OnEnChangeEdit1()
 {
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code he.
 }
