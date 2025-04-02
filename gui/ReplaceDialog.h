#pragma once

#include "buildergen/TpGUI.h"

class ReplaceDialog : public TpReplaceDialog {
    public:
    ReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~ReplaceDialog();
    
    protected:
    wxTextCtrl* m_textCtrl;

    // virtual void OnClose(wxCloseEvent& event);
    void m_OkOnClick(wxCommandEvent& event) override;
};