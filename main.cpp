#include <wx/dir.h>
#include <wx/filename.h>
#include "mainframe.h"

void DeleteDirectory(wxString filename) //удаляет весь каталог по указанному пути
{
	wxDir dir(filename);
	wxString file;
	bool cont = dir.GetFirst(&file);
	while (cont)
	{
		file = filename + wxFileName::GetPathSeparator() + file;
		if (wxFileName::FileExists(file)) wxRemoveFile(file);
		if (wxFileName::DirExists(file)) DeleteDirectory(file);
		cont = dir.GetNext(&file);
	}
	wxFileName::Rmdir(dir.GetName());
}

 

void MainFrame::btnCleanClick(wxCommandEvent &event)//основная функция приложения
{
	wxMessageDialog dlgQues 
		//...
			wxMessageDialog dlgErr 
			//...
		wxMessageDialog dlgOK
		//...

	}
}


 


 
