#include "cMain.h"
#include <string.h>
#include "fisica.h"

#define INDEF -1048576

const int MAX_DOUBLE = 50;
int longitud = 0;
int datos = 0;
int nArgumentos = 0;
int Argumentos_current = 0;
double Argumentos[4];
wxTreeItemId IDoperacion = 0;
bool bloqueado = false;
bool Menos_Bloqueado = false;
bool Punto_Bloqueado = false;
bool Enter_Bloqueado = true;

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
wxTreeItemId ConTempKel;
wxTreeItemId ConTempFah;

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

wxTreeItemId OndasVel;

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

wxTreeItemId PascalFMay;
wxTreeItemId PascalAMay;
wxTreeItemId PascalFMen;
wxTreeItemId PascalAMen;

wxTreeItemId ArqFormFE;
wxTreeItemId ArqFormDens;
wxTreeItemId ArqFormVol;
wxTreeItemId ArqPesFE;
wxTreeItemId ArqPesAp;
wxTreeItemId ArqPesRe;

wxTreeItemId DilDil;
wxTreeItemId DilMedIn;
wxTreeItemId DilCoef;
wxTreeItemId DilDelta;
//
cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculadora", wxPoint(10, 10), wxSize(615, 555), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)){
    wxFont Num(25, wxFONTFAMILY_MODERN, wxFONTSTYLE_MAX, wxFONTWEIGHT_EXTRABOLD);
    wxFont Pequenia(13, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_MAX, wxFONTWEIGHT_EXTRABOLD);
    SetFont(Num);
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 90), wxSize(300, 90), wxTE_READONLY);
    SetFont(Pequenia);
    m_txt2 = new wxTextCtrl(this, wxID_ANY, "Selecciona la operacion que deseas realizar en el arbol", wxPoint(10, 10), wxSize(590, 70), wxTE_READONLY);
    m_tree1 = new wxTreeCtrl(this, 10050, wxPoint(320, 90), wxSize(280, 430), wxTR_HAS_BUTTONS);
    //Arbol:
    wxTreeItemId rootId = m_tree1 -> AddRoot("Calculos");
        wxTreeItemId ConversionesID = m_tree1 -> AppendItem(rootId, "Conversiones");
            wxTreeItemId ConversionesDID = m_tree1 -> AppendItem(ConversionesID, "Distancia");
                ConDisKm = m_tree1 -> AppendItem(ConversionesDID, "Km -> m");
                ConDisHm = m_tree1 -> AppendItem(ConversionesDID, "Hm -> m");
                ConDisDam = m_tree1 -> AppendItem(ConversionesDID, "Dam -> m");
                ConDisDm = m_tree1 -> AppendItem(ConversionesDID, "Dm -> m");
                ConDisCm = m_tree1 -> AppendItem(ConversionesDID, "Cm -> m");
                ConDisMm = m_tree1 -> AppendItem(ConversionesDID, "Mm -> m");
            wxTreeItemId ConversionesTID = m_tree1 -> AppendItem(ConversionesID, "Tiempo");
                ConTiH = m_tree1 -> AppendItem(ConversionesTID, "Hora -> s");
                ConTiM = m_tree1 -> AppendItem(ConversionesTID, "Minuto -> s");
            wxTreeItemId ConversionesVID = m_tree1 -> AppendItem(ConversionesID, "Velocidad");
                ConVeKmh = m_tree1 -> AppendItem(ConversionesVID, "Km/h -> m/s");
                ConVeKms = m_tree1 -> AppendItem(ConversionesVID, "Km/s -> m/s");
                ConVeMh = m_tree1 -> AppendItem(ConversionesVID, "m/h -> m/s");
            wxTreeItemId ConversionesMID = m_tree1 -> AppendItem(ConversionesID, "Masa");
                ConMaHe = m_tree1 -> AppendItem(ConversionesMID, "Hectogramo -> Kg");
                ConMaDe = m_tree1 -> AppendItem(ConversionesMID, "Decagramo -> Kg");
                ConMaG = m_tree1 -> AppendItem(ConversionesMID, "Gramo -> Kg");
                ConMaDg = m_tree1 -> AppendItem(ConversionesMID, "Decigramo -> Kg");
                ConMaCg = m_tree1 -> AppendItem(ConversionesMID, "Centigramo -> Kg");
                ConMaMg = m_tree1 -> AppendItem(ConversionesMID, "Miligramo -> Kg");
            wxTreeItemId ConversionesFID = m_tree1 -> AppendItem(ConversionesID, "Fuerza");
                ConFuKn = m_tree1 -> AppendItem(ConversionesFID, "KiloNewton -> N");
                ConFuHn = m_tree1 -> AppendItem(ConversionesFID, "HectoNewton -> N");
                ConFuDan = m_tree1 -> AppendItem(ConversionesFID, "DecaNewton -> N");
                ConFuDn = m_tree1 -> AppendItem(ConversionesFID, "DeciNewton -> N");
                ConFuCn = m_tree1 -> AppendItem(ConversionesFID, "CentiNewton -> N");
                ConFuMn = m_tree1 -> AppendItem(ConversionesFID, "MiliNewton -> N");
            wxTreeItemId ConversionesEID = m_tree1 -> AppendItem(ConversionesID, "Energia");
                ConEnKj = m_tree1 -> AppendItem(ConversionesEID, "KiloJoule -> J");
                ConEnHj = m_tree1 -> AppendItem(ConversionesEID, "HectoJoule -> J");
                ConEnDaj = m_tree1 -> AppendItem(ConversionesEID, "DecaJoule -> J");
                ConEnDj = m_tree1 -> AppendItem(ConversionesEID, "DeciJoule -> J");
                ConEnCj = m_tree1 -> AppendItem(ConversionesEID, "CentiJoule -> J");
                ConEnMj = m_tree1 -> AppendItem(ConversionesEID, "MiliJoule -> J");
            wxTreeItemId ConversionesFrID = m_tree1 -> AppendItem(ConversionesID, "Frecuencia");
                ConFrGhz = m_tree1 -> AppendItem(ConversionesFrID, "Gigahertz -> H");
                ConFrMhz = m_tree1 -> AppendItem(ConversionesFrID, "Megahertz -> H");
            wxTreeItemId ConversionesTempID = m_tree1 -> AppendItem(ConversionesID, "Temperatura");
                ConTempKel = m_tree1 -> AppendItem(ConversionesTempID, "Kelvin -> Centigrados");
                ConTempFah = m_tree1 -> AppendItem(ConversionesTempID, "Fahrenheit -> Centigrados");
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
            TVVel = m_tree1 -> AppendItem(TVID, "Velocidad");
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
        wxTreeItemId PascalID = m_tree1 -> AppendItem(rootId, "Pascal");
            PascalFMay = m_tree1 -> AppendItem(PascalID, "Fuerza Mayor");
            PascalAMay = m_tree1 -> AppendItem(PascalID, "Area Mayor");
            PascalFMen = m_tree1 -> AppendItem(PascalID, "Fuerza Menor");
            PascalAMen = m_tree1 -> AppendItem(PascalID, "Area Menor");
        wxTreeItemId ArquimedesID = m_tree1 -> AppendItem(rootId, "Arquimedes");
            wxTreeItemId ArquimedesIDForm = m_tree1 -> AppendItem(ArquimedesID, "Por formula");
                ArqFormFE = m_tree1 -> AppendItem(ArquimedesIDForm, "Fuerza de empuje");
                ArqFormDens = m_tree1 -> AppendItem(ArquimedesIDForm, "Densidad");
                ArqFormVol = m_tree1 -> AppendItem(ArquimedesIDForm, "Volumen");
            wxTreeItemId ArquimedesIDPes = m_tree1 -> AppendItem(ArquimedesID, "Por los pesos");
                ArqPesFE = m_tree1 -> AppendItem(ArquimedesIDPes, "Fuerza de empuje");
                ArqPesAp = m_tree1 -> AppendItem(ArquimedesIDPes, "Peso aparente");
                ArqPesRe = m_tree1 -> AppendItem(ArquimedesIDPes, "Peso real");
        wxTreeItemId DilatacionID = m_tree1 -> AppendItem(rootId, "Dilatacion");
          DilDil = m_tree1 -> AppendItem(DilatacionID, "Dilatacion");
          DilMedIn = m_tree1 -> AppendItem(DilatacionID, "Medida inicial");
          DilCoef = m_tree1 -> AppendItem(DilatacionID, "Coeficiente de dilatacion");
          DilDelta = m_tree1 -> AppendItem(DilatacionID, "Cambio en la temperatura");
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
    m_btn4_4 -> Disable();
    //
}

