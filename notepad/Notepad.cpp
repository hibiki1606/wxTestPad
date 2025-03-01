#include "Notepad.h"

#include "wxtestpad.h"

Notepad::Notepad(wxTextCtrl* textCtrl)
    : m_textCtrl(textCtrl),
      m_savedText(wxEmptyString),
      m_documentTitle("Untitled"),
      m_isSaved(true) {
        wxLogDebug("An instance of Notepad has been initialised");
        // m_textCtrl->Bind(wxEVT_TEXT, &Notepad::m_onTextChanged);
      }
Notepad::~Notepad() {
    wxLogDebug("An instance of Notepad has been deleted");
    // m_textCtrl->Unbind(wxEVT_TEXT, &Notepad::m_onTextChanged);
}

void Notepad::NotifyTextChanged() {
    
}

void Notepad::m_newDocument(const wxString& docContents, const wxString& docTitle) {
    m_isSaved = true;
    m_savedText = docContents;
    m_documentTitle = docTitle;
}

void Notepad::m_onTextChanged(wxCommandEvent& event) {
    m_isSaved = (m_textCtrl->GetValue() == m_savedText);
}

bool Notepad::Open(const wxString& docPath) {
    wxFileInputStream input(docPath);
    wxTextInputStream text(input, "\x09", wxConvUTF8);

    wxString contents;

    while (input.IsOk() && !input.Eof()) {
        contents += text.ReadLine() + "\n";
    }
    
    m_newDocument(contents, docPath);
    this->m_textCtrl->SetValue(contents);

    return true;
}

bool Notepad::Save(const wxString& docPath) {
    wxFileOutputStream output(docPath);

    if (!output.IsOk()) {
        return false;
    }

    wxString textToSave = m_textCtrl->GetValue();

    wxCharBuffer utf8Buffer = textToSave.utf8_str();
    size_t textLength = utf8Buffer.length();

    output.Write(utf8Buffer.data(), textLength);

    m_newDocument(m_textCtrl->GetValue(), docPath);
    NotifyTextChanged();

    return true;
}

bool Notepad::IsSaved() { return m_isSaved; }

void Notepad::SetText(const wxString& str) { m_savedText = str; }

wxString Notepad::GetText() { return m_savedText; }

wxString Notepad::GetDocumentTitle() { return m_documentTitle; }