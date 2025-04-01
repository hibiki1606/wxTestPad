///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/ribbon/buttonbar.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/ribbon/panel.h>
#include <wx/ribbon/page.h>
#include <wx/ribbon/control.h>
#include <wx/ribbon/art.h>
#include <wx/ribbon/bar.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		enum
		{
			TP_RIBBON_OPEN = 6000,
			TP_RIBBON_SAVEAS,
			TP_RIBBON_FIND,
			TP_RIBBON_REPLACE,
			TP_RIBBON_COPY,
			TP_RIBBON_PASTE,
			TP_RIBBON_FONT,
			TP_RIBBON_THEME,
			TP_RIBBON_ABOUT,
		};

		wxRibbonBar* m_ribbonBar;
		wxRibbonPage* m_ribbonPageTestPad;
		wxRibbonPanel* m_ribbonPanelFile;
		wxRibbonButtonBar* m_ribbonButtonBar7;
		wxRibbonPanel* m_ribbonPanelEdit;
		wxRibbonButtonBar* m_ribbonButtonBar6;
		wxRibbonPanel* m_ribbonPanelClipboard;
		wxRibbonButtonBar* m_ribbonButtonBar5;
		wxRibbonPanel* m_ribbonPanelText;
		wxRibbonButtonBar* m_ribbonButtonBar9;
		wxRibbonPanel* m_ribbonPanelAppearance;
		wxRibbonButtonBar* m_ribbonButtonBar51;
		wxRibbonPage* m_ribbonPageHelp;
		wxRibbonPanel* m_ribbonPanelAbout;
		wxRibbonButtonBar* m_ribbonButtonBar8;
		wxTextCtrl* m_textCtrl;
		wxStatusBar* m_statusBar;

		// Virtual event handlers, override them in your derived class
		virtual void MainFrameOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void m_ribbonOnClick( wxRibbonButtonBarEvent& event ) { event.Skip(); }
		virtual void m_ribbonToggleTheme( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxTpGUI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 900,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ReplaceDialog
///////////////////////////////////////////////////////////////////////////////
class ReplaceDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrlFrom;
		wxCheckBox* m_checkBoxReplaceAll;
		wxStaticText* m_staticTextTo;
		wxTextCtrl* m_textCtrlTo;
		wxButton* m_buttonOk;

		// Virtual event handlers, override them in your derived class
		virtual void m_OkOnClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ReplaceDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Replace..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~ReplaceDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class FindDialog
///////////////////////////////////////////////////////////////////////////////
class FindDialog : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_textCtrlFind;
		wxButton* m_buttonFindNext;

		// Virtual event handlers, override them in your derived class
		virtual void m_FindNextOnClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		FindDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Find Next..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~FindDialog();

};

