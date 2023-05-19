#include "global/global.h"
#include "cadastro.h"

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
	"o status na empresa",
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

int tipoConsultaAtual;
int *pTipoConsultaAtual = &tipoConsultaAtual;
int posicaoConsultaAtual;

//Função de execução criação de novoCadastro. A chamada desse função acontece em menu.c dentro de algumas opções.
void novoCadastro() {
	char stringHolder[MAX_STRING];
	int posicao, tipoCadastroAtual = 0, contadorCampo, limiteContador = 0;
	int holderContadorCampo;
	int *pContadorCampo = &contadorCampo;
	
	//Variáveis para controle de saída e alteração de cadastro em tempo de execução.
		char escolhaSair = 's'; //Nomeando a variável de confirmação de escolha para sair do registro de um novo cadastro.
		int saida, alterar; //Variáveis responsáveis por controlar se o usuário está tentando sair ou alterar algum dado, durante o registro de um novo cadastro.
	//
	
	switch(escolhaUser) {
		case 1:
			camposAtuais = camposCliente;
			posicao = posicaoDisponivel(vetorRefClientes);
			limiteContador = 12;
			break;
		case 2:
			camposAtuais = camposFuncionario;
			posicao = posicaoDisponivel(vetorRefFuncionarios);
			limiteContador = 16;
			break;
		case 3:
			camposAtuais = camposFornecedor;
			posicao = posicaoDisponivel(vetorRefFornecedores);
			limiteContador = 11;
			break;
	}
	
	contadorCampo = 0;
	
	do {
		saida = 0; //Zerando o valor de saída para poder controlar a exibição da mensagem de saída caso o usuário não digitar "SAIR".
		 if(escolhaUser == 1) exibirInterfaceTitulo("NOVO CADASTRO DE CLIENTE", 1);
		 else if(escolhaUser == 2) exibirInterfaceTitulo("NOVO CADASTRO DE FUNCIONÁRIO", 1);
		 else exibirInterfaceTitulo("NOVO CADASTRO DE FORNECEDOR", 1);
		
		exibirMensagem();
		exibirErro();

		exibirInterfaceFormularios(posicao);
		
		//Exibe uma mensagem diferente na parte de baixo do formulário. Se o usuário estiver digitando o primeiro dado, apenas exibirá a opção de voltar, caso esteja em algum outro dado, aparece o texto de mudar.
		contadorCampo > 0 ? exibirTextoMeio("Digite 'SAIR' para voltar ou 'MUDAR' para alterar algum dado.\n") :
							exibirTextoMeio("Digite 'SAIR' para voltar\n");
		
		//Exibe uma mensagem diferente caso seja a primeira vez que esteja digitando um dado, ou se estiver digitando o dado novamente
		alterar > 0 ? printf("\n[%d] Digite novamente %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo) :
					  printf("\n[%d] Digite %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo);
		
		//Recebe o dado
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		
		//Valida se o usuário digitou a palavra "SAIR"
		if(validarPalavraChave(stringHolder, KEY_STRING_SAIR)) {
			printf("\n");
			exibirInterfaceAlerta("Você digitou 'SAIR', TODOS os dados digitados serão perdidos, tem certeza que quer sair? ");
			printf("\nDigite (S) para sair: ");
			scanf("%c", &escolhaSair);
			fflush(stdin);
			if(escolhaSair == 's' || escolhaSair == 'S') {
				posicaoConsultaAtual = posicao;
				excluirCadastro(posicao);
				saida++;
				break;
			} else {
				continue;
			}
		}
		
		//Valida se o usuário digitou a palavra "MUDAR"
		if(validarPalavraChave(stringHolder, KEY_STRING_MUDAR)) {
			if(contadorCampo > 0) {
				if(contadorCampo == 1) {
					holderContadorCampo = 1;
					alterar++;
					contadorCampo = 0;
					continue;
				} else {
					holderContadorCampo = contadorCampo;
					printf("Digite o número do campo você quer alterar: ");
					scanf("%d", &contadorCampo);
					fflush(stdin);
					contadorCampo--;
					if(contadorCampo < 0 || contadorCampo > limiteContador) {
						erro = 6;
						contadorCampo = holderContadorCampo;
						continue;
					} else if(contadorCampo > holderContadorCampo && contadorCampo < limiteContador) {
						erro = 7; 
						contadorCampo = holderContadorCampo;
						continue;
					} else {
						alterar++;
						continue;
					}
				}
			} else {
				erro = alterar > 0 ? 8 : 5;
				continue;
			}
		}
		
		//Insere a string no vetor de dados
		inserirString(posicao, stringHolder, pContadorCampo);
		
		//Caso o usuário tente mudar um dado e consiga alterar o dado com sucesso, exibe uma mensagem indicando que o campo foi alterado. Se não estiver mudando um dado, a mensagem não aparece.
		if(alterar > 0) {
			mensagem = 2;
			contadorCampo = holderContadorCampo;
			alterar = 0;
			continue;
		}
		
		//Fluxo normal de contador, para ir percorrendo entre os campos.
		contadorCampo++;

	} while(contadorCampo < limiteContador);
	
	//Se o usuário digitar 'SAIR', não exibirá a mensagem de "enviando cadastro". Apenas retornará ao menu anterior.
	if(saida == 0) {
		exibirInterfaceTitulo("NOVO CADASTRO", 1);
		exibirInterfaceFormularios(posicao);
		printf("\n\nEnviando Cadastro...\n");
		system("pause");
		mensagem = 1;
	} else {
		mensagem = 0;
	}

}

//Função de exibição de cadastros. A chamada desse função acontece em menu.c dentro de algumas opções.
void consultaCadastro(int *estado) {
	int posicao, contadorDadosExistentes;
	
	switch(escolhaUser) {
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
		if(escolhaUser == 1) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
		 else if(escolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCIONÁRIOS", 1);
		 else exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
		
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
	
		switch(escolhaUser) {
			case 1:
				printf("\nDigite o número de cadastro do Cliente ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefClientes, posicao);
				break;
			case 2:
				printf("\nDigite o número de cadastro do Funcionário ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefFuncionarios, posicao);
				break;
			case 3:
				printf("\nDigite o número de cadastro do Fornecedor ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefFornecedores, posicao);
				break;
			default:
				 erro = 3;
		}
		
		posicaoConsultaAtual = posicao-1;
		
		if(erro == 0) {
			if(escolhaUser == 1) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
		 	else if(escolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCIONÁRIOS", 1);
		 	else exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
			exibirInterfaceFormularios(posicao-1);
			*estado = 1;
			break;
		}
		
		if(posicao == 0) {
			erro = 0;
			*estado = 0;
			break;
		}
		
		fflush(stdin);
	} while(erro == 4);
}

void inserirString(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
	switch(escolhaUser) {
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
					strcpy(funcionarios[posicaoDisponivel].status, string);
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

void verificarDadosVetorDisponivel(int *vetorReferencia, int posicaoConsultada) {
	posicaoConsultada -= 1;
	
	if(vetorReferencia[posicaoConsultada] == 0) {
		erro = 4;
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

int calcularDadosExistentes(int vetorReferencia[MAX_VETOR]) {
	int i, contadorDadosExistentes = 0;
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetorReferencia[i] == 1) {
			contadorDadosExistentes++;
		}
	}
	
	return contadorDadosExistentes;
}

void alterarCadastro() {
	char stringNova[MAX_STRING];
	
	int escolhaCampo = 0;
	int *pEscolhaCampo = &escolhaCampo;
	
	char tituloHolder[50];
	
	switch(escolhaUser) {
		case 1: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE CLIENTES"); break;
		case 2: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FUNCIONARIOS"); break;
		case 3: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES"); break;
	}
	
	exibirInterfaceTitulo(tituloHolder, 1);
	
	exibirInterfaceFormularios(posicaoConsultaAtual);

	switch(escolhaUser) {
		case 1: camposAtuais = camposCliente; break;
		case 2: camposAtuais = camposFuncionario; break;
		case 3: camposAtuais = camposFornecedor; break;
	}


	printf("\n\nDigite o número do campo que você quer alterar: ");
	scanf("%d", &escolhaCampo);
	fflush(stdin);
	
	escolhaCampo -= 1;
	
	printf("\nVocê está alterando %s.\n", camposAtuais[escolhaCampo].displayCampo);
	printf("Digite o novo valor do campo: ");
	fgets(stringNova, MAX_STRING, stdin);
	stringNova[strcspn(stringNova, "\n")] = '\0';
	fflush(stdin);
	
	alterarString(posicaoConsultaAtual, stringNova, escolhaCampo);
	mensagem = 2;
	exibirInterfaceTitulo(tituloHolder, 1);
	exibirMensagem();
	exibirInterfaceFormularios(posicaoConsultaAtual);
}

void alterarString(int posicao, char stringNova[MAX_STRING], int campo) {
	switch(escolhaUser) {
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
					strcpy(funcionarios[posicao].status, stringNova);
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

void executarExcluirCadastro(int tipoTexto, int *pEscolhaUserMod) {
	int escolhaAlterar = 0, contadorDadosExistentes = 0;
	
	char tituloHolder[50];
	
	switch(tipoConsultaAtual) {
		case 1: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE CLIENTES"); break;
		case 2: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FUNCIONARIOS"); break;
		case 3: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES"); break;
	}
	
	exibirInterfaceTitulo("ATENÇÃO!", 1);
	
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
	
	switch(tipoTexto) {
		case 1: exibirInterfaceAlerta("Você tem certeza que deseja EXCLUIR o cadastro? Essa decisão é IRREVERSÍVEL! "); break;
		case 2: exibirInterfaceAlerta("Você tem certeza que deseja ALTERAR TODO o cadastro? Essa decisão é IRREVERSÍVEL!"); break;
	}
	
	printf("\n\n[1] Sim, tenho certeza!\t\t[2] Não, deixe-me pensar...\n\n");
	printf("Opção: ");
	scanf("%d", &escolhaAlterar);
	fflush(stdin);
		
	if(escolhaAlterar == 1) {
		*pEscolhaUserMod = 0;
		mensagem = 3;
		excluirCadastro(posicaoConsultaAtual);
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
	} else {
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceFormularios(posicaoConsultaAtual);
	}
}

void excluirCadastro(int posicaoConsultaAtual) {
	switch(escolhaUser) {
		case 1:
			strcpy(clientes[posicaoConsultaAtual].nome, "");
			strcpy(clientes[posicaoConsultaAtual].cpf, "");
			strcpy(clientes[posicaoConsultaAtual].dataNascimento, "");
			strcpy(clientes[posicaoConsultaAtual].telefone, "");
			strcpy(clientes[posicaoConsultaAtual].email, "");
			strcpy(clientes[posicaoConsultaAtual].endereco, "");
			strcpy(clientes[posicaoConsultaAtual].numEndereco, "");
			strcpy(clientes[posicaoConsultaAtual].compEndereco, "");
			strcpy(clientes[posicaoConsultaAtual].bairro, "");
			strcpy(clientes[posicaoConsultaAtual].cep, "");
			strcpy(clientes[posicaoConsultaAtual].cidade, "");
			strcpy(clientes[posicaoConsultaAtual].estado, "");
			vetorRefClientes[posicaoConsultaAtual] = 0;
			break;
		case 2:
			strcpy(funcionarios[posicaoConsultaAtual].nome, "");
			strcpy(funcionarios[posicaoConsultaAtual].status, "");
			strcpy(funcionarios[posicaoConsultaAtual].cpf, "");
			strcpy(funcionarios[posicaoConsultaAtual].dataNascimento, "");
			strcpy(funcionarios[posicaoConsultaAtual].estadoCivil, "");
			strcpy(funcionarios[posicaoConsultaAtual].dataAdmissao, "");
			strcpy(funcionarios[posicaoConsultaAtual].salarioBase, "");
			strcpy(funcionarios[posicaoConsultaAtual].telefone, "");
			strcpy(funcionarios[posicaoConsultaAtual].email, "");
			strcpy(funcionarios[posicaoConsultaAtual].endereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].numEndereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].compEndereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].bairro, "");
			strcpy(funcionarios[posicaoConsultaAtual].cep, "");
			strcpy(funcionarios[posicaoConsultaAtual].cidade, "");
			strcpy(funcionarios[posicaoConsultaAtual].estado, "");
			vetorRefFuncionarios[posicaoConsultaAtual] = 0;
			break;
		case 3:
			strcpy(fornecedores[posicaoConsultaAtual].nomeFantasia, "");
			strcpy(fornecedores[posicaoConsultaAtual].cnpj, "");
			strcpy(fornecedores[posicaoConsultaAtual].telefone, "");
			strcpy(fornecedores[posicaoConsultaAtual].email, "");
			strcpy(fornecedores[posicaoConsultaAtual].endereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].numEndereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].compEndereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].bairro, "");
			strcpy(fornecedores[posicaoConsultaAtual].cep, "");
			strcpy(fornecedores[posicaoConsultaAtual].cidade, "");
			strcpy(fornecedores[posicaoConsultaAtual].estado, "");
			vetorRefFornecedores[posicaoConsultaAtual] = 0;
			break;
	}
}

int validarPalavraChave(char string[], char stringChave[]) {
	char stringHolder[MAX_STRING];
	int i;
	
	for(i = 0; i < strlen(stringChave); i++) {
		stringHolder[i] = toupper(string[i]);
	}
	
	if(strncmp(stringHolder, stringChave, strlen(stringChave)) == 0) return true;
	else return false;
}
