
// MFCyolo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCyoloApp: 
// �йش����ʵ�֣������ MFCyolo.cpp
//

class CMFCyoloApp : public CWinApp
{
public:
	CMFCyoloApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCyoloApp theApp;