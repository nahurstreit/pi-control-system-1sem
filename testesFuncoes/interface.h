#ifndef INTERFACE_H
#define INTERFACE_H

#include "menu.h"
#include "cadastro.h"

#define MAX_LINHA 103
#define MAX_CABECALHO 3

typedef struct {
	char linhaDisplay[MAX_LINHA];
} Display;

//Funções de interface:
void exibirInterfaceFormularios(Cliente clientes[], Funcionario funcionarios[], Fornecedor fornecedores[], int *pEscolhaUser, int posicao);

void exibirInterfaceDadosConsulta(Cliente clientes[], int vetorRefClientes[], Funcionario funcionarios[], int vetorRefFuncionarios[], Fornecedor fornecedores[], int vetorRefFornecedores[], int *pEscolhaUser, int contadorDadosExistentes);

void exibirInterfaceTitulo(char string[], int limpar);

void exibirCabecalhoAtual(Display *displayCabecalhoAtual);

void exibirInterfaceInteracao(char string[]);

void exibirInterfaceOpcoes(Menu *pMenuAtual);

void exibirTextoMeio(char string[]);

#endif
