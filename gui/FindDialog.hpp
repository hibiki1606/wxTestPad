#pragma once

#include "buildergen/TpGUI.h"
#include "DialogBase.hpp"
#include "wxtestpad.h"

class FindDialog : public DialogBase, public TpFindDialog {
   public:
    FindDialog(wxWindow* parent, wxTextCtrl* textCtrl);

   protected:
    void m_FindNextOnClick(wxCommandEvent& event) override;
};