#include "../../global/global.h"
#include "../../arquivo/arquivo.h"
#include "../cadastro.h"

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
	handleSalvar(escolhaUser);
	mensagem = 2;
	exibirInterfaceTitulo(tituloHolder, 1);
	exibirMensagem();
	exibirInterfaceFormularios(posicaoConsultaAtual);
}
