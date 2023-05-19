#include "../../global/global.h"
#include "../cadastro.h"

void executarExcluirCadastro(int tipoTexto, int *pEscolhaUserMod) {
	int escolhaAlterar = 0, contadorDadosExistentes = 0;
	
	char tituloHolder[50];
	
	switch(tipoConsultaAtual) {
		case 1: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE CLIENTES"); break;
		case 2: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FUNCIONARIOS"); break;
		case 3: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES"); break;
	}
	
	exibirInterfaceTitulo("ATEN��O!", 1);
	
	switch(tipoConsultaAtual) {
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
	
	switch(tipoTexto) {
		case 1: exibirInterfaceAlerta("Voc� tem certeza que deseja EXCLUIR o cadastro? Essa decis�o � IRREVERS�VEL! "); break;
		case 2: exibirInterfaceAlerta("Voc� tem certeza que deseja ALTERAR TODO o cadastro? Essa decis�o � IRREVERS�VEL!"); break;
	}
	
	printf("\n\n[1] Sim, tenho certeza!\t\t[2] N�o, deixe-me pensar...\n\n");
	printf("Op��o: ");
	scanf("%d", &escolhaAlterar);
	fflush(stdin);
		
	if(escolhaAlterar == 1) {
		*pEscolhaUserMod = 0;
		mensagem = 3;
		excluirCadastro(posicaoConsultaAtual);
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
	} else {
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceFormularios(posicaoConsultaAtual);
	}
}

