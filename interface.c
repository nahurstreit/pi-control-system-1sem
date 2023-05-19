#include "global/global.h"
#include "interface.h"

Display displayRefFormularioCadastroCliente[13] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome:                                                                      |", //NumCadastro: 16 // Nome: 32 -> 100
	"+----------------------------------------------------------------------------------------------------+", 
	"| [2] CPF:                                   | [3] Data Nasc.:                                       |", //CPF: 11 -> 44 // Data Nasc.: 63 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [4] Telefone:                              | [5] E-mail:                                           |", //Telefone: 16 -> 44 // E-mail: 59 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [6] Endere�o:                                                                | [7] N�mero:         |", //Endere�o: 16 -> 78 // N�mero: 93 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [8] Complemento:                           | [9] Bairro:                                           |", //Complemento: 19 -> 44 // Bairro: 59 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [10] CEP:                 | [11] Cidade:                                     | [12] Estado:        |", //CEP: 12 -> 26 // Cidade: 43 -> 90// Estado: 94 -> 100 
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefFormularioCadastroFuncionario[15] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome:                                                | [2] Status:         |", //NumCadastro: 16-> 19 // Nome: 32 ->  // Status: 93
	"+----------------------------------------------------------------------------------------------------+",
	"| [3] CPF:                        | [4] Data de Nasc.:            | [5] Estado Civil:                |", //CPF: 11 -> 32 // Data de Nasc.: 55 -> 64 // Estado Civil: 86 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [6] Data de Admiss�o:                       | [7] Sal�rio Base: R$                                 |", //Data de Admiss�o: 24 -> 44 // Sal�rio Base: 68 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [8] Telefone:                               | [9] E-mail:                                          |", //Telefone: 16 -> 44 // E-mail: 60 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [10] Endere�o:                                                               | [11] N�mero:        |", //Endere�o: 17 -> 78 // N�mero: 94 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [12] Complemento:                           | [13] Bairro:                                         |", //Complemento: 20 -> 44 // Bairro: 61 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [14] CEP:                 | [15] Cidade:                                     | [16] Estado:        |", //CEP: 12 -> 26 // Cidade: 43 -> // Estado: 94 -> 100 
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefFormularioCadastroFornecedor[11] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| Num Cadastro:     | [1] Nome Fantasia:                                                             |", //NumCadastro: 16-> 19 // Nome Fantasia: 41 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [2] CNPJ:                    | [3] Telefone:                  | [4] E-mail:                        |", //CNPJ: 12 -> 26 // Telefone: 47 -> 59 // E-mail: 78 -> 100
	"+----------------------------------------------------------------------------------------------------+",
	"| [5] Endere�o:                                                                | [6] N�mero:         |", //Endere�o: 16 -> 78 // N�mero: 93 -> 100
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

