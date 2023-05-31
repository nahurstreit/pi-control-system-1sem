#include "../../global/global.h"
#include "../cadastro.h"

void excluirCadastro(int posicaoConsultaAtual) {
	switch(tipoConsultaAtual) {
		case 1:
			strcpy(clientes[posicaoConsultaAtual].nome, "");
			strcpy(clientes[posicaoConsultaAtual].cpf, "");
			strcpy(clientes[posicaoConsultaAtual].dataNascimento, "");
			strcpy(clientes[posicaoConsultaAtual].telefone, "");
			strcpy(clientes[posicaoConsultaAtual].email, "");
			strcpy(clientes[posicaoConsultaAtual].endereco, "");
			strcpy(clientes[posicaoConsultaAtual].numEndereco, "");
			strcpy(clientes[posicaoConsultaAtual].compEndereco, "");
			strcpy(clientes[posicaoConsultaAtual].bairro, "");
			strcpy(clientes[posicaoConsultaAtual].cep, "");
			strcpy(clientes[posicaoConsultaAtual].cidade, "");
			strcpy(clientes[posicaoConsultaAtual].estado, "");
			vetorRefClientes[posicaoConsultaAtual] = 0;
			break;
		case 2:
			strcpy(funcionarios[posicaoConsultaAtual].nome, "");
			strcpy(funcionarios[posicaoConsultaAtual].status, "");
			strcpy(funcionarios[posicaoConsultaAtual].cpf, "");
			strcpy(funcionarios[posicaoConsultaAtual].dataNascimento, "");
			strcpy(funcionarios[posicaoConsultaAtual].estadoCivil, "");
			strcpy(funcionarios[posicaoConsultaAtual].dataAdmissao, "");
			strcpy(funcionarios[posicaoConsultaAtual].salarioBase, "");
			strcpy(funcionarios[posicaoConsultaAtual].telefone, "");
			strcpy(funcionarios[posicaoConsultaAtual].email, "");
			strcpy(funcionarios[posicaoConsultaAtual].endereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].numEndereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].compEndereco, "");
			strcpy(funcionarios[posicaoConsultaAtual].bairro, "");
			strcpy(funcionarios[posicaoConsultaAtual].cep, "");
			strcpy(funcionarios[posicaoConsultaAtual].cidade, "");
			strcpy(funcionarios[posicaoConsultaAtual].estado, "");
			vetorRefFuncionarios[posicaoConsultaAtual] = 0;
			break;
		case 3:
			strcpy(fornecedores[posicaoConsultaAtual].nomeFantasia, "");
			strcpy(fornecedores[posicaoConsultaAtual].cnpj, "");
			strcpy(fornecedores[posicaoConsultaAtual].telefone, "");
			strcpy(fornecedores[posicaoConsultaAtual].email, "");
			strcpy(fornecedores[posicaoConsultaAtual].site, "");
			strcpy(fornecedores[posicaoConsultaAtual].endereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].numEndereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].compEndereco, "");
			strcpy(fornecedores[posicaoConsultaAtual].bairro, "");
			strcpy(fornecedores[posicaoConsultaAtual].cep, "");
			strcpy(fornecedores[posicaoConsultaAtual].cidade, "");
			strcpy(fornecedores[posicaoConsultaAtual].estado, "");
			vetorRefFornecedores[posicaoConsultaAtual] = 0;
			break;
		case 4:
			strcpy(produtos[posicaoConsultaAtual].nomeProduto, "");
			produtos[posicaoConsultaAtual].valorUnitario = 0.0;
			vetorRefProdutos[posicaoConsultaAtual] = 0;
			break;
	}
}
