#include "global/global.h"
#include "menu/menu.h"
#include "cadastro/cadastro.h"
#include "interface/interface.h"
#include "arquivo/arquivo.h"

void main() {
	setlocale(LC_ALL, "Portuguese_Brazil");
	exibirMenuPrincipal();
	popularVetores();

	do{
	    system("color E0"); //Definição da cor do sistema
	    
	    HWND hWnd = GetConsoleWindow();
    	ShowWindow(hWnd, SW_MAXIMIZE);
    	
		exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);	
		
		exibirMensagem(); //Exibindo eventuais mensagens, por padrão erro = 0, portanto, sem mensagens
		
		exibirErro(); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes();
		
		receberOpcaoMenu(); //Solicita a escolha do usuário e faz o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
}
