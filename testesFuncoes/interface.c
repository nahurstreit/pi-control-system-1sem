#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "cadastro.h"
#include "interface.h"

/*
"+----------------------------------------------------------------------------------------------------+",
"|                                                                                                    |",
*/
//16 / 32
				//11 / 63
				//16 /59
				//16 /93
				//19 / 59
				//12 /43 / 94

Display formularioCadastroCliente[13] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome:                                                                      |", //NumCadastro: 16 // Nome: 32 -> 100
	"+----------------------------------------------------------------------------------------------------+", 
	"| [2] CPF:                                   | [3] Data Nasc.:                                       |", //CPF: 11 -> 44 // Data Nasc.: 63 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [4] Telefone:                              | [5] E-mail:                                           |", //Telefone: 16 -> 44 // E-mail: 59 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [6] Endereço:                                                                | [7] Número:         |", //Endereço: 16 -> 78 // Número: 93 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [8] Complemento:                           | [9] Bairro:                                           |", //Complemento: 19 -> 44 // Bairro: 59 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [10] CEP:                 | [11] Cidade:                                     | [12] Estado:        |", //CEP: 12 -> 26 // Cidade: 43 -> 90// Estado: 94 -> 100 
	"+----------------------------------------------------------------------------------------------------+",
};

Display formularioCadastroFuncionario[15] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome:                                                | [2] Status:         |", //NumCadastro: 16-> 19 // Nome: 32 ->  // Status: 93
	"+----------------------------------------------------------------------------------------------------+",
	"| [3] CPF:                        | [4] Data de Nasc.:            | [5] Estado Civil:                |", //CPF: 11 -> 32 // Data de Nasc.: 55 -> 64 // Estado Civil: 86 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [6] Data de Admissão:                       | [7] Salário Base: R$                                 |", //Data de Admissão: 24 -> 44 // Salário Base: 68 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [8] Telefone:                               | [9] E-mail:                                          |", //Telefone: 16 -> 44 // E-mail: 60 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [10] Endereço:                                                               | [11] Número:        |", //Endereço: 17 -> 78 // Número: 94 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [12] Complemento:                           | [13] Bairro:                                         |", //Complemento: 20 -> 44 // Bairro: 61 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [14] CEP:                 | [15] Cidade:                                     | [16] Estado:        |", //CEP: 12 -> 26 // Cidade: 43 -> // Estado: 94 -> 100 
	"+----------------------------------------------------------------------------------------------------+",
};

Display formularioCadastroFornecedor[11] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome Fantasia:                                                             |", //NumCadastro: 16-> 19 // Nome Fantasia: 41 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [2] CNPJ:                    | [3] Telefone:                  | [4] E-mail:                        |", //CNPJ: 12 -> 26 // Telefone: 47 -> 59 // E-mail: 78 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [5] Endereço:                                                                | [6] Número:         |", //Endereço: 16 -> 78 // Número: 93 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [7] Complemento:                           | [8] Bairro:                                           |", //Complemento: 19 -> 44 // Bairro: 59 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [8] CEP:                  | [9] Cidade:                                      | [10] Estado:        |", //CEP: 11-> 26 // Cidade: 42 -> 89// Estado: 94 -> 100 
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefTitulo[3] = {
	"======================================================================================================",
	"||                                                                                                  ||",
	"======================================================================================================",
};

Display displayRefInteracao[3] = {
	"....................................",
	"|                                  |",
	"....................................",
};

Display displayRefOpcoes[] = {
	"Opções",
};