void cMain::bloquear(){
    bloqueado = true;
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
  bloqueado = false;
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
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado2(wxCommandEvent& evt){
    m_txt1 -> AppendText("2");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado3(wxCommandEvent& evt){
    m_txt1 -> AppendText("3");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado4(wxCommandEvent& evt){
    m_txt1 -> AppendText("4");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado5(wxCommandEvent& evt){
    m_txt1 -> AppendText("5");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado6(wxCommandEvent& evt){
    m_txt1 -> AppendText("6");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado7(wxCommandEvent& evt){
    m_txt1 -> AppendText("7");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado8(wxCommandEvent& evt){
    m_txt1 -> AppendText("8");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado9(wxCommandEvent& evt){
    m_txt1 -> AppendText("9");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionado0(wxCommandEvent& evt){
    m_txt1 -> AppendText("0");
    m_btn4_1 -> Disable();
    m_btn4_3 -> Enable();
    m_btn4_4 -> Enable();
    longitud++;
    if(longitud >= MAX_DOUBLE) cMain::bloquear();
    else cMain::desbloquear();
    evt.Skip();
}
void cMain::boton_presionadoMenos(wxCommandEvent& evt){
    Menos_Bloqueado = true;
    m_btn4_1 -> Disable();
    m_txt1 -> AppendText("-");
    m_btn4_3 -> Enable();
    evt.Skip();
}
void cMain::boton_presionadoBackSpace(wxCommandEvent& evt){
    char numeros[1024];
    strncpy(numeros, (const char*)m_txt1 -> GetLineText(0).mb_str(wxConvUTF8), 1023);
    int len = strlen(numeros);
    if(numeros[len-1] == '.'){
        m_btn4_5 -> Enable();
        Punto_Bloqueado = false;
    }
    numeros[len-1] = '\0';
    m_txt1 -> ChangeValue(numeros);
    len--;
    if(len < MAX_DOUBLE)
        cMain::desbloquear();
    if(len == 0){
        m_btn4_1 -> Enable();
        m_btn4_3 -> Disable();
        m_btn4_4 -> Disable();
        Menos_Bloqueado = false;
    }
    evt.Skip();
}
void cMain::boton_presionadoPunto(wxCommandEvent& evt){
    m_txt1 -> AppendText(".");
    m_btn4_5 -> Disable();
    m_btn4_3 -> Enable();
    evt.Skip();
}

void cMain::onEnter(){
    char numeros[1024];
    strncpy(numeros, (const char*)m_txt1 -> GetLineText(0).mb_str(wxConvUTF8), 1023);
    if(strlen(numeros) != 0){
      longitud = 0;
      cMain::desbloquear();
      m_btn4_1 -> Enable();
      m_btn4_5 -> Enable();
      m_btn4_4 -> Disable();
      Enter_Bloqueado = false;
      double resultado = 0;
      bool notacion_usado = false;
      if(nArgumentos != 0){
        Argumentos[Argumentos_current] = wxAtof(m_txt1 -> GetValue());
        Argumentos_current++;
        m_txt1 -> Clear();
        if(Argumentos_current == nArgumentos){ //todos los argumentos han sido recibidos
          /*
          * 1 Argumento
          */
          if(IDoperacion == ConDisKm)
            resultado = Conversiones(Argumentos[0], 0, 0);
          else if(IDoperacion == ConDisHm)
            resultado = Conversiones(Argumentos[0], 0, 1);
          else if(IDoperacion == ConDisDam)
            resultado = Conversiones(Argumentos[0], 0, 2);
          else if(IDoperacion == ConDisDm)
            resultado = Conversiones(Argumentos[0], 0, 3);
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
            resultado = Conversiones(Argumentos[0], 5, 5);
          else if(IDoperacion == ConFrGhz)
            resultado = Conversiones(Argumentos[0], 6, 0);
          else if(IDoperacion == ConFrMhz)
            resultado = Conversiones(Argumentos[0], 6, 1);
          else if(IDoperacion == NotConDN){
            notacion_usado = true;
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
          else if(IDoperacion == PesoPes)
            resultado = Peso(INDEF, Argumentos[0], 0);
          else if(IDoperacion == PesoMas)
            resultado = Peso(Argumentos[0], INDEF, 1);
          else if(IDoperacion == ConTempKel)
            resultado = Conversiones(Argumentos[0], 7, 0);
          else if(IDoperacion == ConTempFah)
            resultado = Conversiones(Argumentos[0], 7, 1);
          /*
           * 2 Argumentos
           */
          else if(IDoperacion == NotRC){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], INDEF, INDEF, 2, INDEF));
          }
          else if(IDoperacion == NotConND){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], INDEF, INDEF, 6, 0));
          }
          else if(IDoperacion == MRUVel)
            resultado = MRU(INDEF, Argumentos[0], Argumentos[1], 0);
          else if(IDoperacion == MRUDis)
            resultado = MRU(Argumentos[0], INDEF, Argumentos[1], 1);
          else if(IDoperacion == MRUTie)
            resultado = MRU(Argumentos[1], Argumentos[0], INDEF, 2);
          else if(IDoperacion == FuerFue)
            resultado = Fuerza(Argumentos[0], Argumentos[1], INDEF, 0);
          else if(IDoperacion == FuerMasa)
            resultado = Fuerza(INDEF, Argumentos[1], Argumentos[0], 1);
          else if(IDoperacion == FuerAce)
            resultado = Fuerza(Argumentos[1], INDEF, Argumentos[0], 2);
          else if(IDoperacion == EnePotPot)
            resultado = Energia(Argumentos[0], Argumentos[1], INDEF, INDEF, INDEF, INDEF, 0, 0);
          else if(IDoperacion == EnePotPes)
            resultado = Energia(INDEF, Argumentos[1], INDEF, Argumentos[0], INDEF, INDEF, 0, 1);
          else if(IDoperacion == EnePotAlt)
            resultado = Energia(Argumentos[1], INDEF, INDEF, Argumentos[0], INDEF, INDEF, 0, 2);
          else if(IDoperacion == EneCinCin)
            resultado = Energia(Argumentos[0], INDEF, Argumentos[1], INDEF, INDEF, INDEF, 1, 0);
          else if(IDoperacion == EneCinMas)
            resultado = Energia(INDEF, INDEF, Argumentos[1], INDEF, Argumentos[0], INDEF, 1, 1);
          else if(IDoperacion == EneCinVel)
            resultado = Energia(Argumentos[1], INDEF, INDEF, INDEF, Argumentos[0], INDEF, 1, 2);
          else if(IDoperacion == EneMecMec)
            resultado = Energia(INDEF, INDEF, INDEF, Argumentos[0], Argumentos[1], INDEF, 2, 0);
          else if(IDoperacion == EneMecPot)
            resultado = Energia(INDEF, INDEF, INDEF, INDEF, Argumentos[1], Argumentos[0], 2, 1);
          else if(IDoperacion == EneMecCin)
            resultado = Energia(INDEF, INDEF, INDEF, Argumentos[1], INDEF, Argumentos[0], 2, 2);
          else if(IDoperacion == TrabTrab)
            resultado = Trabajo(INDEF, Argumentos[0], Argumentos[1], 0);
          else if(IDoperacion == TrabFuer)
            resultado = Trabajo(Argumentos[0], INDEF, Argumentos[1], 1);
          else if(IDoperacion == TrabDis)
            resultado = Trabajo(Argumentos[0], Argumentos[1], INDEF, 2);
          else if(IDoperacion == PotPot)
            resultado = Potencia(INDEF, Argumentos[0], Argumentos[1], 0);
          else if(IDoperacion == PotTrab)
            resultado = Potencia(Argumentos[0], INDEF, Argumentos[1], 1);
          else if(IDoperacion == PotTie)
            resultado = Potencia(Argumentos[0], Argumentos[1], INDEF, 2);
          else if(IDoperacion == PresPresPres)
            resultado = Presion(INDEF, Argumentos[0], Argumentos[1], INDEF, INDEF,
                                INDEF, INDEF, INDEF, 0, 0);
          else if(IDoperacion == PresPresFuer)
            resultado = Presion(Argumentos[0], INDEF, Argumentos[1], INDEF, INDEF,
                                INDEF, INDEF, INDEF, 0, 1);
          else if(IDoperacion == PresPresArea)
            resultado = Presion(Argumentos[1], Argumentos[0], INDEF, INDEF, INDEF,
                                INDEF, INDEF, INDEF, 0, 2);
          else if(IDoperacion == PresHidPres)
            resultado = Presion(INDEF, INDEF, INDEF, Argumentos[0], Argumentos[1],
                                INDEF, INDEF, INDEF, 1, 0);
          else if(IDoperacion == PresHidDens)
            resultado = Presion(Argumentos[0], INDEF, INDEF, INDEF, Argumentos[1],
                                INDEF, INDEF, INDEF, 1, 1);
          else if(IDoperacion == PresHidAlt)
            resultado = Presion(Argumentos[0], INDEF, INDEF, Argumentos[1], INDEF,
                                INDEF, INDEF, INDEF, 1, 2);
          else if(IDoperacion == PresAbsAbs)
            resultado = Presion(INDEF, INDEF, INDEF, INDEF, INDEF,
                                INDEF, Argumentos[1], Argumentos[0], 2, 0);
          else if(IDoperacion == PresAbsHid)
            resultado = Presion(INDEF, INDEF, INDEF, INDEF, INDEF,
                                Argumentos[0], Argumentos[1], INDEF, 2, 1);
          else if(IDoperacion == PresAbsAtm)
            resultado = Presion(INDEF, INDEF, INDEF, INDEF, INDEF,
                                Argumentos[0], INDEF, Argumentos[1], 2, 2);
          else if(IDoperacion == CLVelF)
            resultado = CaidaLibre(INDEF, Argumentos[1], Argumentos[0], 0);
          else if(IDoperacion == CLAlt)
            resultado = CaidaLibre(Argumentos[0], INDEF, Argumentos[1], 1);
          else if(IDoperacion == ArqFormFE)
            resultado = Arquimedes(INDEF, Argumentos[0], Argumentos[1], INDEF, INDEF, 0, 0);
          else if(IDoperacion == ArqFormDens)
            resultado = Arquimedes(Argumentos[0], INDEF, Argumentos[1], INDEF, INDEF, 0, 1);
          else if(IDoperacion == ArqFormVol)
            resultado = Arquimedes(Argumentos[0], Argumentos[1], INDEF, INDEF, INDEF, 0, 2);
          else if(IDoperacion == ArqPesFE)
            resultado = Arquimedes(INDEF, INDEF, INDEF, Argumentos[0], Argumentos[1], 1, 0);
          else if(IDoperacion == ArqPesAp)
            resultado = Arquimedes(Argumentos[1], INDEF, INDEF, Argumentos[0], INDEF, 1, 1);
          else if(IDoperacion == ArqPesRe)
            resultado = Arquimedes(Argumentos[1], INDEF, INDEF, INDEF, Argumentos[1], 1, 2);
          /*
           * 3 Argumentos
           */
          else if(IDoperacion == LGUFr){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(LGU(INDEF, Argumentos[0], Argumentos[1], Argumentos[2], 0), INDEF, INDEF, INDEF, 6, 1));
          }
          else if(IDoperacion == LGUMa){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(LGU(Argumentos[0], Argumentos[2], INDEF, Argumentos[1], 1), INDEF, INDEF, INDEF, 6, 1));
          }
          else if(IDoperacion == LGUDis){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(LGU(Argumentos[2], Argumentos[0], Argumentos[1], INDEF, 2), INDEF, INDEF, INDEF, 6, 1));
          }
          else if(IDoperacion == NotPot){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], INDEF, Argumentos[2], 5, INDEF));
          }
          else if(IDoperacion == OndasVel)
            resultado = Ondas(Argumentos[0], Argumentos[1], Argumentos[2]);
          else if(IDoperacion == PascalFMay)
            resultado = Pascal(INDEF, Argumentos[0], Argumentos[1], Argumentos[2], 0);
          else if(IDoperacion == PascalAMay)
            resultado = Pascal(Argumentos[0], INDEF, Argumentos[1], Argumentos[2], 1);
          else if(IDoperacion == PascalFMen)
            resultado = Pascal(Argumentos[0], Argumentos[1], INDEF, Argumentos[2], 2);
          else if(IDoperacion == PascalAMen)
            resultado = Pascal(Argumentos[0], Argumentos[1], Argumentos[2], INDEF, 3);
          /*
           * 4 Argumentos
           */
          else if(IDoperacion == NotSum){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 0, INDEF));
          }
          else if(IDoperacion == NotRes){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 1, INDEF));
          }
          else if(IDoperacion == NotMul){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 3, INDEF));
          }
          else if(IDoperacion == NotDiv){
            notacion_usado = true;
            m_txt1 -> SetValue(Notacion(Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 4, INDEF));
          }
          else if(IDoperacion == MRUVAce)
            resultado = MRUV(INDEF, Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 0);
          else if(IDoperacion == MRUVVelF)
            resultado = MRUV(Argumentos[0], INDEF, Argumentos[1], Argumentos[2], Argumentos[3], 1);
          else if(IDoperacion == MRUVVelI)
            resultado = MRUV(Argumentos[0], Argumentos[1], INDEF, Argumentos[2], Argumentos[3], 2);
          else if(IDoperacion == MRUVDis)
            resultado = MRUV(Argumentos[0], Argumentos[1], Argumentos[2], INDEF, Argumentos[3], 3);
          else if(IDoperacion == MRUVTie)
            resultado = MRUV(Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], INDEF, 4);
          else if(IDoperacion == DilDil)
            resultado = Dilatacion(INDEF, Argumentos[0], Argumentos[1], Argumentos[2], Argumentos[3], 0);
          else if(IDoperacion == DilMedIn)
            resultado = Dilatacion(Argumentos[0], INDEF, Argumentos[1], Argumentos[2], Argumentos[3], 1);
          else if(IDoperacion == DilCoef)
            resultado = Dilatacion(Argumentos[0], Argumentos[1], INDEF, Argumentos[2], Argumentos[3], 2);
          else if(IDoperacion == DilDelta)
            resultado = Dilatacion(Argumentos[0], Argumentos[1], Argumentos[2], INDEF, Argumentos[3], 3);
          /*
           *Fin
           */
        if(notacion_usado == false)
          m_txt1 -> SetValue(wxString::Format(wxT("%f"), resultado));
        m_txt2 -> SetValue("La respuesta es:");
        }
        else{ //los argumentos no han sido recibidos por completo aun
          if(IDoperacion == NotRC || IDoperacion == NotConND) //&& Argumentos_current == 2
            m_txt2 -> SetValue("Introduce el exponente");
          else if(IDoperacion == MRUVel || IDoperacion == MRUDis || IDoperacion == PotPot ||
                  IDoperacion == PotTrab)
            m_txt2 -> SetValue("Introduce el tiempo");
          else if(IDoperacion == MRUTie || IDoperacion == EneCinCin || IDoperacion == EneCinMas)
            m_txt2 -> SetValue("Introduce la velocidad");
          else if(IDoperacion == FuerFue || IDoperacion == FuerMasa)
            m_txt2 -> SetValue("Introduce la aceleracion");
          else if(IDoperacion == FuerAce || IDoperacion == EnePotAlt || IDoperacion == EneCinVel)
            m_txt2 -> SetValue("Introduce la masa");
          else if(IDoperacion == EnePotPot || IDoperacion == EnePotPes || IDoperacion == PresHidPres ||
                  IDoperacion == PresHidDens)
            m_txt2 -> SetValue("Introduce la altura");
          else if(IDoperacion == EneMecMec || IDoperacion == EneMecPot)
            m_txt2 -> SetValue("Introduce la energia cinetica");
          else if(IDoperacion == EneMecCin)
            m_txt2 -> SetValue("Introduce la energia potencial");
          else if(IDoperacion == TrabTrab || IDoperacion == TrabFuer)
            m_txt2 -> SetValue("Introduce la distancia");
          else if(IDoperacion == TrabDis)
            m_txt2 -> SetValue("Introduce la fuerza");
          else if(IDoperacion == PotTie)
            m_txt2 -> SetValue("Introduce el trabajo");
          else if(IDoperacion == PresPresPres || IDoperacion == PresPresFuer)
            m_txt2 -> SetValue("Introduce el area");
          else if(IDoperacion == PresPresArea)
            m_txt2 -> SetValue("Introduce la presion");
          else if(IDoperacion == PresHidAlt)
            m_txt2 -> SetValue("Introduce la densidad");
          else if(IDoperacion == PresAbsAbs || IDoperacion == PresAbsHid)
            m_txt2 -> SetValue("Introduce la presion atmosferica");
          else if(IDoperacion == PresAbsAtm)
            m_txt2 -> SetValue("Introduce la presion hidroestatica");
          else if(IDoperacion == CLVelF)
            m_txt2 -> SetValue("Introduce la altura, si no la tienes introduce '-1048576'");
          else if(IDoperacion == CLAlt)
            m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
          else if(IDoperacion == ArqFormFE)
            m_txt2 -> SetValue("Introduce el volumen");
          else if(IDoperacion == ArqFormDens)
            m_txt2 -> SetValue("Introduce el volumen");
          else if(IDoperacion == ArqFormVol)
            m_txt2 -> SetValue("Introduce la densidad");
          else if(IDoperacion == ArqPesFE)
            m_txt2 -> SetValue("Introduce el peso aparente");
          else if(IDoperacion == ArqPesAp)
            m_txt2 -> SetValue("Introduce la fuerza de empuje");
          else if(IDoperacion == ArqPesRe)
            m_txt2 -> SetValue("Introduce la fuerza de empuje");
          /*
           * Requieren mas de 2 argumentos
           */
          else if(IDoperacion == LGUFr){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la segunda masa");
            else
              m_txt2 -> SetValue("Introduce la distancia");
          }
          else if(IDoperacion == LGUMa){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la distancia");
            else
              m_txt2 -> SetValue("Introduce la masa");
          }
          else if(IDoperacion == LGUDis){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la segunda masa");
            else
              m_txt2 -> SetValue("Introduce la fuerza");
          }
          else if(IDoperacion == NotPot){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el exponente del numero");
            else
              m_txt2 -> SetValue("Introduce el exponente de todo");
          }
          else if(IDoperacion == OndasVel){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la longitud, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce la frecuencia, si no la tienes introduce '-1048576'");
          }
          else if(IDoperacion == PascalFMay){
              if(Argumentos_current == 1)
                m_txt2 -> SetValue("Introduce la fuerza menor");
              else
                m_txt2 -> SetValue("Introduce el area menor");
          }
          else if(IDoperacion == PascalAMay){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la fuerza menor");
            else
              m_txt2 -> SetValue("Introduce el area menor");
          }
          else if(IDoperacion == PascalFMen){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el area mayor");
            else
              m_txt2 -> SetValue("Introduce el area menor");
          }
          else if(IDoperacion == PascalAMen){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el area mayor");
            else
              m_txt2 -> SetValue("Introduce la fuerza menor");
          }
          /*
           * Requieren 4 argumentos
           */
          else if(IDoperacion == NotSum || IDoperacion == NotRes ||
                  IDoperacion == NotMul || IDoperacion == NotDiv){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el exponente del primer numero");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce el segundo numero");
            else
              m_txt2 -> SetValue("Introduce el exponente del segundo numero");
          }
          else if(IDoperacion == MRUVAce){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la velocidad inicial, si no la tienes introduce '-1048576'");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce la distancia, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
          }
          else if(IDoperacion == MRUVVelF){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la velocidad inicial, si no la tienes introduce '-1048576'");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce la distancia, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
          }
          else if(IDoperacion == MRUVVelI){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la velocidad final, si no la tienes introduce '-1048576'");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce la distancia, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
          }
          else if(IDoperacion == MRUVDis){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la velocidad final, si no la tienes introduce '-1048576'");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce la velocidad inicial, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
          }
          else if(IDoperacion == MRUVTie){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la velocidad final, si no la tienes introduce '-1048576'");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce la velocidad inicial, si no la tienes introduce '-1048576'");
            else
              m_txt2 -> SetValue("Introduce la distancia, si no la tienes introduce '-1048576'");
          }
          else if(IDoperacion == DilDil){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el coeficiente de dilatacion");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce el cambio en la temperatura");
            else
              m_txt2 -> SetValue("Introduce el numero de dimensiones del objeto");
          }
          else if(IDoperacion == DilMedIn){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce el coeficiente de dilatacion");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce el cambio en la temperatura");
            else
              m_txt2 -> SetValue("Introduce el numero de dimensiones del objeto");
          }
          else if(IDoperacion == DilCoef){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la medida inicial");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce el cambio en la temperatura");
            else
              m_txt2 -> SetValue("Introduce el numero de dimensiones del objeto");
          }
          else if(IDoperacion == DilDelta){
            if(Argumentos_current == 1)
              m_txt2 -> SetValue("Introduce la medida inicial");
            else if(Argumentos_current == 2)
              m_txt2 -> SetValue("Introduce el coeficiente de dilatacion");
            else
              m_txt2 -> SetValue("Introduce Introduce el numero de dimensiones del objeto");
          }
        }
      }
  }
}

