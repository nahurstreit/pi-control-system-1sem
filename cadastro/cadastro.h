#ifndef CADASTRO_H
#define CADASTRO_H

#include "../global/global.h"
#include "cadastro_var/cadastro_var.h"

//Declara��o das fun��es a serem utilizadas pelo c�digo
	/**
	 * @brief: Cria um novo cadastro de acordo com a escolha do usu�rio
	 * 
	 * @note: Utiliza outras fun��es da interface.c, menu.c e dados.c para exibir informa��es na tela, ler dados do usu�rio, validar e inserir
	 * informa��es no vetor de dados.
	 *
	 * @details A partir da escolha do usu�rio, a fun��o define qual tipo de cadastro deve ser realizado (cliente, funcion�rio ou fornecedor). 
	 * Em seguida, ela exibe um formul�rio na tela para o usu�rio preencher e insere as informa��es no vetor de dados. 
	 * Por fim, a fun��o exibe uma mensagem de confirma��o na tela e atualiza o valor de mensagem para 0.
	 * 
	 *
	 * @return: Nenhum.
	 **/
	extern void novoCadastro();
	

	/**
	 * @brief Fun��o respons�vel por consultar um cadastro de acordo com a escolha do usu�rio e exibir os dados na tela para seguir com o acesso ao dado
	 * e posteriormente a modifica��o do dado.
	 *
	 * @details Esta fun��o recebe como entrada quatro ponteiros: pEscolhaUser, pMensagem, pErro e estado, os quais s�o utilizados para identificar 
	 * a op��o de escolha do usu�rio, exibir mensagens e erros na tela e controlar o estado atual da fun��o quando o usu�rio estiver modificando um cadastro.
	 * A fun��o inicia com um switch-case para calcular a quantidade de dados existentes no vetor correspondente � escolha do usu�rio. 
	 * Em seguida, um loop do-while � iniciado para exibir a interface de consulta e receber a posi��o do cadastro a ser consultado ou modifica��o. 
	 * Dependendo da escolha do usu�rio, � exibido o t�tulo correspondente na interface de consulta e uma mensagem e/ou erro, caso exista. 
	 * Em seguida, a interface de dados � exibida e, dependendo da op��o do usu�rio, a posi��o do cadastro � recebida e verificada se � v�lida. 
	 * Se a posi��o for v�lida, a interface de formul�rio � exibida com os dados do cadastro correspondente e o estado da fun��o � alterado para 1. 
	 * Caso contr�rio, � exibido um erro ou a fun��o retorna ao estado inicial. 
	 * O loop do-while continua at� que a posi��o do cadastro seja v�lida ou o usu�rio opte por voltar para o menu principal.
	 *
	 * @param estado Ponteiro para o estado atual do programa (utilizado na altera��o de cadastro).
	 *
	 * @return: Nenhum.
	*/
	extern void consultaCadastro(int *estado);


	/**
	 * @brief: Fun��o respons�vel por percorrer um vetor de refer�ncia e indicar a primeira posi��o dispon�vel em um vetor de dados.
	 *
	 * @note: Vetor de refer�ncia e vetor de dados s�o estruturas de dados que permitem armazenar informa��es de forma organizada. 
	 * O vetor de refer�ncia � uma estrutura auxiliar que cont�m apenas valores bin�rios (0 ou 1), que indicam se uma posi��o correspondente no vetor de dados
	 * est� preenchida (1) ou n�o (0). J� o vetor de dados � a estrutura principal que armazena os dados reais de cadastro.
	 * O vetor de refer�ncia e o vetor de dados est�o relacionados, de forma que cada posi��o no vetor de refer�ncia corresponde a uma posi��o no vetor de dados. 
	 * Quando o valor em uma posi��o do vetor de refer�ncia � 1, significa que a posi��o correspondente no vetor de dados j� cont�m dados armazenados. 
	 * Por outro lado, quando o valor em uma posi��o do vetor de refer�ncia � 0, indica que a posi��o correspondente no vetor de dados est� dispon�vel
	 * para receber novos dados.
	 *
	 * @details: A fun��o posicaoDisponivel percorre o vetor de refer�ncia, verificando qual � a primeira posi��o que cont�m o valor 0. Ao encontrar a primeira
	 * posi��o dispon�vel, a fun��o marca essa posi��o como ocupada (atribuindo o valor 1 ao vetor de refer�ncia) e retorna o �ndice da posi��o no vetor de dados
	 * correspondente. Isso permite que novos dados possam ser inseridos em uma posi��o vazia do vetor de dados de forma organizada e sem sobreposi��o de dados.
	 *
	 * @param vetorReferencia Ponteiro para o vetor de refer�ncia a ser percorrido.
	 *
	 * @return: A primeira posi��o dispon�vel no vetor de dados.
	 **/
	extern int posicaoDisponivel(int *vetorReferencia);


	/**
	 * @brief: Insere uma string em uma posi��o de cadastro de acordo com o tipo de cadastro e contador de campo.
	 *
	 * @details: A fun��o insere a string em uma posi��o espec�fica do cadastro de acordo com o tipo de cadastro e o contador de campo.
	 * O tipo de cadastro � usado para determinar em qual estrutura (clientes, funcion�rios ou fornecedores) a string ser� inserida.
	 * O contador de campo � usado para determinar em qual campo da estrutura a string ser� inserida, de acordo com a ordem dos campos
	 * definida na estrutura correspondente.
	 *
	 * @param posicaoDisponivel inteiro que indica a posi��o dispon�vel para inserir a string.
	 * @param string qual � a string a ser inserida.
	 * @param contadorCampo ponteiro inteiro que aponta para o contador de campos do cadastro correspondente.
	 *
	 * @return: Nenhum.
	 **/
	extern void inserirString(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);

 
	/**
	  * @brief: Verifica se o valor da posi��o consultada, no vetor de refer�ncia, � igual a zero.
	  *
	  * @attention: A posi��o escolhida pelo usu�rio � reduzida em 1 para que possa ser acessada corretamente no vetor de refer�ncia.
	  * @remark: A posi��o do vetor � equivalente ao n�mero de cadastro. Como a posi��o dos vetores come�am sempre na unidade 0, para ser
	  * humanamente intuitivo de interpretar e pensar nos cadastros, o l�gico seria pensar que a numera��o dos cadastros deve come�ar a partir do n�mero 1,
	  * n�o do n�mero 0. Para resolver tal problema, APENAS NA EXIBI��O, sempre � adicionado uma unidade em rela��o � posi��o verdadeira do vetor.
	  * Dessa forma, mesmo que o primeiro dado seja armazenado na posi��o [0] do vetor, para o usu�rio o n�mero de cadastro do primeiro dado ser� 1.
	  * Como o usu�rio vai acabar vendo um n�mero diferente daquele que representa a verdadeira posi��o que ele quer acessar no vetor de dados, 
	  * faz-se necess�rio subtrair uma unidade ao receber seu input, para consultar o cadastro correto.
	  * Tal aplica��o tamb�m facilita tornar 0 um valor exclusivo para voltar ao menu anterior.
	  *
	  * @details: Essa fun��o recebe a escolha do usu�rio, o vetor de refer�ncia, a posi��o escolhida pelo usu�rio e um ponteiro para o valor do erro. 
	  * Caso o valor da posi��o do vetor de refer�ncia seja igual a zero, a fun��o atualiza o valor do erro para 4.
	  * Isso faz com que exiba a mensagem indicando que n�o houve retorno algum, e que o usu�rio precisa digitar um valor v�lido.
	  *
	  * @param vetorReferencia Vetor de refer�ncia a ser verificado.
	  * @param posicao Posi��o escolhida pelo usu�rio.
	  *
	  * @return: Nenhum	
	  **/
	extern void verificarDadosVetorDisponivel(int *vetorReferencia, int posicaoConsultada);
	
		
	/**
	 * @brief: Calcula a quantidade de dados existentes no vetor de refer�ncia.
	 *
	 * @details: A fun��o recebe como par�metro um vetor de dados, e percorre todo o vetor verificando se cada posi��o cont�m o valor 1.
	 * Caso a posi��o contenha 1, o contador de dados existentes � incrementado. No final, a fun��o retorna o n�mero total de dados existentes no vetor.
	 *
	 * @param vetorReferencia Vetor de refer�ncia a ser analisado.
	 *
	 * @return: Retorna o n�mero de dados existentes no vetor.
	 **/
	extern int calcularDadosExistentes(int vetorReferencia[MAX_VETOR]);

	/**
	 * @brief: Fun��o que permite a altera��o de um campo espec�fico do cadastro do usu�rio.
	 *
	 * @note: A fun��o utiliza outros elementos e fun��es previamente declarados no c�digo, como o vetor de campos "camposAtuais",
	 * a string de t�tulo "tituloHolder", e as fun��es "exibirInterfaceTitulo", "exibirInterfaceFormularios", "alterarString"
	 * e "exibirInterfaceInteracao".
	 *
	 * @details: A fun��o exibe o t�tulo e formul�rios do cadastro do usu�rio, permitindo que ele escolha qual campo deseja alterar
	 * e digitando o novo valor do campo. Em seguida, a fun��o atualiza a string do campo no vetor de dados do cadastro, exibe a mensagem de
	 * sucesso e os novos formul�rios do cadastro atualizado.
	 *
	 * 
	 * @return: Nenhum
	 **/
	extern void alterarCadastro();
	

	/**
	 * @brief: Altera uma string em uma determinada posi��o de acordo com o tipo de consulta e o campo escolhido.
	 *
	 * @details: A fun��o realiza a altera��o de uma string de um cadastro espec�fico, baseado no tipo de consulta e no campo escolhido. 
	 * � utilizado o comando switch para verificar o tipo de consulta e, em seguida, outro switch para verificar o campo escolhido. 
	 * A string antiga � substitu�da pela nova utilizando a fun��o strcpy().
	 *
	 * @param posicao A posi��o do cadastro a ser alterado.
	 * @param stringNova A nova string a ser inserida.
	 * @param campo O campo do cadastro a ser alterado.
	 *
	 * @return: Nenhum.
	 **/
	extern void alterarString(int posicao, char stringNova[MAX_STRING], int campo);
	
	
	/**
	 * @brief: Fun��o para excluir um registro de cliente, funcion�rio ou fornecedor, dependendo do tipo de consulta atual.
	 *
	 * @note: A fun��o atualiza o vetor global correspondente (clientes, funcionarios ou fornecedores) e o vetor de refer�ncia 
	 * correspondente (vetorRefClientes, vetorRefFuncionarios ou vetorRefFornecedores) na posi��o da consulta atual (definida anteriormente 
	 * quando o usu�rio seleciona "Consultar (1) Clientes, (2) Funcion�rios, (3) Fornecedores") tornando esses registros vazios e 
	 * definindo a posi��o como n�o ocupada (0).
	 *
	 * @details: A fun��o utiliza um switch para determinar o tipo de consulta atual (clientes, funcionarios ou fornecedores). 
	 * Em seguida, a fun��o copia strings vazias ("") para cada campo do registro na posi��o da consulta atual do vetor correspondente 
	 * e define a posi��o como n�o ocupada no vetor de refer�ncia. Isso garante que o registro seja exclu�do da base de dados.
	 *
	 * @return: Nenhum.
	 **/
	extern void excluirCadastro(int posicaoConsultaAtual);


	/**
	 * @brief: Fun��o respons�vel por executar a exclus�o de um cadastro espec�fico.
	 *
	 * @note: O t�tulo e perguntas mudam de acordo com o tipo escolhido. A fun��o utiliza as vari�veis globais vetorRefClientes,
	 * vetorRefFuncionarios e vetorRefFornecedores.
	 *
	 * @details: A fun��o inicia com a exibi��o de uma mensagem de aten��o para o usu�rio. Em seguida, realiza a contagem de cadastros existentes
	 * de acordo com o tipo de consulta atual. (definida anteriormente quando o usu�rio seleciona "Consultar (1) Clientes, (2) Funcion�rios, (3) Fornecedores")
	 * Depois, exibe a mensagem correspondente ao tipo de opera��o escolhida pelo usu�rio (exclus�o ou modifica��o).
	 * Caso o usu�rio confirme a opera��o, a fun��o realiza a exclus�o do cadastro na posi��o atual da consulta e atualiza a interface de dados
	 * de consulta com as informa��es atualizadas. Caso contr�rio, exibe novamente a interface de formul�rios para que o usu�rio possa realizar alguma outra opera��o.
	 *
	 * @param tipoTexto Tipo de textos a serem exibidos (1 - Textos para exclus�o, 2 - Textos para modifica��o).
	 * @param pEscolhaUserMod Ponteiro para vari�vel que armazena a escolha do usu�rio para modifica��o.
	 *
	 * @return: N�o h� retorno expl�cito, mas atualiza as vari�veis apontadas pelos ponteiros passados como par�metros.
	 **/
	extern void executarExcluirCadastro(int tipoTexto, int *pEscolhaUserMod);
	
	extern bool validarPalavraChave(char string[], char stringChave[]);

#endif
