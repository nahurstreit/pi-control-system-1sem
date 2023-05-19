#ifndef CADASTRO_H
#define CADASTRO_H

#include "../global/global.h"
#include "cadastro_var/cadastro_var.h"

//Declaração das funções a serem utilizadas pelo código
	/**
	 * @brief: Cria um novo cadastro de acordo com a escolha do usuário
	 * 
	 * @note: Utiliza outras funções da interface.c, menu.c e dados.c para exibir informações na tela, ler dados do usuário, validar e inserir
	 * informações no vetor de dados.
	 *
	 * @details A partir da escolha do usuário, a função define qual tipo de cadastro deve ser realizado (cliente, funcionário ou fornecedor). 
	 * Em seguida, ela exibe um formulário na tela para o usuário preencher e insere as informações no vetor de dados. 
	 * Por fim, a função exibe uma mensagem de confirmação na tela e atualiza o valor de mensagem para 0.
	 * 
	 *
	 * @return: Nenhum.
	 **/
	extern void novoCadastro();
	

	/**
	 * @brief Função responsável por consultar um cadastro de acordo com a escolha do usuário e exibir os dados na tela para seguir com o acesso ao dado
	 * e posteriormente a modificação do dado.
	 *
	 * @details Esta função recebe como entrada quatro ponteiros: pEscolhaUser, pMensagem, pErro e estado, os quais são utilizados para identificar 
	 * a opção de escolha do usuário, exibir mensagens e erros na tela e controlar o estado atual da função quando o usuário estiver modificando um cadastro.
	 * A função inicia com um switch-case para calcular a quantidade de dados existentes no vetor correspondente à escolha do usuário. 
	 * Em seguida, um loop do-while é iniciado para exibir a interface de consulta e receber a posição do cadastro a ser consultado ou modificação. 
	 * Dependendo da escolha do usuário, é exibido o título correspondente na interface de consulta e uma mensagem e/ou erro, caso exista. 
	 * Em seguida, a interface de dados é exibida e, dependendo da opção do usuário, a posição do cadastro é recebida e verificada se é válida. 
	 * Se a posição for válida, a interface de formulário é exibida com os dados do cadastro correspondente e o estado da função é alterado para 1. 
	 * Caso contrário, é exibido um erro ou a função retorna ao estado inicial. 
	 * O loop do-while continua até que a posição do cadastro seja válida ou o usuário opte por voltar para o menu principal.
	 *
	 * @param estado Ponteiro para o estado atual do programa (utilizado na alteração de cadastro).
	 *
	 * @return: Nenhum.
	*/
	extern void consultaCadastro(int *estado);


	/**
	 * @brief: Função responsável por percorrer um vetor de referência e indicar a primeira posição disponível em um vetor de dados.
	 *
	 * @note: Vetor de referência e vetor de dados são estruturas de dados que permitem armazenar informações de forma organizada. 
	 * O vetor de referência é uma estrutura auxiliar que contém apenas valores binários (0 ou 1), que indicam se uma posição correspondente no vetor de dados
	 * está preenchida (1) ou não (0). Já o vetor de dados é a estrutura principal que armazena os dados reais de cadastro.
	 * O vetor de referência e o vetor de dados estão relacionados, de forma que cada posição no vetor de referência corresponde a uma posição no vetor de dados. 
	 * Quando o valor em uma posição do vetor de referência é 1, significa que a posição correspondente no vetor de dados já contém dados armazenados. 
	 * Por outro lado, quando o valor em uma posição do vetor de referência é 0, indica que a posição correspondente no vetor de dados está disponível
	 * para receber novos dados.
	 *
	 * @details: A função posicaoDisponivel percorre o vetor de referência, verificando qual é a primeira posição que contém o valor 0. Ao encontrar a primeira
	 * posição disponível, a função marca essa posição como ocupada (atribuindo o valor 1 ao vetor de referência) e retorna o índice da posição no vetor de dados
	 * correspondente. Isso permite que novos dados possam ser inseridos em uma posição vazia do vetor de dados de forma organizada e sem sobreposição de dados.
	 *
	 * @param vetorReferencia Ponteiro para o vetor de referência a ser percorrido.
	 *
	 * @return: A primeira posição disponível no vetor de dados.
	 **/
	extern int posicaoDisponivel(int *vetorReferencia);


	/**
	 * @brief: Insere uma string em uma posição de cadastro de acordo com o tipo de cadastro e contador de campo.
	 *
	 * @details: A função insere a string em uma posição específica do cadastro de acordo com o tipo de cadastro e o contador de campo.
	 * O tipo de cadastro é usado para determinar em qual estrutura (clientes, funcionários ou fornecedores) a string será inserida.
	 * O contador de campo é usado para determinar em qual campo da estrutura a string será inserida, de acordo com a ordem dos campos
	 * definida na estrutura correspondente.
	 *
	 * @param posicaoDisponivel inteiro que indica a posição disponível para inserir a string.
	 * @param string qual é a string a ser inserida.
	 * @param contadorCampo ponteiro inteiro que aponta para o contador de campos do cadastro correspondente.
	 *
	 * @return: Nenhum.
	 **/
	extern void inserirString(int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);

 
	/**
	  * @brief: Verifica se o valor da posição consultada, no vetor de referência, é igual a zero.
	  *
	  * @attention: A posição escolhida pelo usuário é reduzida em 1 para que possa ser acessada corretamente no vetor de referência.
	  * @remark: A posição do vetor é equivalente ao número de cadastro. Como a posição dos vetores começam sempre na unidade 0, para ser
	  * humanamente intuitivo de interpretar e pensar nos cadastros, o lógico seria pensar que a numeração dos cadastros deve começar a partir do número 1,
	  * não do número 0. Para resolver tal problema, APENAS NA EXIBIÇÃO, sempre é adicionado uma unidade em relação à posição verdadeira do vetor.
	  * Dessa forma, mesmo que o primeiro dado seja armazenado na posição [0] do vetor, para o usuário o número de cadastro do primeiro dado será 1.
	  * Como o usuário vai acabar vendo um número diferente daquele que representa a verdadeira posição que ele quer acessar no vetor de dados, 
	  * faz-se necessário subtrair uma unidade ao receber seu input, para consultar o cadastro correto.
	  * Tal aplicação também facilita tornar 0 um valor exclusivo para voltar ao menu anterior.
	  *
	  * @details: Essa função recebe a escolha do usuário, o vetor de referência, a posição escolhida pelo usuário e um ponteiro para o valor do erro. 
	  * Caso o valor da posição do vetor de referência seja igual a zero, a função atualiza o valor do erro para 4.
	  * Isso faz com que exiba a mensagem indicando que não houve retorno algum, e que o usuário precisa digitar um valor válido.
	  *
	  * @param vetorReferencia Vetor de referência a ser verificado.
	  * @param posicao Posição escolhida pelo usuário.
	  *
	  * @return: Nenhum	
	  **/
	extern void verificarDadosVetorDisponivel(int *vetorReferencia, int posicaoConsultada);
	
		
	/**
	 * @brief: Calcula a quantidade de dados existentes no vetor de referência.
	 *
	 * @details: A função recebe como parâmetro um vetor de dados, e percorre todo o vetor verificando se cada posição contém o valor 1.
	 * Caso a posição contenha 1, o contador de dados existentes é incrementado. No final, a função retorna o número total de dados existentes no vetor.
	 *
	 * @param vetorReferencia Vetor de referência a ser analisado.
	 *
	 * @return: Retorna o número de dados existentes no vetor.
	 **/
	extern int calcularDadosExistentes(int vetorReferencia[MAX_VETOR]);

	/**
	 * @brief: Função que permite a alteração de um campo específico do cadastro do usuário.
	 *
	 * @note: A função utiliza outros elementos e funções previamente declarados no código, como o vetor de campos "camposAtuais",
	 * a string de título "tituloHolder", e as funções "exibirInterfaceTitulo", "exibirInterfaceFormularios", "alterarString"
	 * e "exibirInterfaceInteracao".
	 *
	 * @details: A função exibe o título e formulários do cadastro do usuário, permitindo que ele escolha qual campo deseja alterar
	 * e digitando o novo valor do campo. Em seguida, a função atualiza a string do campo no vetor de dados do cadastro, exibe a mensagem de
	 * sucesso e os novos formulários do cadastro atualizado.
	 *
	 * 
	 * @return: Nenhum
	 **/
	extern void alterarCadastro();
	

	/**
	 * @brief: Altera uma string em uma determinada posição de acordo com o tipo de consulta e o campo escolhido.
	 *
	 * @details: A função realiza a alteração de uma string de um cadastro específico, baseado no tipo de consulta e no campo escolhido. 
	 * É utilizado o comando switch para verificar o tipo de consulta e, em seguida, outro switch para verificar o campo escolhido. 
	 * A string antiga é substituída pela nova utilizando a função strcpy().
	 *
	 * @param posicao A posição do cadastro a ser alterado.
	 * @param stringNova A nova string a ser inserida.
	 * @param campo O campo do cadastro a ser alterado.
	 *
	 * @return: Nenhum.
	 **/
	extern void alterarString(int posicao, char stringNova[MAX_STRING], int campo);
	
	
	/**
	 * @brief: Função para excluir um registro de cliente, funcionário ou fornecedor, dependendo do tipo de consulta atual.
	 *
	 * @note: A função atualiza o vetor global correspondente (clientes, funcionarios ou fornecedores) e o vetor de referência 
	 * correspondente (vetorRefClientes, vetorRefFuncionarios ou vetorRefFornecedores) na posição da consulta atual (definida anteriormente 
	 * quando o usuário seleciona "Consultar (1) Clientes, (2) Funcionários, (3) Fornecedores") tornando esses registros vazios e 
	 * definindo a posição como não ocupada (0).
	 *
	 * @details: A função utiliza um switch para determinar o tipo de consulta atual (clientes, funcionarios ou fornecedores). 
	 * Em seguida, a função copia strings vazias ("") para cada campo do registro na posição da consulta atual do vetor correspondente 
	 * e define a posição como não ocupada no vetor de referência. Isso garante que o registro seja excluído da base de dados.
	 *
	 * @return: Nenhum.
	 **/
	extern void excluirCadastro(int posicaoConsultaAtual);


	/**
	 * @brief: Função responsável por executar a exclusão de um cadastro específico.
	 *
	 * @note: O título e perguntas mudam de acordo com o tipo escolhido. A função utiliza as variáveis globais vetorRefClientes,
	 * vetorRefFuncionarios e vetorRefFornecedores.
	 *
	 * @details: A função inicia com a exibição de uma mensagem de atenção para o usuário. Em seguida, realiza a contagem de cadastros existentes
	 * de acordo com o tipo de consulta atual. (definida anteriormente quando o usuário seleciona "Consultar (1) Clientes, (2) Funcionários, (3) Fornecedores")
	 * Depois, exibe a mensagem correspondente ao tipo de operação escolhida pelo usuário (exclusão ou modificação).
	 * Caso o usuário confirme a operação, a função realiza a exclusão do cadastro na posição atual da consulta e atualiza a interface de dados
	 * de consulta com as informações atualizadas. Caso contrário, exibe novamente a interface de formulários para que o usuário possa realizar alguma outra operação.
	 *
	 * @param tipoTexto Tipo de textos a serem exibidos (1 - Textos para exclusão, 2 - Textos para modificação).
	 * @param pEscolhaUserMod Ponteiro para variável que armazena a escolha do usuário para modificação.
	 *
	 * @return: Não há retorno explícito, mas atualiza as variáveis apontadas pelos ponteiros passados como parâmetros.
	 **/
	extern void executarExcluirCadastro(int tipoTexto, int *pEscolhaUserMod);
	
	extern bool validarPalavraChave(char string[], char stringChave[]);

#endif
