
// RandWDlg.h : ͷ�ļ�
//

#pragma once


// CRandWDlg �Ի���
class CRandWDlg : public CDialogEx
{
// ����
public:
	CRandWDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenButton();
	afx_msg void OnBnClickedSaveButton();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClicked2Button();
	afx_msg void OnEnChangeEdit1();
	CString getContent;
	afx_msg void OnBnClicked16Button();
	CString strFile1;
	CString strFile2;
	afx_msg void OnEnChangeOpenEdit();
	afx_msg void OnEnChangeSaveEdit();
	CString strFile3;
	afx_msg void OnBnClickedBackButton();
	afx_msg void OnEnChangeSaveEdit2();
	double countTime;
};
