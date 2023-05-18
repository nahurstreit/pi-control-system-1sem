#include "global_var.h"

Menu menuAtual;

int escolhaUser;

int erro = 0; //Variável que armazena o valor atual de Erro 
int mensagem = 0; //Variável que armazena o valor atual de Mensagem

Cliente clientes[MAX_VETOR];
int vetorRefClientes[MAX_VETOR] = {0};

Funcionario funcionarios[MAX_VETOR];
int vetorRefFuncionarios[MAX_VETOR] = {0};

Fornecedor fornecedores[MAX_VETOR];
int vetorRefFornecedores[MAX_VETOR] = {0};
