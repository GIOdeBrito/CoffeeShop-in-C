#include <stdio.h>
#include <string.h>
#include "loja.h"

void mostrar_cardapio (void)
{
	int pagina = 0, index = 0;

	printf("\t#####################\n");
	printf("\t#     CARDAPIO      #\n");
	printf("\t#####################\n");

	// Carrinho de compra do usuário
	item_checkout cart[64];

	for(int i = 0; i < 64; i++)
	{
		cart[i].id = 0;
		cart[i].quantity = 0;
	}

	while(true)
	{
		printf("\n\t[ %d ]\n\n",pagina + 1);
		printf("\t[1] Adicionar item ao carrinho\n");
		printf("\t[2] Progredir\n");
		printf("\t[3] Retroceder\n");
		printf("\t[4] Ver carrinho\n");
		printf("\t[0] Sair\n");

		char* str = ler_entrada();

		// Adicionar item ao carrinho
		if(comparar_charv(str,"1") == true)
		{
			printf("\tInsira o numero do item:\n\tSe tiver duvidas, veja o cardapio.");
			char* __item = ler_entrada();

			// Somente prossegue se for um número
			if(e_numero(__item) == true)
			{
				add_cart(cart, str_para_int(__item));
			}
		}
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
		// Ver carrinho
		if(comparar_charv(str,"4") == true)
		{
			list_cart(&cart);
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

void add_cart (item_checkout* cart, int id)
{
	if(id > itens_q-1)
	{
		return;
	}

	for(int i = 0; i < 64; i++)
	{
		//*(cart + i) = 66;
		//&cart[i].id = 66;

		//cart[i]->id = 66;

		printf("%d\n", *(cart+i).id);
	}
}

void list_cart (item_checkout cart[])
{
	for(int i = 0; i < length(cart); i++)
	{
		if(cart[i].quantity == 0)
		{
			continue;
		}

		printf("\t---------------------\n");
		printf("\t%s\n", itens[cart[i].id].nome);
		printf("\t%d unidades\n", cart[i].quantity);
		printf("\tTotal = R$%.2lf\n", itens[cart[i].id].valor * cart[i].quantity);
		printf("\t---------------------\n\n");
		esperar(0.32);
	}
}
