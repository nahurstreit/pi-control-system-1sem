#include "../global/global.h"
#include "../cadastro/cadastro.h"
#include "arquivo.h"

void salvarArquivo_Clientes(){
	
	FILE *pArq_Clientes;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo

    pArq_Clientes = fopen("data/clientes/data_Clientes.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Clientes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = 9;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefClientes);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	char stringNome[MAX_STRING];
	char stringCpf[MAX_STRING];
	char stringDataNascimento[MAX_STRING];
	char stringTelefone[MAX_STRING];
	char stringEmail[MAX_STRING];
	char stringEndereco[MAX_STRING];
	char stringNumEndereco[6];
	char stringCompEndereco[MAX_STRING];
	char stringBairro[MAX_STRING];
	char stringCep[MAX_STRING];
	char stringCidade[MAX_STRING];
	char stringEstado[MAX_STRING];
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefClientes[i] == 1) {
			strcpy(stringNome, clientes[i].nome);
			strcpy(stringCpf, clientes[i].cpf);
			strcpy(stringDataNascimento, clientes[i].dataNascimento);
			strcpy(stringTelefone, clientes[i].telefone);
			strcpy(stringEmail, clientes[i].email);
			strcpy(stringEndereco, clientes[i].endereco);
			strcpy(stringNumEndereco, clientes[i].numEndereco);
			strcpy(stringCompEndereco, clientes[i].compEndereco);
			strcpy(stringBairro, clientes[i].bairro);
			strcpy(stringCep, clientes[i].cep);
			strcpy(stringCidade, clientes[i].cidade);
			strcpy(stringEstado, clientes[i].estado);
			
			criarLinhaArquivo(pStringLinha, stringNome);
			criarLinhaArquivo(pStringLinha, stringCpf);
			criarLinhaArquivo(pStringLinha, stringDataNascimento);
			criarLinhaArquivo(pStringLinha, stringTelefone);
			criarLinhaArquivo(pStringLinha, stringEmail);
			criarLinhaArquivo(pStringLinha, stringEndereco);
			criarLinhaArquivo(pStringLinha, stringNumEndereco);
			criarLinhaArquivo(pStringLinha, stringCompEndereco);
			criarLinhaArquivo(pStringLinha, stringBairro);
			criarLinhaArquivo(pStringLinha, stringCep);
			criarLinhaArquivo(pStringLinha, stringCidade);
			criarLinhaArquivo(pStringLinha, stringEstado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>\n");
		}
		
		fprintf(pArq_Clientes, stringLinha);
	}
	
	fclose(pArq_Clientes);
}

