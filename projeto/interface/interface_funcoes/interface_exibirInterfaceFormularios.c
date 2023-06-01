#include "../../global/global.h"
#include "../../cadastro/cadastro.h"
#include "../interface.h"

void exibirInterfaceFormularios(int posicao) {
	int i, j;
	char posicaoString[3];
	char stringValorProduto[MAX_STRING];
	Display *pDisplayAtual;
	Display copiaDisplay[30];
	Display *pCopiaDisplay = copiaDisplay;
	
	if(escolhaUser == 5) tipoConsultaAtual = 5;
	
	switch(tipoConsultaAtual) {
		case 1:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroCliente);
			pDisplayAtual = displayRefFormularioCadastroCliente;
			posicao = posicaoConsultaAtual;
			break;
		case 2:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroFuncionario);
			pDisplayAtual = displayRefFormularioCadastroFuncionario;
			posicao = posicaoConsultaAtual;
			break;
		case 3:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroFornecedor);
			pDisplayAtual = displayRefFormularioCadastroFornecedor;
			posicao = posicaoConsultaAtual;
			break;
		case 4:
			tamanhoDisplay = sizeof(displayRefFormularioCadastroProduto);
			pDisplayAtual = displayRefFormularioCadastroProduto;
			posicao = posicaoConsultaAtual;
			break;
		case 5:
			tamanhoDisplay = sizeof(displayRefFormularioNovaOrdem);
			pDisplayAtual = displayRefFormularioNovaOrdem;
			break;
	}
	
	tamanhoDisplay /= sizeof(Display);
	//Transforma a posição passada pelo usuário como int, para string, para conseguir ser exibida ao usuário
	sprintf(&posicaoString[0], "%d", posicao+1);
	
	//Copia os formulários de Display em uma variável do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
		/*Substitui nas linhas do copiaDisplay, em espaços específicos, os conteúdo presentes no vetor de dados. Como o vetor por padrão tem o número zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribuição fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada é atribuido, portanto a linha permanece intacta até que seja adicionada uma string. */
		switch(tipoConsultaAtual) {
			case 1:
				//Display Número de cadastro
					for(j = 0; j < strlen(posicaoString); j++) {
						pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
					}
				//Display Nome
					for(j = 0; j < strlen(clientes[posicao].nome); j++) {
						pCopiaDisplay[1].linhaDisplay[32 + j] = clientes[posicao].nome[j];
					}
				//Display CPF
					for(j = 0; j < strlen(clientes[posicao].cpf); j++) {
						pCopiaDisplay[3].linhaDisplay[11 + j] = clientes[posicao].cpf[j];
					}
				//Display Data Nascimento
					for(j = 0; j < strlen(clientes[posicao].dataNascimento); j++) {
						pCopiaDisplay[3].linhaDisplay[63 + j] = clientes[posicao].dataNascimento[j];
					}
				//Display Telefone
					for(j = 0; j < strlen(clientes[posicao].telefone); j++) {
						pCopiaDisplay[5].linhaDisplay[16 + j] = clientes[posicao].telefone[j];
					}
				//Display E-mail
					for(j = 0; j < strlen(clientes[posicao].email); j++) {
						pCopiaDisplay[5].linhaDisplay[59 + j] = clientes[posicao].email[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(clientes[posicao].endereco); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = clientes[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(clientes[posicao].numEndereco); j++) {
						pCopiaDisplay[7].linhaDisplay[93 + j] = clientes[posicao].numEndereco[j];
					}
				//Display Complemento Endereço
					for(j = 0; j < strlen(clientes[posicao].compEndereco); j++) {
						pCopiaDisplay[9].linhaDisplay[19 + j] = clientes[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(clientes[posicao].bairro); j++) {
						pCopiaDisplay[9].linhaDisplay[59 + j] = clientes[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(clientes[posicao].cep); j++) {
						pCopiaDisplay[11].linhaDisplay[12 + j] = clientes[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(clientes[posicao].cidade); j++) {
						pCopiaDisplay[11].linhaDisplay[43 + j] = clientes[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(clientes[posicao].estado); j++) {
						pCopiaDisplay[11].linhaDisplay[94 + j] = clientes[posicao].estado[j];
					}
				break;
			case 2:				
				//Display Número de cadastro
				for(j = 0; j < strlen(posicaoString); j++) {
					pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
				}
				//Display nome
					for(j = 0; j < strlen(funcionarios[posicao].nome); j++) {
						pCopiaDisplay[1].linhaDisplay[32 + j] = funcionarios[posicao].nome[j];
					}
				//Display Status
					for(j = 0; j < strlen(funcionarios[posicao].status); j++) {
						pCopiaDisplay[1].linhaDisplay[93 + j] = funcionarios[posicao].status[j];
					}
				//Display CPF
					for(j = 0; j < strlen(funcionarios[posicao].cpf); j++) {
						pCopiaDisplay[3].linhaDisplay[11 + j] = funcionarios[posicao].cpf[j];
					}				
				//Display Data Nascimento
					for(j = 0; j < strlen(funcionarios[posicao].dataNascimento); j++) {
						pCopiaDisplay[3].linhaDisplay[55 + j] = funcionarios[posicao].dataNascimento[j];
					}
				//Display Estado Civil
					for(j = 0; j < strlen(funcionarios[posicao].estadoCivil); j++) {
						pCopiaDisplay[3].linhaDisplay[86 + j] = funcionarios[posicao].estadoCivil[j];
					}
				//Display Data Admissão				
					for(j = 0; j < strlen(funcionarios[posicao].dataAdmissao); j++) {
						pCopiaDisplay[5].linhaDisplay[24 + j] = funcionarios[posicao].dataAdmissao[j];
					}
				//Display Salário Base: 
					for(j = 0; j < strlen(funcionarios[posicao].salarioBase); j++) {
						pCopiaDisplay[5].linhaDisplay[68 + j] = funcionarios[posicao].salarioBase[j];
					}
				//Display Telefone:
					for(j = 0; j < strlen(funcionarios[posicao].telefone); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = funcionarios[posicao].telefone[j];
					}
				//Display E-mail:
					for(j = 0; j < strlen(funcionarios[posicao].email); j++) {
						pCopiaDisplay[7].linhaDisplay[60 + j] = funcionarios[posicao].email[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(funcionarios[posicao].endereco); j++) {
						pCopiaDisplay[9].linhaDisplay[17 + j] = funcionarios[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(funcionarios[posicao].numEndereco); j++) {
						pCopiaDisplay[9].linhaDisplay[94 + j] = funcionarios[posicao].numEndereco[j];
					}
				//Display Complemento
					for(j = 0; j < strlen(funcionarios[posicao].compEndereco); j++) {
						pCopiaDisplay[11].linhaDisplay[20 + j] = funcionarios[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(funcionarios[posicao].bairro); j++) {
						pCopiaDisplay[11].linhaDisplay[61 + j] = funcionarios[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(funcionarios[posicao].cep); j++) {
						pCopiaDisplay[13].linhaDisplay[12 + j] = funcionarios[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(funcionarios[posicao].cidade); j++) {
						pCopiaDisplay[13].linhaDisplay[43 + j] = funcionarios[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(funcionarios[posicao].estado); j++) {
						pCopiaDisplay[13].linhaDisplay[94 + j] = funcionarios[posicao].estado[j];
					}
				break;
			case 3:				
				//Display Número de cadastro
					for(j = 0; j < strlen(posicaoString); j++) {
						pCopiaDisplay[1].linhaDisplay[16 + j] = posicaoString[j];
					}
				//Display Nome
					for(j = 0; j < strlen(fornecedores[posicao].nomeFantasia); j++) {
						pCopiaDisplay[1].linhaDisplay[41 + j] = fornecedores[posicao].nomeFantasia[j];
					}
				//Display CNPJ
					for(j = 0; j < strlen(fornecedores[posicao].cnpj); j++) {
						pCopiaDisplay[3].linhaDisplay[12 + j] = fornecedores[posicao].cnpj[j];
					}
				//Display Telefone
					for(j = 0; j < strlen(fornecedores[posicao].telefone); j++) {
						pCopiaDisplay[3].linhaDisplay[61 + j] = fornecedores[posicao].telefone[j];
					}
				//Display E-mail
					for(j = 0; j < strlen(fornecedores[posicao].email); j++) {
						pCopiaDisplay[5].linhaDisplay[13 + j] = fornecedores[posicao].email[j];
					}
				//Display Site
					for(j = 0; j < strlen(fornecedores[posicao].site); j++) {
						pCopiaDisplay[5].linhaDisplay[57 + j] = fornecedores[posicao].site[j];
					}
				//Display Endereço
					for(j = 0; j < strlen(fornecedores[posicao].endereco); j++) {
						pCopiaDisplay[7].linhaDisplay[16 + j] = fornecedores[posicao].endereco[j];
					}
				//Display Número Endereço
					for(j = 0; j < strlen(fornecedores[posicao].numEndereco); j++) {
						pCopiaDisplay[7].linhaDisplay[93 + j] = fornecedores[posicao].numEndereco[j];
					}
				//Display Complemento Endereço
					for(j = 0; j < strlen(fornecedores[posicao].compEndereco); j++) {
						pCopiaDisplay[9].linhaDisplay[19 + j] = fornecedores[posicao].compEndereco[j];
					}
				//Display Bairro
					for(j = 0; j < strlen(fornecedores[posicao].bairro); j++) {
						pCopiaDisplay[9].linhaDisplay[59 + j] = fornecedores[posicao].bairro[j];
					}
				//Display CEP
					for(j = 0; j < strlen(fornecedores[posicao].cep); j++) {
						pCopiaDisplay[11].linhaDisplay[12 + j] = fornecedores[posicao].cep[j];
					}
				//Display Cidade
					for(j = 0; j < strlen(fornecedores[posicao].cidade); j++) {
						pCopiaDisplay[11].linhaDisplay[44 + j] = fornecedores[posicao].cidade[j];
					}
				//Display Estado
					for(j = 0; j < strlen(fornecedores[posicao].estado); j++) {
						pCopiaDisplay[11].linhaDisplay[94 + j] = fornecedores[posicao].estado[j];
					}
				break;
			case 4:
					for(j = 0; j < strlen(posicaoString); j++) {
						pCopiaDisplay[1].linhaDisplay[11 + j] = posicaoString[j];
					}
					for(j = 0; j < strlen(produtos[posicao].nomeProduto); j++) {
						pCopiaDisplay[1].linhaDisplay[38 + j] = produtos[posicao].nomeProduto[j];
					}
					sprintf(stringValorProduto, "%.2f", produtos[posicao].valorUnitario);
					for(j = 0; j < strlen(stringValorProduto); j++) {
						pCopiaDisplay[1].linhaDisplay[92 + j] = stringValorProduto[j];
					}
				break;
			default:
				printf("Erro ao posicionar os dados no display visual.");
			}	
	
	for(i = 0; i < tamanhoDisplay; i++) {
		printf("%s\n", pCopiaDisplay[i].linhaDisplay);
	}
}
