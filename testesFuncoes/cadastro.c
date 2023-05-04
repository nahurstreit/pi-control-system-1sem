#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING 50
#define MAX_VETOR 100

//Criação do struct(tipo) Cliente, para armazenar os dados dos clientes.
typedef struct {
	char nome[MAX_STRING];
	char cpf[MAX_STRING];
	char dataNascimento[MAX_STRING];
	char endereco[MAX_STRING];
	char numEndereco[6];
	char compEndereco[MAX_STRING];
	char refEndereco[MAX_STRING];
	char cep[MAX_STRING];
	char email[MAX_STRING];
	char telefone[MAX_STRING];
} Cliente;

typedef struct {
	char nome[MAX_STRING];
	char cpf[MAX_STRING];
	char dataNascimento[MAX_STRING];
	char endereco[MAX_STRING];
	char numEndereco[6];
	char compEndereco[MAX_STRING];
	char refEndereco[MAX_STRING];
	char cep[MAX_STRING];
	char email[MAX_STRING];
	char telefone[MAX_STRING];
} Funcionario;

//Criação do struct(tipo) TextoCampo, para armazenar os textos que serão exibidos ao pedir para o usuário digitar alguma coisa no cadastro
typedef struct {
	char displayCampo[30];
} TextoCampo;

//Criação da vetor com nome camposCliente que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Cliente
TextoCampo camposCliente[] = {
	"o nome",
	"o CPF",
	"a data de nascimento",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"uma referência p/ o endereço",
	"o CEP",
	"o email",
	"o telefone",
};

//Criação da vetor com nome camposCliente que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Cliente
TextoCampo camposFuncionario[] = {
	"o nome",
	"o CPF",
	"a data de nascimento",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"uma referência p/ o endereço",
	"o CEP",
	"o email",
	"o telefone",
	"a data de admissão",
	""
};

TextoCampo *camposAtuais;

//Criação dos vetores
Cliente clientes[MAX_VETOR];
int vetorClientes[MAX_VETOR] = {0};
int *pVetorClientes = vetorClientes;

Funcionario funcionarios[MAX_VETOR];
int vetorFuncionarios[MAX_VETOR] = {0};
int *pVetorFuncionarios = vetorFuncionarios;

void placeStrings(int tipoCadastro, int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);
void showRegistro(int posicao, int campo);
void exibirRegistroCliente(int posicao);
void verificarDadosVetorDisponivel(int tipoVetor, int *vetor, int posicao);

int posicaoDisponivel(int *vetor);

int novoCadastro(int *pEscolhaUser, int *pMensagem) {
	char stringHolder[MAX_STRING];
	int posicao, tipoCadastroAtual = 0, contadorCampo;
	int *pContadorCampo = &contadorCampo;
	tipoCadastroAtual = *pEscolhaUser;
	
	
	switch(*pEscolhaUser) {
		case 1:
			camposAtuais = camposCliente;
			break;
		case 2:
			camposAtuais = camposFuncionario;
			break;
	}
	
	if(tipoCadastroAtual == 1) {
		posicao = posicaoDisponivel(pVetorClientes);
	} else if(tipoCadastroAtual == 2) {
		posicao = posicaoDisponivel(pVetorFuncionarios);
	}
	contadorCampo = 0;
	
	do {
		printf("Digite %s: ", camposAtuais[contadorCampo].displayCampo);
		fgets(stringHolder, MAX_STRING, stdin);
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		
		placeStrings(tipoCadastroAtual, posicao, stringHolder, pContadorCampo);
		fflush(stdin);
	
	} while(contadorCampo < 10);
	
	*pMensagem = 1;
}


//int teste() {
//	setlocale(LC_ALL, "Portuguese");
//	
//	int i, posicao, contadorCampo = 0;
//	int tipoCadastroAtual;
//	int opt = 3, optTipo;
//	int *pContadorCampo = &contadorCampo;
//	char stringHolder[MAX_STRING];
//	char campoHolder[20];
//	
//	do{
//		system("cls");
//		printf("O que você quer fazer?\n");
//		printf("[1] - Cadastrar Novo\n");
//		printf("[2] - Consultar Existente\n");
//		printf("[0] - Sair\n");
//		printf("\nEscolha: ");
//		scanf("%d", &opt);
//		fflush(stdin);
//		
//		optTipo = 0;
//		
//		switch(opt) {
//			case 1:
//				system("cls");
//				printf("Cadastrar Novo\n\n");
//				printf("[1] Cliente\n");
//				printf("[2] Funcionário\n");
//				printf("[0] Voltar\n");
//				printf("Escolha: ");
//				scanf("%d", &optTipo);
//				fflush(stdin);
//				tipoCadastroAtual = 0;
//				tipoCadastroAtual = optTipo;
//				
//				switch(optTipo) {
//					case 1:
//						camposAtuais = camposCliente;
//						break;
//					case 2:
//						camposAtuais = camposFuncionario;
//						break;
//				}	
//				
//				do {
//						
//						if(optTipo == 1) {
//							posicao = posicaoDisponivel(pVetorClientes);
//						} else if(optTipo == 2) {
//							posicao = posicaoDisponivel(pVetorFuncionarios);
//						}
//						contadorCampo = 0;
//						
//						do {
//							printf("Digite %s: ", camposAtuais[contadorCampo].displayCampo);
//							fgets(stringHolder, MAX_STRING, stdin);
//							stringHolder[strcspn(stringHolder, "\n")] = '\0';
//							
//							placeStrings(tipoCadastroAtual, posicao, stringHolder, pContadorCampo);
//							fflush(stdin);
//										
//						} while(contadorCampo < 10);
//						
//						printf("\n\nO que você quer fazer?\n");
//						printf("\n[1] Cadastrar um Novo");
//						printf("\n[9] Voltar");
//						printf("\n\nEscolha: ");
//						scanf("%d", &opt);
//						fflush(stdin);
//										
//					} while(opt != 9);
//				break;
//			case 2:
//				do{
//					system("cls");
//					printf("Consulta\n\n");
//					printf("[1] Cliente\n");
//					printf("[2] Funcionário\n\n");
//					printf("Escolha: ");
//					scanf("%d", &optTipo);
//					fflush(stdin);
//					
//					switch(optTipo) {
//						case 1:
//							printf("Digite o número do cliente: ");
//							scanf("%d", &posicao);
//							fflush(stdin);
//							verificarDadosVetorDisponivel(optTipo, vetorClientes, posicao); 
//							break;
//						case 2:
//							printf("Digite o número do funcionário: ");
//							scanf("%d", &posicao);
//							fflush(stdin);
//							verificarDadosVetorDisponivel(optTipo, vetorFuncionarios, posicao);
//							break;
//					}
//
//					
//					printf("\n\nO que você quer fazer?\n");
//					printf("\n[1] Consultar Novo");
//					printf("\n[9] Voltar");
//					printf("\n\nEscolha: ");
//					scanf("%d", &opt);
//					fflush(stdin);
//					
//					
//				} while(opt != 9);
//		}
//		
//	} while(opt != 0);
//}

