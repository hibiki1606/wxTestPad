#pragma once

#include "DialogBase.h"
#include "buildergen/TpGUI.h"

class ReplaceDialog : public DialogBase, public TpReplaceDialog {
    public:
    ReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~ReplaceDialog();
    
    protected:
    // virtual void OnClose(wxCloseEvent& event);
    void m_OkOnClick(wxCommandEvent& event) override;
};