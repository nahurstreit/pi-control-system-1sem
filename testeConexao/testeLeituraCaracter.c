#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 100
#define MAX_CAMPO 50
#define MAX_STRING 50

//CADASTRO
	/**
	 * @brief Definição do struct do tipo Cliente, para armazenar de forma categórica os dados do cliente.
	 **/
	typedef struct {
		char nome[MAX_STRING];
		char cpf[MAX_STRING];
		char dataNascimento[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[6];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Cliente;

int main() {
	int j;
	int i;
	Cliente clientes[MAX_VETOR];
	lerArquivoCliente();
	
	// Teste: imprime os campos dos clientes
    for (j = 0; j < i; j++) {
        printf("Cliente %d: Nome: %s, CPF: %s, Data Nascimento: %s", j + 1, clientes[j].nome, clientes[j].cpf, clientes[j].dataNascimento);
    }
    
    // Teste: imprime os campos dos funcionário
    for (j = 0; j < i; j++) {
        printf("Cliente %d: Nome: %s, CPF: %s, Data Nascimento: %s", j + 1, clientes[j].nome, clientes[j].cpf, clientes[j].dataNascimento);
    }
    
}

void lerArquivoCliente() {
	     
    FILE *arquivo;
    char linha[MAX_CAMPO * 2]; // tamanho máximo da linha no arquivo

    arquivo = fopen("data_Clientes.txt", "r"); // substitua "dados.txt" pelo nome do seu arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    }

    int i = 0, j;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
    
        char *token = strtok(linha, ";");

        if (token != NULL) {
            strcpy(clientes[i].nome, token);
        }

        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].cpf, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].dataNascimento, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].telefone, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].email, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].endereco, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].numEndereco, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].compEndereco, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].bairro, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].cep, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].cidade, token);
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].estado, token);
        }

        i++;
    }

    fclose(arquivo);
}

