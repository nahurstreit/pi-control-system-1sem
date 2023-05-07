#ifndef INTERFACE_H
#define INTERFACE_H

void interfaceLinhaDivisor();
void interfaceLinhaSimples(char *string, int posicao);
void interfaceLinhaComposta(char *string1, int posicao1, char *string2, int posicao2);

typedef struct {
	char linhaFormulario[103];
} Formulario;

#endif
