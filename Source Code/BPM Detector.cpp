#include "audio.h"
#include "menu.h"
#include "updater.h"
#include "utils.h"
#include <wx/filedlg.h>
#include <wx/wfstream.h>

// Event table
wxBEGIN_EVENT_TABLE(Audio, wxFrame)
EVT_MENU(wxID_OPEN, Audio::onLoadBtnPress)
EVT_BUTTON(wxID_ANY, Audio::onPlayBtnPress)
EVT_BUTTON(wxID_ANY, Audio::onPauseBtnPress)
EVT_BUTTON(wxID_ANY, Audio::onStopBtnPress)
EVT_BUTTON(wxID_ANY, Audio::onPitchDecrease)
EVT_BUTTON(wxID_ANY, Audio::onPitchIncrease)
wxEND_EVENT_TABLE()

Audio::Audio() : wxFrame(nullptr, wxID_ANY, "Audio", wxDefaultPosition, wxSize(800, 500))
{
// Menu bar
menuBar = new Menu;
SetMenuBar(menuBar); 

// Files list box
fileslbl = new wxStaticText(this, wxID_ANY, "Files", wxPoint(20, 25), wxSize(80, 30), wxALIGN_LEFT, wxStaticTextNameStr);
filesListBox = new wxListCtrl(this, wxID_ANY, wxPoint(20, 50), wxSize(380, 200), wxLC_SINGLE_SEL | wxLC_LIST, wxDefaultValidator, wxListCtrlNameStr);

// Play controls
playBtn = new wxButton(this, wxID_ANY, "Play", wxPoint(200, 360), wxSize(120, 30));
pauseBtn = new wxButton(this, wxID_ANY, "Pause", wxPoint(350, 360), wxSize(120, 30));
stopBtn = new wxButton(this, wxID_ANY, "Stop", wxPoint(500, 360), wxSize(120, 30));
progresslbl = new wxStaticText(this, wxID_ANY, "0:00", wxPoint(150, 390), wxSize(80, 30), wxALIGN_LEFT, wxStaticTextNameStr);
progressEndlbl = new wxStaticText(this, wxID_ANY, "4:07", wxPoint(650, 390), wxSize(80, 30), wxALIGN_LEFT, wxStaticTextNameStr);
progress = new wxGauge(this, wxID_ANY, 100, wxPoint(200, 385), wxSize(430, 20), wxGA_HORIZONTAL, wxDefaultValidator, wxGaugeNameStr);
progress->SetValue(50);

// Pitch controls
pitchChoices = new wxArrayString();
for (int i = 8; i >= -8; i--)
{
    pitchChoices->Add(wxString::Format("%+d Semitones", i));
}
pitchlbl = new wxStaticText(this, wxID_ANY, "Pitch", wxPoint(600, 25), wxSize(40, 30));
decpitchbtn = new wxButton(this, wxID_ANY, "-", wxPoint(500, 50), wxSize(40, 40));
incpitchbtn = new wxButton(this, wxID_ANY, "+", wxPoint(700, 50), wxSize(40, 40));
pitchcb = new wxComboBox(this, wxID_ANY, "", wxPoint(560, 50), wxSize(120, 40), *pitchChoices, wxCB_READONLY);

// Layout
Centre();
Fit();

// Audio controller
controller = new AudioController(-1, 44100);

}

Audio::~Audio()
{
delete pitchChoices;
}

void Audio::onLoad