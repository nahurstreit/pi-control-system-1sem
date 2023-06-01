#include "../../global/global.h"
#include "../arquivo.h"

bool checarLinhaNula(char token[]) {
	if(strncmp(token, "!<>", 3) == 0) return true;
	else return false;
}