void placeStrings(int tipoCadastro, int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
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
				case 3:
					strcpy(clientes[posicaoDisponivel].endereco, string);
					break;
				case 4:
					strcpy(clientes[posicaoDisponivel].numEndereco, string);
					break;
				case 5:
					strcpy(clientes[posicaoDisponivel].compEndereco, string);
					break;
				case 6:
					strcpy(clientes[posicaoDisponivel].refEndereco, string);
					break;
				case 7:
					strcpy(clientes[posicaoDisponivel].cep, string);
					break;
				case 8:
					strcpy(clientes[posicaoDisponivel].email, string);
					break;
				default:
					strcpy(clientes[posicaoDisponivel].telefone, string);
			}

			break;
		case 2:
			switch(*contadorCampo) {
				case 0:
					strcpy(funcionarios[posicaoDisponivel].nome, string);
					break;
				case 1:
					strcpy(funcionarios[posicaoDisponivel].cpf, string);
					break;
				case 2:
					strcpy(funcionarios[posicaoDisponivel].dataNascimento, string);
					break;
				case 3:
					strcpy(funcionarios[posicaoDisponivel].endereco, string);
					break;
				case 4:
					strcpy(funcionarios[posicaoDisponivel].numEndereco, string);
					break;
				case 5:
					strcpy(funcionarios[posicaoDisponivel].compEndereco, string);
					break;
				case 6:
					strcpy(funcionarios[posicaoDisponivel].refEndereco, string);
					break;
				case 7:
					strcpy(funcionarios[posicaoDisponivel].cep, string);
					break;
				case 8:
					strcpy(funcionarios[posicaoDisponivel].email, string);
					break;
				default:
					strcpy(funcionarios[posicaoDisponivel].telefone, string);
			}
			break;
	}
	(*contadorCampo)++;
}

void exibirRegistroCliente(int posicao) {
	printf("Nome: %s\n", clientes[posicao].nome);
	printf("CPF: %s\n", clientes[posicao].cpf);
	printf("Endereço: %s\t", clientes[posicao].endereco);
	printf("Número: %s\t", clientes[posicao].numEndereco);
	printf("Complemento: %s\n", clientes[posicao].compEndereco);
	printf("Referência: %s\n", clientes[posicao].refEndereco);
	printf("CEP: %s\n", clientes[posicao].cep);
	printf("E-mail: %s\n", clientes[posicao].email);
	printf("Telefone: %s\n", clientes[posicao].telefone);
}

void exibirRegistroFuncionario(int posicao) {
	printf("Nome: %s\n", funcionarios[posicao].nome);
	printf("CPF: %s\n", funcionarios[posicao].cpf);
	printf("Endereço: %s\t", funcionarios[posicao].endereco);
	printf("Número: %s\t", funcionarios[posicao].numEndereco);
	printf("Complemento: %s\n", funcionarios[posicao].compEndereco);
	printf("Referência: %s\n", funcionarios[posicao].refEndereco);
	printf("CEP: %s\n", funcionarios[posicao].cep);
	printf("E-mail: %s\n", funcionarios[posicao].email);
	printf("Telefone: %s\n", funcionarios[posicao].telefone);
}

void verificarDadosVetorDisponivel(int tipoVetor, int *vetor, int posicao) {
	if(vetor[posicao] == 0) {
	printf("Não existem registros para esse código!");
	} else {
		switch(tipoVetor) {
			case 1:
				exibirRegistroCliente(posicao);
				break;
			case 2:
				exibirRegistroFuncionario(posicao);
				break;
		}
		printf("\n\n");
	}
}

int posicaoDisponivel(int *vetor) {
	int i;
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetor[i] == 0) {
			vetor[i] = 1;
			break;
		}
	}
	
	return i;
}
