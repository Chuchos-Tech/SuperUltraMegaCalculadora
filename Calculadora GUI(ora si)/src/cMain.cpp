#include "cMain.h"
#include <string.h>
#include "fisica.h"
#define INDEF -1048576

const int MAX_DOUBLE = 4932;
int longitud = 0;
int datos = 0;
int nArgumentos = 0;
int Argumentos_current = 0;
wxTreeItemId IDoperacion = 0;

//definiciones de wxTreeItemId:
wxTreeItemId ConDisKm;
wxTreeItemId ConDisHm;
wxTreeItemId ConDisDam;
wxTreeItemId ConDisDm;
wxTreeItemId ConDisCm;
wxTreeItemId ConDisMm;
wxTreeItemId ConTiH;
wxTreeItemId ConTiM;
wxTreeItemId ConVeKmh;
wxTreeItemId ConVeKms;
wxTreeItemId ConVeMh;
wxTreeItemId ConMaHe;
wxTreeItemId ConMaDe;
wxTreeItemId ConMaG;
wxTreeItemId ConMaDg;
wxTreeItemId ConMaCg;
wxTreeItemId ConMaMg;
wxTreeItemId ConFuKn;
wxTreeItemId ConFuHn;
wxTreeItemId ConFuDan;
wxTreeItemId ConFuDn;
wxTreeItemId ConFuCn;
wxTreeItemId ConFuMn;
wxTreeItemId ConEnKj;
wxTreeItemId ConEnHj;
wxTreeItemId ConEnDaj;
wxTreeItemId ConEnDj;
wxTreeItemId ConEnCj;
wxTreeItemId ConEnMj;
wxTreeItemId ConFrGhz;
wxTreeItemId ConFrMhz;

wxTreeItemId LGUFr;
wxTreeItemId LGUMa;
wxTreeItemId LGUDis;

wxTreeItemId NotSum;
wxTreeItemId NotRes;
wxTreeItemId NotRC;
wxTreeItemId NotMul;
wxTreeItemId NotDiv;
wxTreeItemId NotPot;
wxTreeItemId NotConND;
wxTreeItemId NotConDN;

wxTreeItemId MRUVel;
wxTreeItemId MRUDis;
wxTreeItemId MRUTie;

wxTreeItemId MRUVAce;
wxTreeItemId MRUVVelF;
wxTreeItemId MRUVVelI;
wxTreeItemId MRUVDis;
wxTreeItemId MRUVTie;

wxTreeItemId OndasVel; //revisar esto, por que demonios no tiene hijos

wxTreeItemId CLVelF;
wxTreeItemId CLAlt;
wxTreeItemId CLTie;

wxTreeItemId TVAlt;
wxTreeItemId TVTie;
wxTreeItemId TVVel;

wxTreeItemId FuerFue;
wxTreeItemId FuerMasa;
wxTreeItemId FuerAce;

wxTreeItemId PesoPes;
wxTreeItemId PesoMas;

wxTreeItemId EnePotPot;
wxTreeItemId EnePotPes;
wxTreeItemId EnePotAlt;
wxTreeItemId EneCinCin;
wxTreeItemId EneCinMas;
wxTreeItemId EneCinVel;
wxTreeItemId EneMecMec;
wxTreeItemId EneMecPot;
wxTreeItemId EneMecCin;

wxTreeItemId TrabTrab;
wxTreeItemId TrabFuer;
wxTreeItemId TrabDis;

wxTreeItemId PotPot;
wxTreeItemId PotTrab;
wxTreeItemId PotTie;

