#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"
#include "cadastro.h"
#include "interface.h"


//Cria��o da vetor com nome camposCliente que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Cliente
TextoCampo camposCliente[] = {
	"o nome do cliente",
	"o CPF",
	"a data de nascimento",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Cria��o da vetor com nome camposFuncionario que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Funcion�rio
TextoCampo camposFuncionario[] = {
	"o nome do funcion�rio",
	"o estado na empresa",
	"o CPF",
	"a data de nascimento",
	"o estado civil",
	"a data de admiss�o",
	"o salario base (R$)",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Cria��o da vetor com nome camposFornecedor que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Fornecedor
TextoCampo camposFornecedor[] = {
	"o nome fantasia",
	"o CNPJ",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Cria��o da vari�vel global camposAtuais, do tipo TextoCamp, que ser� um pointer para os camposFuncionario, camposCliente ou camposFornecedor
TextoCampo *camposAtuais;

//Cria��o dos vetores para armazenar e controlar o armazenamento dos clientes
	//Vetor de dados
		Cliente clientes[MAX_VETOR];
	//
	
	//Vetor de refer�ncia
		int vetorRefClientes[MAX_VETOR] = {0};
		int *pVetorRefClientes = vetorRefClientes; 	//Pointer para o vetor de refer�ncia
	//
//
//Cria��o dos vetores para armazenar e controlar o armazenamento dos funcion�rios
	//Vetor de dados
		Funcionario funcionarios[MAX_VETOR];
	//

	//Vetor de refer�ncia
		int vetorRefFuncionarios[MAX_VETOR] = {0};
		int *pVetorRefFuncionarios = vetorRefFuncionarios;
	//
//
//Cria��o dos vetores para armazenar e controlar o armazenamento dos fornecedores
	//Vetor de dados
		Fornecedor fornecedores[MAX_VETOR];
	//

	//Vetor de refer�ncia
		int vetorRefFornecedores[MAX_VETOR] = {0};
		int *pVetorRefFornecedores = vetorRefFornecedores;
	//
//

int tipoConsultaAtual;
int *pTipoConsultaAtual = &tipoConsultaAtual;
int posicaoConsultaAtual;

//Fun��o de execu��o cria��o de novoCadastro. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
int novoCadastro(int *pEscolhaUser, int *pMensagem, int *pErro) {
	char stringHolder[MAX_STRING];
	int posicao, tipoCadastroAtual = 0, contadorCampo, limiteContador = 0;
	int *pContadorCampo = &contadorCampo;
	
	switch(*pEscolhaUser) {//pEscolhaUser vem dentro de menu.c
		case 1:
			camposAtuais = camposCliente;
			posicao = posicaoDisponivel(pVetorRefClientes);
			limiteContador = 12;
			break;
		case 2:
			camposAtuais = camposFuncionario;
			posicao = posicaoDisponivel(pVetorRefFuncionarios);
			limiteContador = 16;
			break;
		case 3:
			camposAtuais = camposFornecedor;
			posicao = posicaoDisponivel(pVetorRefFornecedores);
			limiteContador = 11;
			break;
	}
	
	contadorCampo = 0;
	
	do {
		 if(*pEscolhaUser == 1) exibirInterfaceTitulo("NOVO CADASTRO DE CLIENTE", 1);
		 else if(*pEscolhaUser == 2) exibirInterfaceTitulo("NOVO CADASTRO DE FUNCION�RIO", 1);
		 else exibirInterfaceTitulo("NOVO CADASTRO DE FORNECEDOR", 1);
		
		exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao);
		
		printf("\n\n[%d] Digite %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo);
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		inserirString(*pEscolhaUser, posicao, stringHolder, pContadorCampo);
		contadorCampo++;

	} while(contadorCampo < limiteContador);
	
	exibirInterfaceTitulo("NOVO CADASTRO", 1);
	exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao);
	printf("Enviando Cadastro...");
	getch();
	
	*pMensagem = 1;
}

//Fun��o de exibi��o de cadastros. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
int consultaCadastro(int *pEscolhaUser, int *pMensagem, int *pErro, int *estado) {
	int posicao, contadorDadosExistentes;
	
	tipoConsultaAtual = *pEscolhaUser;
	
	switch(*pEscolhaUser) {
		case 1:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefClientes);
			break;
		case 2:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefFuncionarios);
			break;
		case 3:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefFornecedores);
			break;
	}
	
	do{
		if(*pEscolhaUser == 1) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
		 else if(*pEscolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCION�RIOS", 1);
		 else exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
	
		exibirErro(pErro);
		
		exibirInterfaceDadosConsulta(clientes, vetorRefClientes, funcionarios, vetorRefFuncionarios, fornecedores, vetorRefFornecedores, pEscolhaUser, contadorDadosExistentes);
	
		switch(*pEscolhaUser) {
			case 1:
				printf("\nDigite o n�mero de cadastro do Cliente ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefClientes, posicao, pErro);
				break;
			case 2:
				printf("\nDigite o n�mero de cadastro do Funcion�rio ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefFuncionarios, posicao, pErro);
				break;
			case 3:
				printf("\nDigite o n�mero de cadastro do Fornecedor ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefFornecedores, posicao, pErro);
				break;
			default:
				 *pErro = 3;
		}
		
		posicaoConsultaAtual = posicao-1;
		
		if(*pErro == 0) {
			if(*pEscolhaUser == 1) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
		 	else if(*pEscolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCION�RIOS", 1);
		 	else exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
			exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao-1);
			*estado = 1;
			break;
		}
		
		if(posicao == 0) {
			*pErro = 0;
			*estado = 0;
			break;
		}
		
		fflush(stdin);
	} while(*pErro == 4);
}

void inserirString(int tipoCadastro, int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
	switch(tipoCadastro) {
		case 1:
			switch(*contadorCampo) {
				case 0:
					strcpy(clientes[posicaoDisponivel].nome, string);
					break;
				case 1:
					strcpy(clientes[posicaoDisponivel].cpf, string);
					break;
				case 2:
					strcpy(clientes[posicaoDisponivel].dataNascimento, string);
					break;
				case 3 :
					strcpy(clientes[posicaoDisponivel].telefone, string);
					break;
				case 4:
					strcpy(clientes[posicaoDisponivel].email, string);
					break;	
				case 5:
					strcpy(clientes[posicaoDisponivel].endereco, string);
					break;
				case 6:
					strcpy(clientes[posicaoDisponivel].numEndereco, string);
					break;
				case 7:
					strcpy(clientes[posicaoDisponivel].compEndereco, string);
					break;
				case 8:
					strcpy(clientes[posicaoDisponivel].bairro, string);
					break;
				case 9:
					strcpy(clientes[posicaoDisponivel].cep, string);
					break;
				case 10:
					strcpy(clientes[posicaoDisponivel].cidade, string);
					break;
				default:
					strcpy(clientes[posicaoDisponivel].estado, string);
			}
			break;
		case 2:
			switch(*contadorCampo) {
				case 0:
					strcpy(funcionarios[posicaoDisponivel].nome, string);
					break;
				case 1:
					strcpy(funcionarios[posicaoDisponivel].estadoEmpresa, string);
					break;				
				case 2:
					strcpy(funcionarios[posicaoDisponivel].cpf, string);
					break;
				case 3:
					strcpy(funcionarios[posicaoDisponivel].dataNascimento, string);
					break;
				case 4:
					strcpy(funcionarios[posicaoDisponivel].estadoCivil, string);
					break;
				case 5:
					strcpy(funcionarios[posicaoDisponivel].dataAdmissao, string);
					break;
				case 6:
					strcpy(funcionarios[posicaoDisponivel].salarioBase, string);
					break;
				case 7:
					strcpy(funcionarios[posicaoDisponivel].telefone, string);
					break;
				case 8:
					strcpy(funcionarios[posicaoDisponivel].email, string);
					break;	
				case 9:
					strcpy(funcionarios[posicaoDisponivel].endereco, string);
					break;
				case 10:
					strcpy(funcionarios[posicaoDisponivel].numEndereco, string);
					break;
				case 11:
					strcpy(funcionarios[posicaoDisponivel].compEndereco, string);
					break;
				case 12:
					strcpy(funcionarios[posicaoDisponivel].bairro, string);
					break;
				case 13:
					strcpy(funcionarios[posicaoDisponivel].cep, string);
					break;
				case 14:
					strcpy(funcionarios[posicaoDisponivel].cidade, string);
					break;
				default: 
					strcpy(funcionarios[posicaoDisponivel].estado, string);
			}
			break;
		case 3:
			switch(*contadorCampo) {
				case 0:
					strcpy(fornecedores[posicaoDisponivel].nomeFantasia, string);
					break;
				case 1:
					strcpy(fornecedores[posicaoDisponivel].cnpj, string);
					break;
				case 2:
					strcpy(fornecedores[posicaoDisponivel].telefone, string);
					break;
				case 3:
					strcpy(fornecedores[posicaoDisponivel].email, string);
					break;
				case 4:
					strcpy(fornecedores[posicaoDisponivel].endereco, string);
					break;
				case 5:
					strcpy(fornecedores[posicaoDisponivel].numEndereco, string);
					break;
				case 6:
					strcpy(fornecedores[posicaoDisponivel].compEndereco, string);
					break;
				case 7:
					strcpy(fornecedores[posicaoDisponivel].bairro, string);
					break;
				case 8:
					strcpy(fornecedores[posicaoDisponivel].cep, string);
					break;
				case 9:
					strcpy(fornecedores[posicaoDisponivel].cidade, string);
					break;
				default: 
					strcpy(fornecedores[posicaoDisponivel].estado, string);
			}
			break;
	}
}

void verificarDadosVetorDisponivel(int *pEscolhaUser, int *vetorReferencia, int posicao, int *pErro) {
	posicao -= 1;
	
	if(vetorReferencia[posicao] == 0) {
		*pErro = 4;
	} else {
		exibirErro(pErro);
	}
}

int posicaoDisponivel(int *vetorReferencia) {
	int i;
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetorReferencia[i] == 0) {
			vetorReferencia[i] = 1;
			break;
		}
	}
	
	return i;
}

int calcularDadosExistentes(int vetor[MAX_VETOR]) {
	int i, contadorDadosExistentes = 0;
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetor[i] == 1) {
			contadorDadosExistentes++;
		}
	}
	
	return contadorDadosExistentes;
}

