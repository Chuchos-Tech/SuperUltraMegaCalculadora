#ifndef _INC_STRING
#include <string.h>
#endif

#ifndef _MATH_H_
#include <math.h>
#endif

#ifndef FIS_H_INCLUDED
#define FIS_H_INCLUDED

const long double GRAV_UNI = 0.0000000000667;
const double gravedad = 9.80665;
char res[1000];

long double Conversiones(long double numero, int seleccion, int seleccion2){
    switch(seleccion){
        case 0:
            switch(seleccion2){
                case 0:
                    numero *= 1000;
                    break;
                case 1:
                    numero *= 100;
                    break;
                case 2:
                    numero *= 10;
                    break;
                case 3:
                    numero *= 0.1;
                    break;
                case 4:
                    numero *= 0.001;
                    break;
                case 5:
                    numero *= 0.0001;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 1:
            switch(seleccion2){
                case 0:
                    numero *= 3600;
                    break;
                case 1:
                    numero *= 60;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 2:
            switch(seleccion2){
                case 0:
                    numero *= 1000;
                    numero /= 3600;
                    break;
                case 1:
                    numero *= 1000;
                    break;
                case 2:
                    numero /= 3600;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 3:
            switch(seleccion2){
                case 0:
                    numero *= 0.1;
                    break;
                case 1:
                    numero *= 0.01;
                    break;
                case 2:
                    numero *= 0.001;
                    break;
                case 3:
                    numero *= 0.0001;
                    break;
                case 4:
                    numero *= 0.00001;
                    break;
                case 5:
                    numero *= 0.000001;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 4:
            switch(seleccion2){
                case 0:
                    numero *= 1000;
                    break;
                case 1:
                    numero *= 100;
                    break;
                case 2:
                    numero *= 10;
                    break;
                case 3:
                    numero *= 0.1;
                    break;
                case 4:
                    numero *= 0.001;
                    break;
                case 5:
                    numero *= 0.0001;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 5:
            switch(seleccion2){
                case 0:
                    numero *= 1000;
                    break;
                case 1:
                    numero *= 100;
                    break;
                case 2:
                    numero *= 10;
                    break;
                case 3:
                    numero *= 0.1;
                    break;
                case 4:
                    numero *= 0.001;
                    break;
                case 5:
                    numero *= 0.0001;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 6:
            switch(seleccion2){
                case 0:
                    numero *= 1000000;
                    break;
                case 1:
                    numero *= 1000000000;
                    break;
                default:
                    return -1048576;
                    break;
            }
            return numero;
            break;
        case 7:
            switch(seleccion2){
                case 0:
                    return numero - 273.15;
                case 1:
                    return (numero - 32) * 5 / 9;
                default:
                    return -1048576;
            }
        default:
            return -1048576;
            break;
    }
}

long double LGU(long double fuerza, long double masa1, long double masa2, long double distancia, int aux) {
    switch (aux) {
        case 0:
            return (GRAV_UNI * masa1 * masa2) / (distancia * distancia);
            break;
        case 1:
            return (fuerza * pow(distancia, 2)) / (masa1 * GRAV_UNI);
            break;
        case 2:
            return sqrt((GRAV_UNI * masa1 * masa2) / fuerza);
            break;
        default:
            return -1048576;
    }
}

char *Notacion(double numero, int exponente, double numero2,  int exponente2, int seleccion, int seleccion2){
    switch (seleccion) {
        case 0: //suma
            if (exponente > 1)
                while (exponente--)
                    numero *= 10;

            else
                while (exponente++)
                    numero /= 10;

            if (exponente2 > 1)
                while (exponente2--)
                    numero2 *= 10;

            else
                while (exponente2++)
                    numero2 /= 10;

            numero += numero2;
            sprintf(res,"%.6f",numero);
            return res;
            break;
        case 1: //resta
            if (exponente > 1)
                while (exponente--)
                    numero *= 10;

            else
                while (exponente++)
                    numero /= 10;

            if (exponente2 > 1)
                while (exponente2--)
                    numero2 *= 10;

            else
                while (exponente2++)
                    numero2 /= 10;

            numero -= numero2;
            sprintf(res,"%.6f",numero);
            return res;
            break;
        case 2: //raiz
            numero = sqrt(numero);
            exponente /= 2;
            sprintf(res, "%.6f*10^%d", numero, exponente);
            return res;
            break;
        case 3: //multiplicacion
            {
            numero *= numero2;
            exponente += exponente2;
            sprintf(res, "%.6f*10^%d", numero, exponente);
            return res;
            break;
            }
        case 4: //division
            {
            numero /= numero2;
            exponente -= exponente2;
            sprintf(res, "%.6f*10^%d", numero, exponente);
            return res;
            break;
            }
        case 5: //potenciacion
            {
            numero = pow(numero, exponente2);
            exponente *= exponente2;
            sprintf(res, "%.6f*10^%d", numero, exponente);
            return res;
            break;
            }
        case 6: //conversiones
            {
            exponente2 = 0;
            switch (seleccion2) {
            case 1:
                {
                if (numero == 0) {
                    sprintf(res, "-1048576");
                    return res;
                }
                if (numero > 1) {//conversion de arriba hacia abajo
                    while (numero > 1) {
                        numero /= 10;
                        exponente2++;
                    }
                    numero *= 10;
                    exponente2--;
                    sprintf(res, "%.5f*10^%d", numero, exponente2);
                    return res;
                }
                else {//abajo hacia arriba
                    while (numero < 1) {
                        numero *= 10;
                        exponente2--;
                    }
                    sprintf(res, "%.5f*10^%d", numero, exponente2);
                    return res;
                }
                }
            case 0:
                {
                if (exponente < 0) {
                    for (int aux = exponente; aux != 0; aux++) {
                        numero /= 10;
                    }
                }
                else {
                    for (int aux = exponente; aux != 0; aux--) {
                        numero *= 10;
                        printf("hola\n");
                    }
                }
                printf("%.6f", numero);
                sprintf(res, "%.6f", numero);
                return res;
                }
            default:
                sprintf(res, "-1048576");
                return res;
            }
            }
        default:
            sprintf(res,"-1048576");
            return res;
            break;
    }
}

long double MRU(long double velocidad, long double distancia, long double tiempo, int seleccion){
    switch(seleccion) {
        case 0:
            velocidad = distancia /= tiempo;
            return velocidad;
        case 1:
            distancia = velocidad *= tiempo;
            return distancia;
        case 2:
            tiempo = distancia /= velocidad;
            return tiempo;
        default:
            return -1048576;
    }
}

long double MRUV(long double aceleracion, long double vel_final, long double vel_inicial, long double distancia, long double tiempo, int seleccion){
    switch(seleccion){
        case 0:
            {
            if(aceleracion != -1048576){
                return aceleracion;
            }
            if(vel_final != -1048576){
                if(distancia != -1048576){
                    aceleracion = (pow(vel_final, 2) - pow(vel_inicial, 2)) / distancia / 2;
                }
                else{
                    aceleracion = vel_final - vel_inicial / tiempo;
                }
            }
            else{
                aceleracion = vel_inicial * tiempo / (pow(tiempo, 2));
            }
            return aceleracion;
            }
        case 1:
            {
            if(vel_final  != -1048576){
                return vel_final;
            }
            if(tiempo != -1048576){
                vel_final = vel_inicial += aceleracion *= tiempo;
            }
            else{
                vel_final = sqrt(pow(vel_inicial, 2) + 2 * aceleracion * distancia);
            }
            return vel_final;
            }
        case 2:
            {
            if(vel_inicial != -1048576){
                return vel_inicial;
            }
            if(vel_final != -1048576){
                if(aceleracion != -1048576){
                    if(distancia != -1048576){
                        vel_inicial = sqrt(pow(vel_final, 2) - 2 * aceleracion * distancia);
                    }
                    else{
                        vel_inicial = vel_final - (aceleracion * tiempo);
                    }
                }
                else{
                    vel_inicial = 2 * (distancia / tiempo) - vel_final;
                }
            }
            else{
                vel_inicial = distancia / tiempo - (aceleracion * tiempo / 2);
            }
            return vel_inicial;
            }
        case 3:
            {
            if(distancia != -1048576){
                return distancia;
            }
            if(vel_final != -1048576){
                if(tiempo != -1048576){
                    distancia = (vel_inicial + vel_final) / 2 * tiempo;
                }
                else{
                    distancia = (pow(vel_final, 2) - pow(vel_inicial, 2)) / 2 * aceleracion;
                }
            }
            else if(vel_inicial != -1048576){
                distancia = vel_inicial * tiempo + pow(aceleracion * tiempo * 0.5, 2);
            }
            else
                distancia = vel_final * tiempo - pow(aceleracion * tiempo * 0.5, 2);
            return distancia;
            }
        case 4:
            {
            if(tiempo != -1048576){
                return tiempo;
            }
            if(vel_inicial == -1048576 || vel_final == -1048576)
                return sqrt(-4);
            if(aceleracion != -1048576){
                tiempo = (vel_final - vel_inicial) / aceleracion;
            }
            else{
                tiempo = ((vel_final + vel_inicial) / 2) * distancia;
            }
            return tiempo;
            }
        default:
            {
            return -1048576;
            }
    }
}

long double Ondas(long double periodo, long double longitud, long double frecuencia){
    if(periodo != -1048576){
        return longitud / periodo;
    }
    else{
        return frecuencia * longitud;
    }
}

long double CaidaLibre(long double vel_final, long double altura, long double tiempo, int seleccion){
    switch(seleccion){
        case 0:
            if(vel_final != -1048576){
                return vel_final;
            }
            if(tiempo != -1048576){
                vel_final = tiempo * gravedad;
            }
            else if(altura != -1048576){
                vel_final = sqrt(2 * altura * gravedad);
            }
            return vel_final;
        case 1:
            if(altura != -1048576){
                return altura;
            }
            if(vel_final != -1048576){
                altura = pow(vel_final, 2) / (2 * gravedad);
            }
            else{
                altura = gravedad * pow(tiempo, 2) / 2;
            }
            return altura;
        case 2:
            if(tiempo != -1048576){
                return tiempo;
            }
            tiempo = sqrt(2 * altura / gravedad);
            return tiempo;
        default:
            return -1048576;
    }
}

long double TiroVertical(long double altura, long double tiempo, long double vel_inicial, int seleccion){
    switch(seleccion){
        case 0:
            if(altura != -1048576){
                return altura;
            }
            return pow(vel_inicial, 2) / (2 * -gravedad) * -2;
        case 1:
            if(tiempo != -1048576){
                return tiempo;
            }
            tiempo = -vel_inicial / -gravedad;
            return tiempo;
        case 2:
            if(vel_inicial != -1048576){
                return vel_inicial;
            }
            vel_inicial = -1 * (-gravedad * tiempo);
            return vel_inicial;
        default:
            return -1048576;
    }
}

long double Fuerza(long double masa, long double aceleracion, long double fuerza, int seleccion){
    switch(seleccion){
        case 0:
            fuerza = masa * aceleracion;
            return fuerza;
        case 1:
            masa = fuerza / aceleracion;
            return masa;
        case 2:
            aceleracion = fuerza / masa;
            return aceleracion;
        default:
            return -1048576;
    }
}

long double Peso(long double peso, long double masa, int seleccion){
    switch(seleccion){
        case 0:
            peso = masa * gravedad;
            return peso;
        case 1:
            masa = peso / gravedad;
            return masa;
        default:
            return -1048576;
    }
}

long double Energia(long double masa, long double altura, long double velocidad, long double enpot,
                    long double encin, long double enmec, int seleccion, int seleccion2){
    switch(seleccion){
        case 0:
            {
            switch(seleccion2){
                case 0:
                    enpot = masa * altura * gravedad;
                    return enpot;
                case 1:
                    masa = enpot / (altura * gravedad);
                    return masa;
                case 2:
                    altura = enpot / (masa * gravedad);
                    printf("%Lf %Lf\n", enpot, masa);
                    return altura;
                default:
                    return -1048576;
            }
            }
        case 1:
            {
            switch(seleccion2){
                case 0:
                    encin = masa * pow(velocidad, 2) / 2;
                    return encin;
                case 1:
                    masa = encin / (pow(velocidad, 2) / 2);
                    return masa;
                case 2:
                    velocidad = sqrt(encin / (masa / 2));
                    return velocidad;
                default:
                    return -1048576;
            }
            }
        case 2:
            {
            switch(seleccion2){
                case 0:
                    return enpot + encin; //enmec
                case 1:
                    return enmec - encin; //enpot
                case 2:
                    return enmec - enpot; //encin
                default:
                    return -1048576;
            }
            }
        default:
            return -1048576;
    }
}

long double Trabajo(long double trabajo, long double fuerza, long double distancia, int seleccion){
    switch(seleccion){
        case 0:
            trabajo = fuerza * distancia;
            return trabajo;
        case 1:
            fuerza = trabajo / distancia;
            return fuerza;
        case 2:
            distancia = trabajo / fuerza;
            return distancia;
        default:
            return -1048576;
    }
}

long double Potencia(long double potencia, long double trabajo, long double tiempo, int seleccion){
    switch(seleccion){
        case 0:
            return trabajo / tiempo;
        case 1:
            return potencia * tiempo;
        case 2:
            return trabajo / potencia;
        default:
            return -1048576;
    }
}

long double Presion(long double presion, long double fuerza, long double area, long double densidad,
                    long double altura, long double pabs, long double patm, long double phidro,
                    int seleccion, int seleccion2){
    switch(seleccion){
        case 0:
            switch(seleccion2){
                case 0:
                    return fuerza / area;
                case 1:
                    return presion * area;
                case 2:
                    return fuerza / presion;
                default:
                    return -1048576;
            }
        case 1:
            {
            switch(seleccion2){
                case 0:
                    return densidad * altura * gravedad;
                case 1:
                    return presion / (altura * gravedad);
                case 2:
                    return presion / (densidad * gravedad);
                default:
                    return -1048576;
            }
            }
        case 2:
            {
            switch(seleccion2){
                case 0:
                    return phidro + patm;
                case 1:
                    return pabs - patm;
                case 2:
                    return pabs - phidro;
                default:
                    return -1048576;
            }
            }
        default:
            return -1048576;
    }
}

long double Pascal(long double FuerzaMayor, long double AreaMayor, long double FuerzaMenor, long double AreaMenor, int seleccion){
    switch(seleccion){
        case 0:
            FuerzaMayor = (FuerzaMenor * AreaMayor) / AreaMenor;
            return FuerzaMayor;
            break;
        case 1:
            AreaMayor = (FuerzaMayor * AreaMenor) / FuerzaMenor;
            return AreaMayor;
            break;
        case 2:
            FuerzaMenor = (FuerzaMayor * AreaMenor) / AreaMayor;
            return FuerzaMenor;
            break;
        case 3:
            AreaMenor = (FuerzaMenor * AreaMayor) / FuerzaMayor;
            return AreaMenor;
            break;
        default:
            return -1048576;
    }
}

long double Arquimedes(long double FuerzaEmpuje, long double densidad, long double volumen,
                       long double PesoReal, long double PesoAparente, int seleccion, int seleccion2){
    switch(seleccion){
        case 0: //por formula
            switch(seleccion2){
                case 0:
                    FuerzaEmpuje = densidad * volumen * gravedad;
                    return FuerzaEmpuje;
                case 1:
                    densidad = FuerzaEmpuje / (volumen * gravedad);
                    return densidad;
                case 2:
                    volumen = FuerzaEmpuje / (densidad * gravedad);
                    return volumen;
                default:
                    return -1048576;
            }
        case 1: //por los pesos
            switch(seleccion2){
                case 0:
                    FuerzaEmpuje = PesoReal - PesoAparente;
                    return FuerzaEmpuje;
                case 1:
                    PesoAparente = PesoReal - FuerzaEmpuje;
                    return PesoAparente;
                case 2:
                    PesoReal = PesoAparente + FuerzaEmpuje;
                    return PesoReal;
                default:
                    return -1048576;
            }
        default:
            return -1048576;
            break;
    }
}

long double Dilatacion(long double dilatacion, long double medida_inicial, long double coeficiente,
                       long double delta_temp, long double dimensiones, int seleccion){
    trunc(abs(dimensiones));
    coeficiente *= dimensiones;
    switch(seleccion){
        case 0:
            dilatacion = medida_inicial * coeficiente * delta_temp;
            return dilatacion;
        case 1:
            medida_inicial = dilatacion / (coeficiente * delta_temp);
            return medida_inicial;
        case 2:
            coeficiente = (dilatacion / (medida_inicial * delta_temp)) / dimensiones;
            return coeficiente;
        case 3:
            delta_temp = dilatacion / (medida_inicial * coeficiente);
            return delta_temp;
        default:
            return -1048576;
    }
}

#endif
