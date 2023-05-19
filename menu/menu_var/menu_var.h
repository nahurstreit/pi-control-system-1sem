#ifndef MENU_VAR_H
#define MENU_VAR_H

#include "../../global/global.h"
#include "../menu.h"

//menuPrincipal
		extern Menu menuPrincipal;
	
	//menuCadastros 
		extern Menu menuCadastro;
		
			//Criar novo Cadastro
				extern Menu menuNovoCadastro;
			//
			
			//Consultar Cadastros
				extern Menu menuConsultarCadastro;
				
				//Menu de modifica��es do cadastro
					extern Menu menuModificarCadastro;
				//
			//
	//
	
/** Para uso Posterior
	//menuOrdemProducao
		Menu menuOrdemProducao;
		
			//Nova Ordem de Produ��o
				Menu menuNovaOrdemProducao;	
			//
			
			//Consultar Ordem de Produ��o
				Menu menuConsultarOrdemProducao;
			//
	//
**/
//

//Cria��o de vari�veis de escopo global para manipula��o em fun��es
	extern int loopMenu; //Vari�vel respons�vel por controlar o loop do 'do while' dentro da fun��o main, sendo o �nico jeito de encerrar o menu, caso seja digitado a op��o 0 dentro do menu principal.
//

#endif
