#ifndef INTERFACE_H
#define INTERFACE_H

#include "menu.h"
#include "cadastro.h"

#define MAX_LINHA 103
#define MAX_CABECALHO 3

	/**
	 * @brief: Define uma estrutura de dados do tipo Display, que é utilizada para armazenar uma string que representa uma linha
	 * do display da interface gráfica do programa.
	 *
	 * @details: A estrutura Display é utilizada para representar as linhas do display da interface gráfica do programa, sendo que cada 
	 * elemento do array de Display corresponde a uma linha. A constante MAX_LINHA representa o tamanho máximo que cada linha pode ter.
	 * A estrutura é utilizada em diversos pontos do código para exibir informações para o usuário de forma visualmente agradável e organizada.
	 *
	 * @param linhaDisplay Array de caracteres que armazena a string que representa uma linha do display.
	 *
	 **/
	typedef struct {
		char linhaDisplay[MAX_LINHA];
	} Display;

//Funções de interface:
	/**
	 * @brief: Esta função é responsável por exibir na tela um formulário gráfico com as informações de um cliente, funcionário ou fornecedor, 
	 * dependendo da opção escolhida pelo usuário.
	 *
	 * @note: esta função recebe como entrada os dados dos clientes, funcionários e fornecedores para exibição gráfica em um formulário pré-montado.
	 * Os formulários pré-montados são dispostos na parte superior do arquivo interface.c e nada mais são do que um vetores do tipo Display, que carregam
	 * linhas já divididas para armazenar os campos específicos.
	 * Sendo utilizado com a função novoCadastro(), é capaz de exibir em tempo real o que o usuário acabou de digitar, dentro do formulário visual.
	 * Também, sendo utilizado com a função consultaCadastro(), é capaz de exibir os dados já existentes nos vetores de dados.
	 *
	 * @details: esta função exibe um formulário com as informações de um cliente, funcionário ou fornecedor, dependendo da opção escolhida pelo usuário.
	 * É utilizado um vetor de estruturas Display para armazenar cada linha do formulário a ser exibido. O vetor copiaDisplay é utilizado para armazenar
	 * as informações do vetor de Display original e, posteriormente, atualizar as informações de acordo com os dados do vetor de clientes, funcionários
	 * ou fornecedores. Os dados são atualizados por meio de laços de repetição que percorrem as linhas do vetor copiaDisplay e atualizam as informações
	 * de acordo com as informações do vetor de clientes, funcionários ou fornecedores. Vale ressaltar que essa função não recebe ou valida os dados,
	 * apenas os exibe em uma interface gráfica.
	 *
	 * @param clientes[]: vetor de dados de clientes.
	 * @param funcionarios[]: vetor de dados de funcionários.
	 * @param fornecedores[]: vetor de dados de fornecedores.
	 * @param *pEscolhaUser: ponteiro para a escolha do usuário.
	 * @param posicao: posição do elemento no vetor a ser exibido.
	 *
	 * @return: a função não possui retorno.
	 **/
	void exibirInterfaceFormularios(Cliente clientes[], Funcionario funcionarios[], Fornecedor fornecedores[], int *pEscolhaUser, int posicao);
	

	/**
	 * @brief: Função que exibe uma interface com dados mínimos para consulta e referência de dados já existentes de clientes, funcionários e fornecedores.
	 *
	 * @details: A função começa com a declaração de algumas variáveis locais, incluindo um vetor de caracteres que é usado para armazenar o valor de i
	 * como uma string, um ponteiro para um objeto Display que contém informações do cabeçalho atual de dados mínimos e um vetor de objetos Display que
	 * contém informações de como são as bordas para aquele tipo de dado mínimo.
	 * Em seguida, a função usa um switch para determinar qual tipo de consulta o usuário deseja realizar. Se o usuário escolher a consulta de clientes,
	 * a função exibe o cabeçalho de consulta de clientes e percorre o vetor de referência de clientes, se o valor de i for = 1, significa que existem
	 * dados no vetor de dados, então exibe as informações mínimas correspondentes para cada cliente que está cadastrado no sistema.
	 * O mesmo raciocínio de cabeçalho, borda e percorrer o vetor de referência, se repete para funcionários e fornecedores. 
	 * Em cada caso, a função usa os objetos Display para exibir as informações de cada item.
	 *
	 * @param clientes: vetor de clientes cadastrados.
	 * @param vetorRefClientes: vetor de referência de clientes, onde cada posição é 1 se o cliente correspondente está cadastrado ou 0 caso contrário.
	 * @param funcionarios: vetor de funcionários cadastrados.
	 * @param vetorRefFuncionarios: vetor de referência de funcionários, onde cada posição é 1 se o funcionário correspondente está cadastrado ou 0 caso contrário.
	 * @param fornecedores: vetor de fornecedores cadastrados.
	 * @param vetorRefFornecedores: vetor de referência de fornecedores, onde cada posição é 1 se o fornecedor correspondente está cadastrado ou 0 caso contrário.
	 * @param pEscolhaUser: ponteiro para inteiro que indica a escolha do usuário.
	 * @param contadorDadosExistentes: contador que indica a quantidade de dados existentes no sistema.
	 *
	 *@return: Nenhum.
	 **/	
	void exibirInterfaceDadosConsulta(Cliente clientes[], int vetorRefClientes[], Funcionario funcionarios[], int vetorRefFuncionarios[], Fornecedor fornecedores[], int vetorRefFornecedores[], int *pEscolhaUser, int contadorDadosExistentes);

	/**
	 * @brief: Exibe um título na interface gráfica.
	 *
	 * @details: A função recebe uma string que será exibida como título na interface gráfica.
	 * Se o parâmetro "limpar" for igual a 1, a função limpa a tela antes de exibir o título.
	 * Antes de exibir o título na interface gráfica, é exibido a logotipo da empresa, em todos os itens do menu.
	 * A função cria uma cópia do display de referência do título e altera a linha do meio para exibir a string como título.
	 * A função então exibe as três linhas do display na tela.
	 *
	 * @param string String que será exibida como título.
	 * @param limpar Se for igual a 1, limpa a tela antes de exibir o título.
	 *
	 * @return: Nenhum
	 **/
	void exibirInterfaceTitulo(char string[], int limpar);
	
	/**
	 * @brief: Exibe o cabeçalho atual de consulta na tela, em uma inteface gráfica.
	 *
	 * @details: Essa função recebe como parâmetro um ponteiro para um array de strings que representa o cabeçalho atual do sistema e exibe 
	 * cada linha do cabeçalho na tela. O número máximo de linhas do cabeçalho é definido pela constante MAX_CABECALHO.
	 *
	 * @param displayCabecalhoAtual Ponteiro para o array de strings que representa o cabeçalho atual do sistema
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceCabecalhoAtual(Display *displayCabecalhoAtual);

	/**
	 * @brief: Exibe na tela uma interface de interação com o usuário contendo uma string (Mensagem ou Erro).
	 * 
	 * @details: A função imprime na tela uma interface com uma moldura composta de pontos, com a string passada como parâmetro centralizada no meio
	 * e com dois espaços em branco abaixo da moldura.
	 *
	 * @param string[] String a ser exibida na interface de interação.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceInteracao(char string[]);
	
	/**
	 * @brief: A função exibirInterfaceOpcoes é responsável por exibir na tela as opções de um determinado menu, em um layout padronizado com bordas, 
	 * cabeçalho e número de opções.
	 *
	 * @note: A função utiliza referência de uma variável global MAX_LINHA, que contêm as dimensões da interface gráfica.
	 *
	 * @details: A função começa criando o cabeçalho "Opções", com as bordas laterais preenchidas por caracteres "~", centralizando o texto.
	 *  Depois disso, a função percorre as opções do menu e as exibe na tela com seus respectivos números e textos. Por fim, a função exibe
	 * uma linha horizontal de caracteres "~", indicando o final da lista de opções, e solicita ao usuário que digite sua opção.
	 *
	 * @param pMenuAtual Recebe um ponteiro para uma estrutura do tipo Menu, que contém as opções a serem exibidas.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceOpcoes(Menu *pMenuAtual);
	
	
	/**
	 * @brief: exibirInterfaceAlerta é uma função que recebe uma string como parâmetro e exibe um alerta estilizado na interface do usuário. 
	 * A string passada é centralizada horizontalmente dentro do alerta.
	 *
	 * @details: A função começa imprimindo uma linha horizontal de "x" com tamanho MAX_LINHA. Em seguida, imprime a primeira linha vertical com um "x"
	 * no começo e no final e espaços em branco no meio. A segunda linha vertical é semelhante, mas contém a string passada como parâmetro centralizada
	 * horizontalmente. A terceira linha vertical é igual à primeira, e a última linha horizontal é igual à primeira.
	 *
	 * @param string[] é a string que será exibida no centro do alerta.
	 *
	 * @return: Nenhum.
	 **/
	void exibirInterfaceAlerta(char string[]);
	
	
	/**
	 * @brief: Função responsável por exibir uma string no centro da tela.
	 *
	 * @details: A função calcula o número de espaços que devem ser inseridos antes da string para que ela fique centralizada na tela. 
	 * Em seguida, exibe a string na tela.
	 *
	 * @param string[]: String que será exibida no centro da tela.
	 *
	 * @return: Nenhum.
	 **/
	void exibirTextoMeio(char string[]);
	
	/**
	 * @brief: Função responsável por exibir a logotipo no centro da tela.
	 *
	 * @return: Nenhum.
	 **/
	void exibirLogotipo();
	
#endif
