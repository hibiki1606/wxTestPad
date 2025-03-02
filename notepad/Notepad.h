#pragma once

#include "wxtestpad.h"

class Notepad {
   public:
    Notepad(wxTextCtrl* textCtrl);
    ~Notepad();

    using NotifyIsSavedChanged = std::function<void(bool)>;
    void SetNotifyIsSavedChanged(NotifyIsSavedChanged callback);

    void NotifyTextChanged();

    bool Open(const wxString& docPath);
    bool Save(const wxString& docPath);    

    bool GetIsSaved();
    void SetIsSaved(bool isSaved);
    
    wxString GetDocumentTitle();

   private:
    enum CommandType { OPEN, SAVE };
    wxTextCtrl* m_textCtrl;

    wxString m_savedText;
    wxString m_documentTitle;

    bool m_isSaved;
    NotifyIsSavedChanged m_isSavedChangedCallBack;

    void m_newDocument(const enum CommandType& commandType, const wxString& docContents, const wxString& docTitle);
    void m_updateStatus();
};