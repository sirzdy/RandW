#include<conio.h>
// RandWDlg.cpp : ʵ���ļ�
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


// CRandWDlg �Ի���




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


// CRandWDlg ��Ϣ�������

BOOL CRandWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRandWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRandWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRandWDlg::OnBnClickedOpenButton()
{  
    // ���ù�����   
    TCHAR szFilter[] = _T("Word�ĵ�(*.doc)|*.doc|�ı��ĵ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");   
    // ������ļ��Ի���   
    CFileDialog fileDlg(TRUE, _T("doc"), _T("my"), 0, szFilter, this);    
  
    // ��ʾ���ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
        strFilePath1 = fileDlg.GetPathName();   
        SetDlgItemText(IDC_OPEN_EDIT, strFilePath1);   
    }   
}


void CRandWDlg::OnBnClickedSaveButton()
{
	 
    // ���ù�����   
    TCHAR szFilter[] = _T("�ı��ĵ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");   
    // ���챣���ļ��Ի���   
    CFileDialog fileDlg(FALSE, _T("txt"), _T("my"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);   

    // ��ʾ�����ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
        strFilePath2 = fileDlg.GetPathName();   
        SetDlgItemText(IDC_SAVE_EDIT, strFilePath2);   
    }   
}

void CRandWDlg::OnBnClickedBackButton()
{
	// ���ù�����   
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
    CFileDialog fileDlg(FALSE, _T("doc"), _T("myUndo"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this); 
	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())   
	{   
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath3 = fileDlg.GetPathName();   
		SetDlgItemText(IDC_SAVE_EDIT2, strFilePath3);   
	}   
}

/************************************************************************/
/* �������ļ�תʮ�������ַ����ļ�                                       */
/************************************************************************/
void CRandWDlg::OnBnClicked2Button()
{
	if(strFile1==""||strFile2=="")
	{
		AfxMessageBox("��ѡ���ļ���");
		return;
	}
	if (strFile1==strFile2)
	{
		AfxMessageBox("��ѡ��ͬ���ļ���");
		return;
	}
	INT_PTR nRes;
	nRes = MessageBox(_T("��ȷ��Ҫ����ת����"),_T("�������ļ�תʮ�������ַ����ļ�"),MB_OKCANCEL|MB_ICONQUESTION);
	if(IDCANCEL == nRes)
		return;
	double countDown = clock();

	/************************MFC ��ʽ����************************/
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
	
	/**********************C ���Է�ʽ����************************/
	FILE *fp = fopen(strFile1, "rb");
	FILE *f = fopen(strFile2,"w");
	if(fp==NULL||f==NULL)
	{
		AfxMessageBox("�ļ�������ļ������ڣ�������ѡ���ļ���");
		return;
	}
	unsigned char buf[MAXLEN]={0};
	int rc;//fread����ֵ
	while( (rc = fread(buf,sizeof(unsigned char),MAXLEN,fp)) != 0 )  
	{   
		for(int i = 0;i<rc;i++)
		{
			
			int num = buf[i];
			/**�淶��д*/
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
	getContent = "ԭ�������ļ���"+strFile1+"\r\nĿ��ʮ�������ַ����ļ���"+strFile2+"\r\nִ�гɹ���";
	UpdateData(FALSE);
}

/************************************************************************/
/*   ʮ�������ַ����ļ�ת�������ļ�                                     */
/************************************************************************/

void CRandWDlg::OnBnClicked16Button()
{
	if(strFile2==""||strFile3=="")
	{
		AfxMessageBox("��ѡ���ļ���");
		return;
	}
	if (strFile3==strFile2)
	{
		AfxMessageBox("��ѡ��ͬ���ļ���");
		return;
	}
	INT_PTR nRes;
	nRes = MessageBox(_T("��ȷ��Ҫ����ת����"),_T("ʮ�������ַ����ļ�ת�������ļ�"),MB_OKCANCEL|MB_ICONQUESTION);
	if(IDCANCEL == nRes)
		return;
	double countDown = clock();
	/************************MFC ��ʽ����************************/
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
	
	/**********************C ���Է�ʽ����************************/
	FILE *fp = fopen(strFile2, "r");
	FILE *f = fopen(strFile3, "wb");
	if(fp==NULL||f==NULL)
	{
		AfxMessageBox("�ļ�������ļ������ڣ�������ѡ���ļ���");
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
	getContent = "ԭʮ�������ַ����ļ���"+strFile2+"\r\nĿ��������ļ���"+strFile3+"\r\nִ�гɹ���";
	UpdateData(FALSE);
}

void CRandWDlg::OnEnChangeOpenEdit()
{
	UpdateData(TRUE);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRandWDlg::OnEnChangeSaveEdit()
{
	UpdateData(TRUE);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}




void CRandWDlg::OnEnChangeSaveEdit2()
{
	UpdateData(TRUE);
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAboutDlg::OnStnClickedLink()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShellExecute(0, NULL, _T("http://github.zhangdanyang.com/2016/08/29/%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%96%87%E4%BB%B6%E4%B8%8E%E5%8D%81%E5%85%AD%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%96%87%E4%BB%B6%E4%BA%92%E7%9B%B8%E8%BD%AC%E6%8D%A2/"), NULL, NULL, SW_NORMAL);
}


void CAboutDlg::OnStnClickedMore()
{

	ShellExecute(0, NULL, _T("http://github.zhangdanyang.com/2016/08/29/%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%96%87%E4%BB%B6%E4%B8%8E%E5%8D%81%E5%85%AD%E8%BF%9B%E5%88%B6%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%96%87%E4%BB%B6%E4%BA%92%E7%9B%B8%E8%BD%AC%E6%8D%A2/"), NULL, NULL, SW_NORMAL);
}
