#include "../../global/global.h"
#include "../../arquivo/arquivo.h"
#include "../cadastro.h"

void alterarCadastro() {
	char stringNova[MAX_STRING];
	
	int escolhaCampo = 0;
	int alterar = 0, saida = 0;
	int *pEscolhaCampo = &escolhaCampo;
	
	char tituloHolder[50];
	
	
	switch(tipoConsultaAtual) {
		case 1: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE CLIENTES"); break;
		case 2: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FUNCIONARIOS"); break;
		case 3: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES"); break;
		case 4: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE PRODUTOS"); break;
	}
	
	do{
		saida = 0;
		if(erro > 0) alterar = 1;
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceFormularios(posicaoConsultaAtual);
	
		switch(tipoConsultaAtual) {
			case 1: camposAtuais = camposCliente; break;
			case 2: camposAtuais = camposFuncionario; break;
			case 3: camposAtuais = camposFornecedor; break;
			case 4: camposAtuais = camposProduto; break;
		}
		
		if(alterar == 0) {
			printf("\n\nDigite o número do campo que você quer alterar: ");
			scanf("%d", &escolhaCampo);
			fflush(stdin);
			escolhaCampo -= 1;
		}
		
		alterar = 0;
		
		printf("\nVocê está alterando %s.\n", camposAtuais[escolhaCampo].displayCampo);
		printf("Digite o novo valor do campo ou 'SAIR' para voltar: ");
		fgets(stringNova, MAX_STRING, stdin);
		stringNova[strcspn(stringNova, "\n")] = '\0';
		fflush(stdin);
		
		if(validarPalavraChave(stringNova, "SAIR")) {
			saida = 1;
			break;
		}
		
		alterarString(posicaoConsultaAtual, stringNova, escolhaCampo);
	} while(erro != 0);
	
	if(saida != 1) {
		handleSalvar(escolhaUser);
		mensagem = Mensagem_CampoAlterado;
	}
}
