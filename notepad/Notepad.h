#pragma once

#include "wxtestpad.h"

class Notepad {
   private:
    wxTextCtrl* m_textCtrl;

    wxString m_savedText;
    wxString m_documentTitle;

    bool m_isSaved;

    void m_newDocument(const wxString& docContents, const wxString& docTitle);
    void m_onTextChanged(wxCommandEvent& event);

   public:
    Notepad(wxTextCtrl* textCtrl);
    ~Notepad();

    bool Open(const wxString& docPath);
    bool Save(const wxString& docPath);
    
    void NotifyTextChanged();

    void SetText(const wxString& str);
    wxString GetText();

    wxString GetDocumentTitle();
    bool IsSaved();
};