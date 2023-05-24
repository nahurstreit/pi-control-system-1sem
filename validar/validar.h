#ifndef VALIDAR_H
#define VALIDAR_H
#include "../global/global.h"

//Funções de remoção
void removerCaracteresEspeciais(char *pString, bool permitirEspacos);

//Funções de verificação
bool verificarContemLetras(char pString[]);
bool verificarContemNumeros(char pString[]);
bool verificarQtdDigitos(char string[], int quantidade);
bool validarEntrada(char *pString, bool removerCaracteresEspeciais, bool permitirNumeros, bool permitirLetras, int tamanhoMaximoString);

//Funções de conversão
void vetorStringParaInteiro(char *pString, int *pVetorIntDestino, int qtdChar);
void vetorInteiroParaString(int pVetor[], char pString[], int caso);

//Funções de Validação
extern bool validarCPF(char *pCpf);
extern bool validarCNPJ(char *pCnpj);

extern bool validarStatus(char *pString);

extern bool validarDataNascimento(char pString[]);
extern bool validarDataAdmissao(char pString[]);

extern bool validarEstadoCivil(char *pString);

extern bool validarTelefone(char *pString);

extern bool validarCEP(char *pString);

extern bool validarEstado(char pString[]);

extern bool validarPalavraChave(char string[], char stringChave[]); 

#endif
