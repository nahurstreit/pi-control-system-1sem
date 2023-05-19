#include "cadastro_var.h"

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

int tipoConsultaAtual;
int posicaoConsultaAtual;

