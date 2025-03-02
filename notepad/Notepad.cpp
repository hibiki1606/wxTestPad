#include <wx/sstream.h>
#include <wx/txtstrm.h>
#include <wx/wfstream.h>

#include "Notepad.h"

Notepad::Notepad(wxTextCtrl* textCtrl)
    : m_textCtrl(textCtrl),
      m_savedText(wxEmptyString),
      m_documentTitle("Untitled"),
      m_isSaved(true) {
    m_textCtrl->Bind(wxEVT_TEXT, [&](wxCommandEvent&) {
        NotifyTextChanged();
    });
    wxLogDebug("Notepad object has been created.");
}

Notepad::~Notepad() {
    wxLogDebug("Notepad object has been deleted.");
}

void Notepad::NotifyTextChanged() {
    SetIsSaved(m_textCtrl->GetValue() == m_savedText);
}

bool Notepad::Open(const wxString& docPath) {
    wxFileInputStream input(docPath);
    // wxTextInputStream text(input, "\x09", wxConvUTF8);
    if (!input.IsOk()) {
        wxLogError("Failed to open %s", docPath);
        return false;
    }

    wxString contents;
    wxStringOutputStream output(&contents);

    input.Read(output);
    // while (!input.Eof()) {
    //     contents += text.ReadLine() + "\n";
    // }

    m_newDocument(CommandType::OPEN, contents, docPath);

    return true;
}

bool Notepad::Save(const wxString& docPath) {
    wxFileOutputStream output(docPath);

    if (!output.IsOk()) {
        wxLogError("Failed to open %s", docPath);
        return false;
    }

    wxString textToSave = m_textCtrl->GetValue();

    wxCharBuffer utf8Buffer = textToSave.utf8_str();
    size_t textLength = utf8Buffer.length();

    output.Write(utf8Buffer.data(), textLength);
    m_newDocument(CommandType::SAVE, textToSave, docPath);

    return true;
}

void Notepad::SetNotifyIsSavedChanged(NotifyIsSavedChanged callback) {
    m_isSavedChangedCallBack = callback;
}

bool Notepad::GetIsSaved() { return m_isSaved; }
void Notepad::SetIsSaved(bool status) {
    // if (m_isSaved == status)
    //     return;

    m_isSaved = status;
    m_isSavedChangedCallBack(status);
}

wxString Notepad::GetDocumentTitle() { return m_documentTitle; }

void Notepad::m_newDocument(const enum CommandType& commandType, const wxString& docContents, const wxString& docTitle) {
    SetIsSaved(true);
    m_savedText = docContents;
    m_documentTitle = docTitle;
    if (commandType == CommandType::OPEN)
        m_textCtrl->SetValue(docContents);
}

void Notepad::m_updateStatus() {
    NotifyTextChanged();
    m_isSavedChangedCallBack(m_isSaved);
}