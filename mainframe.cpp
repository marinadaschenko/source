 
#include "mainframe.h"
 

#define wxID_PATH 1089
#define wxID_CLEAN 1090

MainFrame::MainFrame(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
  
    label_1 = new wxStaticText(this, wxID_ANY, wxT("Путь:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    tPath = new wxTextCtrl(this, wxID_ANY, wxEmptyString);
    btnPath = new wxButton(this, wxID_PATH, wxT("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT);
    btnClean = new wxButton(this, wxID_CLEAN, wxT("Очистить"));

    set_properties();
    do_layout();
  
}


void MainFrame::set_properties()
{
     
    SetTitle(wxT("Очиститель"));
    SetSize(wxSize(400, 300));
    tPath->SetToolTip(wxT("Путь для очистки"));
    btnPath->SetToolTip(wxT("Выбрать путь"));
   
}


void MainFrame::do_layout()
{
     
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    sizer_2->Add(label_1, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 0);
    sizer_2->Add(tPath, 1, 0, 0);
    sizer_2->Add(btnPath, 0, 0, 0);
    sizer_1->Add(sizer_2, 0, wxEXPAND, 0);
    sizer_1->Add(1, 1, 1, 0, 0);
    sizer_3->Add(1, 1, 1, 0, 0);
    sizer_3->Add(btnClean, 0, 0, 0);
    sizer_1->Add(sizer_3, 0, wxEXPAND, 0);
    SetSizer(sizer_1);
    Layout();
    
}


BEGIN_EVENT_TABLE(MainFrame, wxFrame)
     
    EVT_BUTTON(wxID_PATH, MainFrame::btnPathClick)
    EVT_BUTTON(wxID_CLEAN, MainFrame::btnCleanClick)
     
END_EVENT_TABLE();


// wxGlade: add MainFrame event handlers


class MyApp: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MainFrame* fMain = new MainFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(fMain);
    fMain->Show();
    return true;
}
