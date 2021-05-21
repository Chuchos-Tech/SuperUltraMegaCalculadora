/***************************************************************
 * Name:      Calculadora_GUI_ora_si_App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2021-03-10
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "Calculadora_GUI_ora_si_App.h"
#include "Calculadora_GUI_ora_si_Main.h"

IMPLEMENT_APP(Calculadora_GUI_ora_si_App);

bool Calculadora_GUI_ora_si_App::OnInit()
{
    
    Calculadora_GUI_ora_si_Dialog* dlg = new Calculadora_GUI_ora_si_Dialog(0L, _("wxWidgets Application Template"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
