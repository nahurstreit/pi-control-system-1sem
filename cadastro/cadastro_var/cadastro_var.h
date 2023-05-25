#ifndef CADASTRO_VAR_H
#define CADASTRO_VAR_H

#include "../../global/global.h"

//Criação da vetor com nome camposCliente que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Cliente
extern TextoCampo camposCliente[];

//Criação da vetor com nome camposFuncionario que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Funcionário
extern TextoCampo camposFuncionario[];

//Criação da vetor com nome camposFornecedor que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Fornecedor
extern TextoCampo camposFornecedor[];

extern TextoCampo camposProduto[];

//Criação da variável global camposAtuais, do tipo TextoCamp, que será um pointer para os camposFuncionario, camposCliente ou camposFornecedor
extern TextoCampo *camposAtuais;

extern int tipoConsultaAtual;
extern int posicaoConsultaAtual;

#endif
