#include "../../../global/global.h"
#include "../../../validar/validar.h"
#include "../../interface.h"

void exibirInterfaceDadosConsultaProducao(char stringFiltro[]) {
	int i, j, k;
	char iString[3];
	
	Display *displayCabecalhoAtual;
	
	Display displayItemAtual[2];
	
	int dadosEncontrados = calcularDadosExistentes(vetorRefProducoes);
	
	Filtro filtroAtual = 0;
	
	char copiaCPF[11];
	
	if(strstr(stringFiltro, "DATA") != NULL || strstr(stringFiltro, "D ") != NULL) {
		removerCaracteresEspeciais(stringFiltro, true);
		
		char *token = strtok(stringFiltro, " ");
		
		token = strtok(NULL, "");
		strcpy(stringFiltro, token);
		
		if(validarPalavraChave(stringFiltro, "H") || validarPalavraChave(stringFiltro, "HOJE")) receberAnoAtual(stringFiltro);
		
		if(strlen(stringFiltro) < 6) {
			erro = Erro_Filtro_NaoExiste;
			return;
		}
		
		removerCaracteresEspeciais(stringFiltro, false);
		
		completarDataAbreviada(stringFiltro, true);
		
		sprintf(stringFiltro, "%c%c/%c%c/%c%c%c%c", stringFiltro[0], stringFiltro[1], stringFiltro[2], stringFiltro[3], stringFiltro[4], stringFiltro[5], stringFiltro[6], stringFiltro[7]);
		
		int valid = 0;
		for(i = 0; i < MAX_VETOR; i++) {
			if(strcmp(stringFiltro, producoes[i].data) == 0) valid++;
		}
		
		if(valid == 0) {
			erro = Erro_Filtro_NaoExiste;
			return;
		}
		filtroAtual = Filtro_Data;
	} else if(strstr(stringFiltro, "CLIENTE") != NULL || strstr(stringFiltro, "C ")) {
		
		removerCaracteresEspeciais(stringFiltro, true);
		
		char *token = strtok(stringFiltro, " ");
		
		token = strtok(NULL, "");
		strcpy(stringFiltro, token);
		
		escolhaUser = 1;
		if(strlen(stringFiltro) > 4) {
			if(consultarCPFouCNPJ(stringFiltro) < 0) {
				erro = Erro_Filtro_NaoExiste;
				return;
			}
		}
		removerCaracteresEspeciais(stringFiltro, false);
		
		filtroAtual = Filtro_Cliente;
	} else if(strstr(stringFiltro, "FUNCIONARIO") != NULL || strstr(stringFiltro, "F ") != NULL) {
		removerCaracteresEspeciais(stringFiltro, true);
		
		char *token = strtok(stringFiltro, " ");
		
		token = strtok(NULL, "");
		strcpy(stringFiltro, token);
		
		escolhaUser = 2;
		if(strlen(stringFiltro) > 4) {			
			if(consultarCPFouCNPJ(stringFiltro) < 0) {
				erro = Erro_Filtro_NaoExiste;
				return;
			} else {
				for(i = 0; i < MAX_VETOR; i++) {
					if(strcmp(funcionarios[i].cpf, stringFiltro) == 0){
						sprintf(stringFiltro, "%d", i + 1);
						break;
					}
				}
			}
		}
		removerCaracteresEspeciais(stringFiltro, false);
		
		filtroAtual = Filtro_Funcionario;
	}
	
	

	for(i = 0; i < MAX_CABECALHO; i++) {
		printf("%s\n", displayRefCabecalhoConsultaProducoes[i]);
	};

	if(erro > 0) {
		return;
	}
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetorRefProducoes[i] == 1) {
			if(strcmp(stringFiltro, "") != 0) {
				switch(filtroAtual) {
					case Filtro_Data:
						if(strcmp(stringFiltro, producoes[i].data) != 0) {
							continue;
						}
						break;
					case Filtro_Cliente:
						if(strlen(stringFiltro) > 3) {
							strcpy(copiaCPF, producoes[i].cpfCliente);
							removerCaracteresEspeciais(copiaCPF, false);
							
							if(strcmp(stringFiltro, copiaCPF) != 0) {
								continue;
							}
						} else {
							if(strcmp(stringFiltro, producoes[i].numCadCliente) != 0) {
								continue;
							}
						}
						break;
					case Filtro_Funcionario:
						if(strcmp(stringFiltro, producoes[i].numCadFuncionario) != 0) {
							continue;
						}						
						break;
				}
			}
			for(j = 0; j < 2; j++) {
				displayItemAtual[j] = displayRefConsulta_Producoes[j];
			}
			
			sprintf(&iString[0],"%d", i + 1);
			for(j = 0; j < strlen(iString); j++) {
				displayItemAtual[0].linhaDisplay[6 + j] = iString[j];
			}
			
			k = 0;
			for(j = 0; j < strlen(producoes[i].data); j++) {
				if(j == 6 || j == 7) {
					k++;
					continue;
				}
				displayItemAtual[0].linhaDisplay[14 + j - k] = producoes[i].data[j];
			}
			
			for(j = 0; j < strlen(producoes[i].numCadCliente); j++) {
				displayItemAtual[0].linhaDisplay[29 + j] = producoes[i].numCadCliente[j];
			}
			
			for(j = 0; j < strlen(producoes[i].cpfCliente); j++) {
				displayItemAtual[0].linhaDisplay[38 + j] = producoes[i].cpfCliente[j];
			}
			
			for(j = 0; j < strlen(producoes[i].telefoneCliente); j++) {
				displayItemAtual[0].linhaDisplay[55 + j] = producoes[i].telefoneCliente[j];
			}
			
			for(j = 0; j < strlen(producoes[i].numCadFuncionario); j++) {
				displayItemAtual[0].linhaDisplay[77 + j] = producoes[i].numCadFuncionario[j];
			}
			
			calcularValorTotal();
			for(j = 0; j < strlen(producoes[i].valorTotal); j++) {
				displayItemAtual[0].linhaDisplay[90 + j] = producoes[i].valorTotal[j];
			}
			
			for(j = 0; j < 2; j++) {
				printf("%s\n", displayItemAtual[j].linhaDisplay);
			}
		}
	}
	
	if(dadosEncontrados == 0) {
		for(i = 0; i < 2; i++) {
			printf("%s\n", displayRefConsulta_SemDados[i]);
		}
	}
}
