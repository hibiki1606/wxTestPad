///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxTpGUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItemOpen;
	m_menuItemOpen = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Open...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemOpen );

	wxMenuItem* m_menuItemSave;
	m_menuItemSave = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemSave );

	wxMenuItem* m_menuItemSaveAs;
	m_menuItemSaveAs = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Save as...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemSaveAs );

	m_menu1->AppendSeparator();

	wxMenuItem* m_menuItemExit;
	m_menuItemExit = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemExit );

	m_menubar1->Append( m_menu1, _("File") );

	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItemAbout;
	m_menuItemAbout = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItemAbout );

	m_menubar1->Append( m_menu2, _("Help") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer1->Add( m_textCtrl, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::MainFrameOnClose ) );
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_menuItemOpenOnMenuSelection ), this, m_menuItemOpen->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_menuItemSaveAsOnMenuSelection ), this, m_menuItemSaveAs->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_menuItemExitOnMenuSelection ), this, m_menuItemExit->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_menuItemAboutOnMenuSelection ), this, m_menuItemAbout->GetId());
}

MainFrame::~MainFrame()
{
}
