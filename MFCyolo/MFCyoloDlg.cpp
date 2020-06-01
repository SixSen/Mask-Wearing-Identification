
// MFCyoloDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCyolo.h"
#include "MFCyoloDlg.h"
#include "afxdialogex.h"
#include <stdlib.h> 
#include <direct.h>
#include<iostream>
#include <dos.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCyoloDlg 对话框



CMFCyoloDlg::CMFCyoloDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCYOLO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCyoloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCyoloDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCyoloDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCyoloDlg::OnBnClickedCancel)
//	ON_BN_CLICKED(IDC_BUTTON1, &CMFCyoloDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCyoloDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCyoloDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCyoloDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFCyoloDlg 消息处理程序

BOOL CMFCyoloDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCyoloDlg::OnPaint()
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
HCURSOR CMFCyoloDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCyoloDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CString load(_T("正在加载，请稍后"));
	//ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c .\\cam.vbs", NULL, SW_SHOW);
	//MessageBox(load);
	ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c .\\start.bat ", NULL, SW_SHOW);
	

}


void CMFCyoloDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnCancel();
}


void CMFCyoloDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	GetDlgItem(IDC_STATIC)->GetWindowText(str);
	if (str == "口罩佩戴识别")
	{
		CWaitCursor wait;
		CString dd(_T("请选择识别文件"));
		MessageBox(dd);
		return;
	}

	//MessageBox(str);
	ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c .\\photo.bat "+str, NULL, SW_SHOW);

}


void CMFCyoloDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CString m_ReleaseVerFilePath;
	//打开文件的类型
	TCHAR szFilter[] = _T("JPG图片(*.jpg)|*.jpg|PNG图片(*.png)|*.png|视频文件(*.mp4)|*.mp4|所有文件(*.*)|*.*||");
	CFileDialog dlg(1, NULL, NULL, NULL, szFilter);

	//设置默认路径
	dlg.m_ofn.lpstrInitialDir = _T("C://Users");

	if (dlg.DoModal() == IDOK)
	{
		m_ReleaseVerFilePath = dlg.GetPathName();
		SetDlgItemText(IDC_STATIC, m_ReleaseVerFilePath);
	}
	//ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c photo.bat", NULL, SW_SHOW);

	
}



void CMFCyoloDlg::OnBnClickedC()
{
	// TODO: 在此添加控件通知处理程序代码
}




void CMFCyoloDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str,str1;
	GetDlgItem(IDC_STATIC)->GetWindowText(str);
	str1 = str.Right(3);
	if (str == "口罩佩戴识别")
	{
		CWaitCursor wait;
		CString dd(_T("请选择视频文件识别"));
		MessageBox(dd);
		return;
	}
	if (str1 == "mp4")
	{
		ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c .\\video.bat " + str, NULL, SW_SHOW);
		return;
	}
	CString err(_T("请选择正确的视频格式（.mp4）"));
	MessageBox(err);
	//MessageBox(str);
}


void CMFCyoloDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	CString str,str1;
	GetDlgItem(IDC_STATIC)->GetWindowText(str);
	str1 = str.Right(3);
	if (str == "口罩佩戴识别")
	{
		CWaitCursor wait;
		CString dd(_T("请选择图片文件识别"));
		MessageBox(dd);
		return;
	}
	if (str1 == "png" || str1 == "jpg")
	{
		ShellExecute(AfxGetMainWnd()->m_hWnd, L"open", L"cmd", L"/c  .\\photo.bat " + str, NULL, SW_SHOW);
		return;
	}
	CString err(_T("请选择正确的图片格式（.jpg/.png）"));
	MessageBox(err);
	return;


}
