#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "menu.h"
#include "cadastro.h"
#include "interface.h"


//Criação da vetor com nome camposCliente que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Cliente
TextoCampo camposCliente[] = {
	"o nome do cliente",
	"o CPF",
	"a data de nascimento",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Criação da vetor com nome camposFuncionario que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Funcionário
TextoCampo camposFuncionario[] = {
	"o nome do funcionário",
	"o estado na empresa",
	"o CPF",
	"a data de nascimento",
	"o estado civil",
	"a data de admissão",
	"o salario base (R$)",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Criação da vetor com nome camposFornecedor que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Fornecedor
TextoCampo camposFornecedor[] = {
	"o nome fantasia",
	"o CNPJ",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Criação da variável global camposAtuais, do tipo TextoCamp, que será um pointer para os camposFuncionario, camposCliente ou camposFornecedor
TextoCampo *camposAtuais;

//Criação dos vetores para armazenar e controlar o armazenamento dos clientes
	//Vetor de dados
		Cliente clientes[MAX_VETOR];
	//
	
	//Vetor de referência
		int vetorRefClientes[MAX_VETOR] = {0};
		int *pVetorRefClientes = vetorRefClientes; 	//Pointer para o vetor de referência
	//
//
//Criação dos vetores para armazenar e controlar o armazenamento dos funcionários
	//Vetor de dados
		Funcionario funcionarios[MAX_VETOR];
	//

	//Vetor de referência
		int vetorRefFuncionarios[MAX_VETOR] = {0};
		int *pVetorRefFuncionarios = vetorRefFuncionarios;
	//
//
//Criação dos vetores para armazenar e controlar o armazenamento dos fornecedores
	//Vetor de dados
		Fornecedor fornecedores[MAX_VETOR];
	//

	//Vetor de referência
		int vetorRefFornecedores[MAX_VETOR] = {0};
		int *pVetorRefFornecedores = vetorRefFornecedores;
	//
//

//Função de execução criação de novoCadastro. A chamada desse função acontece em menu.c dentro de algumas opções.
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
		 else if(*pEscolhaUser == 2) exibirInterfaceTitulo("NOVO CADASTRO DE FUNCIONÁRIO", 1);
		 else exibirInterfaceTitulo("NOVO CADASTRO DE FORNECEDOR", 1);
		
		exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao);
		
		printf("\n\n[%d] Digite %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo);
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		inserirString(*pEscolhaUser, posicao, stringHolder, pContadorCampo);

	} while(contadorCampo < limiteContador);
	
	exibirInterfaceTitulo("NOVO CADASTRO", 1);
	exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao);
	printf("Enviando Cadastro...");
	getch();
	
	*pMensagem = 1;
}

//Função de exibição de cadastros. A chamada desse função acontece em menu.c dentro de algumas opções.
int consultaCadastro(int *pEscolhaUser, int *pMensagem, int *pErro) {
	int posicao, contadorDadosExistentes;
	
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
		if(*pEscolhaUser == 1) exibirInterfaceTitulo("MODIFICAR CADASTROS DE CLIENTES", 1);
		 else if(*pEscolhaUser == 2) exibirInterfaceTitulo("MODIFICAR CADASTROS DE FUNCIONÁRIOS", 1);
		 else exibirInterfaceTitulo("MODIFICAR CADASTROS DE FORNECEDORES", 1);
	
		exibirErro(pErro);
		
		exibirInterfaceDadosConsulta(clientes, vetorRefClientes, funcionarios, vetorRefFuncionarios, fornecedores, vetorRefFornecedores, pEscolhaUser, contadorDadosExistentes);
	
		switch(*pEscolhaUser) {
			case 1:
				printf("Digite o número de cadastro do Cliente ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefClientes, posicao, pErro);
				break;
			case 2:
				printf("Digite o número de cadastro do Funcionário ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefFuncionarios, posicao, pErro);
				break;
			case 3:
				printf("Digite o número de cadastro do Fornecedor ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(pEscolhaUser, vetorRefFornecedores, posicao, pErro);
				break;
			default:
				 *pErro = 3;
		}
		
		if(posicao == 0) {
			*pErro = 0;
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
	(*contadorCampo)++;
}

void verificarDadosVetorDisponivel(int *pEscolhaUser, int *vetorReferencia, int posicao, int *pErro) {
	posicao -= 1;
	
	if(vetorReferencia[posicao] == 0) {
		*pErro = 4;
	} else {
		
	exibirInterfaceTitulo("MODIFICAR CADASTRO", 1);
	exibirErro(pErro);
	exibirInterfaceFormularios(clientes, funcionarios, fornecedores, pEscolhaUser, posicao);
	getch();
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
