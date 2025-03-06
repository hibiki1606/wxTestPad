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

