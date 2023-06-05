#include "../../global/global.h"
#include "../../interface/interface.h"
#include "../../producao/producao.h"
#include "../menu.h"


//Funções a serem executadas pelas opções dos Menus
	//Funções de chamada do Menu
		void exibirMenuPrincipal() {
			menuAtual = menuPrincipal;
		}
		
			//Funções menuCadastro
				void exibirMenuCadastro() {
					menuAtual = menuCadastro;
				}
				
					void exibirMenuNovoCadastro() {
						menuAtual = menuNovoCadastro;
					}
						void executarNovoCadastro() {
							novoCadastro(false, true);
						}
						
						void executarNovoProduto() {
							novoCadastro(false, true);
						}
					
					void exibirMenuConsultarCadastro() {
						menuAtual = menuConsultarCadastro;
					}
						void executarConsultaCadastro() {
							int estado = 0;
							int *pEstado = &estado;
							consultaCadastro(pEstado);
							if(estado == 1) {
								do{
									menuAtual = menuModificarCadastro;
									exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
									exibirMensagem();
									exibirErro();
									exibirInterfaceFormularios(posicaoConsultaAtual);
									exibirInterfaceOpcoes();
									receberOpcaoMenu();
									if(verificarExclusaoCadastro()) {
										mensagem = Mensagem_Cadastro_Excluido;
										break;
									}
								} while(escolhaUser != 0 && escolhaUser != 9);
								switch(escolhaUser) {
									case 0:
										exibirMenuConsultarCadastro();
										executarConsultaCadastro();
										break;
									case 9:
										exibirMenuCadastro();
										break;
								}
							}
						}
							void executarAlterarCadastro() {
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								alterarCadastro();
							}
							
							void executarAlterarCadastroInteiro() {
								exibirInterfaceTitulo("ATENÇÃO!", 1);
								char stringAlerta[] = "Você tem certeza que deseja ALTERAR TODO o cadastro? Essa decisão é IRREVERSÍVEL!";
								char stringOpcoes[] = "[1] Sim, tenho certeza!\t\t\t[2] Não, deixe-me pensar...";
								
								if(exibirInterfaceAlerta(stringAlerta, stringOpcoes, "1", false, true, 1)) {
									excluirCadastro(posicaoConsultaAtual);
									novoCadastro(true, false);
									if(!verificarExclusaoCadastro()) {
										mensagem = Mensagem_Cadastro_Modificado;
									} else if(mensagem > 0) {
										escolhaUser = 0;
									}
								}
							}
						
			//
			

			//Funções menuOrdemProducao
				void exibirMenuOrdemProducao() {
					menuAtual = menuOrdemProducao;
				}
					void exibirMenuNovaOrdemProducao() {
						escolhaUser = 5;
						novaOrdem(false);
						if(mensagem == Mensagem_Producao_Nova){ 
							do{
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								exibirMensagem();
								exibirErro();
								exibirInterfaceNovaProducao(producaoAtiva);
								exibirInterfaceOpcoes();
								receberOpcaoMenu();
							} while(escolhaUser != 0);
						}
					}
						void executarImpressaoOP() {
							imprimirOrdemProducao();
							printf("Impressão em andamento.");
							system("pause");
							mensagem = Mensagem_Impressao_Concluida;
							remove("tempImpress.txt");
						}
					
					void exibirMenuConsultarOrdemProducao() {
						menuAtual = menuConsultarOrdemProducao;
						executarConsultaOrdemProducao();
					}
					
					void executarConsultaOrdemProducao() {
						int estado = 0;
						int *pEstado = &estado;
						consultaProducoes(pEstado);
						if(estado == 1) {
							do{
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								exibirMensagem();
								exibirErro();
								exibirInterfaceNovaProducao(producaoAtiva);
								menuAtual = menuConsultarOrdemProducao;
								exibirInterfaceOpcoes();
								receberOpcaoMenu();
								if(producaoAtiva == -1) {
									executarConsultaOrdemProducao();
									exibirMenuOrdemProducao();
									break;
								}
							} while(escolhaUser != 0 && escolhaUser != 9);
							remove("tempImpress.txt");
						} else if(estado == 0) {
							exibirMenuOrdemProducao();
						}
					}
						
						void executarAlterarOP() {
							alterarProducao();
						}
						
						void executarAdicionarNovosItensOP() {
							novaOrdem(true);
						}
						
						void executarExcluirItemOP() {
							excluirItemProducao();
						}
						
						void executarExclusaoOP() {
							exibirInterfaceTitulo("ATENÇÃO!", 1);
							char stringAlerta[] = "Você tem certeza que deseja EXCLUIR a Ordem de Produção? Essa decisão é IRREVERSÍVEL!";
							char stringOpcoes[] = "[1] Sim, tenho certeza!\t\t\t[2] Não, deixe-me pensar...";
							if(exibirInterfaceAlerta(stringAlerta, stringOpcoes, "1", false, true, 1)) {
								excluirArquivoItens(atoi(producoes[producaoAtiva].numCadCliente), producaoAtiva);
								excluirProducao(producaoAtiva);
								mensagem = Mensagem_Producao_Excluida;
								escolhaUser = 0;
								executarConsultaOrdemProducao();
							}
						}
			//
	//
	
	//Função de fim do Menu
		void fimDoMenu() {
			loopMenu = 0;
		}
	//
