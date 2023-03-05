#include <time.h>
#include "loja.h"

void esperar (double seg)
{
	// Inicia a contagem do relógio
	clock_t inicio = clock();
	while(clock() < inicio+SEGUNDOS(seg));
}
