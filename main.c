#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

item* itens = NULL;
int itens_q = 0;

int main (void)
{
	ler_cardapio("dir6/cardapio.txt");
	introducao();

	// Libera a memória alocada pelo "itens"
	free(itens);

    return 0;
}
