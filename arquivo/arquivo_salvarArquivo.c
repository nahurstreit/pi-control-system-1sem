#include "../global/global.h"
#include "../cadastro/cadastro.h"
#include "arquivo.h"

void salvarArquivo_Clientes(){
	
	FILE *pArq_Clientes;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo

    pArq_Clientes = fopen("data/clientes/data_Clientes.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Clientes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefClientes);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefClientes[i] == 1) {
			criarLinhaArquivo(pStringLinha, clientes[i].nome);
			criarLinhaArquivo(pStringLinha, clientes[i].cpf);
			criarLinhaArquivo(pStringLinha, clientes[i].dataNascimento);
			criarLinhaArquivo(pStringLinha, clientes[i].telefone);
			criarLinhaArquivo(pStringLinha, clientes[i].email);
			criarLinhaArquivo(pStringLinha, clientes[i].endereco);
			criarLinhaArquivo(pStringLinha, clientes[i].numEndereco);
			criarLinhaArquivo(pStringLinha, clientes[i].compEndereco);
			criarLinhaArquivo(pStringLinha, clientes[i].bairro);
			criarLinhaArquivo(pStringLinha, clientes[i].cep);
			criarLinhaArquivo(pStringLinha, clientes[i].cidade);
			criarLinhaArquivo(pStringLinha, clientes[i].estado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
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
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefFuncionarios);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefFuncionarios[i] == 1) {			
			criarLinhaArquivo(pStringLinha, funcionarios[i].nome);
			criarLinhaArquivo(pStringLinha, funcionarios[i].status);
			criarLinhaArquivo(pStringLinha, funcionarios[i].cpf);
			criarLinhaArquivo(pStringLinha, funcionarios[i].dataNascimento);
			criarLinhaArquivo(pStringLinha, funcionarios[i].estadoCivil);
			criarLinhaArquivo(pStringLinha, funcionarios[i].dataAdmissao);
			criarLinhaArquivo(pStringLinha, funcionarios[i].salarioBase);
			criarLinhaArquivo(pStringLinha, funcionarios[i].telefone);
			criarLinhaArquivo(pStringLinha, funcionarios[i].email);
			criarLinhaArquivo(pStringLinha, funcionarios[i].endereco);
			criarLinhaArquivo(pStringLinha, funcionarios[i].numEndereco);
			criarLinhaArquivo(pStringLinha, funcionarios[i].compEndereco);
			criarLinhaArquivo(pStringLinha, funcionarios[i].bairro);
			criarLinhaArquivo(pStringLinha, funcionarios[i].cep);
			criarLinhaArquivo(pStringLinha, funcionarios[i].cidade);
			criarLinhaArquivo(pStringLinha, funcionarios[i].estado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
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
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefFornecedores);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefFornecedores[i] == 1) {
			criarLinhaArquivo(pStringLinha, fornecedores[i].nomeFantasia);
			criarLinhaArquivo(pStringLinha, fornecedores[i].cnpj);
			criarLinhaArquivo(pStringLinha, fornecedores[i].telefone);
			criarLinhaArquivo(pStringLinha, fornecedores[i].email);
			criarLinhaArquivo(pStringLinha, fornecedores[i].site);
			criarLinhaArquivo(pStringLinha, fornecedores[i].endereco);
			criarLinhaArquivo(pStringLinha, fornecedores[i].numEndereco);
			criarLinhaArquivo(pStringLinha, fornecedores[i].compEndereco);
			criarLinhaArquivo(pStringLinha, fornecedores[i].bairro);
			criarLinhaArquivo(pStringLinha, fornecedores[i].cep);
			criarLinhaArquivo(pStringLinha, fornecedores[i].cidade);
			criarLinhaArquivo(pStringLinha, fornecedores[i].estado);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
		}
		
		fprintf(pArq_Fornecedores, stringLinha);
	}
	
	fclose(pArq_Fornecedores);
}

void salvarArquivo_Produtos(){
	
	FILE *pArq_Produtos;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo
    char stringValorUnit[MAX_STRING];

    pArq_Produtos = fopen("data/produtos/data_Produtos.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Produtos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefProdutos);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		sprintf(stringValorUnit, "%.2f", produtos[i].valorUnitario);
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefFornecedores[i] == 1) {
			criarLinhaArquivo(pStringLinha, produtos[i].nomeProduto);
			criarLinhaArquivo(pStringLinha, stringValorUnit);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
		}
		
		fprintf(pArq_Produtos, stringLinha);
	}
	
	fclose(pArq_Produtos);
}

void salvarArquivo_Producoes(){
	
	FILE *pArq_Producao;
    char linha[MAX_STRING * 4]; // tamanho máximo da linha no arquivo

    pArq_Producao = fopen("data/producoes/data_Producoes.txt", "w"); // substitua "dados.txt" pelo nome do seu arquivo

    if(pArq_Producao == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefProducoes);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefClientes[i] == 1) {
			criarLinhaArquivo(pStringLinha, producoes[i].data);
			criarLinhaArquivo(pStringLinha, producoes[i].numCadCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].nomeCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].cpfCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].enderecoCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].numEnderecoCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].compEnderecoCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].cepCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].bairroCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].cidadeCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].estadoCliente);
			criarLinhaArquivo(pStringLinha, producoes[i].numCadFuncionario);
			criarLinhaArquivo(pStringLinha, producoes[i].nomeFuncionario);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
		}
		
		fprintf(pArq_Producao, stringLinha);
	}
	
	fclose(pArq_Producao);
}
