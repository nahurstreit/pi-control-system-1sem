#include "producao_var.h"

Producao producoes[MAX_VETOR];

TextoCampo camposOrdem[] = {
	"a data (H ou Hoje para adicionar a data de hoje)",
	"o [n�mero de cadastro] ou [CPF] do cliente",
	"o [n�mero de cadastro] ou [CPF] do funcion�rio respons�vel",
	"o c�digo do produto",
	"a quantidade",
	"o c�digo do pr�ximo produto ou [0] para salvar a ordem de produ��o",
};

int producaoAtiva;
