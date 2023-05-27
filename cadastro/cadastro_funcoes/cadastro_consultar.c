#include "../../global/global.h"
#include "../cadastro.h"

//Fun��o de exibi��o de cadastros. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
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
				strcpy(stringTipo, "Digite o [N�MERO DE CADASTRO] ou [CPF] do Cliente para consult�-lo.");
				break;
			case 2:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCION�RIOS", 1);
				strcpy(stringTipo, "Digite o [N�MERO DE CADASTRO] ou [CPF] do Funcion�rio para consult�-lo.");
				break;
			case 3:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
				strcpy(stringTipo, "Digite o [N�MERO DE CADASTRO] ou [CNPJ] do Fornecedor para consult�-lo.");
				break;
			case 4:
				exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE PROTUDOS", 1);
				strcpy(stringTipo, "Digite o [N�MERO DE CADASTRO] do Produto para consult�-lo");
				break;
			default:
				erro = Erro_Consulta_NaoPossivel;
		}
		
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
		
		printf("%s\n", stringTipo);
		printf("Ou ent�o, digite [0] para VOLTAR � tela anterior.\n\nConsulta: ");
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
		 	else if(escolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCION�RIOS", 1);
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
