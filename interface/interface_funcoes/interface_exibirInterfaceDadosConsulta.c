#include "../../global/global.h"
#include "../../cadastro/cadastro.h"
#include "../../validar/validar.h"
#include "../interface.h"

void exibirInterfaceDadosConsulta(int contadorDadosExistentes, Filtro filtroAtual, char stringFiltro[]) {
	int i, j, k;
	char iString[3];
	
	Display *displayCabecalhoAtual;
	
	Display displayItemAtual[2];
	
	int dadosEncontrados = contadorDadosExistentes;
	char *filtro;
	char *copiaFiltro;
	
	int encontrou = 0;
	
	
	switch(tipoConsultaAtual) {
		case 1 :
			displayCabecalhoAtual = displayRefCabecalhoConsultaClientes;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
					if(vetorRefClientes[i] == 1) {
						if(filtroAtual > 0) {
							switch(filtroAtual) {
								case Filtro_Nome:
									if(filtroCadastro(clientes[i].nome, stringFiltro)) continue;
									break;
								case Filtro_Data:
									if(filtroCadastro(clientes[i].dataNascimento, stringFiltro)) continue;
									break;	
							}
							encontrou++;
						}
						
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Cliente[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					if(strlen(clientes[i].nome) > 34) {
						k = 34;
					} else {
						k = strlen(clientes[i].nome);
					}
					for(j = 0; j < k; j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = clientes[i].nome[j];
					}
					if(k != strlen(clientes[i].nome)) {
						displayItemAtual[0].linhaDisplay[16 + k] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+1] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+2] = '.';
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
					if(filtroAtual > 0) {
							switch(filtroAtual) {
								case Filtro_Nome:
									if(filtroCadastro(funcionarios[i].nome, stringFiltro)) continue;
									break;
								case Filtro_Data:
									if(filtroCadastro(funcionarios[i].dataNascimento, stringFiltro)) continue;
									break;
								case Filtro_Status:
									if(filtroCadastro(funcionarios[i].status, stringFiltro)) continue;
									break;
							}
							encontrou++;
						}
						
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
					
					if(strlen(funcionarios[i].nome) > 34) {
						k = 34;
					} else {
						k = strlen(funcionarios[i].nome);
					}
					
					for(j = 0; j < k; j++) {
						displayItemAtual[0].linhaDisplay[27 + j] = funcionarios[i].nome[j];
					}
					
					if(k != strlen(funcionarios[i].nome)) {
						displayItemAtual[0].linhaDisplay[27 + k] = '.';
						displayItemAtual[0].linhaDisplay[27 + k+1] = '.';
						displayItemAtual[0].linhaDisplay[27 + k+2] = '.';
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
					if(filtroAtual > 0) {
							switch(filtroAtual) {
								case Filtro_Nome:
									if(filtroCadastro(fornecedores[i].nomeFantasia, stringFiltro)) continue;
									break;	
							}
							encontrou++;
						}
					
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Fornecedor[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					if(strlen(fornecedores[i].nomeFantasia) > 34) {
						k = 34;
					} else {
						k = strlen(fornecedores[i].nomeFantasia);
					}
					
					for(j = 0; j < k; j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = fornecedores[i].nomeFantasia[j];
					}
					
					if(k != strlen(fornecedores[i].nomeFantasia)) {
						displayItemAtual[0].linhaDisplay[16 + k] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+1] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+2] = '.';
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
		case 4:
			displayCabecalhoAtual = displayRefCabecalhoConsultaProdutos;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			char stringValorUnit[MAX_STRING];
			for(i = 0; i < MAX_VETOR; i++) {
				if(filtroAtual > 0) {
					if(filtroCadastro(produtos[i].nomeProduto, stringFiltro)) continue;
					encontrou++;
				}
				
				if(vetorRefProdutos[i] == 1) {
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Produto[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					if(strlen(produtos[i].nomeProduto) > 60) {
						k = 60;
					} else {
						k = strlen(produtos[i].nomeProduto);
					}
					
					for(j = 0; j < k; j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = produtos[i].nomeProduto[j];
					}
					
					if(k != strlen(produtos[i].nomeProduto)) {
						displayItemAtual[0].linhaDisplay[16 + k] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+1] = '.';
						displayItemAtual[0].linhaDisplay[16 + k+2] = '.';
					}
					
					sprintf(stringValorUnit, "R$ %.2f", produtos[i].valorUnitario);
					for(j = 0; j < strlen(stringValorUnit); j++) {
						displayItemAtual[0].linhaDisplay[82 + j] = stringValorUnit[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			
			break;
		case 5:
			displayCabecalhoAtual = displayRefCabecalhoConsultaProducoes;
			exibirInterfaceCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				if(vetorRefProducoes[i] == 1) {
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayRefConsulta_Producoes[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(producoes[i].data); j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = producoes[i].data[j];
					}
					
					for(j = 0; j < strlen(producoes[i].numCadCliente); j++) {
						displayItemAtual[0].linhaDisplay[30 + j] = producoes[i].numCadCliente[j];
					}
					
					for(j = 0; j < strlen(producoes[i].cpfCliente); j++) {
						displayItemAtual[0].linhaDisplay[40 + j] = producoes[i].cpfCliente[j];
					}
					
					for(j = 0; j < strlen(producoes[i].telefoneCliente); j++) {
						displayItemAtual[0].linhaDisplay[50 + j] = producoes[i].telefoneCliente[j];
					}
					
					for(j = 0; j < strlen(producoes[i].numCadFuncionario); j++) {
						displayItemAtual[0].linhaDisplay[60 + j] = producoes[i].numCadFuncionario[j];
					}
					
					for(j = 0; j < strlen(producoes[i].valorTotal); j++) {
						displayItemAtual[0].linhaDisplay[90 + j] = producoes[i].valorTotal[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			
			break;
		default:
			printf("Não foi possível puxar os dados existentes");
	}
	
	if(contadorDadosExistentes == 0 || (filtroAtual > 0 && encontrou == 0)) {
		for(i = 0; i < 2; i++) {
			printf("%s\n", displayRefConsulta_SemDados[i]);
		}
	}
}
