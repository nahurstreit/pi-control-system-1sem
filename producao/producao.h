#ifndef PRODUCAO_H
#define PRODUCAO_H

#include "../global/global.h"
#include "../arquivo/arquivo.h"
#include "../validar/validar.h"
#include "../cadastro/cadastro.h"
#include "producao_var/producao_Var.h"

extern void novaOrdem();

extern void inserirStringProd(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);

#endif
