#include "global/global.h"
#include "menu/menu.h"
#include "cadastro/cadastro.h"
#include "interface/interface.h"
#include "arquivo/arquivo.h"

void main() {
	setlocale(LC_ALL, "Portuguese");
	menuAtual = menuPrincipal;
	
	popularVetores();

	do{
	    system("color E0"); //Definição da cor do sistema
	    
	    // Comente esse código para tirar a trava de tela
//		    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//			SMALL_RECT rect = {0, 0, 101, 42}; // Define o tamanho da janela
//			SetConsoleWindowInfo(hConsole, TRUE, &rect); // Define o tamanho da janela
//			SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    	//Comente esse código para tirar a trava de tela
    	
		exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);	
		
		exibirMensagem(); //Exibindo eventuais mensagens, por padrão erro = 0, portanto, sem mensagens
		
		exibirErro(); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes();
		
		receberOpcaoMenu(); //Solicita a escolha do usuário e faz o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
}
