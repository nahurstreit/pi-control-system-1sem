#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../cadastro.h"

void inserirString(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
	float valorUnit;
	
	char idadeMaxima[10];
	char idadeMinima[10];
	receberDataIdade(idadeMaxima, true);
	receberDataIdade(idadeMinima, false);
	
	switch(tipoConsultaAtual) {
		case 1:
			switch(*contadorCampo) {
				case 0:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, false, true, MAX_CAMPO_NOME__CLIENTE)) strcpy(clientes[posicaoDisponivel].nome, string);
					break;
				case 1:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarCPF(string)) strcpy(clientes[posicaoDisponivel].cpf, string);
					break;
				case 2:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarData(string, idadeMaxima, idadeMinima, false, true))strcpy(clientes[posicaoDisponivel].dataNascimento, string);
					break;
				case 3 :
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarTelefone(string)) strcpy(clientes[posicaoDisponivel].telefone, string);
					break;
				case 4:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_EMAIL__CLIENTE)) strcpy(clientes[posicaoDisponivel].email, string);
					break;	
				case 5:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, false, true, true, MAX_CAMPO_ENDERECO__CLIENTE)) strcpy(clientes[posicaoDisponivel].endereco, string);
					break;
				case 6:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, true, false, MAX_CAMPO_NUMENDERECO__CLIENTE)) strcpy(clientes[posicaoDisponivel].numEndereco, string);
					break;
				case 7:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_COMPENDERECO__CLIENTE)) strcpy(clientes[posicaoDisponivel].compEndereco, string);
					break;
				case 8:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, false, true, true, MAX_CAMPO_BAIRRO__CLIENTE)) strcpy(clientes[posicaoDisponivel].bairro, string);
					break;
				case 9:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarCEP(string)) strcpy(clientes[posicaoDisponivel].cep, string);
					break;
				case 10:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, false, true, MAX_CAMPO_CIDADE__CLIENTE)) strcpy(clientes[posicaoDisponivel].cidade, string);
					break;
				default:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEstado(string)) strcpy(clientes[posicaoDisponivel].estado, string);
			}
			break;
		case 2:
			switch(*contadorCampo) {
				case 0:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, false, true, MAX_CAMPO_NOME__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].nome, string);
					break;
				case 1:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarStatus(string)) strcpy(funcionarios[posicaoDisponivel].status, string);
					break;				
				case 2:
					if(validarCPF(string)) strcpy(funcionarios[posicaoDisponivel].cpf, string);
					break;
				case 3:
					if(validarData(string, idadeMaxima, idadeMinima, false, true)) strcpy(funcionarios[posicaoDisponivel].dataNascimento, string);
					break;
				case 4:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEstadoCivil(string)) strcpy(funcionarios[posicaoDisponivel].estadoCivil, string);
					break;
				case 5:
					if(validarData(string, DATA_INICIO_EMPRESA, DATA_LIMITE_FUTURO, true, false)) strcpy(funcionarios[posicaoDisponivel].dataAdmissao, string);
					break;
				case 6:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarTelefone(string)) strcpy(funcionarios[posicaoDisponivel].telefone, string);					
					break;
				case 7:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_EMAIL__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].email, string);
					break;	
				case 8:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, false, true, true, MAX_CAMPO_ENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].endereco, string);
					break;
				case 9:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, true, false, MAX_CAMPO_NUMENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].numEndereco, string);
					break;
				case 10:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_COMPENDERECO__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].compEndereco, string);
					break;
				case 11:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, false, true, true, MAX_CAMPO_BAIRRO__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].bairro, string);
					break;
				case 12:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarCEP(string)) strcpy(funcionarios[posicaoDisponivel].cep, string);
					break;
				case 13:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEntrada(string, true, false, true, MAX_CAMPO_CIDADE__FUNCIONARIO)) strcpy(funcionarios[posicaoDisponivel].cidade, string);
					break;
				default:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					if(validarEstado(string)) strcpy(funcionarios[posicaoDisponivel].estado, string);
			}
			break;
		case 3:
			switch(*contadorCampo) {
				case 0:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_NOMEFANTASIA__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].nomeFantasia, string);
					break;
				case 1:
					if(validarCNPJ(string)) strcpy(fornecedores[posicaoDisponivel].cnpj, string);
					break;
				case 2:
					if(validarTelefone(string)) strcpy(fornecedores[posicaoDisponivel].telefone, string);	
					break;
				case 3:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_EMAIL__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].email, string);
					break;
				case 4:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_SITE__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].site, string);
					break;
				case 5:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_ENDERECO__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].endereco, string);					
					break;
				case 6:
					if(validarEntrada(string, true, true, false, MAX_CAMPO_NUMENDERECO__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].numEndereco, string);					
					break;
				case 7:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_COMPENDERECO__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].compEndereco, string);					
					break;
				case 8:
					if(validarEntrada(string, false, true, true, MAX_CAMPO_BAIRRO__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].bairro, string);
					break;
				case 9:
					if(validarCEP(string)) strcpy(fornecedores[posicaoDisponivel].cep, string);
					break;
				case 10:
					if(validarEntrada(string, true, false, true, MAX_CAMPO_CIDADE__FORNECEDOR)) strcpy(fornecedores[posicaoDisponivel].cidade, string);					
					break;
				default:
					if(validarEstado(string)) strcpy(fornecedores[posicaoDisponivel].estado, string);					
			}
			break;
		case 4:
			switch(*contadorCampo) {
				case 0:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					removerPontoVirgula(string);
					if(validarEntrada(string, false, true, true, 20)) strcpy(produtos[posicaoDisponivel].nomeProduto, string);
					break;
				case 1:
					if(validarEntradaVazia(string)) {
						erro = Erro_Input_CampoObrigatorio; 
						break;
					}
					valorUnit = atof(string);
					produtos[posicaoDisponivel].valorUnitario = valorUnit;
					break;
			}
			break;
	}
}
