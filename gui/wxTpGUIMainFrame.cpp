#include "wxTpGUIMainFrame.h"
#include "../wxtestpad.h"

wxTpGUIMainFrame::wxTpGUIMainFrame(wxWindow* parent) : MainFrame(parent) {}

void wxTpGUIMainFrame::MainFrameOnClose(wxCloseEvent& event) {
    wxMessageDialog dialog(this, "Are you sure you want to close?", TP_PROJECT_NAME,
                           wxYES_NO | wxICON_QUESTION);
    int result = dialog.ShowModal();

    if (result == wxID_YES) {
        event.Skip();
    } else if (result == wxID_NO) {
        event.Veto();
    }
}

void wxTpGUIMainFrame::m_menuItemExitOnMenuSelection(wxCommandEvent& event) {
    this->Close();
}

void wxTpGUIMainFrame::m_menuItemAboutOnMenuSelection(wxCommandEvent& event) {
    this->SetTitle("You clicked the about button !");
}
