#include "producao_var.h"

Producao producoes[MAX_VETOR];

TextoCampo camposOrdem[] = {
	"a data (H ou Hoje para adicionar a data de hoje)",
	"o [número de cadastro] ou [CPF] do cliente",
	"o [número de cadastro] ou [CPF] do funcionário responsável",
	"o código do item comprado",
	"a quantidade desse item",
	"o código do próximo item ou [0] para salvar a ordem de produção",
};
