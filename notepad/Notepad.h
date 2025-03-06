#pragma once

#include "wxtestpad.h"

class Notepad {
   public:
    Notepad(wxTextCtrl* textCtrl);
    ~Notepad();

    using NotifyIsModifiedChanged = std::function<void(bool)>;
    void SetNotifyIsModifiedChanged(NotifyIsModifiedChanged callback);

    bool Open(const wxString& docPath);
    bool Save(const wxString& docPath);    

    bool GetIsModified();
    wxString GetDocumentTitle();
    void SetDocumentTitle(const wxString& title);

   private:
    enum CommandType { OPEN, SAVE };
    wxTextCtrl* m_textCtrl;

    wxString m_savedText;
    wxString m_documentTitle;

    bool m_isSaved;
    NotifyIsModifiedChanged m_isModifiedChangedCallBack;

    void m_newDocument(const wxString& title);
};