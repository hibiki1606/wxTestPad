#include <wx/aboutdlg.h>
#include <wx/fontdlg.h>
#include <wx/clipbrd.h>

#include "TpMainFrame.h"

#include "wxtestpad.h"

TpMainFrame::TpMainFrame(wxWindow* parent) : MainFrame(parent), m_notepad(this, m_textCtrl) {
    m_notepad.SetNotifyIsModifiedChanged([this](bool isModified) {
        this->SetTitle(
            wxString::Format("%s%s - %s", (isModified ? "*" : ""), m_notepad.GetDocumentTitle(), TP_PROJECT_NAME)
        );
    });
    
    this->SetTitle(TP_PROJECT_NAME);
    this->SetStatusText(wxString::Format("%s is ready!", TP_PROJECT_NAME));
}

void TpMainFrame::MainFrameOnClose(wxCloseEvent& event) {
    if (!m_notepad.GetIsModified()) {
        event.Skip();
        return;
    }
    
    bool continueClosing = [this]() {
        wxMessageDialog dialog(
            this, "You have unsaved changes,\nDo you want to save them before closing this app?",
            TP_PROJECT_NAME, wxYES_NO | wxCANCEL | wxICON_QUESTION);
        int result = dialog.ShowModal();

        switch (result) {
            case wxID_YES: return SaveFileDialog();
            case wxID_NO: return true; // Continue closing
            case wxID_CANCEL: return false; // Abort closing
            default: wxLogError("Unexpected value: %d", result); return true;
        }
    }();

    if (continueClosing) {
        event.Skip();
    } else {
        event.Veto();
    }

    return;
}

bool TpMainFrame::OpenFileDialog() {
    return m_notepad.Open();
}

bool TpMainFrame::SaveFileDialog() {
    return m_notepad.Save();
}

bool TpMainFrame::SetClipboard(const wxString& text) {
    if (!wxTheClipboard->Open()) {
        wxLogError("Failed to open the clipboard");
        return false;
    }

    wxTheClipboard->SetData(new wxTextDataObject(text));
    wxTheClipboard->Flush();
    wxTheClipboard->Close();

    return true;
}

wxString TpMainFrame::GetClipboard() {
    if (!wxTheClipboard->Open()) {
        wxLogError("Failed to open the clipboard");
        return wxEmptyString;
    }

    if (!wxTheClipboard->IsSupported(wxDF_TEXT)) {
        wxTheClipboard->Close();
        return wxEmptyString;
    }

    wxTextDataObject data;
    wxTheClipboard->GetData(data);
    wxTheClipboard->Close();
    return data.GetText();
}

bool TpMainFrame::FontDialog() {
    wxFontData data;
    data.SetInitialFont(m_textCtrl->GetFont());

    wxFontDialog dialog(this, data);
    if (dialog.ShowModal() != wxID_OK) return false;
    
    wxFontData result = dialog.GetFontData();
    this->m_textCtrl->SetFont(result.GetChosenFont());

    return true;
}

void TpMainFrame::m_ribbonOnClick(wxRibbonButtonBarEvent& event) {
    // ribbonButton events should be handled here
    // Enum of ribbonButton ID should be like, TP_RIBBON_{NAME}
    int ribbonControlId = event.GetId();
    
    switch (ribbonControlId) {
        case TP_RIBBON_OPEN: {
            OpenFileDialog();
            break;
        }
        case TP_RIBBON_SAVEAS: {
            SaveFileDialog();
            break;
        }
        case TP_RIBBON_FIND: {
            m_notepad.Find();
            break;
        }
        case TP_RIBBON_REPLACE: {
            m_notepad.Replace();
            break;
        }
        case TP_RIBBON_COPY: {
            SetClipboard(m_textCtrl->GetStringSelection());
            break;
        }
        case TP_RIBBON_PASTE: {
            m_textCtrl->AppendText(GetClipboard());
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
    
    return;
}

void TpMainFrame::m_ribbonToggleTheme(wxCommandEvent& event) {
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