#ifndef GLOBAL_ENUM_H
#define GLOBAL_ENUM_H

typedef enum {
	Erro_Nenhum = 0,
	Erro_Input_ApenasNumeros,
	Erro_Input_ApenasLetras,
	Erro_Input_Status_Invalido,
	Erro_Input_CPF_Invalido,
	Erro_Input_CPF_JaCadastrado,
	Erro_Input_CNPJ_Invalido,
	Erro_Input_CNPJ_JaCadastrado,
	Erro_Input_Data_Invalida,
	Erro_Input_DataNascimento_Invalida,
	Erro_Input_DataAdmissao_Invalida,
	Erro_Input_EstadoCivil_Invalido,
	Erro_Input_Telefone_Invalido,
	Erro_Input_CEP_Invalido,
	Erro_Input_Estado_Invalido,
	Erro_Input_Producao_Item_NaoExiste,
	Erro_OpcaoInvalida,
	Erro_Consulta_NaoPossivel,
	Erro_Consulta_NaoExiste,
	Erro_NovoCadastro_Mudar_NenhumCampoAinda,
	Erro_NovoCadastro_Mudar_CampoInvalido,
	Erro_NovoCadastro_Mudar_AindaNaoDigitou,
	Erro_NovoCadastro_Mudar_SoPodeOPrimeiro,
	Erro_Arquivo_ErroAoLerArquivos,
	Erro_Arquivo_ImpossivelLerDataAtual,
	Erro_Filtro_NaoExiste,
} Erro;

typedef enum {
	Mensagem_Cadastro_Novo = 1,
	Mensagem_Cadastro_Excluido,
	Mensagem_Cadastro_Cancelado,
	Mensagem_Cadastro_Modificado,
	Mensagem_CampoAlterado,
	Mensagem_Producao_Nova,
	Mensagem_Producao_Cancelada,
	Mensagem_Producao_Item_Adicionado,
	Mensagem_Producao_Item_Excluido,
	Mensagem_Producao_Excluida,
	Mensagem_Impressao_Concluida,
} Mensagem;

typedef enum {
	Filtro_Data = 1,
	Filtro_Cliente,
	Filtro_Funcionario,
} Filtro;

#endif
