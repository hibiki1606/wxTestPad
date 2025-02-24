#pragma once

#include "buildergen/wxTpGUI.h"

class wxTpGUIMainFrame : public MainFrame {
   protected:
    void MainFrameOnActivate(wxActivateEvent& event);
    void MainFrameOnClose(wxCloseEvent& event);
    void m_menuItemOpenOnMenuSelection(wxCommandEvent& event);
    void m_menuItemSaveAsOnMenuSelection(wxCommandEvent& event);
    void m_menuItemExitOnMenuSelection(wxCommandEvent& event);
    void m_menuItemAboutOnMenuSelection(wxCommandEvent& event);

   public:
    wxTpGUIMainFrame(wxWindow* parent);
};