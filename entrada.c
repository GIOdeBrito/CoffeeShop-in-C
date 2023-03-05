#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "loja.h"

char* ler_entrada (void)
{
	printf("\n\t>> ");

	const int l = 256;
	char linha[l];

	fgets(linha, l, stdin);
	// Remove o '\n' do fgets
	linha[strlen(linha)-1] = '\0';

	char* l_final = linha;

	return l_final;
}
