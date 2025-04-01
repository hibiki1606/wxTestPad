#pragma once

#include "buildergen/TpGUI.h"
#include "wxtestpad.h"

class TpFindDialog : public FindDialog {
   public:
    TpFindDialog(wxWindow* parent, wxTextCtrl* textCtrl);
    ~TpFindDialog();

   protected:
    wxTextCtrl* m_textCtrl;
    void m_FindNextOnClick(wxCommandEvent& event) override;
};