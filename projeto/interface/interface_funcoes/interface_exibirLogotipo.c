#include "../../global/global.h"
#include "../interface.h"

void exibirLogotipo() {
	int i;
	
	for(i = 0; i < 6;i++) {
		printf("%s\n", displayRefLogoTipo[i]);
	}

}
