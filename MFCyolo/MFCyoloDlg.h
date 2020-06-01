
// MFCyoloDlg.h : 头文件
//

#pragma once


// CMFCyoloDlg 对话框
class CMFCyoloDlg : public CDialogEx
{
// 构造
public:
	CMFCyoloDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCYOLO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedC();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedMfclink1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
};
