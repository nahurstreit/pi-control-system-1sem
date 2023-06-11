#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../../arquivo/arquivo.h"
#include "../../interface/interface.h"
#include "../producao.h"

void alterarProducao() {
	char stringNova[MAX_STRING];
	
	int escolhaCampo = 0, posicaoItem;
	int *pEscolhaCampo = &escolhaCampo;
	int alterar = 0, saida = 0;
	
	int i, valid;
	
	popularVetorItens(producaoAtiva);
	
	do{
		saida = 0;
		valid = 0;
		if(erro > 0) alterar = 1;
		exibirInterfaceTitulo("CONSULTAR E MODIFICAR ORDENS DE PRODUÇÃO", 1);
		exibirMensagem();
		exibirErro();

		exibirInterfaceNovaProducao(producaoAtiva);
		
		printf("\n\nDigite o número do campo que você quer alterar: ");
		scanf("%d", &escolhaCampo);
		fflush(stdin);
		
		if(calcularDadosExistentes(vetorRefItensComprados) > 1) {
			if(escolhaCampo > 3) {
				printf("Digite o número do item que você quer alterar: ");
				scanf("%d", &posicaoItem);
				fflush(stdin);
			}
			
			if(vetorRefItensComprados[posicaoItem - 1] == 0) {
				erro = Erro_Input_Producao_Item_NaoExiste;
				continue;
			}
		} else {
			posicaoItem = 1;
		}
		
		escolhaCampo--;
		
		if(escolhaCampo < 3) {
			printf("\nVocê está alterando %s.\n", camposOrdem[escolhaCampo].displayCampo);
		} else {
			printf("\nVocê está alterando %s do item (%d).\n", camposOrdem[escolhaCampo].displayCampo, posicaoItem);
		}
		printf("Digite o novo valor do campo ou 'SAIR' para voltar: ");
		fgets(stringNova, MAX_STRING, stdin);
		stringNova[strcspn(stringNova, "\n")] = '\0';
		fflush(stdin);
		
		if(validarPalavraChave(stringNova, "SAIR")) {
			saida = 1;
			break;
		}
		
		posicaoItem--;
		
		inserirStringProd(producaoAtiva, stringNova, pEscolhaCampo, posicaoItem);
	} while(erro != 0);
	
	escolhaUser = 5;
	if(saida != 1) {
		handleSalvar(escolhaUser);
		salvarArquivo_Itens(atoi(producoes[producaoAtiva].numCadCliente), producaoAtiva);
		mensagem = Mensagem_CampoAlterado;
	}
}
