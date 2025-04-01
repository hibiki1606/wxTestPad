#include "Utils.h"

bool Utils::ReplaceFromPosition(wxString& textRef, const size_t startPos, const wxString& from, const wxString& to) {
    if (textRef.Length() < startPos)
        return false;
    
    size_t replacePos = textRef.find(from, startPos);
    if (replacePos == wxString::npos)
        return false;
    
    size_t replaceLength = from.length();
    textRef.replace(replacePos, replaceLength, to);
    
    return true;
}