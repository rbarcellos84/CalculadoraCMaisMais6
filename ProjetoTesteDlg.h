// ProjetoTesteDlg.h : header file
//

#if !defined(AFX_PROJETOTESTEDLG_H__0A791600_4736_401C_B858_FEDA6702B689__INCLUDED_)
#define AFX_PROJETOTESTEDLG_H__0A791600_4736_401C_B858_FEDA6702B689__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProjetoTesteDlg dialog

class CProjetoTesteDlg : public CDialog
{
//declaração da variavel global para ser utilizado no projeto
public:
    CString var_numero;
    CString var_resultado;
	CString var_operacao;
	CString var_valor_1;
	CString var_valor_2;

// Construction
public:
	CProjetoTesteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProjetoTesteDlg)
	enum { IDD = IDD_PROJETOTESTE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjetoTesteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProjetoTesteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBt5();
	afx_msg void OnBt6();
	afx_msg void OnBt7();
	afx_msg void OnBt8();
	afx_msg void OnBt9();
	afx_msg void OnBt0();
	afx_msg void OnBt1();
	afx_msg void OnBt2();
	afx_msg void OnBt3();
	afx_msg void OnBt4();
	afx_msg void OnBtMa();
	afx_msg void OnBtSb();
	afx_msg void OnBtDv();
	afx_msg void OnBtMt();
	afx_msg void OnBtLp();
	afx_msg void OnBtCa();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJETOTESTEDLG_H__0A791600_4736_401C_B858_FEDA6702B689__INCLUDED_)
