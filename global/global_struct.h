#ifndef GLOBAL_STRUCT_H
#define GLOBAL_STRUCT_H

#include "global_define.h"

//MENU
	/**
	 * @brief Struct que define uma estrutura de menu, contendo um texto, n�mero da op��o e uma fun��o a ser executada.
	 *
	 * @param textoDaOpcao: o texto que ser� exibido para o usu�rio na op��o do menu.
	 * @param numeroDaOpcao: o n�mero que representa a op��o do menu e qual o n�mero que o usu�rio dever� digitar para acessar a op��o.
	 * @param funcao: ponteiro para a fun��o que ser� executada quando a op��o do menu for escolhida.
	 **/
	typedef struct {
		char textoDaOpcao[50];
		int numeroDaOpcao;
		void (*funcao)();
	} OpcaoDoMenu;

	/**
	 * @brief Struct que define uma estrutura de menu, contendo um t�tulo, n�mero de op��es e um array de op��es.
	 * 
	 * @param tituloDoMenu O t�tulo do menu.
	 * @param numeroDeOpcoes O n�mero de op��es no menu.
	 * @param opcoes Um array de OpcaoDoMenu contendo as op��es do menu.
	 **/
	typedef struct {
		char tituloDoMenu[50];
		int numeroDeOpcoes;
		OpcaoDoMenu opcoes[10];
	} Menu;
//

//CADASTRO
	/**
	 * @brief Defini��o do struct do tipo Cliente, para armazenar de forma categ�rica os dados do cliente.
	 **/
	typedef struct {
		char nome[MAX_STRING];
		char cpf[MAX_STRING];
		char dataNascimento[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[MAX_STRING];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Cliente;
	
	/**
	 * @brief Defini��o do struct do tipo Funcion�rio, para armazenar de forma categ�rica os dados do funcion�rio.
	 **/
	typedef struct {
		char nome[MAX_STRING];
		char status[MAX_STRING];
		char cpf[MAX_STRING];
		char dataNascimento[MAX_STRING];
		char estadoCivil[MAX_STRING];
		char dataAdmissao[MAX_STRING];
		char salarioBase[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[MAX_STRING];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Funcionario;
	
	/**
	 * @brief Defini��o do struct do tipo Fornecedor, para armazenar de forma categ�rica os dados do fornecedor.
	 **/
	typedef struct {
		char nomeFantasia[MAX_STRING];
		char cnpj[MAX_STRING];
		char telefone[MAX_STRING];
		char email[MAX_STRING];
		char site[MAX_STRING];
		char endereco[MAX_STRING];
		char numEndereco[MAX_STRING];
		char compEndereco[MAX_STRING];
		char bairro[MAX_STRING];
		char cep[MAX_STRING];
		char cidade[MAX_STRING];
		char estado[MAX_STRING];
	} Fornecedor;
//	
	/**
	 * @brief Defini��o do struct do tipo TextoCampo, para armazenar os textos que ser�o exibidos na hora de pedir e alterar os dados de um cadastro.
	 **/
	typedef struct {
		char displayCampo[70];
	} TextoCampo;

//

//INTERFACE
	/**
	 * @brief: Define uma estrutura de dados do tipo Display, que � utilizada para armazenar uma string que representa uma linha
	 * do display da interface gr�fica do programa.
	 *
	 * @details: A estrutura Display � utilizada para representar as linhas do display da interface gr�fica do programa, sendo que cada 
	 * elemento do array de Display corresponde a uma linha. A constante MAX_LINHA representa o tamanho m�ximo que cada linha pode ter.
	 * A estrutura � utilizada em diversos pontos do c�digo para exibir informa��es para o usu�rio de forma visualmente agrad�vel e organizada.
	 *
	 * @param linhaDisplay Array de caracteres que armazena a string que representa uma linha do display.
	 *
	 **/
	typedef struct {
		char linhaDisplay[MAX_LINHA];
	} Display;
//


typedef struct {
	int codigoProduto;
	char nomeProduto[MAX_STRING];
	float valorUnitario;
} Produto;

typedef struct {
	char codigoProduto[MAX_STRING];
	char nome[MAX_STRING];
	char quantidade[MAX_STRING];
	char valorUnit[MAX_STRING];
} Item;

typedef struct {
	char codigoOrdem[MAX_STRING];
	char data[MAX_STRING];
	char numCadCliente[MAX_STRING];
	char valorTotal[MAX_STRING];
	char nomeCliente[MAX_STRING];
	char cpfCliente[MAX_STRING];
	char telefoneCliente[MAX_STRING];
	char enderecoCliente[MAX_STRING];
	char numEnderecoCliente[MAX_STRING];
	char compEnderecoCliente[MAX_STRING];
	char cepCliente[MAX_STRING];
	char bairroCliente[MAX_STRING];
	char cidadeCliente[MAX_STRING];
	char estadoCliente[MAX_STRING];
	char numCadFuncionario[MAX_STRING];
	char nomeFuncionario[MAX_STRING];
	Item itens[MAX_VETOR];
} Producao;

#endif
