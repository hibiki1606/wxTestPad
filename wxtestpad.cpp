#include <wx/wxprec.h>

#include "./wxtestpad.h"
#include "./gui/buildergen/wxTpGUIMainFrame.h"

class wxTestPadApp : public wxApp {
   public:
    virtual bool OnInit() {
        wxTpGUIMainFrame *frame = new wxTpGUIMainFrame(nullptr);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(wxTestPadApp);