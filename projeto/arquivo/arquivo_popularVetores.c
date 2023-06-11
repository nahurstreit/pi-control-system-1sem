#include "../global/global.h"
#include "arquivo.h"

void popularVetor_Clientes();
void popularVetor_Funcionarios();
void popularVetor_Fornecedores();
void popularVetor_Produtos();
void popularVetor_Producoes();

void popularVetores() {
    popularVetor_Clientes();
    popularVetor_Funcionarios();
    popularVetor_Fornecedores();
    popularVetor_Produtos();
	popularVetor_Producoes();
}

void popularVetor_Clientes() {
	FILE *pArq_Clientes;
    char linha[MAX_STRING * 20]; // tamanho máximo da linha no arquivo

    pArq_Clientes = fopen("data/clientes/data_Clientes.txt", "r");

    if(pArq_Clientes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Clientes) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].nome, token, MAX_STRING - 1);
	            clientes[i].nome[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].cpf, token, MAX_STRING - 1);
	            clientes[i].cpf[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].dataNascimento, token, MAX_STRING - 1);
	            clientes[i].dataNascimento[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].telefone, token, MAX_STRING - 1);
	            clientes[i].telefone[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].email, token, MAX_STRING - 1);
	            clientes[i].email[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].endereco, token, MAX_STRING - 1);
	            clientes[i].endereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].numEndereco, token, 6 - 1);
	            clientes[i].numEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].compEndereco, token, MAX_STRING - 1);
	            clientes[i].compEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].bairro, token, MAX_STRING - 1);
	            clientes[i].bairro[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].cep, token, MAX_STRING - 1);
	            clientes[i].cep[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].cidade, token, MAX_STRING - 1);
	            clientes[i].cidade[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(clientes[i].estado, token, MAX_STRING - 1);
	            clientes[i].estado[MAX_STRING - 1] = '\0';
	        }
	        
	        vetorRefClientes[i] = 1;
		}
        i++;
    }
    fclose(pArq_Clientes);
}

void popularVetor_Funcionarios() {
	FILE *pArq_Funcionarios;
    char linha[MAX_STRING * 20]; // tamanho máximo da linha no arquivo

    pArq_Funcionarios = fopen("data/funcionarios/data_Funcionarios.txt", "r");

    if(pArq_Funcionarios == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Funcionarios) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].nome, token, MAX_STRING - 1);
	            funcionarios[i].nome[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	        
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].status, token, MAX_STRING - 1);
	            funcionarios[i].status[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].cpf, token, MAX_STRING - 1);
	            funcionarios[i].cpf[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].dataNascimento, token, MAX_STRING - 1);
	            funcionarios[i].dataNascimento[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	        
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].estadoCivil, token, MAX_STRING - 1);
	            funcionarios[i].estadoCivil[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	        
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].dataAdmissao, token, MAX_STRING - 1);
	            funcionarios[i].dataAdmissao[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].telefone, token, MAX_STRING - 1);
	            funcionarios[i].telefone[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].email, token, MAX_STRING - 1);
	            funcionarios[i].email[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].endereco, token, MAX_STRING - 1);
	            funcionarios[i].endereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].numEndereco, token, 6 - 1);
	            funcionarios[i].numEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].compEndereco, token, MAX_STRING - 1);
	            funcionarios[i].compEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].bairro, token, MAX_STRING - 1);
	            funcionarios[i].bairro[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].cep, token, MAX_STRING - 1);
	            funcionarios[i].cep[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].cidade, token, MAX_STRING - 1);
	            funcionarios[i].cidade[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(funcionarios[i].estado, token, MAX_STRING - 1);
	            funcionarios[i].estado[MAX_STRING - 1] = '\0';
	        }
	        
	        vetorRefFuncionarios[i] = 1;
		}
        i++;
    }
    fclose(pArq_Funcionarios);
}

