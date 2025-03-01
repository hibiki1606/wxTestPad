#include "wxTpGUIMainFrame.h"

#include "../wxtestpad.h"

wxTpGUIMainFrame::wxTpGUIMainFrame(wxWindow* parent) : MainFrame(parent) {
    this->SetTitle(TP_PROJECT_NAME);
    this->SetStatusText("The app is ready !");
}

void wxTpGUIMainFrame::MainFrameOnActivate(wxActivateEvent& event) {}

void wxTpGUIMainFrame::MainFrameOnClose(wxCloseEvent& event) {
    wxMessageDialog dialog(
        this, "You have unsaved changes,\nDo you want to save them before closing this app?",
        TP_PROJECT_NAME, wxYES_NO | wxCANCEL | wxICON_QUESTION);
    int result = dialog.ShowModal();

    if (result == wxID_YES) {
        event.Skip();  // Continue exit
    } else if (result == wxID_NO) {
        event.Veto();  // Abort exit
    } else if (result == wxID_CANCEL) {
        
    }
}

void wxTpGUIMainFrame::m_menuItemOpenOnMenuSelection(wxCommandEvent& event) {
    wxFileDialog openFileDialog(
        this, "Open text document", wxEmptyString, wxEmptyString,
        "Text documents (*.txt;*.text)|*.txt;*.text|All files (*.*)|*.*",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int result = openFileDialog.ShowModal();

    if (result != wxID_OK) return;

    wxString filePath = openFileDialog.GetPath();
    wxFileInputStream input(filePath);
    wxTextInputStream text(input, "\x09", wxConvUTF8);

    wxString contents;

    while (input.IsOk() && !input.Eof()) {
        contents += text.ReadLine() + "\n";
    }

    this->m_textCtrl->SetValue(contents);
    
    this->SetStatusText(wxString::Format("'%s' opened!", filePath));
}

void wxTpGUIMainFrame::m_menuItemSaveAsOnMenuSelection(wxCommandEvent& event) {
    wxFileDialog saveFileDialog(
        this, "Save text document", wxEmptyString, "document.txt",
        "Text documents (*.txt;*.text)|*.txt;*.text",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    int result = saveFileDialog.ShowModal();

    if (result != wxID_OK) return;

    wxString filePath = saveFileDialog.GetPath();
    wxFileOutputStream output(filePath);
    
    if (!output.IsOk()) {
        wxMessageDialog dialog(
            this, "Can't save the file to the selected path !",
            TP_PROJECT_NAME, wxOK | wxICON_ERROR);
        dialog.ShowModal();
        return;
    }

    wxString textToSave = this->m_textCtrl->GetValue();

    wxCharBuffer utf8Buffer = textToSave.utf8_str();
    size_t textLength = utf8Buffer.length();
    
    output.Write(utf8Buffer.data(), textLength);

    this->SetStatusText(wxString::Format("File saved to: '%s'!", filePath));
}

void wxTpGUIMainFrame::m_menuItemExitOnMenuSelection(wxCommandEvent& event) {
    this->Close();
}

void wxTpGUIMainFrame::m_menuItemAboutOnMenuSelection(wxCommandEvent& event) {
    this->SetTitle("You clicked the about button !");
}
