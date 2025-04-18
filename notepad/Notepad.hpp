#pragma once

#include "wxtestpad.h"

class Notepad {
   public:
    Notepad(wxWindow* parent, wxTextCtrl* textCtrl);
    ~Notepad();

    using NotifyIsModifiedChanged = std::function<void(bool)>;
    void SetNotifyIsModifiedChanged(NotifyIsModifiedChanged callback);

    bool Open();
    bool Save();
    bool Find();
    bool Replace();

    bool GetIsModified();
    wxString GetDocumentTitle();
    void SetDocumentTitle(const wxString& title);

   private:
    enum CommandType { OPEN, SAVE };
    wxWindow* m_parent;
    wxTextCtrl* m_textCtrl;

    wxString m_savedText;
    wxString m_documentTitle;

    bool m_isSaved;
    NotifyIsModifiedChanged m_isModifiedChangedCallBack;

    void m_newDocument(const wxString& title);
};