#pragma once

#include "DialogBase.h"
#include "buildergen/TpGUI.h"

class ReplaceDialog : public DialogBase, public TpReplaceDialog {
    public:
     ReplaceDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    
    protected:
     void m_OkOnClick(wxCommandEvent& event) override;
};