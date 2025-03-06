#include <wx/sstream.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>

#include "Notepad.h"

Notepad::Notepad(wxWindow* parent, wxTextCtrl* textCtrl)
    : m_parent(parent),
      m_textCtrl(textCtrl),
      m_savedText(wxEmptyString),
      m_documentTitle("Untitled")
    {
    m_textCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent&) {
        if(m_savedText == m_textCtrl->GetValue())
            m_textCtrl->SetModified(false);
        m_isModifiedChangedCallBack(m_textCtrl->IsModified());
    });
    wxLogDebug("Notepad object has been created.");
}

Notepad::~Notepad() {
    wxLogDebug("Notepad object has been deleted.");
}

void Notepad::m_newDocument(const wxString& title) {
    SetDocumentTitle(title);
    m_savedText = m_textCtrl->GetValue();
    m_isModifiedChangedCallBack(false);
}

bool Notepad::Open(const wxString& docPath) {
    bool ret = m_textCtrl->LoadFile(docPath);
    m_newDocument(docPath);
    return ret;
}

bool Notepad::Save(const wxString& docPath) {
    bool ret = m_textCtrl->SaveFile(docPath);
    m_newDocument(docPath);
    return ret;
}

bool Notepad::Find() {
    wxTextEntryDialog textEntryDialog(m_parent, wxEmptyString);
    textEntryDialog.SetTitle("Find...");
    if (textEntryDialog.ShowModal() != wxID_OK)
        return false;

    const wxString& query = textEntryDialog.GetValue();
    const wxString& originalText = this->m_textCtrl->GetValue();
    size_t currentPos = this->m_textCtrl->GetInsertionPoint();

    size_t futurePosition = originalText.find(query, currentPos + query.length());
    if (futurePosition == wxString::npos) {
        wxMessageDialog dialog(m_parent, wxString::Format("No result for the text '%s'", query), TP_PROJECT_NAME, wxOK | wxICON_INFORMATION);
        dialog.ShowModal();

        return false;
    }
    this->m_textCtrl->SetInsertionPoint(futurePosition);

    return true;
}


void Notepad::SetNotifyIsModifiedChanged(NotifyIsModifiedChanged callback) {
    m_isModifiedChangedCallBack = callback;
}

wxString Notepad::GetDocumentTitle() { return m_documentTitle; }
void Notepad::SetDocumentTitle(const wxString& title) { m_documentTitle = title; }

bool Notepad::GetIsModified() {
    return m_textCtrl->IsModified();
}