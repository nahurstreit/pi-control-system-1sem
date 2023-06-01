#include "validar_checardata.h"

bool checarAno1(int dataInt[], int anoMaximo[], int anoMinimo[]) {
	if(dataInt[4] == anoMaximo[0]) {
		if(dataInt[5] == anoMaximo[1]) {
			if(dataInt[6] >= anoMaximo[2]) {
				if(dataInt[7] >= anoMaximo[3]) {
					return true;
				}
			}
		}
	} else if(dataInt[4] == anoMinimo[0]) {
		if(dataInt[5] == anoMinimo[1]) {
			if(dataInt[6] <= anoMinimo[2]) {
				if(dataInt[7] <= anoMinimo[3]) {
					return true;
				}
			}
		}
	}
	
	return false;
}

bool checarMes1(int dataInt[]) {
	if(dataInt[2] == 1) {
		if(dataInt[3] <= 2) {
			return true;
		}
	} else if(dataInt[2] == 0) {
		return true;
	}
	
	return false;
}

bool checarDia1(int dataInt[]) {
	if((dataInt[2] == 0 && dataInt[3] == 1) || dataInt[3] == 3 || dataInt[3] == 5 || dataInt[3] == 7 || dataInt[3] == 8 || (dataInt[2] == 1 &&(dataInt[3] == 0 || dataInt[3] == 2) )) {
		if(dataInt[0] <= 3) {
			if(dataInt[0] == 3) {
				if(dataInt[1] <= 1) {
					return true;
				}
			} else {
				return true;
			}
		}
	} else {
		if(dataInt[2] == 0 && dataInt[3] == 2) {
			if(dataInt[0] <= 2) {
				if(dataInt[1] <= 8) {
					return true;
				}
			}
		} else if(dataInt[0] <= 3) {
			if(dataInt[0] == 3) {
				if(dataInt[1] == 0) {
					return true;
				}
			} else {
				return true;
			}
		}
	}
	
	return false;
}
