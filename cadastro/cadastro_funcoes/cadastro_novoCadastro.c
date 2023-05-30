#include "../../global/global.h"
#include "../cadastro.h"

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
			limiteContador = 12;
			break;
		case 4:
			camposAtuais = camposProduto;
			posicao = posicaoDisponivel(vetorRefProdutos);
			limiteContador = 2;
			break;
	}
	
	contadorCampo = 0;
	holderContadorCampo = 0;
	
	do {
		saida = 0; //Zerando o valor de saída para poder controlar a exibição da mensagem de saída caso o usuário não digitar "SAIR".
		 if(escolhaUser == 1) exibirInterfaceTitulo("NOVO CADASTRO DE CLIENTE", 1);
		 else if(escolhaUser == 2) exibirInterfaceTitulo("NOVO CADASTRO DE FUNCIONÁRIO", 1);
		 else if(escolhaUser == 3) exibirInterfaceTitulo("NOVO CADASTRO DE FORNECEDOR", 1);
		 else exibirInterfaceTitulo("NOVO CADASTRO DE PRODUTO", 1);
		
		exibirMensagem();
		exibirErro();

		exibirInterfaceFormularios(posicao);
		
		//Exibe uma mensagem diferente na parte de baixo do formulário. Se o usuário estiver digitando o primeiro dado, apenas exibirá a opção de voltar, caso esteja em algum outro dado, aparece o texto de mudar.
		if(contadorCampo > 0 && alterar == 0) exibirTextoMeio("Digite 'SAIR' para voltar ou 'MUDAR' para alterar algum dado.");
		else if(alterar > 0) exibirTextoMeio("Digite 'SAIR' para voltar ou 'MANTER' para manter o dado já digitado.");
		else exibirTextoMeio("Digite 'SAIR' para voltar");
							
		
		
		//Exibe uma mensagem diferente caso seja a primeira vez que esteja digitando um dado, ou se estiver digitando o dado novamente
		alterar > 0 ? printf("\n\n[%d] Digite novamente %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo) :
					  printf("\n\n[%d] Digite %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo);
		
		//Recebe o dado
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		
		//Valida se o usuário digitou a palavra "SAIR"
		if(validarPalavraChave(stringHolder, KEY_STRING_SAIR)) {
			printf("\n");
			char stringSair[] = "Você digitou 'SAIR', TODOS os dados digitados serão perdidos, tem certeza que quer sair? ";
			char stringOpcaoSair[] = "\nDigite (S) para sair: ";
			if(exibirInterfaceAlerta(stringSair, stringOpcaoSair, "S", true, false, 1)){
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
					if(strlen(stringHolder) > strlen(KEY_STRING_MUDAR) + 1) {
						char *token = strtok(stringHolder, " ");
							token = strtok(NULL, "");
							
							strcpy(stringHolder, token);
							if(!verificarContemLetras(stringHolder)) {
								contadorCampo = atoi(stringHolder);
							} else {
								printf("Digite o número do campo você quer alterar: ");
								scanf("%d", &contadorCampo);
								fflush(stdin);
							}
					} else {
						printf("Digite o número do campo você quer alterar: ");
						scanf("%d", &contadorCampo);
						fflush(stdin);
					}
					contadorCampo--;
					if(contadorCampo == holderContadorCampo) {
						continue;
					} else if(contadorCampo < 0 || contadorCampo >= limiteContador) {
						erro = Erro_NovoCadastro_Mudar_CampoInvalido;
						contadorCampo = holderContadorCampo;
						continue;
					} else if(contadorCampo > holderContadorCampo && contadorCampo < limiteContador) {
						erro = Erro_NovoCadastro_Mudar_AindaNaoDigitou; 
						contadorCampo = holderContadorCampo;
						continue;
					} else {
						alterar++;
						continue;
					}
				}
			} else {
				erro = alterar > 0 ? Erro_NovoCadastro_Mudar_SoPodeOPrimeiro : Erro_NovoCadastro_Mudar_NenhumCampoAinda;
				continue;
			}
		}
		
		if(validarPalavraChave(stringHolder, "MANTER")) {
			contadorCampo = holderContadorCampo;
			alterar = 0;
			continue;
		}
		
		//Insere a string no vetor de dados
		inserirString(posicao, stringHolder, pContadorCampo);
		
		//Caso o usuário tente mudar um dado e consiga alterar o dado com sucesso, exibe uma mensagem indicando que o campo foi alterado. Se não estiver mudando um dado, a mensagem não aparece.
		if(alterar > 0 && erro == 0) {
			mensagem = Mensagem_CampoAlterado;
			contadorCampo = holderContadorCampo;
			alterar = 0;
			continue;
		}
		
		//Fluxo normal de contador, para ir percorrendo entre os campos.
		if(erro == 0) {
			contadorCampo++;
			holderContadorCampo++;
		}

	} while(contadorCampo < limiteContador);
	
	//Se o usuário digitar 'SAIR', não exibirá a mensagem de "enviando cadastro". Apenas retornará ao menu anterior.
	if(saida == 0) {
		handleSalvar(escolhaUser);
		exibirInterfaceTitulo("NOVO CADASTRO", 1);
		exibirInterfaceFormularios(posicao);
		printf("\n\nEnviando Cadastro...\n");
		system("pause");
		mensagem = Mensagem_Cadastro_Novo;
	} else {
		mensagem = Mensagem_Cadastro_Cancelado;
	}
}
