#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceCabecalhoAtual(Display *displayCabecalhoAtual) {
	int i;
	for(i = 0; i < MAX_CABECALHO; i++) {
		printf("%s\n", displayCabecalhoAtual[i]);
	};
}
