#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../cadastro.h"

void alterarString(int posicao, char stringNova[MAX_STRING], int campo) {
	float valorUnit;
	
	switch(tipoConsultaAtual) {
		case 1:
			switch(campo) {
				case 0:
					if(validarEntrada(stringNova, true, false, true, MAX_CAMPO_NOME__CLIENTE)) strcpy(clientes[posicao].nome, stringNova);
					break;
				case 1:
					if(validarCPF(stringNova)) strcpy(clientes[posicao].cpf, stringNova);
					break;
				case 2:
					if(validarDataNascimento(stringNova)) strcpy(clientes[posicao].dataNascimento, stringNova);
					break;
				case 3 :
					if(validarTelefone(stringNova)) strcpy(clientes[posicao].telefone, stringNova);
					break;
				case 4:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_EMAIL__CLIENTE)) strcpy(clientes[posicao].email, stringNova);
					break;	
				case 5:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_ENDERECO__CLIENTE)) strcpy(clientes[posicao].endereco, stringNova);
					break;
				case 6:
					if(validarEntrada(stringNova, true, true, false, MAX_CAMPO_NUMENDERECO__CLIENTE)) strcpy(clientes[posicao].numEndereco, stringNova);
					break;
				case 7:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_COMPENDERECO__CLIENTE)) strcpy(clientes[posicao].compEndereco, stringNova);
					break;
				case 8:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_BAIRRO__CLIENTE)) strcpy(clientes[posicao].bairro, stringNova);
					break;
				case 9:
					if(validarCEP(stringNova)) strcpy(clientes[posicao].cep, stringNova);
					break;
				case 10:
					if(validarEntrada(stringNova, true, false, true, MAX_CAMPO_CIDADE__CLIENTE)) strcpy(clientes[posicao].cidade, stringNova);
					break;
				default:
					if(validarEstado(stringNova)) strcpy(clientes[posicao].estado, stringNova);
			}
			break;
		case 2:
			switch(campo) {
				case 0:
					if(validarEntrada(stringNova, true, false, true, MAX_CAMPO_NOME__FUNCIONARIO)) strcpy(funcionarios[posicao].nome, stringNova);
					break;
				case 1:
					if(validarStatus(stringNova)) strcpy(funcionarios[posicao].status, stringNova);
					break;				
				case 2:
					if(validarCPF(stringNova)) strcpy(funcionarios[posicao].cpf, stringNova);
					break;
				case 3:
					if(validarDataNascimento(stringNova)) strcpy(funcionarios[posicao].dataNascimento, stringNova);					
					break;
				case 4:
					if(validarEstadoCivil(stringNova)) strcpy(funcionarios[posicao].estadoCivil, stringNova);
					break;
				case 5:
					if(validarDataAdmissao(stringNova)) strcpy(funcionarios[posicao].dataAdmissao, stringNova);
					break;
				case 6:
					if(validarEntrada(stringNova, false, true, false, 10)) strcpy(funcionarios[posicao].salarioBase, stringNova);
					break;
				case 7:
					if(validarTelefone(stringNova)) strcpy(funcionarios[posicao].telefone, stringNova);					
					break;
				case 8:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_EMAIL__FUNCIONARIO)) strcpy(funcionarios[posicao].email, stringNova);
					break;	
				case 9:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_ENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicao].endereco, stringNova);
					break;
				case 10:
					if(validarEntrada(stringNova, true, true, false, MAX_CAMPO_NUMENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicao].numEndereco, stringNova);
					break;
				case 11:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_COMPENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicao].compEndereco, stringNova);
					break;
				case 12:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_BAIRRO__FUNCIONARIO)) strcpy(funcionarios[posicao].bairro, stringNova);
					break;
				case 13:
					if(validarCEP(stringNova)) strcpy(funcionarios[posicao].cep, stringNova);
					break;
				case 14:
					if(validarEntrada(stringNova, true, false, true, MAX_CAMPO_CIDADE__FUNCIONARIO)) strcpy(funcionarios[posicao].cidade, stringNova);
					break;
				default: 
					if(validarEstado(stringNova)) strcpy(funcionarios[posicao].estado, stringNova);
			}
			break;
		case 3:
			switch(campo) {
				case 0:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_NOMEFANTASIA__FORNECEDOR)) strcpy(fornecedores[posicao].nomeFantasia, stringNova);
					break;
				case 1:
					if(validarCNPJ(stringNova)) strcpy(fornecedores[posicao].cnpj, stringNova);
					break;
				case 2:
					if(validarTelefone(stringNova)) strcpy(fornecedores[posicao].telefone, stringNova);	
					break;
				case 3:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_EMAIL__FORNECEDOR)) strcpy(fornecedores[posicao].email, stringNova);
					break;
				case 4:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_SITE__FORNECEDOR)) strcpy(fornecedores[posicao].site, stringNova);
					break;
				case 5:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_ENDERECO__FORNECEDOR)) strcpy(fornecedores[posicao].endereco, stringNova);					
					break;
				case 6:
					if(validarEntrada(stringNova, true, true, false, MAX_CAMPO_NUMENDERECO__FORNECEDOR)) strcpy(fornecedores[posicao].numEndereco, stringNova);					
					break;
				case 7:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_COMPENDERECO__FORNECEDOR)) strcpy(fornecedores[posicao].compEndereco, stringNova);					
					break;
				case 8:
					if(validarEntrada(stringNova, false, true, true, MAX_CAMPO_BAIRRO__FORNECEDOR)) strcpy(fornecedores[posicao].bairro, stringNova);
					break;
				case 9:
					if(validarCEP(stringNova)) strcpy(fornecedores[posicao].cep, stringNova);
					break;
				case 10:
					if(validarEntrada(stringNova, true, false, true, MAX_CAMPO_CIDADE__FORNECEDOR)) strcpy(fornecedores[posicao].cidade, stringNova);					
					break;
				default:
					if(validarEstado(stringNova)) strcpy(fornecedores[posicao].estado, stringNova);					
			}
			break;
		case 4:
			switch(campo) {
				case 0:
					removerPontoVirgula(stringNova);
					if(validarEntrada(stringNova, false, true, true, 30)) strcpy(produtos[posicao].nomeProduto, stringNova);
					break;
				case 1:
					valorUnit = atof(stringNova);
					produtos[posicao].valorUnitario = valorUnit;
					break;
			}
			break;
	}
}
