#include "../../global/global.h"
#include "../cadastro.h"

void inserirString(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
	switch(escolhaUser) {
		case 1:
			switch(*contadorCampo) {
				case 0:
					strcpy(clientes[posicaoDisponivel].nome, string);
					break;
				case 1:
					strcpy(clientes[posicaoDisponivel].cpf, string);
					break;
				case 2:
					strcpy(clientes[posicaoDisponivel].dataNascimento, string);
					break;
				case 3 :
					strcpy(clientes[posicaoDisponivel].telefone, string);
					break;
				case 4:
					strcpy(clientes[posicaoDisponivel].email, string);
					break;	
				case 5:
					strcpy(clientes[posicaoDisponivel].endereco, string);
					break;
				case 6:
					strcpy(clientes[posicaoDisponivel].numEndereco, string);
					break;
				case 7:
					strcpy(clientes[posicaoDisponivel].compEndereco, string);
					break;
				case 8:
					strcpy(clientes[posicaoDisponivel].bairro, string);
					break;
				case 9:
					strcpy(clientes[posicaoDisponivel].cep, string);
					break;
				case 10:
					strcpy(clientes[posicaoDisponivel].cidade, string);
					break;
				default:
					strcpy(clientes[posicaoDisponivel].estado, string);
			}
			break;
		case 2:
			switch(*contadorCampo) {
				case 0:
					strcpy(funcionarios[posicaoDisponivel].nome, string);
					break;
				case 1:
					strcpy(funcionarios[posicaoDisponivel].status, string);
					break;				
				case 2:
					strcpy(funcionarios[posicaoDisponivel].cpf, string);
					break;
				case 3:
					strcpy(funcionarios[posicaoDisponivel].dataNascimento, string);
					break;
				case 4:
					strcpy(funcionarios[posicaoDisponivel].estadoCivil, string);
					break;
				case 5:
					strcpy(funcionarios[posicaoDisponivel].dataAdmissao, string);
					break;
				case 6:
					strcpy(funcionarios[posicaoDisponivel].salarioBase, string);
					break;
				case 7:
					strcpy(funcionarios[posicaoDisponivel].telefone, string);
					break;
				case 8:
					strcpy(funcionarios[posicaoDisponivel].email, string);
					break;	
				case 9:
					strcpy(funcionarios[posicaoDisponivel].endereco, string);
					break;
				case 10:
					strcpy(funcionarios[posicaoDisponivel].numEndereco, string);
					break;
				case 11:
					strcpy(funcionarios[posicaoDisponivel].compEndereco, string);
					break;
				case 12:
					strcpy(funcionarios[posicaoDisponivel].bairro, string);
					break;
				case 13:
					strcpy(funcionarios[posicaoDisponivel].cep, string);
					break;
				case 14:
					strcpy(funcionarios[posicaoDisponivel].cidade, string);
					break;
				default: 
					strcpy(funcionarios[posicaoDisponivel].estado, string);
			}
			break;
		case 3:
			switch(*contadorCampo) {
				case 0:
					strcpy(fornecedores[posicaoDisponivel].nomeFantasia, string);
					break;
				case 1:
					strcpy(fornecedores[posicaoDisponivel].cnpj, string);
					break;
				case 2:
					strcpy(fornecedores[posicaoDisponivel].telefone, string);
					break;
				case 3:
					strcpy(fornecedores[posicaoDisponivel].email, string);
					break;
				case 4:
					strcpy(fornecedores[posicaoDisponivel].endereco, string);
					break;
				case 5:
					strcpy(fornecedores[posicaoDisponivel].numEndereco, string);
					break;
				case 6:
					strcpy(fornecedores[posicaoDisponivel].compEndereco, string);
					break;
				case 7:
					strcpy(fornecedores[posicaoDisponivel].bairro, string);
					break;
				case 8:
					strcpy(fornecedores[posicaoDisponivel].cep, string);
					break;
				case 9:
					strcpy(fornecedores[posicaoDisponivel].cidade, string);
					break;
				default: 
					strcpy(fornecedores[posicaoDisponivel].estado, string);
			}
			break;
	}
}