Display displayCabecalhoConsultaClientes[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Nº Cadastro |                Nome                   |       CPF       |          Telefone          |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayCabecalhoConsultaFuncionarios[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"|  Status  | Nº Cadastro |                Nome                   |       CPF       |     Telefone    |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayCabecalhoConsultaFornecedores[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Nº Cadastro |             Nome Fantasia             |      CNPJ       |          Telefone          |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayConsulta_ClienteFornecedor[2] = {
	"|             |                                       |                 |                            |", //7 //16 -> 50
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayConsulta_Funcionario[2] = {
	"|          |             |                                       |                 |                 |", //7 //13 //26 -> 63 // 67 // 86
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefConsulta_SemDados[2] = {
	"|                                     Não há nenhum dado ainda.                                      |", 
	"+----------------------------------------------------------------------------------------------------+",
};

int tamanhoDisplay;
int contadorExistentes = 0;
int *pContadorExistentes = &contadorExistentes;

void exibirInterfaceFormularios(Cliente clientes[], Funcionario funcionarios[], Fornecedor fornecedores[], int *pEscolhaUser, int posicao) {
	int i, j;
	char posicaoString[3];
	Display *pDisplayAtual;
	Display copiaDisplay[20];
	Display *pCopiaDisplay = copiaDisplay;
	
	switch(*pEscolhaUser) {
		case 1:
			tamanhoDisplay = sizeof(formularioCadastroCliente);
			pDisplayAtual = formularioCadastroCliente;
			break;
		case 2:
			tamanhoDisplay = sizeof(formularioCadastroFuncionario);
			pDisplayAtual = formularioCadastroFuncionario;
			break;
		case 3:
			tamanhoDisplay = sizeof(formularioCadastroFornecedor);
			pDisplayAtual = formularioCadastroFornecedor;
			break;
	}
	
	tamanhoDisplay /= sizeof(Display);
	//Transforma a posição passada pelo usuário como int, para string, para conseguir ser exibida ao usuário
	sprintf(&posicaoString[0], "%d", posicao+1);
	
	//Copia os formulários de Display em uma variável do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
		/*Substitui nas linhas do copiaDisplay, em espaços específicos, os conteúdo presentes no vetor de dados. Como o vetor por padrão tem o número zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribuição fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada é atribuido, portanto a linha permanece intacta até que seja adicionada uma string. */
		switch(*pEscolhaUser) {
			case 1:
				//Display Número de cadastro
					for(j = 0; j < strlen(posicaoString); j++) {
						pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
					}
				//Display Nome
					for(j = 0; j < strlen(clientes[posicao].nome); j++) {
						pCopiaDisplay[1].linhaDisplay[32 + j] = clientes[posicao].nome[j];
					}
				//Display CPF
					for(j = 0; j < strlen(clientes[posicao].cpf); j++) {
						pCopiaDisplay[3].linhaDisplay[11 + j] = clientes[posicao].cpf[j];
					}
				//Display Data Nascimento
					for(j = 0; j < strlen(clientes[posicao].dataNascimento); j++) {
						pCopiaDisplay[3].linhaDisplay[63 + j] = clientes[posicao].dataNascimento[j];
					}
				//Display Telefone
					for(j = 0; j < strlen(clientes[posicao].telefone); j++) {
						pCopiaDisplay[5].linhaDisplay[16 + j] = clientes[posicao].telefone[j];
					}
				//Display E-mail
					for(j = 0; j < strlen(clientes[posicao].email); j++) {
						pCopiaDisplay[5].linhaDisplay[59 + j] = clientes[posicao].email[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(clientes[posicao].endereco); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = clientes[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(clientes[posicao].numEndereco); j++) {
						pCopiaDisplay[7].linhaDisplay[93 + j] = clientes[posicao].numEndereco[j];
					}
				//Display Complemento Endereço
					for(j = 0; j < strlen(clientes[posicao].compEndereco); j++) {
						pCopiaDisplay[9].linhaDisplay[19 + j] = clientes[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(clientes[posicao].bairro); j++) {
						pCopiaDisplay[9].linhaDisplay[59 + j] = clientes[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(clientes[posicao].cep); j++) {
						pCopiaDisplay[11].linhaDisplay[12 + j] = clientes[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(clientes[posicao].cidade); j++) {
						pCopiaDisplay[11].linhaDisplay[43 + j] = clientes[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(clientes[posicao].estado); j++) {
						pCopiaDisplay[11].linhaDisplay[94 + j] = clientes[posicao].estado[j];
					}
				break;
			case 2:				
				//Display Número de cadastro
				for(j = 0; j < strlen(posicaoString); j++) {
					pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
				}
				//Display nome
					for(j = 0; j < strlen(funcionarios[posicao].nome); j++) {
						pCopiaDisplay[1].linhaDisplay[32 + j] = funcionarios[posicao].nome[j];
					}
				//Display Status
					for(j = 0; j < strlen(funcionarios[posicao].estadoEmpresa); j++) {
						pCopiaDisplay[1].linhaDisplay[93 + j] = funcionarios[posicao].estadoEmpresa[j];
					}
				//Display CPF
					for(j = 0; j < strlen(funcionarios[posicao].cpf); j++) {
						pCopiaDisplay[3].linhaDisplay[11 + j] = funcionarios[posicao].cpf[j];
					}				
				//Display Data Nascimento
					for(j = 0; j < strlen(funcionarios[posicao].dataNascimento); j++) {
						pCopiaDisplay[3].linhaDisplay[55 + j] = funcionarios[posicao].dataNascimento[j];
					}
				//Display Estado Civil
					for(j = 0; j < strlen(funcionarios[posicao].estadoCivil); j++) {
						pCopiaDisplay[3].linhaDisplay[86 + j] = funcionarios[posicao].estadoCivil[j];
					}
				//Display Data Admissão				
					for(j = 0; j < strlen(funcionarios[posicao].dataAdmissao); j++) {
						pCopiaDisplay[5].linhaDisplay[24 + j] = funcionarios[posicao].dataAdmissao[j];
					}
				//Display Salário Base: 
					for(j = 0; j < strlen(funcionarios[posicao].salarioBase); j++) {
						pCopiaDisplay[5].linhaDisplay[68 + j] = funcionarios[posicao].salarioBase[j];
					}
				//Display Telefone:
					for(j = 0; j < strlen(funcionarios[posicao].telefone); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = funcionarios[posicao].telefone[j];
					}
				//Display E-mail:
					for(j = 0; j < strlen(funcionarios[posicao].email); j++) {
						pCopiaDisplay[7].linhaDisplay[60 + j] = funcionarios[posicao].email[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(funcionarios[posicao].endereco); j++) {
						pCopiaDisplay[9].linhaDisplay[17 + j] = funcionarios[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(funcionarios[posicao].numEndereco); j++) {
						pCopiaDisplay[9].linhaDisplay[94 + j] = funcionarios[posicao].numEndereco[j];
					}
				//Display Complemento
					for(j = 0; j < strlen(funcionarios[posicao].compEndereco); j++) {
						pCopiaDisplay[11].linhaDisplay[20 + j] = funcionarios[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(funcionarios[posicao].bairro); j++) {
						pCopiaDisplay[11].linhaDisplay[61 + j] = funcionarios[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(funcionarios[posicao].cep); j++) {
						pCopiaDisplay[13].linhaDisplay[12 + j] = funcionarios[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(funcionarios[posicao].cidade); j++) {
						pCopiaDisplay[13].linhaDisplay[43 + j] = funcionarios[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(funcionarios[posicao].estado); j++) {
						pCopiaDisplay[13].linhaDisplay[94 + j] = funcionarios[posicao].estado[j];
					}
				break;
			case 3:				
				//Display Número de cadastro
					for(j = 0; j < strlen(posicaoString); j++) {
						pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
					}
				//Display Nome
					for(j = 0; j < strlen(fornecedores[posicao].nomeFantasia); j++) {
						pCopiaDisplay[1].linhaDisplay[41 + j] = fornecedores[posicao].nomeFantasia[j];
					}
				//Display CNPJ
					for(j = 0; j < strlen(fornecedores[posicao].cnpj); j++) {
						pCopiaDisplay[3].linhaDisplay[12 + j] = fornecedores[posicao].cnpj[j];
					}
				//Display Telefone
					for(j = 0; j < strlen(fornecedores[posicao].telefone); j++) {
						pCopiaDisplay[3].linhaDisplay[47 + j] = fornecedores[posicao].telefone[j];
					}
				//Display E-mail
					for(j = 0; j < strlen(fornecedores[posicao].email); j++) {
						pCopiaDisplay[3].linhaDisplay[78 + j] = fornecedores[posicao].email[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(fornecedores[posicao].endereco); j++) {
						pCopiaDisplay[5].linhaDisplay[16 + j] = fornecedores[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(fornecedores[posicao].numEndereco); j++) {
						pCopiaDisplay[5].linhaDisplay[93 + j] = fornecedores[posicao].numEndereco[j];
					}
				//Display Complemento Endereço
					for(j = 0; j < strlen(fornecedores[posicao].compEndereco); j++) {
						pCopiaDisplay[7].linhaDisplay[19 + j] = fornecedores[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(fornecedores[posicao].bairro); j++) {
						pCopiaDisplay[7].linhaDisplay[59 + j] = fornecedores[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(fornecedores[posicao].cep); j++) {
						pCopiaDisplay[9].linhaDisplay[11 + j] = fornecedores[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(fornecedores[posicao].cidade); j++) {
						pCopiaDisplay[9].linhaDisplay[42 + j] = fornecedores[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(fornecedores[posicao].estado); j++) {
						pCopiaDisplay[9].linhaDisplay[94 + j] = fornecedores[posicao].estado[j];
					}
				break;
			default:
				printf("Erro ao posicionar os dados no display visual.");
			}	
	
	for(i = 0; i < tamanhoDisplay; i++) {
		printf("%s\n", pCopiaDisplay[i].linhaDisplay);
	}
}


void exibirInterfaceDadosConsulta(Cliente clientes[], int vetorRefClientes[], Funcionario funcionarios[], int vetorRefFuncionarios[], Fornecedor fornecedores[], int vetorRefFornecedores[], int *pEscolhaUser, int contadorDadosExistentes) {
	int i, j;
	char iString[3];
	
	Display *displayCabecalhoAtual;
	
	Display displayItemAtual[2];
	
	int dadosEncontrados = contadorDadosExistentes;
	
	switch(*pEscolhaUser) {
		case 1 :
			displayCabecalhoAtual = displayCabecalhoConsultaClientes;
			exibirCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				
				if(vetorRefClientes[i] == 1) {
	
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayConsulta_ClienteFornecedor[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(clientes[i].nome); j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = clientes[i].nome[j];
					}
					
					for(j = 0; j < strlen(clientes[i].cpf); j++) {
						displayItemAtual[0].linhaDisplay[57 + j] = clientes[i].cpf[j];
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
			displayCabecalhoAtual = displayCabecalhoConsultaFuncionarios;
			exibirCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				if(vetorRefFuncionarios[i] == 1) {
						
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayConsulta_Funcionario[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].estadoEmpresa); j++) {
						displayItemAtual[0].linhaDisplay[13 + j] = funcionarios[i].estadoEmpresa[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].nome); j++) {
						displayItemAtual[0].linhaDisplay[26 + j] = funcionarios[i].nome[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].cpf); j++) {
						displayItemAtual[0].linhaDisplay[63 + j] = funcionarios[i].cpf[j];
					}
					
					for(j = 0; j < strlen(funcionarios[i].telefone); j++) {
						displayItemAtual[0].linhaDisplay[86 + j] = funcionarios[i].telefone[j];
					}
					
					for(j = 0; j < 2; j++) {
						printf("%s\n", displayItemAtual[j].linhaDisplay);
					}
				}
			}
			break;
		case 3:
			displayCabecalhoAtual = displayCabecalhoConsultaFornecedores;
			exibirCabecalhoAtual(displayCabecalhoAtual);
			for(i = 0; i < MAX_VETOR; i++) {
				if(vetorRefFornecedores[i] == 1) {
					
					for(j = 0; j < 2; j++) {
						displayItemAtual[j] = displayConsulta_ClienteFornecedor[j];
					}
					
					sprintf(&iString[0],"%d", i + 1);
					for(j = 0; j < strlen(iString); j++) {
						displayItemAtual[0].linhaDisplay[7 + j] = iString[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].nomeFantasia); j++) {
						displayItemAtual[0].linhaDisplay[16 + j] = fornecedores[i].nomeFantasia[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].cnpj); j++) {
						displayItemAtual[0].linhaDisplay[57 + j] = fornecedores[i].cnpj[j];
					}
					
					for(j = 0; j < strlen(fornecedores[i].telefone); j++) {
						displayItemAtual[0].linhaDisplay[74 + j] = fornecedores[i].telefone[j];
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
	
	if(contadorDadosExistentes == 0) {
		for(i = 0; i < 2; i++) {
			printf("%s\n", displayRefConsulta_SemDados[i]);
		}
	}
}
void exibirCabecalhoAtual(Display *displayCabecalhoAtual) {
	int i;
	for(i = 0; i < MAX_CABECALHO; i++) {
		printf("%s\n", displayCabecalhoAtual[i]);
	};
}

void exibirInterfaceTitulo(char string[], int limpar) {
	int i;
	int tamanhoString = strlen(string);
	int posicaoTitulo = (MAX_LINHA - tamanhoString)/2;
	
	if(limpar == 1) system("cls");  
	
	Display displayCopia[3];
	
	for(i = 0; i < 3; i++) {
		displayCopia[i] = displayRefTitulo[i];
	}
	
	for(i = 0; i < tamanhoString; i++) {
		displayCopia[1].linhaDisplay[posicaoTitulo + i] = string[i]; 
	}
	
	for(i = 0; i < 3; i++) {
		printf("%s\n", displayCopia[i].linhaDisplay);
	}
	printf("\n");
}

void exibirInterfaceInteracao(char string[]) {
	int i;
	int tamanhoString = strlen(string); 
	
	for(i = 0; i < strlen(string) + 4; i++) {
		printf(".");
	}
		printf("\n| %s |\n", string);
	for(i = 0; i < strlen(string) + 4; i++) {
		printf(".");
	}
	
	printf("\n\n");
}

void exibirInterfaceOpcoes(Menu *pMenuAtual) {
	
	int i;
	int numOpcoes = pMenuAtual -> numeroDeOpcoes;
	char stringMeio[10] = " Opções ";
	
	Display displayCopia[1];
	displayCopia[0] = displayRefOpcoes[0];

	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	printf(stringMeio);
	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	
	printf("\n\n");
	for(i = 0; i < numOpcoes; i++) {
		printf(" [%d] - %s\n\n", pMenuAtual -> opcoes[i].numeroDaOpcao, pMenuAtual -> opcoes[i].textoDaOpcao);
	}
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("~");
	}
	
	printf("\n\nOpção: ");
	
}

void exibirTextoMeio(char string[]) {
	int i, tamanhoString = strlen(string);
	
	for(i = 0; i < (MAX_LINHA - tamanhoString)/2; i++) {
		printf(" ");
	}
	printf(string);
	printf("\n");
}

void exibirInterfaceAlerta(char string[]) {
	int i, tamanhoString = strlen(string);
	
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("x");
	}
	printf("\nx");
	for(i = 0; i < MAX_LINHA - 3; i++) {
		printf(" ");
	}
	printf("x\nx");
	for(i = 0; i < ((MAX_LINHA - tamanhoString)/2) - 1; i++) {
		printf(" ");
	}
	printf("%s", string);
	for(i = 0; i < ((MAX_LINHA - tamanhoString)/2) - 2; i++) {
		printf(" ");
	}
	printf("x\nx");
	for(i = 0; i < MAX_LINHA - 3; i++) {
		printf(" ");
	}
	printf("x\n");
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("x");
	}
}
