 

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/image.h>

 

class MainFrame: public wxFrame {
public:
     

    MainFrame(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    
    void set_properties();
    void do_layout();
     

public:
    
    wxStaticText* label_1;
    wxTextCtrl* tPath;
    wxButton* btnPath;
    wxButton* btnClean;

 
}; 


 
