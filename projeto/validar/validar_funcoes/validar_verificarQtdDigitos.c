#include "../../global/global.h"
#include "../validar.h"

bool verificarQtdDigitos(char *pString, int quantidade) {
    int i, contadorDigitos = 0;

    for (i = 0; pString[i] != '\0'; i++) {
        if (isdigit(pString[i])) {
            contadorDigitos++;
        }
    }

    return contadorDigitos == quantidade;
}