Display displayRefCabecalhoConsultaClientes[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| N� Cadastro |                Nome                   |       CPF       |          Telefone          |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefCabecalhoConsultaFuncionarios[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"|  Status  | N� Cadastro |                Nome                   |       CPF       |     Telefone    |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefCabecalhoConsultaFornecedores[MAX_CABECALHO] = {
	"+----------------------------------------------------------------------------------------------------+",
	"| N� Cadastro |             Nome Fantasia             |         CNPJ          |       Telefone       |",
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefConsulta_Cliente[2] = {
	"|             |                                       |                 |                            |", //7 //16 -> 50
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefConsulta_Funcionario[2] = {
	"|          |             |                                       |                 |                 |", //7 //13 //26 -> 63 // 67 // 86
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefConsulta_Fornecedor[2] = {
	"|             |                                       |                       |                      |", //7 //16 -> 50
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefConsulta_SemDados[2] = {
	"|                                     N�o h� nenhum dado ainda.                                      |", 
	"+----------------------------------------------------------------------------------------------------+",
};

Display displayRefLogoTipo[] = {
	"                  _____           _       ______                     _               ",
	"                 |  __ \\         | |     |  ____|                   | |             ",
	"                 | |__) |   ___  | |_    | |__      ___    ___    __| |   ___   _ __ ",
	"                 |  ___/   / _ \\ | __|   |  __|    / _ \\  / _ \\  / _` |  / _ \\ | '__|",
	"                 | |      |  __/ | |_    | |      |  __/ |  __/ | (_| | |  __/ | |   ",
	"                 |_|       \\___|  \\__|   |_|       \\___|  \\___|  \\__,_|  \\___| |_|",
	
};

int tamanhoDisplay;
int contadorExistentes = 0;
int *pContadorExistentes = &contadorExistentes;

void exibirInterfaceFormularios(int posicao) {
	int i, j;
	char posicaoString[3];
	Display *pDisplayAtual;
	Display copiaDisplay[20];
	Display *pCopiaDisplay = copiaDisplay;
	
	switch(escolhaUser) {
		case 1:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroCliente);
			pDisplayAtual = displayRefFormularioCadastroCliente;
			break;
		case 2:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroFuncionario);
			pDisplayAtual = displayRefFormularioCadastroFuncionario;
			break;
		case 3:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroFornecedor);
			pDisplayAtual = displayRefFormularioCadastroFornecedor;
			break;
	}
	
	tamanhoDisplay /= sizeof(Display);
	//Transforma a posi��o passada pelo usu�rio como int, para string, para conseguir ser exibida ao usu�rio
	sprintf(&posicaoString[0], "%d", posicao+1);
	
	//Copia os formul�rios de Display em uma vari�vel do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
		/*Substitui nas linhas do copiaDisplay, em espa�os espec�ficos, os conte�do presentes no vetor de dados. Como o vetor por padr�o tem o n�mero zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribui��o fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada � atribuido, portanto a linha permanece intacta at� que seja adicionada uma string. */
		switch(escolhaUser) {
			case 1:
				//Display N�mero de cadastro
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
				//Display Endere�o
					for(j = 0; j < strlen(clientes[posicao].endereco); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = clientes[posicao].endereco[j];
					}
				//Display N�mero Endere�o
					for(j = 0; j < strlen(clientes[posicao].numEndereco); j++) {
						pCopiaDisplay[7].linhaDisplay[93 + j] = clientes[posicao].numEndereco[j];
					}
				//Display Complemento Endere�o
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
				//Display N�mero de cadastro
				for(j = 0; j < strlen(posicaoString); j++) {
					pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
				}
				//Display nome
					for(j = 0; j < strlen(funcionarios[posicao].nome); j++) {
						pCopiaDisplay[1].linhaDisplay[32 + j] = funcionarios[posicao].nome[j];
					}
				//Display Status
					for(j = 0; j < strlen(funcionarios[posicao].status); j++) {
						pCopiaDisplay[1].linhaDisplay[93 + j] = funcionarios[posicao].status[j];
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
				//Display Data Admiss�o				
					for(j = 0; j < strlen(funcionarios[posicao].dataAdmissao); j++) {
						pCopiaDisplay[5].linhaDisplay[24 + j] = funcionarios[posicao].dataAdmissao[j];
					}
				//Display Sal�rio Base: 
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
				//Display Endere�o
					for(j = 0; j < strlen(funcionarios[posicao].endereco); j++) {
						pCopiaDisplay[9].linhaDisplay[17 + j] = funcionarios[posicao].endereco[j];
					}
				//Display N�mero Endere�o
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
				//Display N�mero de cadastro
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
				//Display Endere�o
					for(j = 0; j < strlen(fornecedores[posicao].endereco); j++) {
						pCopiaDisplay[5].linhaDisplay[16 + j] = fornecedores[posicao].endereco[j];
					}
				//Display N�mero Endere�o
					for(j = 0; j < strlen(fornecedores[posicao].numEndereco); j++) {
						pCopiaDisplay[5].linhaDisplay[93 + j] = fornecedores[posicao].numEndereco[j];
					}
				//Display Complemento Endere�o
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

void exibirInterfaceCabecalhoAtual(Display *displayCabecalhoAtual) {
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
	exibirLogotipo();
	
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

void exibirInterfaceOpcoes() {
	int i;
	int numOpcoes = menuAtual.numeroDeOpcoes;
	char stringMeio[10] = " Op��es ";

	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	printf(stringMeio);
	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	
	printf("\n\n");
	for(i = 0; i < numOpcoes; i++) {
		printf(" [%d] - %s\n\n", menuAtual.opcoes[i].numeroDaOpcao, menuAtual.opcoes[i].textoDaOpcao);
	}
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("~");
	}
	
	printf("\n\nOp��o: ");
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

void exibirTextoMeio(char string[]) {
	int i, tamanhoString = strlen(string);
	
	for(i = 0; i < (MAX_LINHA - tamanhoString - 2)/2; i++) {
		printf(" ");
	}
	printf(string);
	printf("\n");
}

void exibirLogotipo() {
	int i;
	
	for(i = 0; i < (sizeof(displayRefLogoTipo) / sizeof(Display));i++) {
		printf("%s\n", displayRefLogoTipo[i]);
	}
	printf("\n");

}