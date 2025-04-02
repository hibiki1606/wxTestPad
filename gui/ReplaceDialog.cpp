#include "ReplaceDialog.hpp"

#include "wxtestpad.h"
#include "utilities/Utils.hpp"

ReplaceDialog::ReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl) : DialogBase(textCtrl), TpReplaceDialog(parent) {

}

void ReplaceDialog::m_OkOnClick(wxCommandEvent& event) {
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
        size_t currentPosition = m_textCtrl->GetInsertionPoint();
        if (Utils::ReplaceFromPosition(text, currentPosition, replaceFrom, replaceTo)) {
            m_textCtrl->SetValue(text);
            // m_textCtrl->SetInsertionPoint();
            isOk = true;
        } else {
            wxMessageBox(wxString::Format("No result for the text '%s'", replaceFrom), TP_PROJECT_NAME, wxOK | wxICON_INFORMATION);
            isOk = false;
        }
    }
    EndModal(isOk ? wxID_OK : wxID_CANCEL);
}