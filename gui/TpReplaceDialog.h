#pragma once

#include "buildergen/TpGUI.h"

class TpReplaceDialog : public ReplaceDialog {
    public:
    TpReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~TpReplaceDialog();
    
    protected:
    wxTextCtrl* m_textCtrl;

    // virtual void OnClose(wxCloseEvent& event);
    void m_OkOnClick(wxCommandEvent& event) override;
};