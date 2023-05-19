#include "cadastro_var.h"

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

int tipoConsultaAtual;
int posicaoConsultaAtual;

