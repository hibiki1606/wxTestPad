#include "FindDialog.h"

FindDialog::FindDialog(wxWindow* parent, wxTextCtrl* textCtrl) : DialogBase(textCtrl), TpFindDialog(parent) {

}

FindDialog::~FindDialog() {
    
}

void FindDialog::m_FindNextOnClick(wxCommandEvent& event) {
    const wxString& query = m_textCtrlFind->GetValue();
    const wxString& originalText = this->m_textCtrl->GetValue();
    size_t currentPos = this->m_textCtrl->GetInsertionPoint();

    size_t futurePos = originalText.find(query, currentPos + 1);
    if (futurePos == currentPos + 1 || futurePos == wxString::npos) {
        wxMessageBox(wxString::Format("No more result for the text '%s'", query), TP_PROJECT_NAME, wxOK | wxICON_INFORMATION);
        EndModal(wxID_CANCEL);
        return;
    }
    this->m_textCtrl->SetInsertionPoint(futurePos);

    EndModal(wxID_OK);
}