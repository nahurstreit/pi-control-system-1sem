#ifndef CADASTRO_H
#define CADASTRO_H

#define MAX_STRING 50

//Funções cadastro:
int novoCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);
int consultaCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);

//Criação do struct(tipo) Cliente, para armazenar os dados dos clientes.
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

//Criação do struct(tipo) Funcionario, para armazenar os dados dos funcionarios.
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

//Criação do struct(tipo) Fornecedor, para armazenar os dados dos fornecedores.
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

//Criação do struct(tipo) TextoCampo, para armazenar os textos que serão exibidos ao pedir para o usuário digitar alguma coisa no cadastro
typedef struct {
	char displayCampo[30];
} TextoCampo;

//Declaração das funções a serem utilizadas pelo código
	
//Explicação detalhada de posicaoDisponivel:
		int posicaoDisponivel(int *vetor);
		/* posicaoDisponivel é a função responsável por percorrer os, aqui chamados, vetores de referência(vetorRefClientes, vetorRefFuncionarios, vetorFornecedores)
		os quais armazenam em si apenas 0 ou 1 e correlacionar com a mesma posição nos, aqui chamados, vetores de dados(funcionarios, clientes, fornecedores). 
		Quando um vetor de referência tem em sua posição x (vetorExemplo[X]) o valor 1 guardado, significa que o vetor de dados correspondente , 
		na sua posição  x (exemplo[X]), já tem os dados de campo preenchidos. Isso significa que já existem dados naquele espaço do vetor de dados, e a
		função posicaoDisponivel, que recebe um ponteiro para um vetor de referência, percorre pelo vetor passado como parâmetro e indica qual é a primeira
		posição, dentro do vetor de dados, que tem um número zero. Como os vetores de referência e vetores de dados estão relacionados, a mesma posição
		no vetor de dados será uma posição que não tem nenhum dado cadastrado. Logo em cima desse texto, na parte (1), está declarado em Clientes
		um exemplo do que é um vetor de referência e um vetor de dado*/
//
	
//inserirString tem como objetivo pegar o input do usuário e colocar dentro da estrutura: (camposFuncionário, ou camposCliente, ou camposFornecedor) em uma posição que atualmente não esteja ocupada retornada pela função [posicaoDisponivel]
void inserirString(int tipoCadastro, int posicaoDisponivel, char string[MAX_STRING], int *contadorCampo);

/*Através de um input de usuário, que será referido como "número de cadastro", mas será usado na função, como a posição dentro dos vetores, 
verifica através vetor de referência, se o valor em vetorExemplo[número de cadastro//posicao] = 0, se for, exibe erro, senão, executa a função 
de exibição específica, escolhida anteriormente e armazenada em *pEscolhaUser. *pEscolha user é uma variável que vem do arquivo menu.c durante
 a execução dos menus. Seus valores dentro da verificação de dados resultam em: 
 valor 1 = exibirRegistroCliente
 valor 2 = exibirRegistroFuncionario
 valor 3 = exibirRegistroFornecedor */
void verificarDadosVetorDisponivel(int *pEscolhaUser, int *vetor, int posicao, int *pErro);

int calcularDadosExistentes(int vetor[MAX_VETOR]);

void alterarCadastro(int *pEscolhaUser, int *pMensagem, int *pErro);
#endif