void cMain::boton_presionadoEnter(wxCommandEvent& evt){
  cMain::onEnter();
  evt.Skip();
}

void cMain::onTreeSelectionChanged(wxTreeEvent& evt){
    longitud = 0;
    cMain::desbloquear();
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
    IDoperacion == TVVel ||
    IDoperacion == PesoPes ||
    IDoperacion == PesoMas ||
    IDoperacion == ConTempKel ||
    IDoperacion == ConTempFah
  ) {
      nArgumentos = 1;
      Argumentos_current = 0;
      if(IDoperacion == TVAlt || IDoperacion == TVTie)
        m_txt2 -> SetValue("Introduce la velocidad");
      else if(IDoperacion == TVVel)
        m_txt2 -> SetValue("Introduce el tiempo");
      else if(IDoperacion == CLTie)
        m_txt2 -> SetValue("Introduce la altura");
      else if(IDoperacion == PesoPes)
        m_txt2 -> SetValue("Introduce la masa");
      else if(IDoperacion == PesoMas)
        m_txt2 -> SetValue("Introduce el peso");
      else
        m_txt2 -> SetValue("Introduce el numero a convertir");
  }

  if(
    IDoperacion == NotRC ||
    IDoperacion == NotConND ||
    IDoperacion == MRUVel ||
    IDoperacion == MRUDis ||
    IDoperacion == MRUTie ||
    IDoperacion == FuerFue ||
    IDoperacion == FuerMasa ||
    IDoperacion == FuerAce ||
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
    IDoperacion == PresAbsAtm ||
    IDoperacion == CLVelF || //r2, u1
    IDoperacion == CLAlt || //r2, u1
    IDoperacion == ArqFormFE ||
    IDoperacion == ArqFormDens ||
    IDoperacion == ArqFormVol ||
    IDoperacion == ArqPesFE ||
    IDoperacion == ArqPesAp ||
    IDoperacion == ArqPesRe
  ) {
      nArgumentos = 2;
      Argumentos_current = 0;
      if(IDoperacion == NotRC || IDoperacion == NotConND)
        m_txt2 -> SetValue("Introduce el numero sin exponente");
      else if(IDoperacion == MRUVel || IDoperacion == MRUTie)
        m_txt2 -> SetValue("Introduce la distancia");
      else if(IDoperacion == MRUDis)
        m_txt2 -> SetValue("Introduce la velocidad");
      else if(IDoperacion == FuerFue || IDoperacion == EnePotPot || IDoperacion == EneCinCin)
        m_txt2 -> SetValue("Introduce la masa");
      else if(IDoperacion == FuerMasa || IDoperacion == FuerAce ||
              IDoperacion == TrabTrab || IDoperacion == PresPresPres || IDoperacion == PresPresArea)
        m_txt2 -> SetValue("Introduce la fuerza");
      else if(IDoperacion == EnePotPes || IDoperacion == EnePotAlt || IDoperacion == EneMecMec)
        m_txt2 -> SetValue("Introduce la energia potencial");
      else if(IDoperacion == EneCinMas || IDoperacion == EneCinVel)
        m_txt2 -> SetValue("Introduce la energia cinetica");
      else if(IDoperacion == EneMecPot || IDoperacion == EneMecCin)
        m_txt2 -> SetValue("Introduce la energia mecanica");
      else if(IDoperacion == TrabFuer || IDoperacion == TrabDis || IDoperacion == PotPot)
        m_txt2 -> SetValue("Introduce el trabajo");
      else if(IDoperacion == PotTrab || IDoperacion == PotTie)
        m_txt2 -> SetValue("Introduce la potencia");
      else if(IDoperacion == PresPresFuer || IDoperacion == PresHidDens || IDoperacion == PresHidAlt)
        m_txt2 -> SetValue("Introduce la presion");
      else if(IDoperacion == PresHidPres)
        m_txt2 -> SetValue("Introduce la densidad");
      else if(IDoperacion == PresAbsAbs)
        m_txt2 -> SetValue("Introduce la presion hidroestatica");
      else if(IDoperacion == PresAbsHid || IDoperacion == PresAbsAtm)
        m_txt2 -> SetValue("Introduce la presion absoluta");
      else if(IDoperacion == CLVelF)
        m_txt2 -> SetValue("Introduce el tiempo, si no lo tienes introduce '-1048576'");
      else if(IDoperacion == CLAlt)
        m_txt2 -> SetValue("Introduce la velocidad final, si no la tienes introduce '-1048576'");
      else if(IDoperacion == ArqFormFE)
        m_txt2 -> SetValue("Introduce la densidad");
      else if(IDoperacion == ArqFormDens)
        m_txt2 -> SetValue("Introduce la fuerza de empuje");
      else if(IDoperacion == ArqFormVol)
        m_txt2 -> SetValue("Introduce la fuerza de empuje");
      else if(IDoperacion == ArqPesFE)
        m_txt2 -> SetValue("Introduce el peso real");
      else if(IDoperacion == ArqPesAp)
        m_txt2 -> SetValue("Introduce el peso real");
      else if(IDoperacion == ArqPesRe)
        m_txt2 -> SetValue("Introduce el peso aparente");
  }

  if(
    IDoperacion == LGUFr ||
    IDoperacion == LGUMa ||
    IDoperacion == LGUDis ||
    IDoperacion == NotPot ||
    IDoperacion == OndasVel || //r3, u2
    IDoperacion == PascalFMay ||
    IDoperacion == PascalAMay ||
    IDoperacion == PascalFMen ||
    IDoperacion == PascalAMen
  ) {
    nArgumentos = 3;
    Argumentos_current = 0;
    if(IDoperacion == LGUFr)
      m_txt2 -> SetValue("Introduce la primera masa");
    else if(IDoperacion == LGUMa)
      m_txt2 -> SetValue("Introduce la fuerza");
    else if(IDoperacion == LGUDis)
      m_txt2 -> SetValue("Introduce la primera masa");
    else if(IDoperacion == NotPot)
      m_txt2 -> SetValue("Introduce el numero sin exponente");
    else if(IDoperacion == OndasVel)
      m_txt2 -> SetValue("Introduce el periodo, si no lo tienes introduce '-1048576'");
    else if(IDoperacion == PascalFMay)
      m_txt2 -> SetValue("Introduce el area mayor");
    else if(IDoperacion == PascalAMay)
      m_txt2 -> SetValue("Introduce la fuerza mayor");
    else if(IDoperacion == PascalFMen)
      m_txt2 -> SetValue("Introduce la fuerza mayor");
    else if(IDoperacion == PascalAMen)
      m_txt2 -> SetValue("Introuce fuerza mayor");
  }

  if(
    IDoperacion == NotSum ||
    IDoperacion == NotRes ||
    IDoperacion == NotMul ||
    IDoperacion == NotDiv ||
    IDoperacion == MRUVAce || //r4, u3
    IDoperacion == MRUVVelF || //r4, u3
    IDoperacion == MRUVVelI || //r4, u3
    IDoperacion == MRUVDis || //r4, u3
    IDoperacion == MRUVTie || //r4, u3
    IDoperacion == DilDil ||
    IDoperacion == DilMedIn ||
    IDoperacion == DilCoef ||
    IDoperacion == DilDelta
  ) {
    nArgumentos = 4;
    Argumentos_current = 0;
    if(IDoperacion == NotSum || IDoperacion == NotRes ||
       IDoperacion == NotMul || IDoperacion == NotDiv)
      m_txt2 -> SetValue("Introduce el primer numero");
    else if(IDoperacion == MRUVAce)
      m_txt2 -> SetValue("Introduce la velocidad final, si no la tienes introduce '-1048576'");
    else if(IDoperacion == MRUVVelF)
      m_txt2 -> SetValue("Introduce la aceleracion, si no la tienes introduce '-1048576'");
    else if(IDoperacion == MRUVVelI)
      m_txt2 -> SetValue("Introduce la aceleracion, si no la tienes introduce '-1048576'");
    else if(IDoperacion == MRUVDis)
      m_txt2 -> SetValue("Introduce la aceleracion, si no la tienes introduce '-1048576'");
    else if(IDoperacion == MRUVTie)
      m_txt2 -> SetValue("Introduce la aceleracion, si no la tienes introduce '-1048576'");
    else if(IDoperacion == DilDil)
      m_txt2 -> SetValue("Introduce la medida inicial");
    else if(IDoperacion == DilMedIn)
      m_txt2 -> SetValue("Introduce la dilatacion");
    else if(IDoperacion == DilCoef)
      m_txt2 -> SetValue("Introduce la dilatacion");
    else if(IDoperacion == DilDelta)
      m_txt2 -> SetValue("Introduce la dilatacion");
  }
}

