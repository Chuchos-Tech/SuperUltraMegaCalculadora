#ifndef CMAIN_H
#define CMAIN_H
#include "wx/wx.h"
#include "wx/treectrl.h"

class cMain : public wxFrame{
    public:
        cMain();
    wxButton *m_btn1_1 = nullptr; //Fila_Columna
    wxButton *m_btn1_2 = nullptr;
    wxButton *m_btn1_3 = nullptr;
    wxButton *m_btn2_1 = nullptr;
    wxButton *m_btn2_2 = nullptr;
    wxButton *m_btn2_3 = nullptr;
    wxButton *m_btn3_1 = nullptr;
    wxButton *m_btn3_2 = nullptr;
    wxButton *m_btn3_3 = nullptr;
    wxButton *m_btn4_1 = nullptr;
    wxButton *m_btn4_2 = nullptr;
    wxButton *m_btn4_3 = nullptr;
    wxButton *m_btn4_4 = nullptr;
    wxButton *m_btn4_5 = nullptr;
    wxTextCtrl *m_txt1 = nullptr;
    wxTreeCtrl *m_tree1 = nullptr;
    wxTextCtrl *m_txt2 = nullptr;
    void onTreeSelectionChanged(wxTreeEvent& evt);
    wxDECLARE_EVENT_TABLE();
    void boton_presionado1(wxCommandEvent& evt);
    void boton_presionado2(wxCommandEvent& evt);
    void boton_presionado3(wxCommandEvent& evt);
    void boton_presionado4(wxCommandEvent& evt);
    void boton_presionado5(wxCommandEvent& evt);
    void boton_presionado6(wxCommandEvent& evt);
    void boton_presionado7(wxCommandEvent& evt);
    void boton_presionado8(wxCommandEvent& evt);
    void boton_presionado9(wxCommandEvent& evt);
    void boton_presionado0(wxCommandEvent& evt);
    void boton_presionadoMenos(wxCommandEvent& evt);
    void boton_presionadoEnter(wxCommandEvent& evt);
    void boton_presionadoBackSpace(wxCommandEvent& evt);
    void boton_presionadoPunto(wxCommandEvent& evt);
    void onKeyPress(wxKeyEvent &evt);

    void onEnter();
    
    void bloquear();
    void desbloquear();
};

#endif // CMAIN_H
