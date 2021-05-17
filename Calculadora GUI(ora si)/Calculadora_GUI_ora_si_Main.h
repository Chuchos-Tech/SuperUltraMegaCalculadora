/***************************************************************
 * Name:      Calculadora_GUI_ora_si_Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2021-03-10
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef CALCULADORA_GUI_ORA_SI_MAIN_H
#define CALCULADORA_GUI_ORA_SI_MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Calculadora_GUI_ora_si_App.h"


#include <wx/button.h>
#include <wx/statline.h>
class Calculadora_GUI_ora_si_Dialog: public wxDialog
{
    public:
        Calculadora_GUI_ora_si_Dialog(wxDialog *dlg, const wxString& title);
        ~Calculadora_GUI_ora_si_Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // CALCULADORA_GUI_ORA_SI_MAIN_H