void cMain::onKeyPress(wxKeyEvent &evt){
    if(!bloqueado){
      if(evt.GetKeyCode() == 48 || evt.GetKeyCode() == WXK_NUMPAD0){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("0");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 49 || evt.GetKeyCode() == WXK_NUMPAD1){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("1");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 50 || evt.GetKeyCode() == WXK_NUMPAD2){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("2");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 51 || evt.GetKeyCode() == WXK_NUMPAD3){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("3");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 52 || evt.GetKeyCode() == WXK_NUMPAD4){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("4");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 53 || evt.GetKeyCode() == WXK_NUMPAD5){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("5");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 54 || evt.GetKeyCode() == WXK_NUMPAD6){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("6");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 55 || evt.GetKeyCode() == WXK_NUMPAD7){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("7");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 56 || evt.GetKeyCode() == WXK_NUMPAD8){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("8");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 57 || evt.GetKeyCode() == WXK_NUMPAD9){
          Menos_Bloqueado = true;
          Enter_Bloqueado = false;
          m_txt1 -> AppendText("9");
          m_btn4_1 -> Disable();
          m_btn4_3 -> Enable();
          m_btn4_4 -> Enable();
          longitud++;
          if(longitud >= MAX_DOUBLE)
              cMain::bloquear();
          else
              cMain::desbloquear();
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 45 || evt.GetKeyCode() == WXK_NUMPAD_SUBTRACT){
        if(!Menos_Bloqueado){
          m_btn4_1 -> Disable();
          m_txt1 -> AppendText("-");
          m_btn4_3 -> Enable();
          evt.Skip();
          Menos_Bloqueado = true;
        }
      }
      else if(evt.GetKeyCode() == 46 || evt.GetKeyCode() == WXK_NUMPAD_DECIMAL){
        Menos_Bloqueado = true;
        if(!Punto_Bloqueado){
          Punto_Bloqueado = true;
          m_txt1 -> AppendText(".");
          m_btn4_5 -> Disable();
          m_btn4_3 -> Enable();
          evt.Skip();
        }
      }
      else if(evt.GetKeyCode() == WXK_BACK){
          char numeros[1024];
          strncpy(numeros, (const char*)m_txt1 -> GetLineText(0).mb_str(wxConvUTF8), 1023);
          int len = strlen(numeros);
          if(numeros[len-1] == '.'){
              m_btn4_5 -> Enable();
              Punto_Bloqueado = false;
          }
          numeros[len-1] = '\0';
          m_txt1 -> ChangeValue(numeros);
          len--;
          if(len < MAX_DOUBLE)
              cMain::desbloquear();
          if(len == 0){
              m_btn4_1 -> Enable();
              m_btn4_3 -> Disable();
              m_btn4_4 -> Disable();
              Menos_Bloqueado = false;
          }
          evt.Skip();
      }
      else if(evt.GetKeyCode() == 13){
        if(!Enter_Bloqueado)
          cMain::onEnter();
      }
    }
}

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_TREE_SEL_CHANGED(10050, cMain::onTreeSelectionChanged)
    EVT_KEY_DOWN(cMain::onKeyPress)
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
