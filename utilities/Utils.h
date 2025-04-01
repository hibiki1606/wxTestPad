#pragma once

#include "wxtestpad.h"

class Utils {
    public:
    static bool ReplaceFromPosition(wxString& text, const size_t startPos, const wxString& from, const wxString& to);
};