#include "TpReplaceDialog.h"

#include "wxtestpad.h"
#include "utilities/Utils.h"

TpReplaceDialog::TpReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl) : ReplaceDialog(parent) {
    m_textCtrl = textCtrl;
    wxLogDebug("Replace dialog has been created.");
}

TpReplaceDialog::~TpReplaceDialog() {
    wxLogDebug("Replace dialog has been deleted.");
}

void TpReplaceDialog::m_OkOnClick(wxCommandEvent& event) {
    bool isOk = false;
    wxString text = m_textCtrl->GetValue();
    const wxString& replaceFrom = m_textCtrlFrom->GetValue();
    const wxString& replaceTo = m_textCtrlTo->GetValue();
    const bool replaceAll = m_checkBoxReplaceAll->GetValue();

    if (replaceAll) {
        text.Replace(replaceFrom, replaceTo, true);
        m_textCtrl->SetValue(text);
        isOk = true;
    } else {
        // I have to refactor these code anyway
        size_t currentPosition = m_textCtrl->GetInsertionPoint();
        // wxLogDebug("%d", currentPosition);
        if (Utils::ReplaceFromPosition(text, currentPosition, replaceFrom, replaceTo)) {
            m_textCtrl->SetValue(text);
            // m_textCtrl->SetInsertionPoint();
            isOk = true;
        } else {
            wxMessageBox(wxString::Format("No result for the text '%s'", replaceFrom), TP_PROJECT_NAME, wxOK | wxICON_INFORMATION);
            isOk = false;
        }
    }
    wxLogDebug("endmodal");
    EndModal(isOk ? wxID_OK : wxID_CANCEL);
}