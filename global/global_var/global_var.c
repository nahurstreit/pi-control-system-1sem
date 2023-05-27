#include "global_var.h"

Menu menuAtual;

int escolhaUser;

Erro erro = 0; //Variável que armazena o valor atual de Erro 
Mensagem mensagem = 0; //Variável que armazena o valor atual de Mensagem

Cliente clientes[MAX_VETOR];
int vetorRefClientes[MAX_VETOR] = {0};

Funcionario funcionarios[MAX_VETOR];
int vetorRefFuncionarios[MAX_VETOR] = {0};

Fornecedor fornecedores[MAX_VETOR];
int vetorRefFornecedores[MAX_VETOR] = {0};

Produto produtos[MAX_VETOR];
int vetorRefProdutos[MAX_VETOR] = {0};

Producao producoes[MAX_VETOR];
int vetorRefProducoes[MAX_VETOR] = {1};

Item itensComprados[MAX_VETOR];
int vetorRefItensComprados[MAX_VETOR] = {0};
