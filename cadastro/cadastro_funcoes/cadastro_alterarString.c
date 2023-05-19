#include "../../global/global.h"
#include "../cadastro.h"

void alterarString(int posicao, char stringNova[MAX_STRING], int campo) {
	switch(escolhaUser) {
		case 1:
			switch(campo) {
				case 0:
					strcpy(clientes[posicao].nome, stringNova);
					break;
				case 1:
					strcpy(clientes[posicao].cpf, stringNova);
					break;
				case 2:
					strcpy(clientes[posicao].dataNascimento, stringNova);
					break;
				case 3 :
					strcpy(clientes[posicao].telefone, stringNova);
					break;
				case 4:
					strcpy(clientes[posicao].email, stringNova);
					break;	
				case 5:
					strcpy(clientes[posicao].endereco, stringNova);
					break;
				case 6:
					strcpy(clientes[posicao].numEndereco, stringNova);
					break;
				case 7:
					strcpy(clientes[posicao].compEndereco, stringNova);
					break;
				case 8:
					strcpy(clientes[posicao].bairro, stringNova);
					break;
				case 9:
					strcpy(clientes[posicao].cep, stringNova);
					break;
				case 10:
					strcpy(clientes[posicao].cidade, stringNova);
					break;
				default:
					strcpy(clientes[posicao].estado, stringNova);
			}
			break;
		case 2:
			switch(campo) {
				case 0:
					strcpy(funcionarios[posicao].nome, stringNova);
					break;
				case 1:
					strcpy(funcionarios[posicao].status, stringNova);
					break;				
				case 2:
					strcpy(funcionarios[posicao].cpf, stringNova);
					break;
				case 3:
					strcpy(funcionarios[posicao].dataNascimento, stringNova);
					break;
				case 4:
					strcpy(funcionarios[posicao].estadoCivil, stringNova);
					break;
				case 5:
					strcpy(funcionarios[posicao].dataAdmissao, stringNova);
					break;
				case 6:
					strcpy(funcionarios[posicao].salarioBase, stringNova);
					break;
				case 7:
					strcpy(funcionarios[posicao].telefone, stringNova);
					break;
				case 8:
					strcpy(funcionarios[posicao].email, stringNova);
					break;	
				case 9:
					strcpy(funcionarios[posicao].endereco, stringNova);
					break;
				case 10:
					strcpy(funcionarios[posicao].numEndereco, stringNova);
					break;
				case 11:
					strcpy(funcionarios[posicao].compEndereco, stringNova);
					break;
				case 12:
					strcpy(funcionarios[posicao].bairro, stringNova);
					break;
				case 13:
					strcpy(funcionarios[posicao].cep, stringNova);
					break;
				case 14:
					strcpy(funcionarios[posicao].cidade, stringNova);
					break;
				default: 
					strcpy(funcionarios[posicao].estado, stringNova);
			}
			break;
		case 3:
			switch(campo) {
				case 0:
					strcpy(fornecedores[posicao].nomeFantasia, stringNova);
					break;
				case 1:
					strcpy(fornecedores[posicao].cnpj, stringNova);
					break;
				case 2:
					strcpy(fornecedores[posicao].telefone, stringNova);
					break;
				case 3:
					strcpy(fornecedores[posicao].email, stringNova);
					break;
				case 4:
					strcpy(fornecedores[posicao].endereco, stringNova);
					break;
				case 5:
					strcpy(fornecedores[posicao].numEndereco, stringNova);
					break;
				case 6:
					strcpy(fornecedores[posicao].compEndereco, stringNova);
					break;
				case 7:
					strcpy(fornecedores[posicao].bairro, stringNova);
					break;
				case 8:
					strcpy(fornecedores[posicao].cep, stringNova);
					break;
				case 9:
					strcpy(fornecedores[posicao].cidade, stringNova);
					break;
				default: 
					strcpy(fornecedores[posicao].estado, stringNova);
			}
			break;
	}
}
