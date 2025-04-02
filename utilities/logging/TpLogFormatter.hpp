#pragma once
#include <wx/log.h>

class TpLogFormatter : public wxLogFormatter {
   public:
    wxString Format(wxLogLevel level, const wxString& msg, const wxLogRecordInfo& info) const override;
};