void alterarCadastro(int *pEscolhaUser, int *pMensagem, int *pErro) {
	char stringNova[MAX_STRING];
	
	int escolhaCampo = 0;
	int *pEscolhaCampo = &escolhaCampo;
	
	exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pTipoConsultaAtual, posicaoConsultaAtual);
	
	printf("\n\nTipo Consulta atual: %d, posicaoConsulta: %d\n\n", tipoConsultaAtual, posicaoConsultaAtual);
	printf("Digite o n�mero do campo que voc� quer alterar: ");
	scanf("%d", &escolhaCampo);
	fflush(stdin);
	
	escolhaCampo -= 1;
	
	printf("Digite o novo valor do campo: ");
	fgets(stringNova, MAX_STRING, stdin);
	stringNova[strcspn(stringNova, "\n")] = '\0';
	fflush(stdin);
	
	alterarString(tipoConsultaAtual, posicaoConsultaAtual, stringNova, escolhaCampo);
	exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTRO", 1);
	exibirInterfaceInteracao("Sucesso! Campo modificado!");
	exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pTipoConsultaAtual, posicaoConsultaAtual);
}

void alterarString(int tipoConsulta, int posicao, char stringNova[MAX_STRING], int campo) {
	switch(tipoConsulta) {
		case 1:
			switch(campo) {
				case 0:
					strcpy(clientes[posicao].nome, stringNova);
					break;
				case 1:
					strcpy(clientes[posicao].cpf, stringNova);
					break;
				case 2:
					strcpy(clientes[posicao].dataNascimento, stringNova);
					break;
				case 3 :
					strcpy(clientes[posicao].telefone, stringNova);
					break;
				case 4:
					strcpy(clientes[posicao].email, stringNova);
					break;	
				case 5:
					strcpy(clientes[posicao].endereco, stringNova);
					break;
				case 6:
					strcpy(clientes[posicao].numEndereco, stringNova);
					break;
				case 7:
					strcpy(clientes[posicao].compEndereco, stringNova);
					break;
				case 8:
					strcpy(clientes[posicao].bairro, stringNova);
					break;
				case 9:
					strcpy(clientes[posicao].cep, stringNova);
					break;
				case 10:
					strcpy(clientes[posicao].cidade, stringNova);
					break;
				default:
					strcpy(clientes[posicao].estado, stringNova);
			}
			break;
		case 2:
			switch(campo) {
				case 0:
					strcpy(funcionarios[posicao].nome, stringNova);
					break;
				case 1:
					strcpy(funcionarios[posicao].estadoEmpresa, stringNova);
					break;				
				case 2:
					strcpy(funcionarios[posicao].cpf, stringNova);
					break;
				case 3:
					strcpy(funcionarios[posicao].dataNascimento, stringNova);
					break;
				case 4:
					strcpy(funcionarios[posicao].estadoCivil, stringNova);
					break;
				case 5:
					strcpy(funcionarios[posicao].dataAdmissao, stringNova);
					break;
				case 6:
					strcpy(funcionarios[posicao].salarioBase, stringNova);
					break;
				case 7:
					strcpy(funcionarios[posicao].telefone, stringNova);
					break;
				case 8:
					strcpy(funcionarios[posicao].email, stringNova);
					break;	
				case 9:
					strcpy(funcionarios[posicao].endereco, stringNova);
					break;
				case 10:
					strcpy(funcionarios[posicao].numEndereco, stringNova);
					break;
				case 11:
					strcpy(funcionarios[posicao].compEndereco, stringNova);
					break;
				case 12:
					strcpy(funcionarios[posicao].bairro, stringNova);
					break;
				case 13:
					strcpy(funcionarios[posicao].cep, stringNova);
					break;
				case 14:
					strcpy(funcionarios[posicao].cidade, stringNova);
					break;
				default: 
					strcpy(funcionarios[posicao].estado, stringNova);
			}
			break;
		case 3:
			switch(campo) {
				case 0:
					strcpy(fornecedores[posicao].nomeFantasia, stringNova);
					break;
				case 1:
					strcpy(fornecedores[posicao].cnpj, stringNova);
					break;
				case 2:
					strcpy(fornecedores[posicao].telefone, stringNova);
					break;
				case 3:
					strcpy(fornecedores[posicao].email, stringNova);
					break;
				case 4:
					strcpy(fornecedores[posicao].endereco, stringNova);
					break;
				case 5:
					strcpy(fornecedores[posicao].numEndereco, stringNova);
					break;
				case 6:
					strcpy(fornecedores[posicao].compEndereco, stringNova);
					break;
				case 7:
					strcpy(fornecedores[posicao].bairro, stringNova);
					break;
				case 8:
					strcpy(fornecedores[posicao].cep, stringNova);
					break;
				case 9:
					strcpy(fornecedores[posicao].cidade, stringNova);
					break;
				default: 
					strcpy(fornecedores[posicao].estado, stringNova);
			}
			break;
	}
}

