#include "../../global/global.h"
#include "../cadastro.h"

//Fun��o de exibi��o de cadastros. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
void consultaCadastro(int *estado) {
	int posicao, contadorDadosExistentes;
	
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
	}
	
	do{
		if(escolhaUser == 1) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE CLIENTES", 1);
		 else if(escolhaUser == 2) exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FUNCION�RIOS", 1);
		 else exibirInterfaceTitulo("CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES", 1);
		
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
	
		switch(escolhaUser) {
			case 1:
				printf("\nDigite o n�mero de cadastro do Cliente ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefClientes, posicao);
				break;
			case 2:
				printf("\nDigite o n�mero de cadastro do Funcion�rio ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefFuncionarios, posicao);
				break;
			case 3:
				printf("\nDigite o n�mero de cadastro do Fornecedor ou [0] para Voltar: ");
				scanf("%d", &posicao);
				verificarDadosVetorDisponivel(vetorRefFornecedores, posicao);
				break;
			default:
				 erro = Erro_Consulta_NaoPossivel;
		}
		
		posicaoConsultaAtual = posicao-1;
		
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
		
		fflush(stdin);
	} while(erro == Erro_Consulta_NaoExiste);
}