wxTreeItemId PresPresPres;
wxTreeItemId PresPresFuer;
wxTreeItemId PresPresArea;
wxTreeItemId PresHidPres;
wxTreeItemId PresHidDens;
wxTreeItemId PresHidAlt;
wxTreeItemId PresAbsAbs;
wxTreeItemId PresAbsHid;
wxTreeItemId PresAbsAtm;
//
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculadora", wxPoint(10, 10), wxSize(625, 575)){
    wxFont Num(25, wxFONTFAMILY_MODERN, wxFONTSIZE_MEDIUM, wxFONTWEIGHT_EXTRABOLD);
    wxFont Pequenia(12, wxFONTFAMILY_MODERN, wxFONTSIZE_MEDIUM, wxFONTWEIGHT_EXTRABOLD);
    SetFont(Num);
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 90), wxSize(300, 90), wxTE_READONLY);
    SetFont(Pequenia);
    m_txt2 = new wxTextCtrl(this, wxID_ANY, "Selecciona la operacion que deseas realizar en el arbol", wxPoint(10, 10), wxSize(590, 70), wxTE_READONLY);
    m_tree1 = new wxTreeCtrl(this, 10050, wxPoint(320, 90), wxSize(280, 435), wxTR_LINES_AT_ROOT);
    //Arbol:
    wxTreeItemId rootId = m_tree1 -> AddRoot("Calculos");
        wxTreeItemId ConversionesID = m_tree1 -> AppendItem(rootId, "Conversiones");
            wxTreeItemId ConversionesDID = m_tree1 -> AppendItem(ConversionesID, "Distancia");
                ConDisKm = m_tree1 -> AppendItem(ConversionesDID, "Km");
                ConDisHm = m_tree1 -> AppendItem(ConversionesDID, "Hm");
                ConDisDam = m_tree1 -> AppendItem(ConversionesDID, "Dam");
                ConDisDm = m_tree1 -> AppendItem(ConversionesDID, "Dm");
                ConDisCm = m_tree1 -> AppendItem(ConversionesDID, "Cm");
                ConDisMm = m_tree1 -> AppendItem(ConversionesDID, "Mm");
            wxTreeItemId ConversionesTID = m_tree1 -> AppendItem(ConversionesID, "Tiempo");
                ConTiH = m_tree1 -> AppendItem(ConversionesTID, "Hora");
                ConTiM = m_tree1 -> AppendItem(ConversionesTID, "Minuto");
            wxTreeItemId ConversionesVID = m_tree1 -> AppendItem(ConversionesID, "Velocidad");
                ConVeKmh = m_tree1 -> AppendItem(ConversionesVID, "Km/h");
                ConVeKms = m_tree1 -> AppendItem(ConversionesVID, "Km/s");
                ConVeMh = m_tree1 -> AppendItem(ConversionesVID, "m/h");
            wxTreeItemId ConversionesMID = m_tree1 -> AppendItem(ConversionesID, "Masa");
                ConMaHe = m_tree1 -> AppendItem(ConversionesMID, "Hectogramo");
                ConMaDe = m_tree1 -> AppendItem(ConversionesMID, "Decagramo");
                ConMaG = m_tree1 -> AppendItem(ConversionesMID, "Gramo");
                ConMaDg = m_tree1 -> AppendItem(ConversionesMID, "Decigramo");
                ConMaCg = m_tree1 -> AppendItem(ConversionesMID, "Centigramo");
                ConMaMg = m_tree1 -> AppendItem(ConversionesMID, "Miligramo");
            wxTreeItemId ConversionesFID = m_tree1 -> AppendItem(ConversionesID, "Fuerza");
                ConFuKn = m_tree1 -> AppendItem(ConversionesFID, "KiloNewton");
                ConFuHn = m_tree1 -> AppendItem(ConversionesFID, "HectoNewton");
                ConFuDan = m_tree1 -> AppendItem(ConversionesFID, "DecaNewton");
                ConFuDn = m_tree1 -> AppendItem(ConversionesFID, "DeciNewton");
                ConFuCn = m_tree1 -> AppendItem(ConversionesFID, "CentiNewton");
                ConFuMn = m_tree1 -> AppendItem(ConversionesFID, "MiliNewton");
            wxTreeItemId ConversionesEID = m_tree1 -> AppendItem(ConversionesID, "Energia");
                ConEnKj = m_tree1 -> AppendItem(ConversionesEID, "KiloJoule");
                ConEnHj = m_tree1 -> AppendItem(ConversionesEID, "HectoJoule");
                ConEnDaj = m_tree1 -> AppendItem(ConversionesEID, "DecaJoule");
                ConEnDj = m_tree1 -> AppendItem(ConversionesEID, "DeciJoule");
                ConEnCj = m_tree1 -> AppendItem(ConversionesEID, "CentiJoule");
                ConEnMj = m_tree1 -> AppendItem(ConversionesEID, "MiliJoule");
            wxTreeItemId ConversionesFrID = m_tree1 -> AppendItem(ConversionesID, "Frecuencia");
                ConFrGhz = m_tree1 -> AppendItem(ConversionesFrID, "Gigahertz");
                ConFrMhz = m_tree1 -> AppendItem(ConversionesFrID, "Megahertz");
        wxTreeItemId LGUID = m_tree1 -> AppendItem(rootId, "LGU");
            LGUFr = m_tree1 -> AppendItem(LGUID, "Fuerza");
            LGUMa = m_tree1 -> AppendItem(LGUID, "Masa");
            LGUDis = m_tree1 -> AppendItem(LGUID, "Distancia");
        wxTreeItemId NotacionID = m_tree1 -> AppendItem(rootId, "Notacion cientifica");
            NotSum = m_tree1 -> AppendItem(NotacionID, "Suma");
            NotRes = m_tree1 -> AppendItem(NotacionID, "Resta");
            NotRC = m_tree1 -> AppendItem(NotacionID, "Raiz Cuadrada");
            NotMul = m_tree1 -> AppendItem(NotacionID, "Multiplicacion");
            NotDiv = m_tree1 -> AppendItem(NotacionID, "Division");
            NotPot = m_tree1 -> AppendItem(NotacionID, "Potenciacion");
            wxTreeItemId NotacionCID = m_tree1 -> AppendItem(NotacionID, "Conversiones");
                NotConND = m_tree1 -> AppendItem(NotacionCID, "Notacion a Decimal");
                NotConDN = m_tree1 -> AppendItem(NotacionCID, "Decimal a Notacion");
        wxTreeItemId MRUID = m_tree1 -> AppendItem(rootId, "MRU");
            MRUVel = m_tree1 -> AppendItem(MRUID, "Velocidad");
            MRUDis = m_tree1 -> AppendItem(MRUID, "Distancia");
            MRUTie = m_tree1 -> AppendItem(MRUID, "Tiempo");
        wxTreeItemId MRUVID = m_tree1 -> AppendItem(rootId, "MRUV");
            MRUVAce = m_tree1 -> AppendItem(MRUVID, "Aceleracion");
            MRUVVelF = m_tree1 -> AppendItem(MRUVID, "Velocidad Final");
            MRUVVelI = m_tree1 -> AppendItem(MRUVID, "Velocidad Inicial");
            MRUVDis = m_tree1 -> AppendItem(MRUVID, "Distancia");
            MRUVTie = m_tree1 -> AppendItem(MRUVID, "Tiempo");
        OndasVel = m_tree1 -> AppendItem(rootId, "Velocidad de onda");
        wxTreeItemId CLID = m_tree1 -> AppendItem(rootId, "Caida Libre");
            CLVelF = m_tree1 -> AppendItem(CLID, "Velocidad Final");
            CLAlt = m_tree1 -> AppendItem(CLID, "Altura");
            CLTie = m_tree1 -> AppendItem(CLID, "Tiempo");
        wxTreeItemId TVID = m_tree1 -> AppendItem(rootId, "Tiro vertical");
            TVAlt = m_tree1 -> AppendItem(TVID, "Altura Max");
            TVTie = m_tree1 -> AppendItem(TVID, "Tiempo");
            TVVel = m_tree1 -> AppendItem(TVID, "Velocidad inicial");
        wxTreeItemId FuerzaID = m_tree1 -> AppendItem(rootId, "Fuerza");
            FuerFue = m_tree1 -> AppendItem(FuerzaID, "Fuerza");
            FuerMasa = m_tree1 -> AppendItem(FuerzaID, "Masa");
            FuerAce = m_tree1 -> AppendItem(FuerzaID, "Aceleracion");
        wxTreeItemId PesoID = m_tree1 -> AppendItem(rootId, "Peso");
            PesoPes = m_tree1 -> AppendItem(PesoID, "Peso");
            PesoMas = m_tree1 -> AppendItem(PesoID, "Masa");
        wxTreeItemId EnergiaID = m_tree1 -> AppendItem(rootId, "Energia");
            wxTreeItemId EnergiaPotID = m_tree1 -> AppendItem(EnergiaID, "Energia potencial");
                EnePotPot = m_tree1 -> AppendItem(EnergiaPotID, "Energia potencial");
                EnePotPes = m_tree1 -> AppendItem(EnergiaPotID, "Peso");
                EnePotAlt = m_tree1 -> AppendItem(EnergiaPotID, "Altura");
            wxTreeItemId EnergiaCinID = m_tree1 -> AppendItem(EnergiaID, "Energia cinetica");
                EneCinCin = m_tree1 -> AppendItem(EnergiaCinID, "Energia cinetica");
                EneCinMas = m_tree1 -> AppendItem(EnergiaCinID, "Masa");
                EneCinVel = m_tree1 -> AppendItem(EnergiaCinID, "Velocidad");
            wxTreeItemId EnergiaMecID = m_tree1 -> AppendItem(EnergiaID, "Energia mecanica");
                EneMecMec = m_tree1 -> AppendItem(EnergiaMecID, "Energia mecanica");
                EneMecPot = m_tree1 -> AppendItem(EnergiaMecID, "Energia potencial");
                EneMecCin = m_tree1 -> AppendItem(EnergiaMecID, "Energia cinetica");
        wxTreeItemId TrabajoID = m_tree1 -> AppendItem(rootId, "Trabajo");
                TrabTrab = m_tree1 -> AppendItem(TrabajoID, "Trabajo");
                TrabFuer = m_tree1 -> AppendItem(TrabajoID, "Fuerza");
                TrabDis = m_tree1 -> AppendItem(TrabajoID, "Distancia");
        wxTreeItemId PotenciaID = m_tree1 -> AppendItem(rootId, "Potencia");
                PotPot = m_tree1 -> AppendItem(PotenciaID, "Potencia");
                PotTrab = m_tree1 -> AppendItem(PotenciaID, "Trabajo");
                PotTie = m_tree1 -> AppendItem(PotenciaID, "Tiempo");
        wxTreeItemId PresionID = m_tree1 -> AppendItem(rootId, "Presion");
            wxTreeItemId PresionCID = m_tree1 -> AppendItem(PresionID, "Presion");
                PresPresPres = m_tree1 -> AppendItem(PresionCID, "Presion");
                PresPresFuer = m_tree1 -> AppendItem(PresionCID, "Fuerza");
                PresPresArea = m_tree1 -> AppendItem(PresionCID, "Area");
            wxTreeItemId PresionHID = m_tree1 -> AppendItem(PresionID, "Presion Hidroestatica");
                PresHidPres = m_tree1 -> AppendItem(PresionHID, "Presion");
                PresHidDens = m_tree1 -> AppendItem(PresionHID, "Densidad");
                PresHidAlt = m_tree1 -> AppendItem(PresionHID, "Altura");
            wxTreeItemId PresionAbsID = m_tree1 -> AppendItem(PresionID, "Presion Absoluta");
                PresAbsAbs = m_tree1 -> AppendItem(PresionAbsID, "Presion Absoluta");
                PresAbsHid = m_tree1 -> AppendItem(PresionAbsID, "Presion Hidroestatica");
                PresAbsAtm = m_tree1 -> AppendItem(PresionAbsID, "Presion Atmosferica");
    m_tree1 -> Expand(rootId);

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

