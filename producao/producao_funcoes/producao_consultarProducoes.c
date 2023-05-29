#include "../../global/global.h"
#include "../../interface/interface.h"
#include "../../cadastro/cadastro.h"
#include "../../menu/menu.h"
#include "../producao.h"

//Função de exibição de cadastros. A chamada desse função acontece em menu.c dentro de algumas opções.
void consultaProducoes(int *estado) {
	int i, j;
	char posicaoString[MAX_STRING];
	int posicao, contadorDadosExistentes;
	char stringTipo[MAX_STRING];
	
	char stringFiltro[MAX_STRING];
	
	Filtro filtroAtual = 0;
	int limparFiltro = 0;
	
	stringFiltro[0] = '\0';
	
	do{	
		filtroAtual = 0;
		limparFiltro = 0;
		exibirInterfaceTitulo("CONSULTAR E MODIFICAR ORDENS DE PRODUÇÃO", 1);
		strcpy(stringTipo, "Digite o [NÚMERO DA ORDEM DE PRODUÇÃO].");
		
		exibirMensagem();
		exibirErro();
		
		exibirInterfaceDadosConsultaProducao(stringFiltro);
		
		if(erro == Erro_Filtro_NaoExiste) {
			stringFiltro[0] = '\0';
			continue;
		}
		
		printf("Filtrar os resultados:");
		printf("\nPor data, digite: DATA + [DATA],");
		printf("\nPor cliente, digite: CLIENTE + [CPF] ou [Nº Cad.],");
		printf("\nPor funcionário, digite: FUNCIONARIO + [CPF] ou [Nº Cad.],\n");
		printf("Para limpar os filtros, digite: LIMPAR.\n");
		
		printf("\n\nDigite o [Nº] da Ordem de Produção para consultá-la.\nOu então, [0] para VOLTAR à tela anterior.");
		printf("\nConsulta: ");
		
		fgets(posicaoString, MAX_STRING, stdin);
		posicaoString[strcspn(posicaoString, "\n")] = '\0';
		fflush(stdin);
		stringFiltro[0] = '\0';
		
		removerCaracteresEspeciais(posicaoString, true);
		
		if(validarPalavraChave(posicaoString, "0")) {
			erro = 0;
			*estado = 0;
			break;
		}
		
		if(validarPalavraChave(posicaoString, "SAIR")) {
			*estado = 0;
			break;
		}
		
		for(i = 0; i < strlen(posicaoString); i++) {
			posicaoString[i] = toupper(posicaoString[i]);
		}
		
		if(strlen(posicaoString) <= 2 && verificarContemLetras(posicaoString)) {
				limparFiltro++;
				continue;
			}
		
		if(strstr(posicaoString, "DATA") != NULL || strstr(posicaoString, "D ") != NULL) {
			strcpy(stringFiltro, posicaoString);
			filtroAtual = Filtro_Data;
			continue;
		}
		
		if(strstr(posicaoString, "CLIENTE") != NULL || strstr(posicaoString, "C ") != NULL) {
			strcpy(stringFiltro, posicaoString);
			filtroAtual = Filtro_Cliente;
			continue;
		}
		
		if(strstr(posicaoString, "FUNCIONARIO") != NULL || strstr(posicaoString, "F ") != NULL) {
			strcpy(stringFiltro, posicaoString);
			filtroAtual = Filtro_Funcionario;
			continue;
		}
		
		if(validarPalavraChave(posicaoString, "LIMPAR") || validarPalavraChave(posicaoString, "L")) {
			limparFiltro++;
			continue;
		}
		
		popularVetorItens(atoi(posicaoString) - 1);
		
		if(erro == 0) {
			producaoAtiva = atoi(posicaoString) -1;
			*estado = 1;
			break;
		}
		
		if(posicao == 0) {
			erro = 0;
			*estado = 0;
			break;
		}
		
	} while(erro > 0 || filtroAtual > 0 || limparFiltro > 0);
}
