// ProjetoTesteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProjetoTeste.h"
#include "ProjetoTesteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

//declaração globol variavel statica

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjetoTesteDlg dialog

CProjetoTesteDlg::CProjetoTesteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjetoTesteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjetoTesteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjetoTesteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjetoTesteDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

// Exibe uma mensagem de erro na tela
void ExibirMensagemErro(const CString& mensagem)
{
    AfxMessageBox(mensagem, MB_OK | MB_ICONERROR);
}

void CalcularOperacao(CStatic& pStaticOperacao, CStatic& pStaticResultado, CStatic& pStaticNumero, const CString& _operador)
{
    CString var_numero;
    CString var_resultado;
    CString var_operacao;
    
    pStaticOperacao.GetWindowText(var_operacao);                    // Obtém o valor do texto estático
    pStaticResultado.GetWindowText(var_resultado);                  // Obtém o valor do texto estático
    pStaticNumero.GetWindowText(var_numero);                        // Obtém o valor do texto estático
    
    if (var_numero != "") {
        if (var_operacao == ""){
            var_operacao = _operador;                               // Atribui valor a variavel
            pStaticOperacao.SetWindowText(var_operacao);            // Atribui o valor da string ao objeto "Static Text"

            pStaticResultado.SetWindowText(var_numero);             // Atribui o valor da string ao objeto "Static Text"

            var_numero = "";                                        // Atribui valor a variavel
            pStaticNumero.SetWindowText(var_numero);                // Atribui o valor da string ao objeto "Static Text"
        }
        else {
            if (var_numero != ""){
                DOUBLE valor1;
                DOUBLE valor2;
                
                try {
                    valor1 = atof(var_resultado);
                    valor2 = atof(var_numero);
                }
                catch (...) {
                    CString mensagemErro = ("Ocorreu um erro ao resgatar o valor dos objetos!");
                    ExibirMensagemErro(mensagemErro);
                }
                
                char buffer[50];
                if (var_operacao == "+"){
                    valor1 = valor1 + valor2;
                    sprintf(buffer, "%.0f", valor1);
                    var_resultado = buffer;
                    pStaticResultado.SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
                    var_numero = "";                                 // Atribui valor a variavel
                    pStaticNumero.SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
                    pStaticOperacao.SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
                }
                else if (var_operacao == "-"){
                    valor1 = valor1 - valor2;
                    sprintf(buffer, "%.0f", valor1);
                    var_resultado = buffer;
                    pStaticResultado.SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
                    var_numero = "";                                 // Atribui valor a variavel
                    pStaticNumero.SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
                    pStaticOperacao.SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
                }
                else if (var_operacao == "/"){
                    valor1 = valor1 / valor2;
                    sprintf(buffer, "%.2f", valor1);
                    var_resultado = buffer;
                    pStaticResultado.SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
                    var_numero = "";                                 // Atribui valor a variavel
                    pStaticNumero.SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
                    pStaticOperacao.SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
                }
                else if (var_operacao == "*"){
                    valor1 = valor1 * valor2;
                    sprintf(buffer, "%.0f", valor1);
                    var_resultado = buffer;
                    pStaticResultado.SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
                    var_numero = "";                                 // Atribui valor a variavel
                    pStaticNumero.SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
                    pStaticOperacao.SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
                }
            }
            else{
                var_operacao = _operador;                            // Atribui valor a variavel
                pStaticOperacao.SetWindowText(var_operacao);         // Atribui o valor da string ao objeto "Static Text"

                pStaticResultado.SetWindowText(var_numero);          // Atribui o valor da string ao objeto "Static Text"

                var_numero = "";                                     // Atribui valor a variavel
                pStaticNumero.SetWindowText(var_numero);             // Atribui o valor da string ao objeto "Static Text"
            }
        }
    }
    else{
        if (var_resultado != ""){
            var_operacao = _operador;                                // Atribui valor a variavel
            pStaticOperacao.SetWindowText(var_operacao);             // Atribui o valor da string ao objeto "Static Text"

            var_numero = "";                                         // Atribui valor a variavel
            pStaticNumero.SetWindowText(var_numero);                 // Atribui o valor da string ao objeto "Static Text"
        }
    }
}

