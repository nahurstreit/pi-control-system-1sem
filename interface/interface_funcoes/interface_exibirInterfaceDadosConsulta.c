#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceDadosConsulta(int contadorDadosExistentes) {
	int i, j;
	char iString[3];
	
	Display *displayCabecalhoAtual;
	
	Display displayItemAtual[2];
	
	int dadosEncontrados = contadorDadosExistentes;
	
	switch(escolhaUser) {
		case 1 :
			displayCabecalhoAtual = displayRefCabecalhoConsultaClientes;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				
				if(vetorRefClientes[i] == 1) {
	
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Cliente[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(clientes[i].nome); j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = clientes[i].nome[j];
					}
					
					for(j = 0; j < strlen(clientes[i].cpf); j++) {
						displayItemAtual[0].linhaDisplay[56 + j] = clientes[i].cpf[j];
					}
					
					for(j = 0; j < strlen(clientes[i].telefone); j++) {
						displayItemAtual[0].linhaDisplay[74 + j] = clientes[i].telefone[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			break;
		case 2:
			displayCabecalhoAtual = displayRefCabecalhoConsultaFuncionarios;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				if(vetorRefFuncionarios[i] == 1) {
						
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Funcionario[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[18 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].status); j++) {
						displayItemAtual[0].linhaDisplay[2 + j] = funcionarios[i].status[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].nome); j++) {
						displayItemAtual[0].linhaDisplay[27 + j] = funcionarios[i].nome[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].cpf); j++) {
						displayItemAtual[0].linhaDisplay[67 + j] = funcionarios[i].cpf[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].telefone); j++) {
						displayItemAtual[0].linhaDisplay[85 + j] = funcionarios[i].telefone[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			break;
		case 3:
			displayCabecalhoAtual = displayRefCabecalhoConsultaFornecedores;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				if(vetorRefFornecedores[i] == 1) {
					
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Fornecedor[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].nomeFantasia); j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = fornecedores[i].nomeFantasia[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].cnpj); j++) {
						displayItemAtual[0].linhaDisplay[56 + j] = fornecedores[i].cnpj[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].telefone); j++) {
						displayItemAtual[0].linhaDisplay[80 + j] = fornecedores[i].telefone[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			break;
		default:
			printf("N�o foi poss�vel puxar os dados existentes");
	}
	
	if(contadorDadosExistentes == 0) {
		for(i = 0; i < 2; i++) {
			printf("%s\n", displayRefConsulta_SemDados[i]);
		}
	}
}