void popularVetor_Fornecedores() {
		FILE *pArq_Fornecedores;
    char linha[MAX_STRING * 20]; // tamanho máximo da linha no arquivo

    pArq_Fornecedores = fopen("data/fornecedores/data_Fornecedores.txt", "r"); 

    if(pArq_Fornecedores == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Fornecedores) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].nomeFantasia, token, MAX_STRING - 1);
	            fornecedores[i].nomeFantasia[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].cnpj, token, MAX_STRING - 1);
	            fornecedores[i].cnpj[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].telefone, token, MAX_STRING - 1);
	            fornecedores[i].telefone[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].email, token, MAX_STRING - 1);
	            fornecedores[i].email[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].site, token, MAX_STRING - 1);
	            fornecedores[i].site[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].endereco, token, MAX_STRING - 1);
	            fornecedores[i].endereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].numEndereco, token, 6 - 1);
	            fornecedores[i].numEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].compEndereco, token, MAX_STRING - 1);
	            fornecedores[i].compEndereco[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].bairro, token, MAX_STRING - 1);
	            fornecedores[i].bairro[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].cep, token, MAX_STRING - 1);
	            fornecedores[i].cep[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].cidade, token, MAX_STRING - 1);
	            fornecedores[i].cidade[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(fornecedores[i].estado, token, MAX_STRING - 1);
	            fornecedores[i].estado[MAX_STRING - 1] = '\0';
	        }
	        
	        vetorRefFornecedores[i] = 1;
		}
        i++;
    }
    fclose(pArq_Fornecedores);
}

void popularVetor_Produtos() {
	FILE *pArq_Produtos;
    char linha[MAX_STRING * 20]; // tamanho máximo da linha no arquivo
    
    char stringValorUnit[MAX_STRING];
    float valorUnit;

    pArq_Produtos = fopen("data/produtos/data_Produtos.txt", "r");

    if(pArq_Produtos == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Produtos) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(produtos[i].nomeProduto, token, MAX_STRING - 1);
	            produtos[i].nomeProduto[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(stringValorUnit, token, MAX_STRING - 1);
	        	stringValorUnit[MAX_STRING - 1] = '\0';
	        	valorUnit = atof(stringValorUnit);
	        	produtos[i].valorUnitario = valorUnit;
	        }
	        
	        vetorRefProdutos[i] = 1;
		}
        i++;
    }
    
    fclose(pArq_Produtos);
}

void popularVetor_Producoes() {
	
	FILE *pArq_Producoes;
    char linha[MAX_STRING * 20]; // tamanho máximo da linha no arquivo
    
    char stringValorUnit[MAX_STRING];
    float valorUnit;

    pArq_Producoes = fopen("data/producoes/data_Producoes.txt", "r");

    if(pArq_Producoes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Producoes) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(producoes[i].data, token, MAX_STRING - 1);
	            producoes[i].data[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].numCadCliente, token, MAX_STRING - 1);
	            producoes[i].numCadCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].nomeCliente, token, MAX_STRING - 1);
	            producoes[i].nomeCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].cpfCliente, token, MAX_STRING - 1);
	            producoes[i].cpfCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].telefoneCliente, token, MAX_STRING - 1);
	            producoes[i].telefoneCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].enderecoCliente, token, MAX_STRING - 1);
	            producoes[i].enderecoCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].numEnderecoCliente, token, MAX_STRING - 1);
	            producoes[i].numEnderecoCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].compEnderecoCliente, token, MAX_STRING - 1);
	            producoes[i].compEnderecoCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].cepCliente, token, MAX_STRING - 1);
	            producoes[i].cepCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].bairroCliente, token, MAX_STRING - 1);
	            producoes[i].bairroCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].cidadeCliente, token, MAX_STRING - 1);
	            producoes[i].cidadeCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].estadoCliente, token, MAX_STRING - 1);
	            producoes[i].estadoCliente[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].numCadFuncionario, token, MAX_STRING - 1);
	            producoes[i].numCadFuncionario[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].nomeFuncionario, token, MAX_STRING - 1);
	            producoes[i].nomeFuncionario[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].valorTotal, token, MAX_STRING - 1);
	            producoes[i].valorTotal[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	        	strncpy(producoes[i].arquivoSalvamentoItens, token, MAX_STRING - 1);
	            producoes[i].arquivoSalvamentoItens[MAX_STRING - 1] = '\0';
	        }
	        
	        popularVetorItens(i);
	        
	        vetorRefProducoes[i] = 1;
		}
        i++;
    }
    
    fclose(pArq_Producoes);
}
