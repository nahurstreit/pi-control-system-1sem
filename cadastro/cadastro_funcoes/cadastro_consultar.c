#include "../../global/global.h"
#include "../cadastro.h"

//Função de exibição de cadastros. A chamada desse função acontece em menu.c dentro de algumas opções.
void consultaCadastro(int *estado) {
	char posicaoString[MAX_STRING];
	int posicao, contadorDadosExistentes;
	char stringTipo[MAX_STRING];
	
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
		case 4:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefProdutos);
			break;
	}
	
	do{
		switch(escolhaUser) {
			case 1:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
				strcpy(stringTipo, "Digite o [NÚMERO DE CADASTRO] ou [CPF] do Cliente para consultá-lo.");
				break;
			case 2:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCIONÁRIOS", 1);
				strcpy(stringTipo, "Digite o [NÚMERO DE CADASTRO] ou [CPF] do Funcionário para consultá-lo.");
				break;
			case 3:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
				strcpy(stringTipo, "Digite o [NÚMERO DE CADASTRO] ou [CNPJ] do Fornecedor para consultá-lo.");
				break;
			case 4:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE PROTUDOS", 1);
				strcpy(stringTipo, "Digite o [NÚMERO DE CADASTRO] do Produto para consultá-lo");
				break;
			default:
				erro = Erro_Consulta_NaoPossivel;
		}
		
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
		
		printf("%s\n", stringTipo);
		printf("Ou então, digite [0] para VOLTAR à tela anterior.\n\nConsulta: ");
		fgets(posicaoString, MAX_STRING, stdin);
		posicaoString[strcspn(posicaoString, "\n")] = '\0';
		fflush(stdin);
		
		removerCaracteresEspeciais(posicaoString, false);
		
		if(verificarContemLetras(posicaoString)) {
			erro = Erro_Input_ApenasNumeros;
			continue;
		}
		
		if(strlen(posicaoString) > 1 && strlen(posicaoString) >= 11) {
			posicao = consultarCPFouCNPJ(posicaoString);
			posicaoConsultaAtual = posicao;
		} else {
			posicao = atoi(posicaoString);
			posicaoConsultaAtual = posicao - 1;
		}
		
		switch(escolhaUser) {
			case 1:
				verificarDadosVetorDisponivel(vetorRefClientes, posicao);
				break;
			case 2:
				verificarDadosVetorDisponivel(vetorRefFuncionarios, posicao);
				break;
			case 3:
				verificarDadosVetorDisponivel(vetorRefFornecedores, posicao);
				break;
			case 4:
				verificarDadosVetorDisponivel(vetorRefProdutos, posicao);
				break;
			default:
				erro = Erro_Consulta_NaoPossivel;
		}
		
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
		
	} while(erro == Erro_Consulta_NaoExiste || erro == Erro_Input_ApenasNumeros);
}
