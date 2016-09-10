#include<conio.h>
// RandWDlg.cpp : 实现文件
//
 

#include "stdafx.h"
#include "RandW.h"
#include "RandWDlg.h"
#include "afxdialogex.h"
#define MAXLEN 16
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
CString strFilePath1; 
CString strFilePath2; 
CString strFilePath3;
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
public:
	afx_msg void OnStnClickedLink();
	afx_msg void OnStnClickedMore();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_STN_CLICKED(IDC_LINK, &CAboutDlg::OnStnClickedLink)
	ON_STN_CLICKED(IDC_MORE, &CAboutDlg::OnStnClickedMore)
END_MESSAGE_MAP()


// CRandWDlg 对话框




CRandWDlg::CRandWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRandWDlg::IDD, pParent)
	, getContent(_T(""))
	, strFile1(_T(""))
	, strFile2(_T(""))
	, strFile3(_T(""))
	, countTime(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRandWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CONTENT, getContent);
	DDX_Text(pDX, IDC_OPEN_EDIT, strFile1);
	DDX_Text(pDX, IDC_SAVE_EDIT, strFile2);
	DDX_Text(pDX, IDC_SAVE_EDIT2, strFile3);
	DDX_Text(pDX, IDC_EDIT1, countTime);
}

BEGIN_MESSAGE_MAP(CRandWDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CRandWDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CRandWDlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDC_2_BUTTON, &CRandWDlg::OnBnClicked2Button)
	ON_BN_CLICKED(IDC_16_BUTTON, &CRandWDlg::OnBnClicked16Button)
	ON_EN_CHANGE(IDC_OPEN_EDIT, &CRandWDlg::OnEnChangeOpenEdit)
	ON_EN_CHANGE(IDC_SAVE_EDIT, &CRandWDlg::OnEnChangeSaveEdit)
	ON_BN_CLICKED(IDC_BACK_BUTTON, &CRandWDlg::OnBnClickedBackButton)
	ON_EN_CHANGE(IDC_SAVE_EDIT2, &CRandWDlg::OnEnChangeSaveEdit2)
END_MESSAGE_MAP()


// CRandWDlg 消息处理程序

BOOL CRandWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRandWDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRandWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRandWDlg::OnBnClickedOpenButton()
{  
    // 设置过滤器   
    TCHAR szFilter[] = _T("Word文档(*.doc)|*.doc|文本文档(*.txt)|*.txt|所有文件(*.*)|*.*||");   
    // 构造打开文件对话框   
    CFileDialog fileDlg(TRUE, _T("doc"), _T("my"), 0, szFilter, this);    
  
    // 显示打开文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
        strFilePath1 = fileDlg.GetPathName();   
        SetDlgItemText(IDC_OPEN_EDIT, strFilePath1);   
    }   
}