BEGIN_MESSAGE_MAP(CProjetoTesteDlg, CDialog)
	//{{AFX_MSG_MAP(CProjetoTesteDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_BT_5, OnBt5)
	ON_BN_CLICKED(ID_BT_6, OnBt6)
	ON_BN_CLICKED(ID_BT_7, OnBt7)
	ON_BN_CLICKED(ID_BT_8, OnBt8)
	ON_BN_CLICKED(ID_BT_9, OnBt9)
	ON_BN_CLICKED(ID_BT_0, OnBt0)
	ON_BN_CLICKED(ID_BT_1, OnBt1)
	ON_BN_CLICKED(ID_BT_2, OnBt2)
	ON_BN_CLICKED(ID_BT_3, OnBt3)
	ON_BN_CLICKED(ID_BT_4, OnBt4)
	ON_BN_CLICKED(ID_BT_MA, OnBtMa)
	ON_BN_CLICKED(ID_BT_SB, OnBtSb)
	ON_BN_CLICKED(ID_BT_DV, OnBtDv)
	ON_BN_CLICKED(ID_BT_MT, OnBtMt)
	ON_BN_CLICKED(ID_BT_LP, OnBtLp)
	ON_BN_CLICKED(ID_BT_CA, OnBtCa)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjetoTesteDlg message handlers

BOOL CProjetoTesteDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CProjetoTesteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProjetoTesteDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProjetoTesteDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CProjetoTesteDlg::OnBt5() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "5";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt6() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "6";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt7() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "7";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt8() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "8";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt9() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "9";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt0() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "0";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt1() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "1";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt2() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "2";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt3() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "3";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBt4() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_2); // Obtém o ponteiro para o controle IDC_STATIC_2
    pStaticText->GetWindowText(var_numero);       // Obtém o valor do texto estático
	var_numero = var_numero + "4";                // Somando valor a variavel
	pStaticText->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBtMa() 
{
	// TODO: Add your control notification handler code here
	//Selecionando o botão soma
	CStatic* pStaticResultado = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_1));  // Obtém o ponteiro para o controle IDC_STATIC_1
	CStatic* pStaticNumero = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_2));     // Obtém o ponteiro para o controle IDC_STATIC_2
	CStatic* pStaticOperacao = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_3));   // Obtém o ponteiro para o controle IDC_STATIC_3

	CalcularOperacao(*pStaticOperacao, *pStaticResultado, *pStaticNumero, "+");
}

void CProjetoTesteDlg::OnBtSb() 
{
	// TODO: Add your control notification handler code here
	//Selecionando o botão subtração
	CStatic* pStaticResultado = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_1));  // Obtém o ponteiro para o controle IDC_STATIC_1
	CStatic* pStaticNumero = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_2));     // Obtém o ponteiro para o controle IDC_STATIC_2
	CStatic* pStaticOperacao = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_3));   // Obtém o ponteiro para o controle IDC_STATIC_3

	CalcularOperacao(*pStaticOperacao, *pStaticResultado, *pStaticNumero, "-");
	
}

void CProjetoTesteDlg::OnBtDv() 
{
	// TODO: Add your control notification handler code here
	//Selecionando o botão divisão
	CStatic* pStaticResultado = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_1));  // Obtém o ponteiro para o controle IDC_STATIC_1
	CStatic* pStaticNumero = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_2));     // Obtém o ponteiro para o controle IDC_STATIC_2
	CStatic* pStaticOperacao = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_3));   // Obtém o ponteiro para o controle IDC_STATIC_3

	CalcularOperacao(*pStaticOperacao, *pStaticResultado, *pStaticNumero, "/");
}

