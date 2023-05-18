#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#define MAX_STRING 50

void inserirTexto(char texto[MAX_STRING], FILE *pArquivo);
void lerArquivo(FILE *pArquivo);

void main() {
	setlocale(LC_ALL, "Portuguese");
	
	char texto[MAX_STRING];
	char modo = 'w', optModo;
	char *pModo = &modo;
	int loopTipo, loopOpr = 0;
	do{
		
		loopOpr = 0;
		
		do{
			system("cls");
//			if(loopTipo != 0) {
//				printf("Digite apenas w, r, ou a!\n");
//			}
			printf("Qual modo você deseja usar (w, r, a)? ");
			scanf("%c", &optModo);
			fflush(stdin);
			
			tolower(optModo);
			
			loopTipo = 0;
			
			if(optModo == 'w') pModo = "w";
			else if(optModo == 'a') pModo = "a";
			else if(optModo == 'r') pModo = "r";
			else loopTipo = 1;
			
		} while (loopTipo != 0);
		
		FILE *pArquivo;
		pArquivo = fopen("TesteArquivo", pModo);
		
		if(pModo == "w" || pModo == "a") {
			printf("Digite um texto: ");
			scanf("%s", texto);
			inserirTexto(texto, pArquivo);
		
			fclose(pArquivo);
			printf("Arquivo atualizado!\n\n");
		} else {
			lerArquivo(pArquivo);
		}
		
		printf("Deseja fazer mais uma operação?\n[1] Sim\n[0] Não\nOpção: ");
		scanf("%d", &loopOpr);
		
	} while(loopOpr != 0);
}

void inserirTexto(char texto[MAX_STRING], FILE *pArquivo) {
	fprintf(pArquivo, texto);
	fprintf(pArquivo, "\n");
}

void lerArquivo(FILE *pArquivo) {
	char rTexto[MAX_STRING];
	
	while(fgets(rTexto, MAX_STRING, pArquivo)) {
		printf("%s", rTexto);	
	}
}
