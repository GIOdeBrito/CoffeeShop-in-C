#include <stdio.h>
#include <string.h>
#include "loja.h"

void introducao (void)
{
	bool continuar = true;

	imprimir_saudacao();

	while(continuar == true)
	{
		printf("\t\[1\] Ver cardapio\n");
		printf("\t\[0\] Sair\n");

		char* str = ler_entrada();

		validar_escolha(str);

		// Encerra o programa
		if(comparar_charv(str,"0") == true)
		{
			break;
		}
	}
}

void imprimir_saudacao (void)
{
	printf("\n\t# # # # # # # # # # # # # # # # #\n");
	esperar(0.3);
	printf("\tBem-vindo\(a\) ao Cafe Urks!\n");
	esperar(0.3);
	printf("\t# # # # # # # # # # # # # # # # #\n");
	esperar(0.3);
	printf("\tV%.2lf\n\n",G_VERSAO);
}

void validar_escolha (char* opcao)
{
	if(comparar_charv(opcao,"1") == true)
	{
		mostrar_cardapio();
	}
}
