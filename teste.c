#include <stdio.h>
#include "loja.h"

void listar_todos_itens (void)
{
	for(int i = 0; i < itens_q; i++)
	{
		if(itens == NULL)
		{
			break;
		}

		//printf("---------------------\n");
		printf("ID=\t%d\n", itens[i].id);
		printf("NOME=\t%s\n", itens[i].nome);
		printf("VALOR=\t%lf\n", itens[i].valor);
		printf("DESC=\t%s\n", itens[i].desc);
		//printf("---------------------\n\n");
	}
}
