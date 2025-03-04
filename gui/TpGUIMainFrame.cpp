#include <wx/aboutdlg.h>
#include <wx/fontdlg.h>

#include "TpGUIMainFrame.h"

#include "wxtestpad.h"

TpGUIMainFrame::TpGUIMainFrame(wxWindow* parent) : MainFrame(parent), m_notepad(m_textCtrl) {
    m_notepad.SetNotifyIsSavedChanged([this](bool isSaved) {
        this->SetTitle(
            wxString::Format("%s%s - %s", (isSaved ? "" : "*"), m_notepad.GetDocumentTitle(), TP_PROJECT_NAME)
        );
    });
    
    this->SetTitle(TP_PROJECT_NAME);
    this->SetStatusText("The app is ready !");
}

void TpGUIMainFrame::MainFrameOnClose(wxCloseEvent& event) {
    if (m_notepad.GetIsSaved()) {
        event.Skip();
        return;
    }
    
    bool continueClosing = [this]() {
        wxMessageDialog dialog(
            this, "You have unsaved changes,\nDo you want to save them before closing this app?",
            TP_PROJECT_NAME, wxYES_NO | wxCANCEL | wxICON_QUESTION);
        int result = dialog.ShowModal();

        switch (result) {
            case wxID_YES: return SaveFile();
            case wxID_NO: return true; // Continue closing
            case wxID_CANCEL: return false; // Abort closing
            default: wxLogError("Unexpected value %d", result); return true;
        }
    }();

    if (continueClosing) {
        event.Skip();
    } else {
        event.Veto();
    }

    return;
}

bool TpGUIMainFrame::OpenFile() {
    wxFileDialog openFileDialog(
        this, "Open text document", wxEmptyString, wxEmptyString,
        "Text documents (*.txt;*.text)|*.txt;*.text|All files (*.*)|*.*",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    int result = openFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = openFileDialog.GetPath();
    return m_notepad.Open(filePath);
}

bool TpGUIMainFrame::SaveFile() {
    wxFileDialog saveFileDialog(
        this, "Save text document", wxEmptyString, "document.txt",
        "Text documents (*.txt;*.text)|*.txt;*.text",
        wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    int result = saveFileDialog.ShowModal();

    if (result != wxID_OK) return false;

    wxString filePath = saveFileDialog.GetPath();
    return m_notepad.Save(filePath);
}

bool TpGUIMainFrame::FontDialog() {
    wxFontData data;
    data.SetInitialFont(m_textCtrl->GetFont());

    wxFontDialog dialog(this, data);
    if (dialog.ShowModal() != wxID_OK) return false;
    
    wxFontData result = dialog.GetFontData();
    this->m_textCtrl->SetFont(result.GetChosenFont());

    return true;
}

void TpGUIMainFrame::m_ribbonOnClick(wxRibbonButtonBarEvent& event) {
    // ribbonButton events should be handled here
    // Enum of ribbonButton ID should be like, TP_RIBBON_{NAME}
    int ribbonControlId = event.GetId();
    wxLogDebug("Ribbon click: %d", ribbonControlId);
    
    switch (ribbonControlId) {
        case TP_RIBBON_OPEN: {
            OpenFile();
            break;
        }
        case TP_RIBBON_SAVEAS: {
            SaveFile();
            break;
        }
        case TP_RIBBON_COPY: {
            break;
        }
        case TP_RIBBON_PASTE: {
            break;
        }
        case TP_RIBBON_FONT: {
            FontDialog();
            break;
        }
        case TP_RIBBON_ABOUT: {
            wxAboutDialogInfo info;
            info.SetName(TP_PROJECT_NAME);
            info.SetVersion("0.1 Dev");
            wxAboutBox(info);
            break;
        }
        default: {
            wxLogError("Unexpected value: %d", ribbonControlId);
            break;
        }
    }
}

void TpGUIMainFrame::m_ribbonToggleTheme(wxCommandEvent& event) {
    // Too unstable to use
    // This function shouldn't be used
    int isClassic = event.IsChecked();
    wxRibbonArtProvider* provider;

    if (isClassic)    
        provider = new wxRibbonAUIArtProvider();
    else
        provider = new wxRibbonMSWArtProvider();
    
    // This also deletes old pointer of provider
    m_ribbonBar->SetArtProvider(provider);
    m_ribbonBar->Refresh();
}