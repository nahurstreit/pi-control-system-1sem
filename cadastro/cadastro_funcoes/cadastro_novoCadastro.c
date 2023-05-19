#include "../../global/global.h"
#include "../cadastro.h"

//Fun��o de execu��o cria��o de novoCadastro. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
void novoCadastro() {
	char stringHolder[MAX_STRING];
	int posicao, tipoCadastroAtual = 0, contadorCampo, limiteContador = 0;
	int holderContadorCampo;
	int *pContadorCampo = &contadorCampo;
	
	//Vari�veis para controle de sa�da e altera��o de cadastro em tempo de execu��o.
		char escolhaSair = 's'; //Nomeando a vari�vel de confirma��o de escolha para sair do registro de um novo cadastro.
		int saida, alterar; //Vari�veis respons�veis por controlar se o usu�rio est� tentando sair ou alterar algum dado, durante o registro de um novo cadastro.
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
		saida = 0; //Zerando o valor de sa�da para poder controlar a exibi��o da mensagem de sa�da caso o usu�rio n�o digitar "SAIR".
		 if(escolhaUser == 1) exibirInterfaceTitulo("NOVO CADASTRO DE CLIENTE", 1);
		 else if(escolhaUser == 2) exibirInterfaceTitulo("NOVO CADASTRO DE FUNCION�RIO", 1);
		 else exibirInterfaceTitulo("NOVO CADASTRO DE FORNECEDOR", 1);
		
		exibirMensagem();
		exibirErro();

		exibirInterfaceFormularios(posicao);
		
		//Exibe uma mensagem diferente na parte de baixo do formul�rio. Se o usu�rio estiver digitando o primeiro dado, apenas exibir� a op��o de voltar, caso esteja em algum outro dado, aparece o texto de mudar.
		contadorCampo > 0 ? exibirTextoMeio("Digite 'SAIR' para voltar ou 'MUDAR' para alterar algum dado.\n") :
							exibirTextoMeio("Digite 'SAIR' para voltar\n");
		
		//Exibe uma mensagem diferente caso seja a primeira vez que esteja digitando um dado, ou se estiver digitando o dado novamente
		alterar > 0 ? printf("\n[%d] Digite novamente %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo) :
					  printf("\n[%d] Digite %s: ", contadorCampo+1, camposAtuais[contadorCampo].displayCampo);
		
		//Recebe o dado
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		
		//Valida se o usu�rio digitou a palavra "SAIR"
		if(validarPalavraChave(stringHolder, KEY_STRING_SAIR)) {
			printf("\n");
			exibirInterfaceAlerta("Voc� digitou 'SAIR', TODOS os dados digitados ser�o perdidos, tem certeza que quer sair? ");
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
		
		//Valida se o usu�rio digitou a palavra "MUDAR"
		if(validarPalavraChave(stringHolder, KEY_STRING_MUDAR)) {
			if(contadorCampo > 0) {
				if(contadorCampo == 1) {
					holderContadorCampo = 1;
					alterar++;
					contadorCampo = 0;
					continue;
				} else {
					holderContadorCampo = contadorCampo;
					printf("Digite o n�mero do campo voc� quer alterar: ");
					scanf("%d", &contadorCampo);
					fflush(stdin);
					contadorCampo--;
					if(contadorCampo == holderContadorCampo) {
						continue;
					} else if(contadorCampo < 0 || contadorCampo >= limiteContador) {
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
		
		//Caso o usu�rio tente mudar um dado e consiga alterar o dado com sucesso, exibe uma mensagem indicando que o campo foi alterado. Se n�o estiver mudando um dado, a mensagem n�o aparece.
		if(alterar > 0) {
			mensagem = 2;
			contadorCampo = holderContadorCampo;
			alterar = 0;
			continue;
		}
		
		//Fluxo normal de contador, para ir percorrendo entre os campos.
		contadorCampo++;

	} while(contadorCampo < limiteContador);
	
	//Se o usu�rio digitar 'SAIR', n�o exibir� a mensagem de "enviando cadastro". Apenas retornar� ao menu anterior.
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

