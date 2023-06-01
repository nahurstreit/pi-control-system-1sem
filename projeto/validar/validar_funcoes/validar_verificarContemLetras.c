#include "../../global/global.h"
#include "../validar.h"

bool verificarContemLetras(char pString[]) {
    int i;
    for(i = 0; pString[i] != '\0'; i++) {
        if(isalpha(pString[i])) return true;
    }
    return false;
}
