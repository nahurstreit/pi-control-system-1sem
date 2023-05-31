#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../producao.h"

void calcularValorTotal() {
	int i;
	float valorTotal = 0.0;
	
	popularVetorItens(producaoAtiva);
	
	for(i = 0; i < calcularDadosExistentes(vetorRefItensComprados); i++) {
		valorTotal += atof(producoes[producaoAtiva].itens[i].valorUnit) * atof(producoes[producaoAtiva].itens[i].quantidade);
	}
	sprintf(producoes[producaoAtiva].valorTotal, "%.2f", valorTotal);
}
