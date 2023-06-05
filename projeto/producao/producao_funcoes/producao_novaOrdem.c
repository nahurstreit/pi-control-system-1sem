#include "../../global/global.h"
#include "../../cadastro/cadastro.h"
#include "../producao.h"
#include "../../menu/menu.h"

//Fun��o de execu��o cria��o de novoCadastro. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
void novaOrdem(bool adicionarItens) {
	char stringHolder[MAX_STRING];
	int escolhaEntrada = 5;
	int posicao, posicaoItem, tipoCadastroAtual = 0, contadorCampo, limiteContador = 0;
	int holderContadorCampo;
	int *pContadorCampo = &contadorCampo;
	
	//Vari�veis para controle de sa�da e altera��o de cadastro em tempo de execu��o.
		char escolhaSair = 's'; //Nomeando a vari�vel de confirma��o de escolha para sair do registro de um novo cadastro.
		int saida, alterar, exibir; //Vari�veis respons�veis por controlar se o usu�rio est� tentando sair ou alterar algum dado, durante o registro de um novo cadastro.
		int escolhaAlterarItem = -1;
		int valid;
	//
	
	if(!adicionarItens) {
		resetarVetorItens();
		posicaoItem = posicaoDisponivel(vetorRefItensComprados);
		posicao = posicaoDisponivel(vetorRefProducoes);
		producaoAtiva = posicao;	
		contadorCampo = 0;
		holderContadorCampo = 0;
	} else {
		popularVetorItens(producaoAtiva);
		posicaoItem = posicaoDisponivel(vetorRefItensComprados);
		posicao = producaoAtiva;
		contadorCampo = 3;
		holderContadorCampo = 3;
	}
	
	limiteContador = 6;
	escolhaUser = 5;
	alterar = 0;
	exibir = 0;
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefClientes);
	do {
		saida = 0; //Zerando o valor de sa�da para poder controlar a exibi��o da mensagem de sa�da caso o usu�rio n�o digitar "SAIR".
		exibirInterfaceTitulo("NOVA ORDEM DE PRODU��O", 1);
		
		exibirMensagem();
		exibirErro();

		exibirInterfaceNovaProducao(posicao);
		
		//Exibe uma mensagem diferente na parte de baixo do formul�rio. Se o usu�rio estiver digitando o primeiro dado, apenas exibir� a op��o de voltar, caso esteja em algum outro dado, aparece o texto de mudar.
		contadorCampo > 0 ? exibirTextoMeio("Digite 'SAIR' para voltar ou 'MUDAR' para alterar algum dado.\n") :
							exibirTextoMeio("Digite 'SAIR' para voltar\n");
		
		//Exibe uma mensagem diferente caso seja a primeira vez que esteja digitando um dado, ou se estiver digitando o dado novamente
		alterar > 0 ? printf("\n[%d] Digite novamente %s: ", contadorCampo+1, camposOrdem[contadorCampo].displayCampo) :
					  printf("\n[%d] Digite %s: ", contadorCampo+1, camposOrdem[contadorCampo].displayCampo);
		
		//Recebe o dado
		fgets(stringHolder, MAX_STRING, stdin);
		fflush(stdin);
		stringHolder[strcspn(stringHolder, "\n")] = '\0';
		
		//Valida se o usu�rio digitou a palavra "SAIR"
		if(validarPalavraChave(stringHolder, KEY_STRING_SAIR)) {
			printf("\n");
			char stringSair[] = "Voc� digitou 'SAIR', TODOS os dados digitados ser�o perdidos, tem certeza que quer sair? ";
			char stringOpcaoSair[] = "\nDigite (S) para sair: ";
			if(exibirInterfaceAlerta(stringSair, stringOpcaoSair, "S", true, false, 1)){
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
								printf("Digite o n�mero do campo voc� quer alterar: ");
								scanf("%d", &contadorCampo);
								fflush(stdin);
							}
					} else {
						printf("Digite o n�mero do campo voc� quer alterar: ");
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
					} else if(contadorCampo == 3 || contadorCampo == 4) {
						if(calcularDadosExistentes(vetorRefItensComprados) <= 1) {
							posicaoItem = 0;
						} else {
							printf("Digite o n�mero do item que voc� quer alterar: ");
							valid = scanf("%d", &posicaoItem);
							fflush(stdin);
							posicaoItem--;
							if(valid == 0) {
								erro = Erro_Input_ApenasNumeros;
								continue;
							}
						}
						alterar++;
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
		
		if(contadorCampo > 4) {
			if(!validarPalavraChave(stringHolder, "0")) {
				posicaoItem = posicaoDisponivel(vetorRefItensComprados);
				contadorCampo = 3;
				holderContadorCampo = 3;
			}
		}
		
		//Insere a string no vetor de dados
		inserirStringProd(posicao, stringHolder, pContadorCampo, posicaoItem);
		
		//Caso o usu�rio tente mudar um dado e consiga alterar o dado com sucesso, exibe uma mensagem indicando que o campo foi alterado. Se n�o estiver mudando um dado, a mensagem n�o aparece.
		if(alterar > 0 && erro == 0) {
			mensagem = Mensagem_CampoAlterado;
			contadorCampo = holderContadorCampo;
			escolhaAlterarItem = -1;
			alterar = 0;
			continue;
		}
		
		if(contadorCampo > 2) {
			salvarArquivo_Itens(atoi(producoes[posicao].numCadCliente), posicao);
		}
		
		//Fluxo normal de contador, para ir percorrendo entre os campos.
		if(erro == 0) {
			contadorCampo++;
			holderContadorCampo++;
		}

	} while(contadorCampo < limiteContador);
	
	//Se o usu�rio digitar 'SAIR', n�o exibir� a mensagem de "enviando cadastro". Apenas retornar� ao menu anterior.
	if(saida == 0) {
		handleSalvar(escolhaUser);
		if(adicionarItens) {
			salvarArquivo_Itens(atoi(producoes[posicao].numCadCliente), posicao);
			mensagem = Mensagem_Producao_Item_Adicionado;
			menuAtual = menuConsultarOrdemProducao;
		} else  {
			mensagem = Mensagem_Producao_Nova;
			menuAtual = menuNovaOrdemProducao;
		}
	} else {
		excluirProducao(producaoAtiva);
		if(contadorCampo > 2) {
			excluirArquivoItens(atoi(producoes[producaoAtiva].numCadCliente), producaoAtiva);
		}
		
		mensagem = Mensagem_Producao_Cancelada;
		menuAtual = menuOrdemProducao;
	}
}
