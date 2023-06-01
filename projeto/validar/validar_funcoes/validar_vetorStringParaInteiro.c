#include "../../global/global.h"
#include "../validar.h"

void vetorStringParaInteiro(char *pString, int *pVetorIntDestino, int qtdChar) {
    int i;
    for (i = 0; i < qtdChar; i++) {
        pVetorIntDestino[i] = pString[i] - '0';
    }
}
