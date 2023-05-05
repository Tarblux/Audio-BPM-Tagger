#include "menu.h"
#include <curl/curl.h>
#include "updater.h"
#include "utils.h"

wxBEGIN_EVENT_TABLE(Menu, wxMenuBar)
    EVT_MENU(wxID_OPEN, Menu::onOpenFile)
    EVT_MENU(wxID_EXIT, Menu::onQuit)
    EVT_MENU(wxID_ABOUT, Menu::onAbout)
    EVT_MENU(wxNewId(), Menu::onCheckForUpdates)
    EVT_MENU(wxNewId(), Menu::onDocumentation)
    EVT_MENU(wxNewId(), Menu::onReleaseNotes)
wxEND_EVENT_TABLE()

Menu::Menu()
    : wxMenuBar()
{
    file = new wxMenu;
    help = new wxMenu;
    file->Append(wxID_OPEN, "&Open File(s)");
    file->Append(wxID_EXIT, "&Quit");
    help->Append(wxNewId(), "&Documentation");
    help->Append(wxNewId(), "&Release Notes");
    help->Append(wxNewId(), "&Check for Updates...");
    help->Append(wxID_ABOUT, "&About");
    Append(file, "&File");
    Append(help, "&Help");
}

void Menu::onOpenFile(wxCommandEvent& evt)
{
    // TODO: implement onOpenFile
}

void Menu::onQuit(wxCommandEvent& evt)
{
    this->m_parent->Close(true);
}

void Menu::onAbout(wxCommandEvent& evt)
{
    openWebLink("https://github.com/Asiern/Audio");
}

void Menu::onCheckForUpdates(wxCommandEvent& evt)
{
    // Request Headers
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: product/1");
    headers = curl_slist_append(headers, "Accept: application/vnd.github.v3+json");

    // Updater
    Updater* updater = new Updater("https://api.github.com/repos/asiern/Audio/releases/latest", headers);
    if (updater->compareVersions(updater->getLatestVersion(), "1.0.0") > 0)
    {
        if (wxMessageBox("Newer version available. Click on YES to download the new version.", "Updater",
                          wxICON_INFORMATION | wxYES_NO, this, 0, 0) == wxYES)
        {
            system("xdg-open https://github.com/Asiern/Audio/releases/latest");
        }
    }
    else
    {
        wxMessageBox("No updates available", "Updater", wxICON_INFORMATION | wxOK, this, 0, 0);
    }
    delete updater;
    curl_slist_free_all(headers);
}

void Menu::onDocumentation(wxCommandEvent& evt)
{
    openWebLink("https://asiern.github.io/Audio/");
}

void Menu::onReleaseNotes(wxCommandEvent& evt)
{
    openWebLink("https://github.com/Asiern/Audio/blob/master/CHANGELOG.md");
}
