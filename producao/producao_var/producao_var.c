#include "producao_var.h"

Producao producoes[MAX_VETOR];

TextoCampo camposOrdem[] = {
	"a data (H ou Hoje para adicionar a data de hoje)",
	"o [número de cadastro] ou [CPF] do cliente",
	"o [número de cadastro] ou [CPF] do funcionário responsável",
	"o código do produto",
	"a quantidade",
	"o código do próximo produto ou [0] para salvar a ordem de produção",
};

int producaoAtiva;
