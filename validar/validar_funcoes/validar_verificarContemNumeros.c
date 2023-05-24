#include "../../global/global.h"
#include "../validar.h"

bool verificarContemNumeros(char pString[]) {
    int i;
    for(i = 0; pString[i] != '\0'; i++) {
        if(isdigit(pString[i])) return true;
    }
    return false;
}
