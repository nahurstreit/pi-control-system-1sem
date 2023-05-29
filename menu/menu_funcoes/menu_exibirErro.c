#include "../../global/global.h"
#include "../../global/global_enum.h"
#include "../menu.h"

void exibirErro() {
	char res[90];
	switch(erro) {
		case Erro_Nenhum:
			break;
		case Erro_Input_ApenasNumeros:
			strcpy(res, "Erro: Digite apenas números!");
			break;
		case Erro_Input_ApenasLetras:
			strcpy(res, "Erro: Digite apenas letras!");
			break;
		case Erro_Input_Status_Invalido:
			strcpy(res, "Erro: Status inválido! Apenas (1) Ativo ou (0) Inativo.");
			break;
		case Erro_Input_CPF_Invalido:
			strcpy(res, "Erro: CPF inválido!");
			break;
		case Erro_Input_CPF_JaCadastrado:
			strcpy(res, "Erro: CPF já cadastrado no sistema!");
			break;
		case Erro_Input_CNPJ_Invalido:
			strcpy(res, "Erro: CNPJ inválido!");
			break;
		case Erro_Input_CNPJ_JaCadastrado:
			strcpy(res, "Erro: CNPJ já cadastrado no sistema!");
			break;
		case Erro_Input_Data_Invalida:
			strcpy(res, "Erro: Data inválida!");
			break;
		case Erro_Input_DataNascimento_Invalida:
			strcpy(res, "Erro: Data de Nascimento inválida!");
			break;
		case Erro_Input_DataAdmissao_Invalida:
			strcpy(res, "Erro: Data de Admissão inválida! Apenas datas entre 2018 e 2023!");
			break;
		case Erro_Input_EstadoCivil_Invalido:
			strcpy(res, "Erro: Estado Civil inválido! Apenas: Solteiro, Casado, Divorciado ou Viuvo.");
			break;
		case Erro_Input_Telefone_Invalido:
			strcpy(res, "Erro: Telefone inválido!");
			break;
		case Erro_Input_CEP_Invalido:
			strcpy(res, "Erro: CEP inválido!");
			break;
		case Erro_Input_Estado_Invalido:
			strcpy(res, "Erro: Estado inválido!");
			break;
		case Erro_OpcaoInvalida:
			strcpy(res, "Erro: Opção inválida! Digite novamente!");
			break;
		case Erro_Consulta_NaoPossivel:
			strcpy(res, "Erro: Não foi possível realizar sua consulta!");
			break;
		case Erro_Consulta_NaoExiste:
			strcpy(res, "Erro: Não existe nenhum registro para essa consulta!");
			break;
		case Erro_NovoCadastro_Mudar_NenhumCampoAinda:
			strcpy(res, "Erro: Você ainda não digitou nenhum campo para poder alterar!");
			break;
		case Erro_NovoCadastro_Mudar_CampoInvalido:
			strcpy(res, "Erro: Campo inválido!");
			break;
		case Erro_NovoCadastro_Mudar_AindaNaoDigitou:
			strcpy(res, "Erro: Você ainda não digitou esse campo!");
			break;
		case Erro_NovoCadastro_Mudar_SoPodeOPrimeiro:
			strcpy(res, "Erro: Você só pode alterar o primeiro campo!");
			break;
		case Erro_Arquivo_ErroAoLerArquivos:
			strcpy(res, "Erro ao ler os dados registrados no sistema.");
			break;
		case Erro_Arquivo_ImpossivelLerDataAtual:
			strcpy(res, "Erro ao ler a data de hoje! Por favor, insira-a manualmente!");
			break;
		case Erro_Filtro_NaoExiste:
			strcpy(res, "Erro: Não existem registros para esse filtro!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
}
