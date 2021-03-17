#include "cMain.h"
#include <string.h>
#define Menos 10
#define BackSpace 11
#define Enter 12
#define Punto 13

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculadora", wxPoint(10, 10), wxSize(625, 575)){
    wxFont Num(25, wxFONTFAMILY_MODERN, wxFONTSIZE_MEDIUM, wxFONTWEIGHT_EXTRABOLD);
    wxFont Pequenia(12, wxFONTFAMILY_MODERN, wxFONTSIZE_MEDIUM, wxFONTWEIGHT_EXTRABOLD);
    SetFont(Pequenia);
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 90), wxSize(300, 90));
    m_txt2 = new wxTextCtrl(this, wxID_ANY, "Selecciona la operacion que deseas realizar en el arbol", wxPoint(10, 10), wxSize(590, 70), wxTE_READONLY);
    m_tree1 = new wxTreeCtrl(this, wxID_ANY, wxPoint(320, 90), wxSize(280, 435), wxTR_LINES_AT_ROOT);
    //Arbol:
    wxTreeItemId rootId = m_tree1 -> AddRoot("Calculos");
        wxTreeItemId ConversionesID = m_tree1 -> AppendItem(rootId, "Conversiones");
            wxTreeItemId ConversionesDID = m_tree1 -> AppendItem(ConversionesID, "Distancia");
                m_tree1 -> AppendItem(ConversionesDID, "Km");
                m_tree1 -> AppendItem(ConversionesDID, "Hm");
                m_tree1 -> AppendItem(ConversionesDID, "Dam");
                m_tree1 -> AppendItem(ConversionesDID, "Dm");
                m_tree1 -> AppendItem(ConversionesDID, "Cm");
                m_tree1 -> AppendItem(ConversionesDID, "Mm");
            wxTreeItemId ConversionesTID = m_tree1 -> AppendItem(ConversionesID, "Tiempo");
                m_tree1 -> AppendItem(ConversionesTID, "Hora");
                m_tree1 -> AppendItem(ConversionesTID, "Minuto");
            wxTreeItemId ConversionesVID = m_tree1 -> AppendItem(ConversionesID, "Velocidad");
                m_tree1 -> AppendItem(ConversionesVID, "Km/h");
                m_tree1 -> AppendItem(ConversionesVID, "Km/s");
                m_tree1 -> AppendItem(ConversionesVID, "m/h");
            wxTreeItemId ConversionesMID = m_tree1 -> AppendItem(ConversionesID, "Masa");
                m_tree1 -> AppendItem(ConversionesMID, "Hectogramo");
                m_tree1 -> AppendItem(ConversionesMID, "Decagramo");
                m_tree1 -> AppendItem(ConversionesMID, "Gramo");
                m_tree1 -> AppendItem(ConversionesMID, "Decigramo");
                m_tree1 -> AppendItem(ConversionesMID, "Centigramo");
                m_tree1 -> AppendItem(ConversionesMID, "Miligramo");
            wxTreeItemId ConversionesFID = m_tree1 -> AppendItem(ConversionesID, "Fuerza");
                m_tree1 -> AppendItem(ConversionesFID, "KiloNewton");
                m_tree1 -> AppendItem(ConversionesFID, "HectoNewton");
                m_tree1 -> AppendItem(ConversionesFID, "DecaNewton");
                m_tree1 -> AppendItem(ConversionesFID, "DeciNewton");
                m_tree1 -> AppendItem(ConversionesFID, "CentiNewton");
                m_tree1 -> AppendItem(ConversionesFID, "MiliNewton");
            wxTreeItemId ConversionesEID = m_tree1 -> AppendItem(ConversionesID, "Energia");
                m_tree1 -> AppendItem(ConversionesEID, "KiloJoule");
                m_tree1 -> AppendItem(ConversionesEID, "HectoJoule");
                m_tree1 -> AppendItem(ConversionesEID, "DecaJoule");
                m_tree1 -> AppendItem(ConversionesEID, "DeciJoule");
                m_tree1 -> AppendItem(ConversionesEID, "CentiJoule");
                m_tree1 -> AppendItem(ConversionesEID, "MiliJoule");
            wxTreeItemId ConversionesFrID = m_tree1 -> AppendItem(ConversionesID, "Frecuencia");
                m_tree1 -> AppendItem(ConversionesFrID, "Gigahertz");
                m_tree1 -> AppendItem(ConversionesFrID, "Megahertz");
        wxTreeItemId LGUID = m_tree1 -> AppendItem(rootId, "LGU");
            m_tree1 -> AppendItem(LGUID, "Fuerza");
            m_tree1 -> AppendItem(LGUID, "Masa");
            m_tree1 -> AppendItem(LGUID, "Distancia");
        wxTreeItemId NotacionID = m_tree1 -> AppendItem(rootId, "Notacion cientifica");
            wxTreeItemId NotacionCID = m_tree1 -> AppendItem(NotacionID, "Conversiones");
                m_tree1 -> AppendItem(NotacionCID, "Decimal a notacion");
                m_tree1 -> AppendItem(NotacionCID, "Notacion a decimal");
            m_tree1 -> AppendItem(NotacionID, "Suma y resta");
            m_tree1 -> AppendItem(NotacionID, "Raiz Cuadrada");
            m_tree1 -> AppendItem(NotacionID, "Multiplicacion");
            m_tree1 -> AppendItem(NotacionID, "Division");
            m_tree1 -> AppendItem(NotacionID, "Potenciacion");
        wxTreeItemId MRUID = m_tree1 -> AppendItem(rootId, "MRU");
            m_tree1 -> AppendItem(MRUID, "Velocidad");
            m_tree1 -> AppendItem(MRUID, "Distancia");
            m_tree1 -> AppendItem(MRUID, "Tiempo");
        wxTreeItemId MRUVID = m_tree1 -> AppendItem(rootId, "MRUV");
            m_tree1 -> AppendItem(MRUVID, "Aceleracion");
            m_tree1 -> AppendItem(MRUVID, "Velocidad Final");
            m_tree1 -> AppendItem(MRUVID, "Velocidad Inicial");
            m_tree1 -> AppendItem(MRUVID, "Distancia");
            m_tree1 -> AppendItem(MRUVID, "Tiempo");
        wxTreeItemId OndasID = m_tree1 -> AppendItem(rootId, "Ondas");
        wxTreeItemId CLID = m_tree1 -> AppendItem(rootId, "Caida Libre");
            m_tree1 -> AppendItem(CLID, "Velocidad Final");
            m_tree1 -> AppendItem(CLID, "Altura");
            m_tree1 -> AppendItem(CLID, "Tiempo");
        wxTreeItemId TVID = m_tree1 -> AppendItem(rootId, "Tiro vertical");
            m_tree1 -> AppendItem(TVID, "Altura Max");
            m_tree1 -> AppendItem(TVID, "Tiempo");
            m_tree1 -> AppendItem(TVID, "Velocidad inicial");
        wxTreeItemId FuerzaID = m_tree1 -> AppendItem(rootId, "Fuerza");
            m_tree1 -> AppendItem(FuerzaID, "Fuerza");
            m_tree1 -> AppendItem(FuerzaID, "Masa");
            m_tree1 -> AppendItem(FuerzaID, "Aceleracion");
        wxTreeItemId PesoID = m_tree1 -> AppendItem(rootId, "Peso");
            m_tree1 -> AppendItem(PesoID, "Peso");
            m_tree1 -> AppendItem(PesoID, "Masa");
        wxTreeItemId EnergiaID = m_tree1 -> AppendItem(rootId, "Energia");
            wxTreeItemId EnergiaPotID = m_tree1 -> AppendItem(EnergiaID, "Energia potencial");
                m_tree1 -> AppendItem(EnergiaPotID, "Energia potencial");
                m_tree1 -> AppendItem(EnergiaPotID, "Peso");
                m_tree1 -> AppendItem(EnergiaPotID, "Altura");
            wxTreeItemId EnergiaCinID = m_tree1 -> AppendItem(EnergiaID, "Energia cinetica");
                m_tree1 -> AppendItem(EnergiaCinID, "Energia cinetica");
                m_tree1 -> AppendItem(EnergiaCinID, "Masa");
                m_tree1 -> AppendItem(EnergiaCinID, "Velocidad");
            wxTreeItemId EnergiaMecID = m_tree1 -> AppendItem(EnergiaID, "Energia mecanica");
                m_tree1 -> AppendItem(EnergiaMecID, "Energia mecanica");
                m_tree1 -> AppendItem(EnergiaMecID, "Energia potencial");
                m_tree1 -> AppendItem(EnergiaMecID, "Energia cinetica");
        wxTreeItemId TrabajoID = m_tree1 -> AppendItem(rootId, "Trabajo");
                m_tree1 -> AppendItem(TrabajoID, "Energia Trabajo");
                m_tree1 -> AppendItem(TrabajoID, "Energia Fuerza");
                m_tree1 -> AppendItem(TrabajoID, "Energia Distancia");
    //Botones:
    SetFont(Num);
    m_btn1_1 = new wxButton(this, 1001, "1", wxPoint(10, 190), wxSize(90, 75));
    m_btn1_2 = new wxButton(this, 1002, "2", wxPoint(115, 190), wxSize(90, 75));
    m_btn1_3 = new wxButton(this, 1003, "3", wxPoint(220, 190), wxSize(90, 75));

    m_btn2_1 = new wxButton(this, 1004, "4", wxPoint(10, 275), wxSize(90, 75));
    m_btn2_2 = new wxButton(this, 1005, "5", wxPoint(115, 275), wxSize(90, 75));
    m_btn2_3 = new wxButton(this, 1006, "6", wxPoint(220, 275), wxSize(90, 75));

    m_btn3_1 = new wxButton(this, 1007, "7", wxPoint(10, 360), wxSize(90, 75));
    m_btn3_2 = new wxButton(this, 1008, "8", wxPoint(115, 360), wxSize(90, 75));
    m_btn3_3 = new wxButton(this, 1009, "9", wxPoint(220, 360), wxSize(90, 75));

    m_btn4_1 = new wxButton(this, 1010, "-", wxPoint(10, 445), wxSize(90, 35));
    m_btn4_5 = new wxButton(this, 1013, ".", wxPoint(10, 485), wxSize(90, 35));
    m_btn4_2 = new wxButton(this, 1000, "0", wxPoint(115, 445), wxSize(90, 75));
    SetFont(Pequenia);
    m_btn4_3 = new wxButton(this, 1011, "<-", wxPoint(220, 445), wxSize(90, 35));
    m_btn4_4 = new wxButton(this, 1012, "enter", wxPoint(220, 485), wxSize(90, 35));
    //
}

