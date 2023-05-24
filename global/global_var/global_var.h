#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include "../global_define.h"
#include "../global_struct.h"
#include "../global_enum.h"

extern Menu menuAtual;

extern 	int escolhaUser; //Vari�vel que armazenar� qual � o valor digitado pelo usu�rio nas op��es do Menu.

extern Erro erro;
extern Mensagem mensagem;

//Vetores para armazenar e controlar o armazenamento dos clientes
extern Cliente clientes[MAX_VETOR];
extern int vetorRefClientes[MAX_VETOR];

extern Funcionario funcionarios[MAX_VETOR];
extern int vetorRefFuncionarios[MAX_VETOR];

extern Fornecedor fornecedores[MAX_VETOR];
extern int vetorRefFornecedores[MAX_VETOR];



#endif
