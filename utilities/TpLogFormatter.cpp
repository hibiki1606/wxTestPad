#include "TpLogFormatter.h"

wxString TpLogFormatter::Format(wxLogLevel level, const wxString& msg, const wxLogRecordInfo& info) const {
    wxString logKind;
    switch (level) {
        // case wxLOG_FatalError: break;
        case wxLOG_Error:   logKind = "Error";   break;
        case wxLOG_Warning: logKind = "Warning"; break;
        case wxLOG_Message: logKind = "Message"; break;
        case wxLOG_Status:  logKind = "Status";  break;
        case wxLOG_Info:    logKind = "Info";    break;
        case wxLOG_Debug:   logKind = "Debug";   break;
        // case wxLOG_Trace: break;
        // case wxLOG_Progress: break;
        // case wxLOG_User: break;
        // case wxLOG_Max: break;
        default: logKind = "Unhandled"; break;
    }
    // Somethng like [Error] string at ../main.cpp(1) caller_function_name
    return wxString::Format("[%s] %s, at %s(%d) %s", logKind, msg, info.filename, info.line, info.func);
}