///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "TpGUI.h"

#include "res/copy.bmp.h"
#include "res/file.bmp.h"
#include "res/find.bmp.h"
#include "res/font.bmp.h"
#include "res/paste.bmp.h"
#include "res/question.bmp.h"
#include "res/save.bmp.h"
#include "res/switch.bmp.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,400 ), wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_ribbonBar = new wxRibbonBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxRIBBON_BAR_DEFAULT_STYLE );
	m_ribbonBar->SetArtProvider(new wxRibbonMSWArtProvider);
	m_ribbonPageTestPad = new wxRibbonPage( m_ribbonBar, wxID_ANY, _("TestPad") , wxNullBitmap , 0 );
	m_ribbonBar->SetActivePage( m_ribbonPageTestPad );
	m_ribbonPanelFile = new wxRibbonPanel( m_ribbonPageTestPad, wxID_ANY, _("File") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar7 = new wxRibbonButtonBar( m_ribbonPanelFile, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar7->AddButton( TP_RIBBON_OPEN, _("Open..."), file_bmp_to_wx_bitmap(), _("Open a file..."));
	m_ribbonButtonBar7->AddButton( TP_RIBBON_SAVEAS, _("Save as..."), save_bmp_to_wx_bitmap(), _("Save the text into a file"));
	m_ribbonPanelEdit = new wxRibbonPanel( m_ribbonPageTestPad, wxID_ANY, _("Edit") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar6 = new wxRibbonButtonBar( m_ribbonPanelEdit, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar6->AddButton( TP_RIBBON_FIND, _("Find..."), find_bmp_to_wx_bitmap(), _("Find..."));
	m_ribbonPanelClipboard = new wxRibbonPanel( m_ribbonPageTestPad, wxID_ANY, _("Clipboard") , wxNullBitmap , wxDefaultPosition, wxSize( -1,-1 ), wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar5 = new wxRibbonButtonBar( m_ribbonPanelClipboard, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_ribbonButtonBar5->AddButton( TP_RIBBON_COPY, _("Copy"), copy_bmp_to_wx_bitmap(), _("Copy the selected text into the clipboard"));
	m_ribbonButtonBar5->AddButton( TP_RIBBON_PASTE, _("Paste"), paste_bmp_to_wx_bitmap(), _("Paste text from the clipboard"));
	m_ribbonPanelText = new wxRibbonPanel( m_ribbonPageTestPad, wxID_ANY, _("Text") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar9 = new wxRibbonButtonBar( m_ribbonPanelText, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar9->AddButton( TP_RIBBON_FONT, _("Font"), font_bmp_to_wx_bitmap(), _("Change font"));
	m_ribbonPanelAppearance = new wxRibbonPanel( m_ribbonPageTestPad, wxID_ANY, _("Appearance") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonPanelAppearance->Hide();

	m_ribbonButtonBar51 = new wxRibbonButtonBar( m_ribbonPanelAppearance, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar51->AddToggleButton( TP_RIBBON_THEME, _("Classic"), switch_bmp_to_wx_bitmap(), _("Toggle the theme"));
	m_ribbonPageHelp = new wxRibbonPage( m_ribbonBar, wxID_ANY, _("Help") , wxNullBitmap , 0 );
	m_ribbonPanelAbout = new wxRibbonPanel( m_ribbonPageHelp, wxID_ANY, _("About") , wxNullBitmap , wxDefaultPosition, wxDefaultSize, wxRIBBON_PANEL_DEFAULT_STYLE );
	m_ribbonButtonBar8 = new wxRibbonButtonBar( m_ribbonPanelAbout, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_ribbonButtonBar8->AddButton( TP_RIBBON_ABOUT, _("About"), question_bmp_to_wx_bitmap(), _("About this app"));
	m_ribbonBar->Realize();

	bSizer1->Add( m_ribbonBar, 0, wxALL|wxEXPAND, 0 );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH2 );
	bSizer1->Add( m_textCtrl, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::MainFrameOnClose ) );
	this->Connect( TP_RIBBON_OPEN, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_SAVEAS, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_FIND, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_COPY, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_PASTE, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_FONT, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
	this->Connect( TP_RIBBON_THEME, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxCommandEventHandler( MainFrame::m_ribbonToggleTheme ) );
	this->Connect( TP_RIBBON_ABOUT, wxEVT_COMMAND_RIBBONBUTTON_CLICKED, wxRibbonButtonBarEventHandler( MainFrame::m_ribbonOnClick ) );
}

MainFrame::~MainFrame()
{
}
