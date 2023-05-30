#include "../../global/global.h"
#include "../../global/global_enum.h"
#include "../menu.h"

void exibirErro() {
	char res[90];
	switch(erro) {
		case Erro_Nenhum:
			break;
		case Erro_Input_ApenasNumeros:
			strcpy(res, "Erro: Digite apenas n�meros!");
			break;
		case Erro_Input_ApenasLetras:
			strcpy(res, "Erro: Digite apenas letras!");
			break;
		case Erro_Input_Status_Invalido:
			strcpy(res, "Erro: Status inv�lido! Apenas (1) Ativo ou (0) Inativo.");
			break;
		case Erro_Input_CPF_Invalido:
			strcpy(res, "Erro: CPF inv�lido!");
			break;
		case Erro_Input_CPF_JaCadastrado:
			strcpy(res, "Erro: CPF j� cadastrado no sistema!");
			break;
		case Erro_Input_CNPJ_Invalido:
			strcpy(res, "Erro: CNPJ inv�lido!");
			break;
		case Erro_Input_CNPJ_JaCadastrado:
			strcpy(res, "Erro: CNPJ j� cadastrado no sistema!");
			break;
		case Erro_Input_Data_Invalida:
			strcpy(res, "Erro: Data inv�lida!");
			break;
		case Erro_Input_DataNascimento_Invalida:
			strcpy(res, "Erro: Data de Nascimento inv�lida!");
			break;
		case Erro_Input_DataAdmissao_Invalida:
			strcpy(res, "Erro: Data de Admiss�o inv�lida! Apenas datas entre 2018 e 2023!");
			break;
		case Erro_Input_EstadoCivil_Invalido:
			strcpy(res, "Erro: Estado Civil inv�lido! Apenas: Solteiro, Casado, Divorciado ou Viuvo.");
			break;
		case Erro_Input_Telefone_Invalido:
			strcpy(res, "Erro: Telefone inv�lido!");
			break;
		case Erro_Input_CEP_Invalido:
			strcpy(res, "Erro: CEP inv�lido!");
			break;
		case Erro_Input_Estado_Invalido:
			strcpy(res, "Erro: Estado inv�lido!");
			break;
		case Erro_OpcaoInvalida:
			strcpy(res, "Erro: Op��o inv�lida! Digite novamente!");
			break;
		case Erro_Consulta_NaoPossivel:
			strcpy(res, "Erro: N�o foi poss�vel realizar sua consulta!");
			break;
		case Erro_Consulta_NaoExiste:
			strcpy(res, "Erro: N�o existe nenhum registro para essa consulta!");
			break;
		case Erro_NovoCadastro_Mudar_NenhumCampoAinda:
			strcpy(res, "Erro: Voc� ainda n�o digitou nenhum campo para poder alterar!");
			break;
		case Erro_NovoCadastro_Mudar_CampoInvalido:
			strcpy(res, "Erro: Campo inv�lido!");
			break;
		case Erro_NovoCadastro_Mudar_AindaNaoDigitou:
			strcpy(res, "Erro: Voc� ainda n�o digitou esse campo!");
			break;
		case Erro_NovoCadastro_Mudar_SoPodeOPrimeiro:
			strcpy(res, "Erro: Voc� s� pode alterar o primeiro campo!");
			break;
		case Erro_Arquivo_ErroAoLerArquivos:
			strcpy(res, "Erro ao ler os dados registrados no sistema.");
			break;
		case Erro_Arquivo_ImpossivelLerDataAtual:
			strcpy(res, "Erro ao ler a data de hoje! Por favor, insira-a manualmente!");
			break;
		case Erro_Filtro_NaoExiste:
			strcpy(res, "Erro: N�o existem registros para esse filtro!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
}
