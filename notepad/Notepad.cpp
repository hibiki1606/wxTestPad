#include <wx/sstream.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>

#include "Notepad.hpp"

#include "gui/ReplaceDialog.hpp"
#include "gui/FindDialog.hpp"

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

bool Notepad::Open() {
    wxFileDialog openFileDialog(
        m_parent, "Open text document", wxEmptyString, wxEmptyString,
        "Text documents (*.txt;*.text)|*.txt;*.text|All files (*.*)|*.*",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int result = openFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = openFileDialog.GetPath();

    bool ret = m_textCtrl->LoadFile(filePath);
    m_newDocument(filePath);
    return ret;
}

bool Notepad::Save() {
    wxFileDialog saveFileDialog(
        m_parent, "Save text document", wxEmptyString, "document.txt",
        "Text documents (*.txt;*.text)|*.txt;*.text",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    int result = saveFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = saveFileDialog.GetPath();

    bool ret = m_textCtrl->SaveFile(filePath);
    m_newDocument(filePath);
    return ret;
}

bool Notepad::Find() {
    FindDialog dialog(m_parent, m_textCtrl);
    dialog.ShowModal();
    return true;
}

bool Notepad::Replace() {
    ReplaceDialog dialog(m_parent, m_textCtrl);
    int result = dialog.ShowModal();
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