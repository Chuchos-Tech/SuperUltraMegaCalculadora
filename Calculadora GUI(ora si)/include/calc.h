#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

char *strapp(char *str, char c){
    switch(c){
        case '0':
            strcat(str, "0");
            break;
        case '1':
            strcat(str, "1");
            break;
        case '2':
            strcat(str, "2");
            break;
        case '3':
            strcat(str, "3");
            break;
        case '4':
            strcat(str, "4");
            break;
        case '5':
            strcat(str, "5");
            break;
        case '6':
            strcat(str, "6");
            break;
        case '7':
            strcat(str, "7");
            break;
        case '8':
            strcat(str, "8");
            break;
        case '9':
            strcat(str, "9");
            break;
        case '.':
            strcat(str, ".");
            break;
    }
    return str;
}

#endif
