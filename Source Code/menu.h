

#ifndef MENU_H
#define MENU_H

#include <wx/wx.h>

/**
 * @brief Menu bar
 * @author Asiern
 * @since Fri Aug 27 2021
 */
class Menu : public wxMenuBar
{
  private:
    wxMenu* file = nullptr;
    wxMenu* help = nullptr;

  protected:
    void onQuit(wxCommandEvent& evt);
    void onAbout(wxCommandEvent& evt);
    void onCheckForUpdates(wxCommandEvent& evt);
    void onDocumentation(wxCommandEvent& evt);
    void onReleaseNotes(wxCommandEvent& evt);
    wxDECLARE_EVENT_TABLE();

  public:
    Menu();
};

#endif