void CProjetoTesteDlg::OnBtMt() 
{
	// TODO: Add your control notification handler code here
	//Selecionando o botão multiplicação
	CStatic* pStaticResultado = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_1));  // Obtém o ponteiro para o controle IDC_STATIC_1
	CStatic* pStaticNumero = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_2));     // Obtém o ponteiro para o controle IDC_STATIC_2
	CStatic* pStaticOperacao = reinterpret_cast<CStatic*>(GetDlgItem(IDC_STATIC_3));   // Obtém o ponteiro para o controle IDC_STATIC_3

	CalcularOperacao(*pStaticOperacao, *pStaticResultado, *pStaticNumero, "*");
}

void CProjetoTesteDlg::OnBtLp() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticText1 = GetDlgItem(IDC_STATIC_1);    // Obtém o ponteiro para o controle IDC_STATIC_1
	CWnd* pStaticText2 = GetDlgItem(IDC_STATIC_2);    // Obtém o ponteiro para o controle IDC_STATIC_2
	CWnd* pStaticOperacao = GetDlgItem(IDC_STATIC_3); // Obtém o ponteiro para o controle IDC_STATIC_3
	var_numero = "";                                  // Limpeza de variavel
	var_resultado = "";
	var_operacao = "";
	var_valor_1 = "";
	var_valor_2 = "";
	pStaticText1->SetWindowText(var_numero);          // Atribui o valor da string ao objeto "Static Text"
	pStaticText2->SetWindowText(var_numero);          // Atribui o valor da string ao objeto "Static Text"
	pStaticOperacao->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
}

void CProjetoTesteDlg::OnBtCa() 
{
	// TODO: Add your control notification handler code here
	CWnd* pStaticResultado = GetDlgItem(IDC_STATIC_1);            // Obtém o ponteiro para o controle IDC_STATIC_1
    CWnd* pStaticNumero = GetDlgItem(IDC_STATIC_2);               // Obtém o ponteiro para o controle IDC_STATIC_2
    CWnd* pStaticOperacao = GetDlgItem(IDC_STATIC_3);             // Obtém o ponteiro para o controle IDC_STATIC_3
	pStaticOperacao->GetWindowText(var_operacao);                 // Obtém o valor do texto estático
    pStaticResultado->GetWindowText(var_resultado);               // Obtém o valor do texto estático
    pStaticNumero->GetWindowText(var_numero);                     // Obtém o valor do texto estático

	if (var_operacao != "" && var_resultado != "" && var_numero != ""){                
		DOUBLE valor1;
        DOUBLE valor2;
        
        try {
			valor1 = atof(var_resultado);
            valor2 = atof(var_numero);
		}
        catch (...) {
			CString mensagemErro = ("Ocorreu um erro ao resgatar o valor dos objetos!");
            ExibirMensagemErro(mensagemErro);
        }

        char buffer[50];
        if (var_operacao == "+"){
            valor1 = valor1 + valor2;
            sprintf(buffer, "%.0f", valor1);
            var_resultado = buffer;
            pStaticResultado->SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
            var_numero = "";                                  // Atribui valor a variavel
            pStaticNumero->SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
            pStaticOperacao->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
        }
        else if (var_operacao == "-"){
            valor1 = valor1 - valor2;
            sprintf(buffer, "%.0f", valor1);
            var_resultado = buffer;
            pStaticResultado->SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
            var_numero = "";                                  // Atribui valor a variavel
            pStaticNumero->SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
            pStaticOperacao->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
        }
        else if (var_operacao == "/"){
            valor1 = valor1 / valor2;
            sprintf(buffer, "%.2f", valor1);
            var_resultado = buffer;
            pStaticResultado->SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
            var_numero = "";                                  // Atribui valor a variavel
            pStaticNumero->SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
            pStaticOperacao->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
        }
        else if (var_operacao == "*"){
            valor1 = valor1 * valor2;
            sprintf(buffer, "%.0f", valor1);
            var_resultado = buffer;
            pStaticResultado->SetWindowText(var_resultado);   // Atribui o valor da string ao objeto "Static Text"
            var_numero = "";                                  // Atribui valor a variavel
            pStaticNumero->SetWindowText(var_numero);         // Atribui o valor da string ao objeto "Static Text"
            pStaticOperacao->SetWindowText(var_numero);       // Atribui o valor da string ao objeto "Static Text"
        }
	}
}