void cMain::bloquear(){
    m_btn1_1 -> Disable();
    m_btn1_2 -> Disable();
    m_btn1_3 -> Disable();

    m_btn2_1 -> Disable();
    m_btn2_2 -> Disable();
    m_btn2_3 -> Disable();

    m_btn3_1 -> Disable();
    m_btn3_2 -> Disable();
    m_btn3_3 -> Disable();

    m_btn4_2 -> Disable();
}

void cMain::desbloquear(){
    m_btn1_1 -> Enable();
    m_btn1_2 -> Enable();
    m_btn1_3 -> Enable();

    m_btn2_1 -> Enable();
    m_btn2_2 -> Enable();
    m_btn2_3 -> Enable();

    m_btn3_1 -> Enable();
    m_btn3_2 -> Enable();
    m_btn3_3 -> Enable();

    m_btn4_2 -> Enable();
}

void cMain::boton_presionado1(wxCommandEvent& evt){
    m_txt1 -> AppendText("1");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado2(wxCommandEvent& evt){
    m_txt1 -> AppendText("2");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado3(wxCommandEvent& evt){
    m_txt1 -> AppendText("3");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado4(wxCommandEvent& evt){
    m_txt1 -> AppendText("4");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado5(wxCommandEvent& evt){
    m_txt1 -> AppendText("5");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado6(wxCommandEvent& evt){
    m_txt1 -> AppendText("6");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado7(wxCommandEvent& evt){
    m_txt1 -> AppendText("7");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado8(wxCommandEvent& evt){
    m_txt1 -> AppendText("8");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado9(wxCommandEvent& evt){
    m_txt1 -> AppendText("9");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado0(wxCommandEvent& evt){
    m_txt1 -> AppendText("0");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionadoMenos(wxCommandEvent& evt){
    m_btn4_1 -> Disable();
    m_txt1 -> AppendText("-");
    m_btn4_3 -> Enable();
    evt.Skip();
}
void cMain::boton_presionadoBackSpace(wxCommandEvent& evt){
    char numeros[1024];
    strncpy(numeros, (const char*)m_txt1 -> GetLineText(0).mb_str(wxConvUTF8), 1023);
    int len = strlen(numeros);
    if(numeros[len-1] == '.')
        m_btn4_5 -> Enable();
    numeros[len-1] = '\0';
    m_txt1 -> ChangeValue(numeros);
    len--;
    if(len == 0){
        m_btn4_1 -> Enable();
        m_btn4_3 -> Disable();
    }
    evt.Skip();
}
void cMain::boton_presionadoPunto(wxCommandEvent& evt){
    m_txt1 -> AppendText(".");
    m_btn4_5 -> Disable();
    m_btn4_3 -> Enable();
    evt.Skip();
}


void cMain::boton_presionadoEnter(wxCommandEvent& evt){
    double Argumentos[4];
    double resultado = 0;
    bool a = false;
    if(nArgumentos != 0){
      Argumentos[Argumentos_current] = wxAtof(m_txt1 -> GetValue());
      Argumentos_current++;
      m_txt1 -> Clear();
      if(Argumentos_current == nArgumentos){ //todos los argumentos han sido recibidos
        if(IDoperacion == ConDisKm)
          resultado = Conversiones(Argumentos[0], 0, 0);
        else if(IDoperacion == ConDisHm)
          resultado = Conversiones(Argumentos[0], 0, 1);
        else if(IDoperacion == ConDisDam)
          resultado = Conversiones(Argumentos[0], 0, 2);
        else if(IDoperacion == ConDisDm)
          resultado = Conversiones(Argumentos[0], 0 ,3);
        else if(IDoperacion == ConDisCm)
          resultado = Conversiones(Argumentos[0], 0, 4);
        else if(IDoperacion == ConDisMm)
          resultado = Conversiones(Argumentos[0], 0, 5);
        else if(IDoperacion == ConTiH)
          resultado = Conversiones(Argumentos[0], 1, 0);
        else if(IDoperacion == ConTiM)
          resultado = Conversiones(Argumentos[0], 1, 1);
        else if(IDoperacion == ConVeKmh)
          resultado = Conversiones(Argumentos[0], 2, 0);
        else if(IDoperacion == ConVeKms)
          resultado = Conversiones(Argumentos[0], 2, 1);
        else if(IDoperacion == ConVeMh)
          resultado = Conversiones(Argumentos[0], 2, 2);
        else if(IDoperacion == ConMaHe)
          resultado = Conversiones(Argumentos[0], 3, 0);
        else if(IDoperacion == ConMaDe)
          resultado = Conversiones(Argumentos[0], 3, 1);
        else if(IDoperacion == ConMaG)
          resultado = Conversiones(Argumentos[0], 3, 2);
        else if(IDoperacion == ConMaDg)
          resultado = Conversiones(Argumentos[0], 3, 3);
        else if(IDoperacion == ConMaCg)
          resultado = Conversiones(Argumentos[0], 3, 4);
        else if(IDoperacion == ConMaMg)
          resultado = Conversiones(Argumentos[0], 3, 5);
        else if(IDoperacion == ConFuKn)
          resultado = Conversiones(Argumentos[0], 4, 0);
        else if(IDoperacion == ConFuHn)
          resultado = Conversiones(Argumentos[0], 4, 1);
        else if(IDoperacion == ConFuDan)
          resultado = Conversiones(Argumentos[0], 4, 2);
        else if(IDoperacion == ConFuDn)
          resultado = Conversiones(Argumentos[0], 4, 3);
        else if(IDoperacion == ConFuCn)
          resultado = Conversiones(Argumentos[0], 4, 4);
        else if(IDoperacion == ConFuMn)
          resultado = Conversiones(Argumentos[0], 4, 5);
        else if(IDoperacion == ConEnKj)
          resultado = Conversiones(Argumentos[0], 5, 0);
        else if(IDoperacion == ConEnHj)
          resultado = Conversiones(Argumentos[0], 5, 1);
        else if(IDoperacion == ConEnDaj)
          resultado = Conversiones(Argumentos[0], 5, 2);
        else if(IDoperacion == ConEnDj)
          resultado = Conversiones(Argumentos[0], 5, 3);
        else if(IDoperacion == ConEnCj)
          resultado = Conversiones(Argumentos[0], 5, 4);
        else if(IDoperacion == ConEnMj)
          resultado = Conversiones(Argumentos[0], 5, 6);
        else if(IDoperacion == ConFrGhz)
          resultado = Conversiones(Argumentos[0], 6, 0);
        else if(IDoperacion == ConFrMhz)
          resultado = Conversiones(Argumentos[0], 6, 1);
        else if(IDoperacion == NotConDN){//notacion regresa cadena de caractereeeees
          a = true;
          printf("%s\n", Notacion(Argumentos[0], INDEF, INDEF, INDEF, 6, 1));
          m_txt1 -> SetValue(Notacion(Argumentos[0], INDEF, INDEF, INDEF, 6, 1));
        }
        else if(IDoperacion == CLTie)
          resultado = CaidaLibre(INDEF, Argumentos[0], INDEF, 2);
        else if(IDoperacion == TVAlt)
          resultado = TiroVertical(INDEF, INDEF, Argumentos[0], 0);
        else if(IDoperacion == TVTie)
          resultado = TiroVertical(INDEF, INDEF, Argumentos[0], 1);
        else if(IDoperacion == TVVel)
          resultado = TiroVertical(INDEF, Argumentos[0], INDEF, 2);
      if(a == false)
        m_txt1 -> SetValue(wxString::Format(wxT("%f"), resultado));
      m_txt2 -> SetValue("La respuesta es:");
      }
    }
}
void cMain::onTreeSelectionChanged(wxTreeEvent& evt){
    IDoperacion = evt.GetItem();
    m_txt1 -> SetValue("");
    if(
    IDoperacion == ConDisKm ||
    IDoperacion == ConDisHm ||
    IDoperacion == ConDisDam ||
    IDoperacion == ConDisDm ||
    IDoperacion == ConDisCm ||
    IDoperacion == ConDisMm ||
    IDoperacion == ConTiH ||
    IDoperacion == ConTiM ||
    IDoperacion == ConVeKmh ||
    IDoperacion == ConVeKms ||
    IDoperacion == ConVeMh ||
    IDoperacion == ConMaHe ||
    IDoperacion == ConMaDe ||
    IDoperacion == ConMaG ||
    IDoperacion == ConMaDg ||
    IDoperacion == ConMaCg ||
    IDoperacion == ConMaMg ||
    IDoperacion == ConFuKn ||
    IDoperacion == ConFuHn ||
    IDoperacion == ConFuDan ||
    IDoperacion == ConFuDn ||
    IDoperacion == ConFuCn ||
    IDoperacion == ConFuMn ||
    IDoperacion == ConEnKj ||
    IDoperacion == ConEnHj ||
    IDoperacion == ConEnDaj ||
    IDoperacion == ConEnDj ||
    IDoperacion == ConEnCj ||
    IDoperacion == ConEnMj ||
    IDoperacion == ConFrGhz ||
    IDoperacion == ConFrMhz ||
    IDoperacion == NotConDN ||
    IDoperacion == CLTie ||
    IDoperacion == TVAlt ||
    IDoperacion == TVTie ||
    IDoperacion == TVVel
  ) {
      nArgumentos = 1;
      Argumentos_current = 0;
      if(IDoperacion == TVAlt || IDoperacion == TVTie)
        m_txt2 -> SetValue("Introduce la velocidad final");
      else if(IDoperacion == TVVel)
        m_txt2 -> SetValue("Introduce el tiempo");
      else if(IDoperacion == CLTie)
        m_txt2 -> SetValue("Introduce la altura");
      else
        m_txt2 -> SetValue("Introduce el numero a convertir");
  }

  if(
    IDoperacion == NotRC ||
    IDoperacion == NotConND ||
    IDoperacion == MRUVel ||
    IDoperacion == MRUDis ||
    IDoperacion == MRUTie ||
    IDoperacion == CLVelF || //r2, u1
    IDoperacion == CLAlt || //r2, u1
    IDoperacion == FuerFue ||
    IDoperacion == FuerMasa ||
    IDoperacion == FuerAce ||
    IDoperacion == PesoPes ||
    IDoperacion == PesoMas ||
    IDoperacion == EnePotPot ||
    IDoperacion == EnePotPes ||
    IDoperacion == EnePotAlt ||
    IDoperacion == EneCinCin ||
    IDoperacion == EneCinMas ||
    IDoperacion == EneCinVel ||
    IDoperacion == EneMecMec ||
    IDoperacion == EneMecPot ||
    IDoperacion == EneMecCin ||
    IDoperacion == TrabTrab ||
    IDoperacion == TrabFuer ||
    IDoperacion == TrabDis ||
    IDoperacion == PotPot ||
    IDoperacion == PotTrab ||
    IDoperacion == PotTie ||
    IDoperacion == PresPresPres ||
    IDoperacion == PresPresFuer ||
    IDoperacion == PresPresArea ||
    IDoperacion == PresHidPres ||
    IDoperacion == PresHidDens ||
    IDoperacion == PresHidAlt ||
    IDoperacion == PresAbsAbs ||
    IDoperacion == PresAbsHid ||
    IDoperacion == PresAbsAtm
  ) {nArgumentos = 2;Argumentos_current = 0;}

  if(
    IDoperacion == LGUFr ||
    IDoperacion == LGUMa ||
    IDoperacion == LGUDis ||
    IDoperacion == NotPot ||
    IDoperacion == OndasVel //r3, u2
  ) {nArgumentos = 3;Argumentos_current = 0;}

  if(
    IDoperacion == NotSum ||
    IDoperacion == NotRes ||
    IDoperacion == NotMul ||
    IDoperacion == NotDiv ||
    IDoperacion == MRUVAce || //r4, u3
    IDoperacion == MRUVVelF || //r4, u3
    IDoperacion == MRUVVelI || //r4, u3
    IDoperacion == MRUVTie //r4, u3
  ) {nArgumentos = 4;Argumentos_current = 0;}
}

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_TREE_SEL_CHANGED(10050, cMain::onTreeSelectionChanged)
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
    EVT_BUTTON(1011, cMain::boton_presionadoBackSpace)
    EVT_BUTTON(1012, cMain::boton_presionadoEnter)
    EVT_BUTTON(1013, cMain::boton_presionadoPunto)
wxEND_EVENT_TABLE()
