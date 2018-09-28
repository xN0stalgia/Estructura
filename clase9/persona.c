#include "persona.h"

void init(EPersona lista[], int len){
    int i;
    for(i=0; i<len; i++){
        lista[i].isEmpty = 1;
    }
}

int obtenerEspacioLibre(EPersona lista[], int len){
    int i;
    int retorno = -1;

    for(i=0; i<len; i++){
        if(lista[i].isEmpty == 1){
            retorno = i;
            break;
        }
    }
    return retorno;
}


void alta(EPersona lista[], int len){
    int index;

    index = obtenerEspacioLibre(lista, len);

    if(index != -1){
        //hay espacio libre
    }
    else{
        //no hay espacio libre
    }

    return;
}
