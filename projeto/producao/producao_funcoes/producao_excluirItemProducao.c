#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../../arquivo/arquivo.h"
#include "../../interface/interface.h"
#include "../producao.h"

void excluirItemProducao() {
	int escolhaCampo = 0, posicaoItem = 0, copiaPosicaoItem;
	int *pEscolhaCampo = &escolhaCampo;
	int alterar = 0, saida = 0, ordemExcluida = 0;
	
	int i, valid;
	
	char stringAlerta[MAX_STRING + 100];
	char stringOpcoes[MAX_STRING];
	
	do{
		ordemExcluida = 0;
		saida = 0;
		valid = 0;
		if(erro > 0) alterar = 1;
		exibirInterfaceTitulo("CONSULTAR E MODIFICAR ORDENS DE PRODU��O", 1);
		exibirMensagem();
		exibirErro();
		
		popularVetorItens(producaoAtiva);
		exibirInterfaceNovaProducao(producaoAtiva);
		
		fflush(stdin);
		
		if(calcularDadosExistentes(vetorRefItensComprados) > 1) {
			printf("\n\nDigite o n�mero do item que voc� quer excluir: ");
			scanf("%d", &posicaoItem);
			fflush(stdin);
			
			if(vetorRefItensComprados[posicaoItem - 1] == 0) {
				erro = Erro_Input_Producao_Item_NaoExiste;
				continue;
			}
		} else {
			strcpy(stringAlerta, "Voc� est� tentando excluir o �nico item dessa Produ��o. A Ordem INTEIRA ser� exclu�da. ");
			strcpy(stringOpcoes, "[1] Sim, quero excluir a ordem inteira!\t\t\t[2] N�o, deixe-me pensar...");
			fflush(stdin);
			if(exibirInterfaceAlerta(stringAlerta, stringOpcoes, "1", false, true, 1)) {
				excluirProducao(producaoAtiva);
				ordemExcluida++;
				break;
			}
		}
		
		sprintf(stringAlerta, "Voc� est� tentando excluir o item %d. Essa decis�o � IRREVERS�VEL, tem certeza disso?", posicaoItem);
		strcpy(stringOpcoes, "[1] Sim, tenho certeza!\t\t\t[2] N�o, deixe-me pensar...");
		
		
		printf("\n\n");
		if(exibirInterfaceAlerta(stringAlerta, stringOpcoes, "1", false, true, 1)) {
			vetorRefItensComprados[posicaoItem - 1] = 0;
			salvarArquivo_Itens(atoi(producoes[producaoAtiva].numCadCliente), producaoAtiva);
			popularVetorItens(producaoAtiva);
		}
//		
//		inserirStringProd(producaoAtiva, stringNova, pEscolhaCampo, posicaoItem);
	} while(erro != 0);
	
	escolhaUser = 5;
	if(saida != 0 && ordemExcluida == 0) {
		handleSalvar(escolhaUser);
		mensagem = Mensagem_Producao_Item_Excluido;
	} else if(ordemExcluida > 0) {
		producaoAtiva = -1;
		handleSalvar(escolhaUser);
		mensagem = Mensagem_Producao_Excluida;
	}
}
