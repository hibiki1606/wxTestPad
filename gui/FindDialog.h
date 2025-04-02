#pragma once

#include "buildergen/TpGUI.h"
#include "DialogBase.h"
#include "wxtestpad.h"

class FindDialog : public DialogBase, public TpFindDialog {
   public:
    FindDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~FindDialog();

   protected:
    void m_FindNextOnClick(wxCommandEvent& event) override;
};