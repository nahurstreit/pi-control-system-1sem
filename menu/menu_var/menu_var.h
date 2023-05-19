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
				
				//Menu de modificações do cadastro
					extern Menu menuModificarCadastro;
				//
			//
	//
	
/** Para uso Posterior
	//menuOrdemProducao
		Menu menuOrdemProducao;
		
			//Nova Ordem de Produção
				Menu menuNovaOrdemProducao;	
			//
			
			//Consultar Ordem de Produção
				Menu menuConsultarOrdemProducao;
			//
	//
**/
//

//Criação de variáveis de escopo global para manipulação em funções
	extern int loopMenu; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.
//

#endif
