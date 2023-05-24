#ifndef INTERFACE_VAR_H
#define INTERFACE_VAR_H

#include "../../global/global.h"
#include "../interface.h"

//Displays de exibição
	//Displays de formulário
		extern Display displayRefFormularioCadastroCliente[13];
		
		extern Display displayRefFormularioCadastroFuncionario[15];
		
		extern Display displayRefFormularioCadastroFornecedor[13];
	//

	//Display de consulta
		extern Display displayRefTitulo[3];
		
		extern Display displayRefCabecalhoConsultaClientes[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaFuncionarios[MAX_CABECALHO];
		
		extern Display displayRefCabecalhoConsultaFornecedores[MAX_CABECALHO];
		
		extern Display displayRefConsulta_Cliente[2];
		
		extern Display displayRefConsulta_Funcionario[2];
		
		extern Display displayRefConsulta_Fornecedor[2];
		
		extern Display displayRefConsulta_SemDados[2];
	//
	
	//Display logotipo
		extern Display displayRefLogoTipo[];
	//
//

//Variáveis de controle
	extern int tamanhoDisplay;
	extern int contadorExistentes;
//

#endif
