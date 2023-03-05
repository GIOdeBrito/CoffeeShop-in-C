#include <stdio.h>
#include <string.h>
#include "loja.h"

void mostrar_cardapio (void)
{
	int pagina = 0;
	int index = 0;

	printf("\t#####################\n");
	printf("\t#     CARDAPIO      #\n");
	printf("\t#####################\n");

	while(true)
	{
		printf("\n\t[ %d ]\n\n",pagina+1);
		printf("\t[1] Adicionar item \`a sacola\n");
		printf("\t[2] Progredir\n");
		printf("\t[3] Retroceder\n");
		printf("\t[0] Sair\n");

		char* str = ler_entrada();

		if(comparar_charv(str,"2") == true && index < itens_q-1)
		{
			listar_itens(index);
			pagina++;
			index += 3;
		}
		if(comparar_charv(str,"3") == true && pagina > 0)
		{
			index -= 3;
			listar_itens(index);
			pagina--;
		}
		// Encerra a listagem
		if(comparar_charv(str,"0") == true)
		{
			break;
		}
	}
}

void listar_itens (int pg)
{
	int iteracao = 0;

	for(int i = pg; ; i++)
	{
		if(itens == NULL || iteracao >= 3 || i >= itens_q)
		{
			break;
		}
		if(i < 0)
		{
			i = 0;
		}

		printf("\t---------------------\n");
		printf("\tNumero #%d\n", itens[i].id+1);
		printf("\t%s\n", itens[i].nome);
		printf("\tR$%.2lf\n", itens[i].valor);
		printf("\t%s\n", itens[i].desc);
		printf("\t---------------------\n\n");
		esperar(0.32);

		iteracao++;
	}
}
