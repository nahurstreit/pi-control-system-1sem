#ifndef GLOBAL_VETOR_H
#define GLOBAL_VETOR_H

//Cadastro
//Criação dos vetores para armazenar e controlar o armazenamento dos clientes
	//Vetor de dados
		Cliente clientes[MAX_VETOR];
	//
	
	//Vetor de referência
		int vetorRefClientes[MAX_VETOR] = {0};
		int *pVetorRefClientes = vetorRefClientes; 	//Pointer para o vetor de referência
	//
//
//Criação dos vetores para armazenar e controlar o armazenamento dos funcionários
	//Vetor de dados
		Funcionario funcionarios[MAX_VETOR];
	//

	//Vetor de referência
		int vetorRefFuncionarios[MAX_VETOR] = {0};
		int *pVetorRefFuncionarios = vetorRefFuncionarios;
	//
//
//Criação dos vetores para armazenar e controlar o armazenamento dos fornecedores
	//Vetor de dados
		Fornecedor fornecedores[MAX_VETOR];
	//

	//Vetor de referência
		int vetorRefFornecedores[MAX_VETOR] = {0};
		int *pVetorRefFornecedores = vetorRefFornecedores;
	//
//


//Criação da vetor com nome camposCliente que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Cliente
TextoCampo camposCliente[] = {
	"o nome do cliente",
	"o CPF",
	"a data de nascimento",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Criação da vetor com nome camposFuncionario que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Funcionário
TextoCampo camposFuncionario[] = {
	"o nome do funcionário",
	"o status na empresa",
	"o CPF",
	"a data de nascimento",
	"o estado civil",
	"a data de admissão",
	"o salario base (R$)",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Criação da vetor com nome camposFornecedor que é do tipo TextoCampo. Refere-se aos textos que serão exibidos ao pedir para os usuários digitarem os dados de cadastro do Fornecedor
TextoCampo camposFornecedor[] = {
	"o nome fantasia",
	"o CNPJ",
	"o telefone",
	"o email",
	"o endereço",
	"o número",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

TextoCampo *camposAtuais;

#endif