void cMain::boton_presionado1(wxCommandEvent& evt){
    m_txt1 -> EmulateKeyPress('1');
}
void cMain::boton_presionado2(wxCommandEvent& evt){

}
void cMain::boton_presionado3(wxCommandEvent& evt){

}
void cMain::boton_presionado4(wxCommandEvent& evt){

}
void cMain::boton_presionado5(wxCommandEvent& evt){

}
void cMain::boton_presionado6(wxCommandEvent& evt){

}
void cMain::boton_presionado7(wxCommandEvent& evt){

}
void cMain::boton_presionado8(wxCommandEvent& evt){

}
void cMain::boton_presionado9(wxCommandEvent& evt){

}
void cMain::boton_presionado0(wxCommandEvent& evt){

}
void cMain::boton_presionadoMenos(wxCommandEvent& evt){

}
void cMain::boton_presionadoEnter(wxCommandEvent& evt){

}
void cMain::boton_presionadoBackSpace(wxCommandEvent& evt){

}
void cMain::boton_presionadoPunto(wxCommandEvent& evt){

}
wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(1001, cMain::boton_presionado1)
    EVT_BUTTON(1002, cMain::boton_presionado2)
    EVT_BUTTON(1003, cMain::boton_presionado3)
    EVT_BUTTON(1004, cMain::boton_presionado4)
    EVT_BUTTON(1005, cMain::boton_presionado5)
    EVT_BUTTON(1006, cMain::boton_presionado6)
    EVT_BUTTON(1007, cMain::boton_presionado7)
    EVT_BUTTON(1008, cMain::boton_presionado8)
    EVT_BUTTON(1009, cMain::boton_presionado9)
    EVT_BUTTON(1000, cMain::boton_presionado0)
    EVT_BUTTON(1010, cMain::boton_presionadoMenos)
    EVT_BUTTON(1011, cMain::boton_presionadoEnter)
    EVT_BUTTON(1012, cMain::boton_presionadoBackSpace)
    EVT_BUTTON(1013, cMain::boton_presionadoPunto)
wxEND_EVENT_TABLE()
