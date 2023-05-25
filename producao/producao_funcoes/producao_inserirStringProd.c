#include "../../global/global.h"
#include "../../validar/validar.h"
#include "../../cadastro/cadastro.h"
#include "../producao.h"

void inserirStringProd(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo) {
	int x;
	char stringData[MAX_STRING];
	int vetorData[8];
	switch(*contadorCampo) {
		case 0:
			if(validarDataAdmissao(string)) {
				removerCaracteresEspeciais(string, false);
				if(strlen(string) == 8) {
				vetorStringParaInteiro(string, vetorData, 8);
				sprintf(string, "%d%d/%d%d/%d%d", vetorData[0], vetorData[1], vetorData[2], vetorData[3], vetorData[6], vetorData[7]);
				}
				strcpy(producoes[posicaoDisponivel].data, string);
			}
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
			
			sprintf(producoes[posicaoDisponivel].numCadCliente, "%d", x+1);
			strcpy(producoes[posicaoDisponivel].nomeCliente, clientes[x].nome);
			strcpy(producoes[posicaoDisponivel].cpfCliente, clientes[x].cpf);
			strcpy(producoes[posicaoDisponivel].enderecoCliente, clientes[x].endereco);
			strcpy(producoes[posicaoDisponivel].numEnderecoCliente, clientes[x].numEndereco);
			strcpy(producoes[posicaoDisponivel].compEnderecoCliente, clientes[x].compEndereco);
			strcpy(producoes[posicaoDisponivel].cepCliente, clientes[x].cep);
			strcpy(producoes[posicaoDisponivel].bairroCliente, clientes[x].bairro);
			strcpy(producoes[posicaoDisponivel].cidadeCliente, clientes[x].cidade);
			strcpy(producoes[posicaoDisponivel].estadoCliente, clientes[x].estado);
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
			
			sprintf(producoes[posicaoDisponivel].numCadFuncionario, "%d", x + 1);
			strcpy(producoes[posicaoDisponivel].nomeFuncionario, funcionarios[x].nome);
			break;
	}
}
