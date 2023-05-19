#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100
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
	
	/**
	 * @brief Definição do struct do tipo Funcionário, para armazenar de forma categórica os dados do funcionário.
	 **/
	typedef struct {
		char nome[MAX_STRING];
		char status[MAX_STRING];
		char cpf[MAX_STRING];
		char dataNascimento[MAX_STRING];
		char estadoCivil[MAX_STRING];
		char dataAdmissao[MAX_STRING];
		char salarioBase[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[6];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Funcionario;
	
	/**
	 * @brief Definição do struct do tipo Fornecedor, para armazenar de forma categórica os dados do fornecedor.
	 **/
	typedef struct {
		char nomeFantasia[MAX_STRING];
		char cnpj[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[6];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Fornecedor;
//

void lerArquivoCliente();
void lerArquivoFuncionario();
void lerArquivoFornecedor();

int main() {
	int j;
	int i;
	lerArquivoCliente();
	lerArquivoFuncionario();
	lerArquivoFornecedor();
	
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
	    struct Cliente clientes[MAX_CLIENTES];
    FILE *arquivo;
    char linha[MAX_CAMPO * 2]; // tamanho máximo da linha no arquivo

    arquivo = fopen("dadosCliente.txt", "r"); // substitua "dados.txt" pelo nome do seu arquivo

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int i = 0, j;
    while (fgets(linha, sizeof(linha), arquivo) != NULL && i < MAX_CLIENTES) {
        linha[strcspn(linha, "\n")] = '\0';
    
        char *token = strtok(linha, ";");

        if (token != NULL) {
            strncpy(clientes[i].nome, token, MAX_CAMPO - 1);
            clientes[i].nome[MAX_CAMPO - 1] = '\0';
        }

        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].cpf, token, MAX_CAMPO - 1);
            clientes[i].idade[MAX_CAMPO - 1] = '\0';
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
            strncpy(clientes[i].dataNascimento, token, MAX_CAMPO - 1);
            clientes[i].idade[MAX_CAMPO - 1] = '\0';
        }

        i++;
    }

    fclose(arquivo);
    

    return 0;
}

