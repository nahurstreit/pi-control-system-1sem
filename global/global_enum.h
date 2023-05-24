#ifndef GLOBAL_ENUM_H
#define GLOBAL_ENUM_H

typedef enum {
	Erro_Nenhum = 0,
	Erro_Input_ApenasNumeros,
	Erro_Input_ApenasLetras,
	Erro_Input_Status_Invalido,
	Erro_Input_CPF_Invalido,
	Erro_Input_CNPJ_Invalido,
	Erro_Input_DataNascimento_Invalida,
	Erro_Input_DataAdmissao_Invalida,
	Erro_Input_EstadoCivil_Invalido,
	Erro_Input_Telefone_Invalido,
	Erro_Input_CEP_Invalido,
	Erro_Input_Estado_Invalido,
	Erro_OpcaoInvalida,
	Erro_Consulta_NaoPossivel,
	Erro_Consulta_NaoExiste,
	Erro_NovoCadastro_Mudar_NenhumCampoAinda,
	Erro_NovoCadastro_Mudar_CampoInvalido,
	Erro_NovoCadastro_Mudar_AindaNaoDigitou,
	Erro_NovoCadastro_Mudar_SoPodeOPrimeiro,
	Erro_Arquivo_ErroAoLerArquivos,
} Erro;

typedef enum {
	Mensagem_Cadastro_Novo = 1,
	Mensagem_Cadastro_Excluido,
	Mensagem_Cadastro_Cancelado,
	Mensagem_CampoAlterado,
} Mensagem;

#endif
