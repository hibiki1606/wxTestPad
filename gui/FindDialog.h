#pragma once

#include "buildergen/TpGUI.h"
#include "wxtestpad.h"

class FindDialog : public TpFindDialog {
   public:
    FindDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~FindDialog();

   protected:
    wxTextCtrl* m_textCtrl;
    void m_FindNextOnClick(wxCommandEvent& event) override;
};