void executarExcluirCadastro(int tipo, int *pEscolhaUserMod, int *pMensagem, int *pErro) {
	int escolhaAlterar = 0, contadorDadosExistentes = 0;
	
	exibirInterfaceTitulo("ATEN��O!", 1);
	
	switch(*pTipoConsultaAtual) {
		case 1:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefClientes);
			break;
		case 2:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefFuncionarios);
			break;
		case 3:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefFornecedores);
			break;
	}
	
	switch(tipo) {
		case 1:
			exibirInterfaceAlerta("Voc� tem certeza que deseja EXCLUIR o cadastro? Essa decis�o � IRREVERS�VEL!");
			printf("\n\n[1] Sim, tenho certeza!\t\t[2] N�o, deixe-me pensar...\n\n");
			printf("Op��o: ");
			scanf("%d", &escolhaAlterar);
				
				if(escolhaAlterar == 1) {
					excluirCadastro(posicaoConsultaAtual);
					exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTRO", 1);
					exibirInterfaceInteracao("Cadastro exclu�do!");
					exibirInterfaceDadosConsulta(clientes, vetorRefClientes, funcionarios, vetorRefFuncionarios, fornecedores, vetorRefFornecedores, pTipoConsultaAtual, contadorDadosExistentes);
					*pEscolhaUserMod = 0;
					*pMensagem = 3;	
				} else {
					exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTRO", 1);
					exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pTipoConsultaAtual, posicaoConsultaAtual);
					break;
				}
		break;
	}
}

