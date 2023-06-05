#include "../../global/global.h"
#include "../validar.h"

bool validarEntradaVazia(char stringEntrada[]) {
	if(strlen(stringEntrada) == 0) {
		return true;
	}
	return false;
}