void salvarArquivo_Funcionarios(){
	
	FILE *pArq_Funcionarios;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo

    pArq_Funcionarios = fopen("data/funcionarios/data_Funcionarios.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Funcionarios == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = 9;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefFuncionarios);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	char stringNome[MAX_STRING];
	char stringStatus[MAX_STRING];
	char stringCpf[MAX_STRING];
	char stringDataNascimento[MAX_STRING];
	char stringEstadoCivil[MAX_STRING];
	char stringDataAdmissao[MAX_STRING];
	char stringSalarioBase[MAX_STRING];
	char stringTelefone[MAX_STRING];
	char stringEmail[MAX_STRING];
	char stringEndereco[MAX_STRING];
	char stringNumEndereco[6];
	char stringCompEndereco[MAX_STRING];
	char stringBairro[MAX_STRING];
	char stringCep[MAX_STRING];
	char stringCidade[MAX_STRING];
	char stringEstado[MAX_STRING];
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefFuncionarios[i] == 1) {
			strcpy(stringNome, funcionarios[i].nome);
			strcpy(stringStatus, funcionarios[i].status);
			strcpy(stringCpf, funcionarios[i].cpf);
			strcpy(stringDataNascimento, funcionarios[i].dataNascimento);
			strcpy(stringEstadoCivil, funcionarios[i].estadoCivil);
			strcpy(stringDataAdmissao, funcionarios[i].dataAdmissao);
			strcpy(stringSalarioBase, funcionarios[i].salarioBase);
			strcpy(stringTelefone, funcionarios[i].telefone);
			strcpy(stringEmail, funcionarios[i].email);
			strcpy(stringEndereco, funcionarios[i].endereco);
			strcpy(stringNumEndereco, funcionarios[i].numEndereco);
			strcpy(stringCompEndereco, funcionarios[i].compEndereco);
			strcpy(stringBairro, funcionarios[i].bairro);
			strcpy(stringCep, funcionarios[i].cep);
			strcpy(stringCidade, funcionarios[i].cidade);
			strcpy(stringEstado, funcionarios[i].estado);
			
			criarLinhaArquivo(pStringLinha, stringNome);
			criarLinhaArquivo(pStringLinha, stringStatus);
			criarLinhaArquivo(pStringLinha, stringCpf);
			criarLinhaArquivo(pStringLinha, stringDataNascimento);
			criarLinhaArquivo(pStringLinha, stringEstadoCivil);
			criarLinhaArquivo(pStringLinha, stringDataAdmissao);
			criarLinhaArquivo(pStringLinha, stringSalarioBase);
			criarLinhaArquivo(pStringLinha, stringTelefone);
			criarLinhaArquivo(pStringLinha, stringEmail);
			criarLinhaArquivo(pStringLinha, stringEndereco);
			criarLinhaArquivo(pStringLinha, stringNumEndereco);
			criarLinhaArquivo(pStringLinha, stringCompEndereco);
			criarLinhaArquivo(pStringLinha, stringBairro);
			criarLinhaArquivo(pStringLinha, stringCep);
			criarLinhaArquivo(pStringLinha, stringCidade);
			criarLinhaArquivo(pStringLinha, stringEstado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>\n");
		}
		
		fprintf(pArq_Funcionarios, stringLinha);
	}
	
	fclose(pArq_Funcionarios);
}

void salvarArquivo_Fornecedores(){
	
	FILE *pArq_Fornecedores;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo

    pArq_Fornecedores = fopen("data/fornecedores/data_Fornecedores.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Fornecedores == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = 9;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefFornecedores);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	char stringNomeFantasia[MAX_STRING];
	char stringCnpj[MAX_STRING];
	char stringTelefone[MAX_STRING];
	char stringEmail[MAX_STRING];
	char stringEndereco[MAX_STRING];
	char stringNumEndereco[6];
	char stringCompEndereco[MAX_STRING];
	char stringBairro[MAX_STRING];
	char stringCep[MAX_STRING];
	char stringCidade[MAX_STRING];
	char stringEstado[MAX_STRING];
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefFornecedores[i] == 1) {
			strcpy(stringNomeFantasia, fornecedores[i].nomeFantasia);
			strcpy(stringCnpj, fornecedores[i].cnpj);
			strcpy(stringTelefone, fornecedores[i].telefone);
			strcpy(stringEmail, fornecedores[i].email);
			strcpy(stringEndereco, fornecedores[i].endereco);
			strcpy(stringNumEndereco, fornecedores[i].numEndereco);
			strcpy(stringCompEndereco, fornecedores[i].compEndereco);
			strcpy(stringBairro, fornecedores[i].bairro);
			strcpy(stringCep, fornecedores[i].cep);
			strcpy(stringCidade, fornecedores[i].cidade);
			strcpy(stringEstado, fornecedores[i].estado);
			
			criarLinhaArquivo(pStringLinha, stringNomeFantasia);
			criarLinhaArquivo(pStringLinha, stringCnpj);
			criarLinhaArquivo(pStringLinha, stringTelefone);
			criarLinhaArquivo(pStringLinha, stringEmail);
			criarLinhaArquivo(pStringLinha, stringEndereco);
			criarLinhaArquivo(pStringLinha, stringNumEndereco);
			criarLinhaArquivo(pStringLinha, stringCompEndereco);
			criarLinhaArquivo(pStringLinha, stringBairro);
			criarLinhaArquivo(pStringLinha, stringCep);
			criarLinhaArquivo(pStringLinha, stringCidade);
			criarLinhaArquivo(pStringLinha, stringEstado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>\n");
		}
		
		fprintf(pArq_Fornecedores, stringLinha);
	}
	
	fclose(pArq_Fornecedores);
}
