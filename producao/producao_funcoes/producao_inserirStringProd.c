#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../producao.h"

void inserirStringProd(int posicao, char string[MAX_STRING], int *contadorCampo, int posicaoItem) {
	int x;
	char stringData[MAX_STRING];
	int vetorDataAtual[8];
	char dataAtual[8];
	
	int posicaoConsulta;
	
	int i;
	float valorTotal = 0.0;
	
	switch(*contadorCampo) {
		case 0:
			if(validarData(string, DATA_INICIO_EMPRESA, DATA_LIMITE_FUTURO, true, false)) strcpy(producoes[posicao].data, string);
			break;
		case 1:
			removerCaracteresEspeciais(string, false);
			
			if(verificarContemLetras(string)) {
				erro = Erro_Input_ApenasNumeros;
				break;
			}
			
			if(strlen(string) > 1 && strlen(string) >= 11) {
				x = consultarCPFouCNPJ(string);
			} else {
				x = atoi(string);
			}
			
			x -=1;
			
			if(vetorRefClientes[x] == 0) {
				erro = Erro_Consulta_NaoExiste;
				break;
			}
			
			sprintf(producoes[posicao].numCadCliente, "%d", x+1);
			strcpy(producoes[posicao].nomeCliente, clientes[x].nome);
			strcpy(producoes[posicao].cpfCliente, clientes[x].cpf);
			strcpy(producoes[posicao].telefoneCliente, clientes[x].telefone);
			strcpy(producoes[posicao].enderecoCliente, clientes[x].endereco);
			strcpy(producoes[posicao].numEnderecoCliente, clientes[x].numEndereco);
			strcpy(producoes[posicao].compEnderecoCliente, clientes[x].compEndereco);
			strcpy(producoes[posicao].cepCliente, clientes[x].cep);
			strcpy(producoes[posicao].bairroCliente, clientes[x].bairro);
			strcpy(producoes[posicao].cidadeCliente, clientes[x].cidade);
			strcpy(producoes[posicao].estadoCliente, clientes[x].estado);
			sprintf(producoes[posicao].arquivoSalvamentoItens, "data/historico_compras/data_Cliente%d/data_Compra%d.txt", x + 1, posicao + 1);
		break;
	case 2:
		removerCaracteresEspeciais(string, false);
			
		escolhaUser = 2;
		if(verificarContemLetras(string)) {
			erro = Erro_Input_ApenasNumeros;
			break;
		}
		
		if(strlen(string) > 1 && strlen(string) >= 11) {
			x = consultarCPFouCNPJ(string);
		} else {
			x = atoi(string);
		}
		
		x -=1;
		escolhaUser = 5;
		
		if(vetorRefFuncionarios[x] == 0) {
			erro = Erro_Consulta_NaoExiste;
			break;
		}
		
		sprintf(producoes[posicao].numCadFuncionario, "%d", x + 1);
		strcpy(producoes[posicao].nomeFuncionario, funcionarios[x].nome);
		break;
	case 3:
		posicaoConsulta = atoi(string);
		posicaoConsulta--;
		
		if(vetorRefProdutos[posicaoConsulta] == 0) {
			erro = Erro_Consulta_NaoExiste;
			break;
		}
		
		sprintf(producoes[posicao].itens[posicaoItem].codigoProduto, "%d", produtos[posicaoConsulta].codigoProduto + 1);
		strcpy(producoes[posicao].itens[posicaoItem].nome, produtos[posicaoConsulta].nomeProduto);
		sprintf(producoes[posicao].itens[posicaoItem].valorUnit, "%.2f", produtos[posicaoConsulta].valorUnitario);
//		for(i = 0; i < calcularDadosExistentes(vetorRefProducoes); i++) {
//					valorTotal += atof(producoes[posicao].itens[i].valorUnit) * atof(producoes[posicao].itens[i].quantidade);
//				}
//			sprintf(producoes[posicao].valorTotal, "%.2f", valorTotal);
		break;
	case 4:
		if(validarEntrada(string, true, true, false, 100)) {
			strcpy(producoes[posicao].itens[posicaoItem].quantidade, string);
			for(i = 0; i < calcularDadosExistentes(vetorRefProducoes); i++) {
					valorTotal += atof(producoes[posicao].itens[i].valorUnit) * atof(producoes[posicao].itens[i].quantidade);
				}
			sprintf(producoes[posicao].valorTotal, "%.2f", valorTotal);
			break;
		}
		erro = Erro_Input_ApenasNumeros;
		break;
	case 5:
		break;
	}
}
