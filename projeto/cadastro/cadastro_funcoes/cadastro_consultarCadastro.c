#include "../../global/global.h"
#include "../cadastro.h"

//Fun��o de exibi��o de cadastros. A chamada desse fun��o acontece em menu.c dentro de algumas op��es.
void consultaCadastro(int *estado) {
	char posicaoString[MAX_STRING];
	int posicao, contadorDadosExistentes;
	char stringTipo[MAX_STRING];
	
	if(escolhaUser != 0 && escolhaUser != 9) tipoConsultaAtual = escolhaUser;
	*estado = 0;
	
	int i;
	
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
		case 4:
			contadorDadosExistentes = calcularDadosExistentes(vetorRefProdutos);
			break;
	}
	
	filtroAtual = 0;
	
	do{
		switch(tipoConsultaAtual) {
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
		if(filtroAtual == Filtro_Limpar) filtroAtual = 0;
		
		exibirInterfaceDadosConsulta(contadorDadosExistentes, filtroAtual, posicaoString);
		filtroAtual = 0;
		
		printf("Filtros:\n");
		printf("NOME + Nome pesquisado.\n");
		if(tipoConsultaAtual == 2) printf("STATUS + 'Ativo' ou 'Inativo'.\n");
		if(tipoConsultaAtual <= 2) printf("DATA + Data de nascimento.\n");
		printf("LIMPAR = Limpa os filtros.\n");	
		printf("\n%s\n", stringTipo);
		printf("Ou ent�o, digite [0] para VOLTAR � tela anterior.\nConsulta: ");
		fgets(posicaoString, MAX_STRING, stdin);
		posicaoString[strcspn(posicaoString, "\n")] = '\0';
		fflush(stdin);

		for(i = 0; i < strlen(posicaoString); i++) {
			posicaoString[i] = toupper(posicaoString[i]);
		}
		
		if(strstr(posicaoString, "NOME")) {
			filtroAtual = Filtro_Nome;
			continue;
		} else if(strstr(posicaoString, "DATA") && tipoConsultaAtual < 3) {
			filtroAtual = Filtro_Data;
			continue;
		} else if(strstr(posicaoString, "STATUS") && tipoConsultaAtual == 2){
			filtroAtual = Filtro_Status;
			continue;
		} else if(strstr(posicaoString, "LIMPAR")){
			filtroAtual = Filtro_Limpar;
			continue;
		} else if(verificarContemLetras(posicaoString)) {
			erro = Erro_Input_ConsultaCadastro_Filtro_Invalido;
			continue;
		} else if(strlen(posicaoString) > 1 && strlen(posicaoString) >= 11) {
			posicao = consultarCPFouCNPJ(posicaoString);
			posicaoConsultaAtual = posicao - 1;
		} else {
			posicao = atoi(posicaoString);
			posicaoConsultaAtual = posicao - 1;
		}
		
		switch(tipoConsultaAtual) {
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
			*estado = 1;
			break;
		}
		
		if(posicao == 0) {
			erro = 0;
			*estado = 0;
			break;
		}
		
	} while(erro > 0 || filtroAtual > 0);
}
