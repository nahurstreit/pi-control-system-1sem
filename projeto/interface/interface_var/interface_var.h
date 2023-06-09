#ifndef INTERFACE_VAR_H
#define INTERFACE_VAR_H

#include "../../global/global.h"
#include "../interface.h"

//Displays de exibi��o
	//Displays de formul�rio
		extern Display displayRefFormularioCadastroCliente[13];
		
		extern Display displayRefFormularioCadastroFuncionario[15];
		
		extern Display displayRefFormularioCadastroFornecedor[13];
		
		extern Display displayRefFormularioCadastroProduto[3];
		
		extern Display displayRefFormularioNovaOrdem[21];
		extern Display displayRefFormularioNovaOrdem_Item[2];
		extern Display displayRefFormularioNovaOrdem_Final[2];
		
		extern Display displayImpressaoNovaOrdem[25];
		extern Display displayImpressaoNovaOrdem_Item[2];
		extern Display displayImpressaoNovaOrdem_Final[2];
	//

	//Display de consulta
		extern Display displayRefTitulo[3];
		
		extern Display displayRefCabecalhoConsultaClientes[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaFuncionarios[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaFornecedores[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaProdutos[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaProducoes[MAX_CABECALHO];
		
		extern Display displayRefConsulta_Cliente[2];
		
		extern Display displayRefConsulta_Funcionario[2];
		
		extern Display displayRefConsulta_Fornecedor[2];
		
		extern Display displayRefConsulta_Produto[2];
		
		extern Display displayRefConsulta_SemDados[2];
		
		extern Display displayRefConsulta_Producoes[2];
	//
	
	//Display logotipo
		extern Display displayRefLogoTipo[];
	//
//

//Vari�veis de controle
	extern int tamanhoDisplay;
	extern int contadorExistentes;
//

#endif
