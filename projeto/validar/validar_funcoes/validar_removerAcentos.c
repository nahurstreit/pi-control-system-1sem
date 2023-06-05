#include "../../global/global.h"
#include "../validar.h"

void removerAcentos(char *texto) {
    char acentos[] = "באדגהיטךכםלiמןףעץפצתשuûüח";
    char sem_acentos[] = "aaaaaeeeeiiiiiooooouuuuuc";
    int i , j;
    int len = strlen(texto);

    for(i = 0; i < len; i++) {
        for(j = 0; j < strlen(acentos); j++) {
        	printf("%c", texto[i]);
        	printf(" = %c", acentos[j]);
        	system("pause");
            if(texto[i] == acentos[j]) {
            	system("pause");
                texto[i] = sem_acentos[j];
                break;
            }
        }
    }
}
