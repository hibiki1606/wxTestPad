#include "wxTpGUIMainFrame.h"

#include "../wxtestpad.h"

wxTpGUIMainFrame::wxTpGUIMainFrame(wxWindow* parent) : MainFrame(parent), m_notepad(m_textCtrl) {
    m_notepad.SetNotifyIsSavedChanged([&](bool isSaved) {
        this->SetTitle(
            wxString::Format("%s%s - %s", (m_notepad.GetIsSaved() ? "" : "*"), m_notepad.GetDocumentTitle(), TP_PROJECT_NAME)
        );
    });
    
    this->SetTitle(TP_PROJECT_NAME);
    this->SetStatusText("The app is ready !");
}

void wxTpGUIMainFrame::MainFrameOnClose(wxCloseEvent& event) {
    bool continueClosing = [this]() {
        wxMessageDialog dialog(
            this, "You have unsaved changes,\nDo you want to save them before closing this app?",
            TP_PROJECT_NAME, wxYES_NO | wxCANCEL | wxICON_QUESTION);
        int result = dialog.ShowModal();

        switch (result) {
            case wxID_YES: return SaveFile();
            case wxID_NO: return true; // Continue closing
            case wxID_CANCEL: return false; // Abort closing
            default: wxLogError("Unexpected value %d", result); return true;
        }
    }();

    if (continueClosing) {
        event.Skip();
    } else {
        event.Veto();
    }

    return;
}

bool wxTpGUIMainFrame::OpenFile() {
    wxFileDialog openFileDialog(
        this, "Open text document", wxEmptyString, wxEmptyString,
        "Text documents (*.txt;*.text)|*.txt;*.text|All files (*.*)|*.*",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int result = openFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = openFileDialog.GetPath();
    return m_notepad.Open(filePath);
}

bool wxTpGUIMainFrame::SaveFile() {
    wxFileDialog saveFileDialog(
        this, "Save text document", wxEmptyString, "document.txt",
        "Text documents (*.txt;*.text)|*.txt;*.text",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    int result = saveFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = saveFileDialog.GetPath();
    return m_notepad.Save(filePath);
}

void wxTpGUIMainFrame::m_menuItemOpenOnMenuSelection(wxCommandEvent& event) {
    OpenFile();
}

void wxTpGUIMainFrame::m_menuItemSaveAsOnMenuSelection(wxCommandEvent& event) {
    SaveFile();
}

void wxTpGUIMainFrame::m_menuItemExitOnMenuSelection(wxCommandEvent& event) {
    this->Close();
}

void wxTpGUIMainFrame::m_menuItemAboutOnMenuSelection(wxCommandEvent& event) {
    this->SetTitle("You clicked the about button !");
}
