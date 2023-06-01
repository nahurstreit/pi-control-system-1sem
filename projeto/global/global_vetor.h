#ifndef GLOBAL_VETOR_H
#define GLOBAL_VETOR_H

//Cadastro
//Cria��o dos vetores para armazenar e controlar o armazenamento dos clientes
	//Vetor de dados
		Cliente clientes[MAX_VETOR];
	//
	
	//Vetor de refer�ncia
		int vetorRefClientes[MAX_VETOR] = {0};
		int *pVetorRefClientes = vetorRefClientes; 	//Pointer para o vetor de refer�ncia
	//
//
//Cria��o dos vetores para armazenar e controlar o armazenamento dos funcion�rios
	//Vetor de dados
		Funcionario funcionarios[MAX_VETOR];
	//

	//Vetor de refer�ncia
		int vetorRefFuncionarios[MAX_VETOR] = {0};
		int *pVetorRefFuncionarios = vetorRefFuncionarios;
	//
//
//Cria��o dos vetores para armazenar e controlar o armazenamento dos fornecedores
	//Vetor de dados
		Fornecedor fornecedores[MAX_VETOR];
	//

	//Vetor de refer�ncia
		int vetorRefFornecedores[MAX_VETOR] = {0};
		int *pVetorRefFornecedores = vetorRefFornecedores;
	//
//


//Cria��o da vetor com nome camposCliente que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Cliente
TextoCampo camposCliente[] = {
	"o nome do cliente",
	"o CPF",
	"a data de nascimento",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Cria��o da vetor com nome camposFuncionario que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Funcion�rio
TextoCampo camposFuncionario[] = {
	"o nome do funcion�rio",
	"o status na empresa",
	"o CPF",
	"a data de nascimento",
	"o estado civil",
	"a data de admiss�o",
	"o salario base (R$)",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

//Cria��o da vetor com nome camposFornecedor que � do tipo TextoCampo. Refere-se aos textos que ser�o exibidos ao pedir para os usu�rios digitarem os dados de cadastro do Fornecedor
TextoCampo camposFornecedor[] = {
	"o nome fantasia",
	"o CNPJ",
	"o telefone",
	"o email",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

TextoCampo *camposAtuais;

#endif
