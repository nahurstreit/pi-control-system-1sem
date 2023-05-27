#ifndef CADASTRO_VAR_H
#define CADASTRO_VAR_H

#include "../../global/global.h"

//Cria��o da vetor com nome camposCliente que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Cliente
extern TextoCampo camposCliente[];

//Cria��o da vetor com nome camposFuncionario que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Funcion�rio
extern TextoCampo camposFuncionario[];

//Cria��o da vetor com nome camposFornecedor que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Fornecedor
extern TextoCampo camposFornecedor[];

extern TextoCampo camposProduto[];

//Cria��o da vari�vel global camposAtuais, do tipo TextoCamp, que ser� um pointer para os camposFuncionario, camposCliente ou camposFornecedor
extern TextoCampo *camposAtuais;

extern int tipoConsultaAtual;
extern int posicaoConsultaAtual;

#endif