void excluirCadastro(int posicao) {
	switch(tipoConsultaAtual) {
		case 1:
			strcpy(clientes[posicao].nome, "");
			strcpy(clientes[posicao].cpf, "");
			strcpy(clientes[posicao].dataNascimento, "");
			strcpy(clientes[posicao].telefone, "");
			strcpy(clientes[posicao].email, "");
			strcpy(clientes[posicao].endereco, "");
			strcpy(clientes[posicao].numEndereco, "");
			strcpy(clientes[posicao].compEndereco, "");
			strcpy(clientes[posicao].bairro, "");
			strcpy(clientes[posicao].cep, "");
			strcpy(clientes[posicao].cidade, "");
			strcpy(clientes[posicao].estado, "");
			vetorRefClientes[posicao] = 0;
			break;
		case 2:
			strcpy(funcionarios[posicao].nome, "");
			strcpy(funcionarios[posicao].estadoEmpresa, "");
			strcpy(funcionarios[posicao].cpf, "");
			strcpy(funcionarios[posicao].dataNascimento, "");
			strcpy(funcionarios[posicao].estadoCivil, "");
			strcpy(funcionarios[posicao].dataAdmissao, "");
			strcpy(funcionarios[posicao].salarioBase, "");
			strcpy(funcionarios[posicao].telefone, "");
			strcpy(funcionarios[posicao].email, "");
			strcpy(funcionarios[posicao].endereco, "");
			strcpy(funcionarios[posicao].numEndereco, "");
			strcpy(funcionarios[posicao].compEndereco, "");
			strcpy(funcionarios[posicao].bairro, "");
			strcpy(funcionarios[posicao].cep, "");
			strcpy(funcionarios[posicao].cidade, "");
			strcpy(funcionarios[posicao].estado, "");
			vetorRefFuncionarios[posicao] = 0;
			break;
		case 3:
			strcpy(fornecedores[posicao].nomeFantasia, "");
			strcpy(fornecedores[posicao].cnpj, "");
			strcpy(fornecedores[posicao].telefone, "");
			strcpy(fornecedores[posicao].email, "");
			strcpy(fornecedores[posicao].endereco, "");
			strcpy(fornecedores[posicao].numEndereco, "");
			strcpy(fornecedores[posicao].compEndereco, "");
			strcpy(fornecedores[posicao].bairro, "");
			strcpy(fornecedores[posicao].cep, "");
			strcpy(fornecedores[posicao].cidade, "");
			strcpy(fornecedores[posicao].estado, "");
			vetorRefFornecedores[posicao] = 0;
			break;
	}
}


