#include "../../global/global.h"
#include "../../cadastro/cadastro.h"
#include "../../validar/validar.h"
#include "../interface.h"

bool filtroCadastro(char stringComparar[], char stringFiltro[]) {
	char copiaComparar[MAX_STRING];
	strcpy(copiaComparar, stringComparar);
	char copiaFiltro[MAX_STRING];
	strcpy(copiaFiltro, stringFiltro);
	
	int i;
	for(i = 0; i < strlen(stringComparar); i++) {
		copiaComparar[i] = toupper(copiaComparar[i]);
	}
	
	for(i = 0; i < strlen(stringFiltro); i++) {
		copiaFiltro[i] = toupper(copiaFiltro[i]);
	}
	
	char *filtro = strtok(copiaFiltro, " ");
	filtro = strtok(NULL, "");
	char *token;
	
	token = copiaComparar;

	switch(filtroAtual) {
		case Filtro_Data:
			removerCaracteresEspeciais(token, false);
			completarDataAbreviada(filtro, false);
			break;
		default: ;
	}
	if(filtroAtual == Filtro_Status) {
		if(strcmp(token, filtro) != 0) {
			return true;
		}
	} else if(!strstr(token, filtro)) {
		return true;
	}
	return false;
}
