#pragma once

#include "buildergen/TpGUI.h"

class DialogBase {
    public:
     DialogBase(wxTextCtrl* textCtrl);
     ~DialogBase();

    protected:
     wxTextCtrl* m_textCtrl;
};