void CRandWDlg::OnBnClickedSaveButton()
{
	 
    // 设置过滤器   
    TCHAR szFilter[] = _T("文本文档(*.txt)|*.txt|所有文件(*.*)|*.*||");   
    // 构造保存文件对话框   
    CFileDialog fileDlg(FALSE, _T("txt"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   

    // 显示保存文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
        strFilePath2 = fileDlg.GetPathName();   
        SetDlgItemText(IDC_SAVE_EDIT, strFilePath2);   
    }   
}

void CRandWDlg::OnBnClickedBackButton()
{
	// 设置过滤器   
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
    CFileDialog fileDlg(FALSE, _T("doc"), _T("myUndo"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this); 
	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())   
	{   
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath3 = fileDlg.GetPathName();   
		SetDlgItemText(IDC_SAVE_EDIT2, strFilePath3);   
	}   
}

/************************************************************************/
/* 二进制文件转十六进制字符串文件                                       */
/************************************************************************/
void CRandWDlg::OnBnClicked2Button()
{
	if(strFile1==""||strFile2=="")
	{
		AfxMessageBox("请选择文件！");
		return;
	}
	if (strFile1==strFile2)
	{
		AfxMessageBox("请选择不同的文件！");
		return;
	}
	INT_PTR nRes;
	nRes = MessageBox(_T("您确定要进行转换吗？"),_T("二进制文件转十六进制字符串文件"),MB_OKCANCEL|MB_ICONQUESTION);
	if(IDCANCEL == nRes)
		return;
	double countDown = clock();

	/************************MFC 方式处理************************/
	//unsigned char buf[MAXLEN]={0};
	//CFile fin(_T(strFile1),CFile::modeRead|CFile::typeBinary);
	//CFile fout(_T(strFile2),CFile::modeCreate|CFile::modeWrite);
	//int nRet = fin.Read(buf,MAXLEN);
	//CString str;
	//while(nRet!=0)
	//{
	//	//fout.Write(buf,nRet);
	//	for(int i=0;i<nRet;i++)
	//	{
	//		str.Format(_T("%.2x "),buf[i]);
	//		fout.Write(str,3);
	//	}
	//	fout.Write("\r\n",2);
	//	nRet = fin.Read(buf,MAXLEN);
	//}
	//fin.Close();
	//fout.Close();
	/***********************************************************/
	
	/**********************C 语言方式处理************************/
	FILE *fp = fopen(strFile1, "rb");
	FILE *f = fopen(strFile2,"w");
	if(fp==NULL||f==NULL)
	{
		AfxMessageBox("文件错误或文件不存在，请重新选择文件！");
		return;
	}
	unsigned char buf[MAXLEN]={0};
	int rc;//fread返回值
	while( (rc = fread(buf,sizeof(unsigned char),MAXLEN,fp)) != 0 )  
	{   
		for(int i = 0;i<rc;i++)
		{
			
			int num = buf[i];
			/**规范书写*/
			if (num<16)
			{
				fprintf(f,"0%x ",num);
			} 
			else
			{
				fprintf(f,"%x ",num);
			}
		}
		fprintf(f,"\n");
	} 
	fclose(fp);
	fclose(f);
	/***********************************************************/
	double countDownEnd = clock();
	countTime = (countDownEnd-countDown)/1000;
	getContent = "原二进制文件："+strFile1+"\r\n目标十六进制字符串文件："+strFile2+"\r\n执行成功！";
	UpdateData(FALSE);
}

/************************************************************************/
/*   十六进制字符串文件转二进制文件                                     */
/************************************************************************/

void CRandWDlg::OnBnClicked16Button()
{
	if(strFile2==""||strFile3=="")
	{
		AfxMessageBox("请选择文件！");
		return;
	}
	if (strFile3==strFile2)
	{
		AfxMessageBox("请选择不同的文件！");
		return;
	}
	INT_PTR nRes;
	nRes = MessageBox(_T("您确定要进行转换吗？"),_T("十六进制字符串文件转二进制文件"),MB_OKCANCEL|MB_ICONQUESTION);
	if(IDCANCEL == nRes)
		return;
	double countDown = clock();
	/************************MFC 方式处理************************/
	//CFile fin(_T(strFile2),CFile::modeRead);
	//CFile fout(_T(strFile3),CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
	//CString str;
	//char buf1,buf2;
	//char ch;
	//int m1,m2,i=0;
	//int nRet1,nRet2,nRet3;
	//nRet1 = fin.Read(&buf1,1);
	//if (buf1=='\r')
	//{
	//	fin.Seek(1,CFile::current);
	//	nRet1 = fin.Read(&buf1,1);
	//}
	//nRet2 = fin.Read(&buf2,1);
	//nRet3 = fin.Read(&ch,1);
	//while(nRet1+nRet2!=0/**&&buf1!='xCC'*/)
	//{
	//	if (buf1>='a'&&buf1<='f')
	//	{
	//		m1=buf1-'a'+10;
	//	}
	//	else
	//	{
	//		m1=buf1-'0';
	//	}
	//	if (buf2>='a'&&buf2<='f')
	//	{
	//		m2=buf2-'a'+10;
	//	}
	//	else
	//	{
	//		m2=buf2-'0';
	//	}
	//	int m = 16*m1+m2;
	//	CString str;
	//	str.Format("%c",m);
	//	fout.Write(str,1);
	//	nRet1 = fin.Read(&buf1,1);
	//	if (buf1=='\r')
	//	{
	//		fin.Seek(1,CFile::current);
	//		nRet1 = fin.Read(&buf1,1);
	//	}
	//	nRet2 = fin.Read(&buf2,1);
	//	nRet3 = fin.Read(&ch,1);
	//}
	//fin.Close();
	//fout.Close();
	/***********************************************************/
	
	/**********************C 语言方式处理************************/
	FILE *fp = fopen(strFile2, "r");
	FILE *f = fopen(strFile3, "wb");
	if(fp==NULL||f==NULL)
	{
		AfxMessageBox("文件错误或文件不存在，请重新选择文件！");
		return;
	}
	int n;
	while(fscanf(fp,"%x",&n)!=EOF)
	{
		fwrite(&n,1,1,f);
	} 
	fclose(fp);
	fclose(f);
	/***********************************************************/
	double countDownEnd = clock();
	countTime = (countDownEnd-countDown)/1000;
	getContent = "原十六进制字符串文件："+strFile2+"\r\n目标二进制文件："+strFile3+"\r\n执行成功！";
	UpdateData(FALSE);
}

void CRandWDlg::OnEnChangeOpenEdit()
{
	UpdateData(TRUE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CRandWDlg::OnEnChangeSaveEdit()
{
	UpdateData(TRUE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void CRandWDlg::OnEnChangeSaveEdit2()
{
	UpdateData(TRUE);
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAboutDlg::OnStnClickedLink()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(0, NULL, _T("http://github.zhangdanyang.com/2016/08/29/%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%96%87%E4%BB%B6%E4%B8%8E%E5%8D%81%E5%85%AD%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%96%87%E4%BB%B6%E4%BA%92%E7%9B%B8%E8%BD%AC%E6%8D%A2/"), NULL, NULL, SW_NORMAL);
}


void CAboutDlg::OnStnClickedMore()
{

	ShellExecute(0, NULL, _T("http://github.zhangdanyang.com/2016/08/29/%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%96%87%E4%BB%B6%E4%B8%8E%E5%8D%81%E5%85%AD%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%96%87%E4%BB%B6%E4%BA%92%E7%9B%B8%E8%BD%AC%E6%8D%A2/"), NULL, NULL, SW_NORMAL);
}
