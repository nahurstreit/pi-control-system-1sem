#ifndef INTERFACE_H
#define INTERFACE_H

#include "menu.h"
#include "cadastro.h"

#define MAX_LINHA 103
#define MAX_CABECALHO 3

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

//Fun��es de interface:
	/**
	 * @brief: Esta fun��o � respons�vel por exibir na tela um formul�rio gr�fico com as informa��es de um cliente, funcion�rio ou fornecedor, 
	 * dependendo da op��o escolhida pelo usu�rio.
	 *
	 * @note: esta fun��o recebe como entrada os dados dos clientes, funcion�rios e fornecedores para exibi��o gr�fica em um formul�rio pr�-montado.
	 * Os formul�rios pr�-montados s�o dispostos na parte superior do arquivo interface.c e nada mais s�o do que um vetores do tipo Display, que carregam
	 * linhas j� divididas para armazenar os campos espec�ficos.
	 * Sendo utilizado com a fun��o novoCadastro(), � capaz de exibir em tempo real o que o usu�rio acabou de digitar, dentro do formul�rio visual.
	 * Tamb�m, sendo utilizado com a fun��o consultaCadastro(), � capaz de exibir os dados j� existentes nos vetores de dados.
	 *
	 * @details: esta fun��o exibe um formul�rio com as informa��es de um cliente, funcion�rio ou fornecedor, dependendo da op��o escolhida pelo usu�rio.
	 * � utilizado um vetor de estruturas Display para armazenar cada linha do formul�rio a ser exibido. O vetor copiaDisplay � utilizado para armazenar
	 * as informa��es do vetor de Display original e, posteriormente, atualizar as informa��es de acordo com os dados do vetor de clientes, funcion�rios
	 * ou fornecedores. Os dados s�o atualizados por meio de la�os de repeti��o que percorrem as linhas do vetor copiaDisplay e atualizam as informa��es
	 * de acordo com as informa��es do vetor de clientes, funcion�rios ou fornecedores. Vale ressaltar que essa fun��o n�o recebe ou valida os dados,
	 * apenas os exibe em uma interface gr�fica.
	 *
	 * @param clientes[]: vetor de dados de clientes.
	 * @param funcionarios[]: vetor de dados de funcion�rios.
	 * @param fornecedores[]: vetor de dados de fornecedores.
	 * @param *pEscolhaUser: ponteiro para a escolha do usu�rio.
	 * @param posicao: posi��o do elemento no vetor a ser exibido.
	 *
	 * @return: a fun��o n�o possui retorno.
	 **/
	void exibirInterfaceFormularios(Cliente clientes[], Funcionario funcionarios[], Fornecedor fornecedores[], int *pEscolhaUser, int posicao);
	

	/**
	 * @brief: Fun��o que exibe uma interface com dados m�nimos para consulta e refer�ncia de dados j� existentes de clientes, funcion�rios e fornecedores.
	 *
	 * @details: A fun��o come�a com a declara��o de algumas vari�veis locais, incluindo um vetor de caracteres que � usado para armazenar o valor de i
	 * como uma string, um ponteiro para um objeto Display que cont�m informa��es do cabe�alho atual de dados m�nimos e um vetor de objetos Display que
	 * cont�m informa��es de como s�o as bordas para aquele tipo de dado m�nimo.
	 * Em seguida, a fun��o usa um switch para determinar qual tipo de consulta o usu�rio deseja realizar. Se o usu�rio escolher a consulta de clientes,
	 * a fun��o exibe o cabe�alho de consulta de clientes e percorre o vetor de refer�ncia de clientes, se o valor de i for = 1, significa que existem
	 * dados no vetor de dados, ent�o exibe as informa��es m�nimas correspondentes para cada cliente que est� cadastrado no sistema.
	 * O mesmo racioc�nio de cabe�alho, borda e percorrer o vetor de refer�ncia, se repete para funcion�rios e fornecedores. 
	 * Em cada caso, a fun��o usa os objetos Display para exibir as informa��es de cada item.
	 *
	 * @param clientes: vetor de clientes cadastrados.
	 * @param vetorRefClientes: vetor de refer�ncia de clientes, onde cada posi��o � 1 se o cliente correspondente est� cadastrado ou 0 caso contr�rio.
	 * @param funcionarios: vetor de funcion�rios cadastrados.
	 * @param vetorRefFuncionarios: vetor de refer�ncia de funcion�rios, onde cada posi��o � 1 se o funcion�rio correspondente est� cadastrado ou 0 caso contr�rio.
	 * @param fornecedores: vetor de fornecedores cadastrados.
	 * @param vetorRefFornecedores: vetor de refer�ncia de fornecedores, onde cada posi��o � 1 se o fornecedor correspondente est� cadastrado ou 0 caso contr�rio.
	 * @param pEscolhaUser: ponteiro para inteiro que indica a escolha do usu�rio.
	 * @param contadorDadosExistentes: contador que indica a quantidade de dados existentes no sistema.
	 *
	 *@return: Nenhum.
	 **/	
	void exibirInterfaceDadosConsulta(Cliente clientes[], int vetorRefClientes[], Funcionario funcionarios[], int vetorRefFuncionarios[], Fornecedor fornecedores[], int vetorRefFornecedores[], int *pEscolhaUser, int contadorDadosExistentes);

	/**
	 * @brief: Exibe um t�tulo na interface gr�fica.
	 *
	 * @details: A fun��o recebe uma string que ser� exibida como t�tulo na interface gr�fica.
	 * Se o par�metro "limpar" for igual a 1, a fun��o limpa a tela antes de exibir o t�tulo.
	 * Antes de exibir o t�tulo na interface gr�fica, � exibido a logotipo da empresa, em todos os itens do menu.
	 * A fun��o cria uma c�pia do display de refer�ncia do t�tulo e altera a linha do meio para exibir a string como t�tulo.
	 * A fun��o ent�o exibe as tr�s linhas do display na tela.
	 *
	 * @param string String que ser� exibida como t�tulo.
	 * @param limpar Se for igual a 1, limpa a tela antes de exibir o t�tulo.
	 *
	 * @return: Nenhum
	 **/
	void exibirInterfaceTitulo(char string[], int limpar);
	
	/**
	 * @brief: Exibe o cabe�alho atual de consulta na tela, em uma inteface gr�fica.
	 *
	 * @details: Essa fun��o recebe como par�metro um ponteiro para um array de strings que representa o cabe�alho atual do sistema e exibe 
	 * cada linha do cabe�alho na tela. O n�mero m�ximo de linhas do cabe�alho � definido pela constante MAX_CABECALHO.
	 *
	 * @param displayCabecalhoAtual Ponteiro para o array de strings que representa o cabe�alho atual do sistema
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceCabecalhoAtual(Display *displayCabecalhoAtual);

	/**
	 * @brief: Exibe na tela uma interface de intera��o com o usu�rio contendo uma string (Mensagem ou Erro).
	 * 
	 * @details: A fun��o imprime na tela uma interface com uma moldura composta de pontos, com a string passada como par�metro centralizada no meio
	 * e com dois espa�os em branco abaixo da moldura.
	 *
	 * @param string[] String a ser exibida na interface de intera��o.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceInteracao(char string[]);
	
	/**
	 * @brief: A fun��o exibirInterfaceOpcoes � respons�vel por exibir na tela as op��es de um determinado menu, em um layout padronizado com bordas, 
	 * cabe�alho e n�mero de op��es.
	 *
	 * @note: A fun��o utiliza refer�ncia de uma vari�vel global MAX_LINHA, que cont�m as dimens�es da interface gr�fica.
	 *
	 * @details: A fun��o come�a criando o cabe�alho "Op��es", com as bordas laterais preenchidas por caracteres "~", centralizando o texto.
	 *  Depois disso, a fun��o percorre as op��es do menu e as exibe na tela com seus respectivos n�meros e textos. Por fim, a fun��o exibe
	 * uma linha horizontal de caracteres "~", indicando o final da lista de op��es, e solicita ao usu�rio que digite sua op��o.
	 *
	 * @param pMenuAtual Recebe um ponteiro para uma estrutura do tipo Menu, que cont�m as op��es a serem exibidas.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceOpcoes(Menu *pMenuAtual);
	
	
	/**
	 * @brief: exibirInterfaceAlerta � uma fun��o que recebe uma string como par�metro e exibe um alerta estilizado na interface do usu�rio. 
	 * A string passada � centralizada horizontalmente dentro do alerta.
	 *
	 * @details: A fun��o come�a imprimindo uma linha horizontal de "x" com tamanho MAX_LINHA. Em seguida, imprime a primeira linha vertical com um "x"
	 * no come�o e no final e espa�os em branco no meio. A segunda linha vertical � semelhante, mas cont�m a string passada como par�metro centralizada
	 * horizontalmente. A terceira linha vertical � igual � primeira, e a �ltima linha horizontal � igual � primeira.
	 *
	 * @param string[] � a string que ser� exibida no centro do alerta.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceAlerta(char string[]);
	
	
	/**
	 * @brief: Fun��o respons�vel por exibir uma string no centro da tela.
	 *
	 * @details: A fun��o calcula o n�mero de espa�os que devem ser inseridos antes da string para que ela fique centralizada na tela. 
	 * Em seguida, exibe a string na tela.
	 *
	 * @param string[]: String que ser� exibida no centro da tela.
	 *
	 * @return: Nenhum.
	 **/
	void exibirTextoMeio(char string[]);
	
	/**
	 * @brief: Fun��o respons�vel por exibir a logotipo no centro da tela.
	 *
	 * @return: Nenhum.
	 **/
	void exibirLogotipo();
	
#endif
