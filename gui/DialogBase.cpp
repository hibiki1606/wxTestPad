#include "DialogBase.h"
#include "wxtestpad.h"

DialogBase::DialogBase(wxTextCtrl* textCtrl) {
    wxLogDebug("Dialog has been created.");
    m_textCtrl = textCtrl;
}

DialogBase::~DialogBase() {
    wxLogDebug("Dialog has been deleted.");
}