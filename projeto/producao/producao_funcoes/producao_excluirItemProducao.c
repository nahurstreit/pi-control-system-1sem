#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../../arquivo/arquivo.h"
#include "../../interface/interface.h"
#include "../producao.h"

void excluirItemProducao() {
	int escolhaCampo = 0, posicaoItem;
	int *pEscolhaCampo = &escolhaCampo;
	int alterar = 0, saida = 0;
	
	int i, valid;
	
	do{
		saida = 0;
		valid = 0;
		if(erro > 0) alterar = 1;
		exibirInterfaceTitulo("CONSULTAR E MODIFICAR ORDENS DE PRODUÇÃO", 1);
		exibirMensagem();
		exibirErro();
		
		popularVetorItens(producaoAtiva);
		exibirInterfaceNovaProducao(producaoAtiva);
		
		fflush(stdin);
		
		if(calcularDadosExistentes(vetorRefItensComprados) > 1) {
			printf("\n\nDigite o número do item que você quer excluir: ");
			scanf("%d", &posicaoItem);
			fflush(stdin);
			
			if(vetorRefItensComprados[posicaoItem - 1] == 0) {
				erro = Erro_Input_Producao_Item_NaoExiste;
				continue;
			}
		} else {
			posicaoItem = 1;
		}
		
		char stringAlerta[MAX_STRING];
		sprintf(stringAlerta, "Você está tentando excluir o item %d. A exclusão é irreversível, tem certeza disso? ", posicaoItem);
		char stringOpcoes[] = "[1] Sim, tenho certeza\t\t\t[2] Não, deixe-me pensar...";
		
		printf("\n\n");
		if(exibirInterfaceAlerta(stringAlerta, stringOpcoes, "1", false, true, 1)) {
			vetorRefItensComprados[posicaoItem - 1] = 0;
		}
		
		posicaoItem--;
//		
//		inserirStringProd(producaoAtiva, stringNova, pEscolhaCampo, posicaoItem);
	} while(erro != 0);
	
	if(saida != 1) {
		handleSalvar(escolhaUser);
		salvarArquivo_Itens(atoi(producoes[producaoAtiva].numCadCliente), producaoAtiva);
		popularVetorItens(producaoAtiva);
		mensagem = Mensagem_Producao_Item_Excluido;
	}
}
