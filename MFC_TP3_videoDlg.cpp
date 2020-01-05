
// MFC_TP3_videoDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"
#include "MFC_TP3_video.h"
#include "MFC_TP3_videoDlg.h"
#include "afxdialogex.h"
#include <Vfw.h>
#include "Ima.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//*****************************
CMFC_TP3_videoDlg *pDial; // pDiad :est un pointeur vers une boite de dialogue qui comporte : Hauteur, Largeur, Imrgb(vecteur de stockage d'image)....

// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	unsigned char * Imrgb= NULL; //******************* ajout pointeur

// Donn�es de bo�te de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
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


// bo�te de dialogue CMFC_TP3_videoDlg



CMFC_TP3_videoDlg::CMFC_TP3_videoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_TP3_VIDEO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_TP3_videoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_TP3_videoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC_TP3_videoDlg::OnBnClickedOk)
	ON_BN_CLICKED(m_init, &CMFC_TP3_videoDlg::OnBnClickedinit)
	ON_BN_CLICKED(m_videoFormat, &CMFC_TP3_videoDlg::OnBnClickedvideoformat)
	ON_BN_CLICKED(m_videoSource, &CMFC_TP3_videoDlg::OnBnClickedvideosource)
	ON_BN_CLICKED(m_traitement, &CMFC_TP3_videoDlg::OnBnClickedtraitement)
	ON_BN_CLICKED(m_inversion, &CMFC_TP3_videoDlg::OnBnClickedinversion)
	ON_BN_CLICKED(m_seuillage, &CMFC_TP3_videoDlg::OnBnClickedseuillage)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_TP3_videoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// gestionnaires de messages pour CMFC_TP3_videoDlg

BOOL CMFC_TP3_videoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
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

	// D�finir l'ic�ne de cette bo�te de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// TODO: ajoutez ici une initialisation suppl�mentaire

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CMFC_TP3_videoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne.  Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMFC_TP3_videoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CMFC_TP3_videoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_TP3_videoDlg::OnBnClickedOk()
{
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contr�le
	CDialogEx::OnOK();
}

bool b = false;
void CMFC_TP3_videoDlg::OnBnClickedinit()
{
	if (b == false) {
		b = true;
		pDial = this; //******* initialiser le pointeur pour l'utilise dans le CIma (traitement d'image).
		hWndC = capCreateCaptureWindow(L"Fenetre de Capture", WS_CHILD | WS_VISIBLE, 0, 0, 640, 480, m_hWnd, 0);
		capDriverConnect(hWndC, 0);
		capPreviewRate(hWndC, 40);
		capPreview(hWndC, TRUE);
		//*****************************
		CAPSTATUS capStatus;
		capGetStatus(hWndC, &capStatus, sizeof(capStatus));
		Largeur = capStatus.uiImageWidth;
		Hauteur = capStatus.uiImageHeight;
		//*************************************
		if (Imrgb != NULL) { free(Imrgb); }
		Imrgb = (unsigned char *)malloc(Largeur * Hauteur * 3 * sizeof(unsigned char *));
	}

}
//********************************************************
void CMFC_TP3_videoDlg::OnBnClickedvideoformat()
{
	capDlgVideoFormat(hWndC);
	
	CAPSTATUS capStatus;
	capGetStatus(hWndC, &capStatus, sizeof(capStatus));
	Largeur = capStatus.uiImageWidth;
	Hauteur = capStatus.uiImageHeight;

}

void CMFC_TP3_videoDlg::OnBnClickedvideosource()
{
	capDlgVideoSource(hWndC);
}


void CMFC_TP3_videoDlg::OnBnClickedtraitement()
{
	//pDial->choixTraitement = 0;
	capSetCallbackOnFrame(hWndC, CMFC_TP3_videoDlg::DetectionContour);
}


CIma Ima;

LPVOID CALLBACK CMFC_TP3_videoDlg::DetectionContour2(HWND hWndC, LPVIDEOHDR pV)
{
	unsigned char *PImage;
	PImage = pV->lpData; // PImage devient le pointeur vers les donn�es
	

	Ima.ConvertYUY2RGB(pV->lpData, pDial->Imrgb, pDial->Largeur, pDial->Hauteur);  
																				  
			
	Ima.Contour2(pDial->Imrgb, pDial->Largeur, pDial->Hauteur); // traitement de Imrgb en RGB 24 bits
	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur);
	
	

	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur); // passage en YUY2
	return 0;
}

LPVOID CALLBACK CMFC_TP3_videoDlg::DetectionContour(HWND hWndC, LPVIDEOHDR pV)
{
	unsigned char *PImage;
	PImage = pV->lpData; // PImage devient le pointeur vers les donn�es


	Ima.ConvertYUY2RGB(pV->lpData, pDial->Imrgb, pDial->Largeur, pDial->Hauteur);


	Ima.Contour(pDial->Imrgb, pDial->Largeur, pDial->Hauteur); // traitement de Imrgb en RGB 24 bits
	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur);



	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur); // passage en YUY2
	return 0;
}

LPVOID CALLBACK CMFC_TP3_videoDlg::InverserImage(HWND hWndC, LPVIDEOHDR pV)
{
	unsigned char *PImage;
	PImage = pV->lpData; // PImage devient le pointeur vers les donn�es


	Ima.ConvertYUY2RGB(pV->lpData, pDial->Imrgb, pDial->Largeur, pDial->Hauteur);


	Ima.inversion(pDial->Imrgb, pDial->Largeur, pDial->Hauteur); // traitement de Imrgb en RGB 24 bits 
	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur);

	

	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur); // passage en YUY2
	return 0;
}

LPVOID CALLBACK CMFC_TP3_videoDlg::SeuillageImage(HWND hWndC, LPVIDEOHDR pV)
{
	unsigned char *PImage;
	PImage = pV->lpData; // PImage devient le pointeur vers les donn�es


	Ima.ConvertYUY2RGB(pV->lpData, pDial->Imrgb, pDial->Largeur, pDial->Hauteur);


	Ima.seuillage(pDial->Imrgb, pDial->Largeur, pDial->Hauteur); // traitement de Imrgb en RGB 24 bits 
	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur);

	

	Ima.ConvertRGBYUY2(pDial->Imrgb, pV->lpData, pDial->Largeur, pDial->Hauteur); // passage en YUY2
	return 0;
}




void CMFC_TP3_videoDlg::OnBnClickedinversion()
{	
	capSetCallbackOnFrame(hWndC, CMFC_TP3_videoDlg::InverserImage);
}

void CMFC_TP3_videoDlg::OnBnClickedseuillage()
{	
	capSetCallbackOnFrame(hWndC, CMFC_TP3_videoDlg::SeuillageImage);
}


void CMFC_TP3_videoDlg::OnBnClickedButton1()
{
	capSetCallbackOnFrame(hWndC, CMFC_TP3_videoDlg::DetectionContour2);
}
