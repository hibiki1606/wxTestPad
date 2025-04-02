#include "wxtestpad.h"
#include "gui/MainWindow.h"
#include "utilities/logging/TpLogFormatter.h"

class wxTestPadApp : public wxApp {
   public:
    virtual bool OnInit() {
        // Init logger
        wxLog::SetActiveTarget(new wxLogStream(NULL));
        wxLog::GetActiveTarget()->SetFormatter(new TpLogFormatter);

        // Start application window
        MainWindow *frame = new MainWindow(nullptr);
        frame->Show(true);
        
        return true;
    }
};

wxIMPLEMENT_APP(wxTestPadApp);