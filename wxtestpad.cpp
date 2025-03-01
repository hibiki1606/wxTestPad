#include "./wxtestpad.h"
#include "./gui/wxTpGUIMainFrame.h"
#include "./utilities/TpLogFormatter.h"

class wxTestPadApp : public wxApp {
   public:
    virtual bool OnInit() {
        // Init logger
        wxLog::SetActiveTarget(new wxLogStream(NULL));
        wxLog::GetActiveTarget()->SetFormatter(new TpLogFormatter);

        // Start application window
        wxTpGUIMainFrame *frame = new wxTpGUIMainFrame(nullptr);
        frame->Show(true);
        
        return true;
    }
};

wxIMPLEMENT_APP(wxTestPadApp);