#ifndef VALIDAR_H
#define VALIDAR_H
#include "../global/global.h"

//Fun��es de remo��o
void removerCaracteresEspeciais(char *pString, bool permitirEspacos);
void removerPontoVirgula(char *pString);

//Fun��es de verifica��o
bool verificarContemLetras(char pString[]);
bool verificarContemNumeros(char pString[]);
bool verificarQtdDigitos(char string[], int quantidade);
bool validarEntrada(char *pString, bool removerCaracteresEspeciais, bool permitirNumeros, bool permitirLetras, int tamanhoMaximoString);

//Fun��es de convers�o
void vetorStringParaInteiro(char *pString, int *pVetorIntDestino, int qtdChar);
void vetorInteiroParaString(int pVetor[], char pString[], int caso);
void receberAnoAtual(char data[]);
void completarDataAbreviada(char data[], bool permiteDataFutura);
void redefinirFormato(char string[], const int excluirPosicoes[]);

//Fun��es de Valida��o
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

extern bool validarData(char pString[], char dataInicio[], char dataFim[], bool permitirAtalhos, bool impossivelMaiorQueHoje);

#endif
