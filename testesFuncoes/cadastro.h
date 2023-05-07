#ifndef CADASTRO_H
#define CADASTRO_H

#define MAX_STRING 50

//Fun��es cadastro:
int novoCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);
int consultaCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);

//Cria��o do struct(tipo) Cliente, para armazenar os dados dos clientes.
typedef struct {
	char nome[MAX_STRING];
	char cpf[MAX_STRING];
	char dataNascimento[MAX_STRING];
	char telefone[MAX_STRING];
	char email[MAX_STRING];
	char endereco[MAX_STRING];
	char numEndereco[6];
	char compEndereco[MAX_STRING];
	char bairro[MAX_STRING];
	char cep[MAX_STRING];
	char cidade[MAX_STRING];
	char estado[MAX_STRING];

} Cliente;

//Cria��o do struct(tipo) Funcionario, para armazenar os dados dos funcionarios.
typedef struct {
	char nome[MAX_STRING];
	char estadoEmpresa[MAX_STRING];
	char cpf[MAX_STRING];
	char dataNascimento[MAX_STRING];
	char estadoCivil[MAX_STRING];
	char dataAdmissao[MAX_STRING];
	char salarioBase[MAX_STRING];
	char telefone[MAX_STRING];
	char email[MAX_STRING];
	char endereco[MAX_STRING];
	char numEndereco[6];
	char compEndereco[MAX_STRING];
	char bairro[MAX_STRING];
	char cep[MAX_STRING];
	char cidade[MAX_STRING];
	char estado[MAX_STRING];
} Funcionario;

//Cria��o do struct(tipo) Fornecedor, para armazenar os dados dos fornecedores.
typedef struct {
	char nomeFantasia[MAX_STRING];
	char cnpj[MAX_STRING];
	char telefone[MAX_STRING];
	char email[MAX_STRING];
	char endereco[MAX_STRING];
	char numEndereco[6];
	char compEndereco[MAX_STRING];
	char bairro[MAX_STRING];
	char cep[MAX_STRING];
	char cidade[MAX_STRING];
	char estado[MAX_STRING];
} Fornecedor;

//Cria��o do struct(tipo) TextoCampo, para armazenar os textos que ser�o exibidos ao pedir para o usu�rio digitar alguma coisa no cadastro
typedef struct {
	char displayCampo[30];
} TextoCampo;

//Declara��o das fun��es a serem utilizadas pelo c�digo
	
//Explica��o detalhada de posicaoDisponivel:
		int posicaoDisponivel(int *vetor);
		/* posicaoDisponivel � a fun��o respons�vel por percorrer os, aqui chamados, vetores de refer�ncia(vetorRefClientes, vetorRefFuncionarios, vetorFornecedores)
		os quais armazenam em si apenas 0 ou 1 e correlacionar com a mesma posi��o nos, aqui chamados, vetores de dados(funcionarios, clientes, fornecedores). 
		Quando um vetor de refer�ncia tem em sua posi��o x (vetorExemplo[X]) o valor 1 guardado, significa que o vetor de dados correspondente , 
		na sua posi��o  x (exemplo[X]), j� tem os dados de campo preenchidos. Isso significa que j� existem dados naquele espa�o do vetor de dados, e a
		fun��o posicaoDisponivel, que recebe um ponteiro para um vetor de refer�ncia, percorre pelo vetor passado como par�metro e indica qual � a primeira
		posi��o, dentro do vetor de dados, que tem um n�mero zero. Como os vetores de refer�ncia e vetores de dados est�o relacionados, a mesma posi��o
		no vetor de dados ser� uma posi��o que n�o tem nenhum dado cadastrado. Logo em cima desse texto, na parte (1), est� declarado em Clientes
		um exemplo do que � um vetor de refer�ncia e um vetor de dado*/
//
	
//inserirString tem como objetivo pegar o input do usu�rio e colocar dentro da estrutura: (camposFuncion�rio, ou camposCliente, ou camposFornecedor) em uma posi��o que atualmente n�o esteja ocupada retornada pela fun��o [posicaoDisponivel]
void inserirString(int tipoCadastro, int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);

/*Atrav�s de um input de usu�rio, que ser� referido como "n�mero de cadastro", mas ser� usado na fun��o, como a posi��o dentro dos vetores, 
verifica atrav�s vetor de refer�ncia, se o valor em vetorExemplo[n�mero de cadastro//posicao] = 0, se for, exibe erro, sen�o, executa a fun��o 
de exibi��o espec�fica, escolhida anteriormente e armazenada em *pEscolhaUser. *pEscolha user � uma vari�vel que vem do arquivo menu.c durante
 a execu��o dos menus. Seus valores dentro da verifica��o de dados resultam em: 
 valor 1 = exibirRegistroCliente
 valor 2 = exibirRegistroFuncionario
 valor 3 = exibirRegistroFornecedor */
void verificarDadosVetorDisponivel(int *pEscolhaUser, int *vetor, int posicao, int *pErro);

int calcularDadosExistentes(int vetor[MAX_VETOR]);

void alterarCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);
#endif
