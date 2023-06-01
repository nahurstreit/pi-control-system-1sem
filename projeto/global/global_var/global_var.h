#ifndef GLOBAL_VAR_H
#define GLOBAL_VAR_H

#include "../global_define.h"
#include "../global_struct.h"
#include "../global_enum.h"

extern Menu menuAtual;

extern 	int escolhaUser; //Variável que armazenará qual é o valor digitado pelo usuário nas opções do Menu.

extern Erro erro;
extern Mensagem mensagem;

//Vetores para armazenar e controlar o armazenamento dos clientes
extern Cliente clientes[MAX_VETOR];
extern int vetorRefClientes[MAX_VETOR];

extern Funcionario funcionarios[MAX_VETOR];
extern int vetorRefFuncionarios[MAX_VETOR];

extern Fornecedor fornecedores[MAX_VETOR];
extern int vetorRefFornecedores[MAX_VETOR];

extern Produto produtos[MAX_VETOR];
extern int vetorRefProdutos[MAX_VETOR];

extern Producao producoes[MAX_VETOR];
extern int vetorRefProducoes[MAX_VETOR];

extern Item itensComprados[MAX_VETOR];
extern int vetorRefItensComprados[MAX_VETOR];
#endif
