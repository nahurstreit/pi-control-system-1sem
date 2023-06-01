#include "../../global/global.h"
#include "../validar.h"

typedef struct {
	char sigla[3];
} Estado;

Estado brasil[27] = {
	{"AC"},
	{"AL"},
	{"AP"},
	{"AM"},
	{"BA"},
	{"CE"},
	{"DF"},
	{"ES"},
	{"GO"},
	{"MA"},
	{"MT"},
	{"MS"},
	{"MG"},
	{"PA"},
	{"PB"},
	{"PR"},
	{"PE"},
	{"PI"},
	{"RJ"},
	{"RN"},
	{"RS"},
	{"RO"},
	{"RR"},
	{"SC"},
	{"SP"},
	{"SE"},
	{"TO"},
};

bool validarEstado(char pString[]) {
	int i;
	
	removerCaracteresEspeciais(pString, false);
	pString[2] = '\0';
	
	for(i = 0; i < 2; i++) {
		pString[i] = toupper(pString[i]);
	}
	
	if(verificarContemNumeros(pString)) {
	    erro = Erro_Input_ApenasLetras;
	    return false;
    }
    
    for(i = 0; i < sizeof(brasil); i++){
    	if(strcmp(brasil[i].sigla, pString) == 0) return true;
	}
    
    erro = Erro_Input_Estado_Invalido;
    return false;
}
