#include "../../global/global.h"
#include "../../arquivo/arquivo.h"
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
	
	char stringExcluir[MAX_STRING];
	switch(tipoTexto) {
		case 1: strcpy(stringExcluir, "Voc� tem certeza que deseja EXCLUIR o cadastro? Essa decis�o � IRREVERS�VEL! "); break;
		case 2: strcpy(stringExcluir, "Voc� tem certeza que deseja ALTERAR TODO o cadastro? Essa decis�o � IRREVERS�VEL!"); break;
	}
	char stringOpcoes[] = "[1] Sim, tenho certeza!\t\t\t[2] N�o, deixe-me pensar...";
		
	if(exibirInterfaceAlerta(stringExcluir, stringOpcoes, "1", false, true, 3)) {
		*pEscolhaUserMod = 0;
		mensagem = Mensagem_Cadastro_Excluido;
		excluirCadastro(posicaoConsultaAtual);
		handleSalvar(escolhaUser);
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceDadosConsulta(contadorDadosExistentes);
	} else {
		exibirInterfaceTitulo(tituloHolder, 1);
		exibirInterfaceFormularios(posicaoConsultaAtual);
		
		*pEscolhaUserMod = 1;
	}
}

