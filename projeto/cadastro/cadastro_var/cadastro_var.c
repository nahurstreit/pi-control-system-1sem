#include "cadastro_var.h"

TextoCampo camposCliente[] = {
	"o nome do cliente",
	"o CPF",
	"a data de nascimento",
	"o telefone (com DDD)",
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
	"o status na empresa ([1] Ativo, [0] Inativo)",
	"o CPF",
	"a data de nascimento",
	"o estado civil (Solteiro / Casado / Divorciado / Viuvo)",
	"a data de admiss�o (H ou Hoje para adicionar a data de hoje)",
	"o salario base (R$)",
	"o telefone (com DDD)",
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
	"o telefone (com DDD)",
	"o email",
	"o site (se houver)",
	"o endere�o",
	"o n�mero",
	"o complemento (se houver)",
	"o bairro",
	"o CEP",
	"a cidade",
	"o estado (sigla)",
};

TextoCampo camposProduto[] = {
	"o nome do produto",
	"o valor unit�rio de venda produto",
};

TextoCampo *camposAtuais;

int tipoConsultaAtual;
int posicaoConsultaAtual;

Filtro filtroAtual;

