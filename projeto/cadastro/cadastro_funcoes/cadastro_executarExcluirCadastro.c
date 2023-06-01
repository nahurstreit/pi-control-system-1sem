#include "../../global/global.h"
#include "../../arquivo/arquivo.h"
#include "../cadastro.h"

void executarExcluirCadastro() {
	int escolhaAlterar = 0, contadorDadosExistentes = 0;
	
	char tituloHolder[50];
	
	switch(tipoConsultaAtual) {
		case 1: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE CLIENTES"); break;
		case 2: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FUNCIONARIOS"); break;
		case 3: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE FORNECEDORES"); break;
		case 4: strcpy(tituloHolder, "CONSULTAR E MODIFICAR CADASTROS DE PRODUTOS"); break;
	}
	
	exibirInterfaceTitulo("ATENÇÃO!", 1);
	
	char stringExcluir[] = "Você tem certeza que deseja EXCLUIR o cadastro? Essa decisão é IRREVERSÍVEL! ";
	char stringOpcoes[] = "[1] Sim, tenho certeza!\t\t\t[2] Não, deixe-me pensar...";
		
	if(exibirInterfaceAlerta(stringExcluir, stringOpcoes, "1", false, true, 3)) {
		excluirCadastro(posicaoConsultaAtual);
		handleSalvar(tipoConsultaAtual);
	}
}

