#include <wx/dir.h>
#include <wx/filename.h>

#include "mainframe.h"

void DeleteDirectory(wxString filename){
    wxDir dir(filename);
    wxString file;
    bool cont = dir.GetFirst(&file);
    while ( cont )
    {
            file = filename + wxFileName::GetPathSeparator()+ file;
            if(wxFileName::FileExists(file)) wxRemoveFile(file);
            if( wxFileName::DirExists(file)) DeleteDirectory(file);
            cont = dir.GetNext(&file);
    }
    wxFileName::Rmdir(dir.GetName());
}

void MainFrame::btnPathClick(wxCommandEvent &event)
{
    wxDirDialog dlgDir(this);
    dlgDir.SetPath(tPath->GetValue());
    if (dlgDir.ShowModal() == wxID_OK)
        tPath->SetValue(dlgDir.GetPath());
}

void MainFrame::btnCleanClick(wxCommandEvent &event)
{
    wxMessageDialog dlgQues(this, wxT("Вы действительно хотите очистить \"") +
      tPath->GetValue() + wxT("\"?"), wxT("Предупреждение"),
      wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION);
    if (dlgQues.ShowModal() == wxID_YES){
        wxDir dir(tPath->GetValue());
        if ( !dir.IsOpened() ) {
            wxLogDebug(wxT("There is no such folder"));
            wxMessageDialog dlgErr(this, wxT("Такой путь некорректен!"), wxT("Ошибка!"),
              wxOK|wxICON_ERROR);
            dlgErr.ShowModal();
            return;
        }
        wxLogDebug(wxT("Enumerating object files in current directory:"));
        wxString filename;
        bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);
        while ( cont ) {
            wxLogDebug(wxT("File: ") + filename);
            wxString t = filename;
            cont = dir.GetNext(&filename);
            wxLogDebug(wxT("Deleting file: ") + dir.GetName() + wxFILE_SEP_PATH + t);
            wxRemoveFile(dir.GetName() + wxFILE_SEP_PATH + t);
        }
        cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
        while ( cont ) {
            wxLogDebug(wxT("Folder: ") + filename);
            wxString t = filename;
            cont = dir.GetNext(&filename);
            wxLogDebug(wxT("Deleting folder: ") + dir.GetName() + wxFILE_SEP_PATH + t);
            DeleteDirectory(dir.GetName() + wxFILE_SEP_PATH + t);
        }
        wxMessageDialog dlgOK(this, wxT("Очистка \"") +tPath->GetValue() + 
          wxT("\" завершена"), wxT("Информация!"), wxOK|wxICON_INFORMATION);
        dlgOK.ShowModal();
        wxLogDebug(wxT("All is ok"));
        
    }
}
