#include <stdio.h>
#include <string.h>
#include "loja.h"

void ler_cardapio (char* cam)
{
	FILE* f = fopen(cam,"r");

	// Encerra a função se o arquivo for nulo
	if(f == NULL)
	{
		printf("Nao encontrado\n");
		return;
	}

	// Número de itens
	int i = 0;

	// Lê o arquivo caractere por caractere
	while(true)
	{
		char c = fgetc(f);

		if(c == EOF)
		{
			break;
		}

		// Declara que há um item e incrementa o número
		if(c == '{')
		{
			i++;
		}
	}

	/*
	Muda o tamanho do vetor de cardápio para q quantidade
	de itens encontrados no arquivo
	*/
	itens = alterar_vetor(itens, i);
	/*
	Armazena a quantidade de itens do cardápio. Como o vetor
	é dinâmico a largura dele não pode ser verificada convencionalmente
	*/
	itens_q = i;

	// Pula para início do arquivo
	rewind(f);

	char linha[256];
	// índice do item atual
	int item_index = 0;
	// tipo do dado que será armazenado
	int item_dado_tipo = 0;

	while(fgets(linha,256,f) != NULL)
	{
		// Remove a quebra de linha do final
		linha[strlen(linha)-1] = '\0';

		/*
		Ignora comentário e abertura de item
		String vazia, pula a iteração
		*/
		if(tem_char(linha,'#') || comparar_charv(linha,"") == true)
		{
			continue;
		}
		// Ignora fechamento de item
		if(tem_char(linha,'}'))
		{
			item_index++;
			item_dado_tipo = 0;
			continue;
		}

		switch(item_dado_tipo)
		{
			// Nome
			case 0: {
				// Remove o '{' do fim da linha
				linha[strlen(linha)-1] = 0;
				itens[item_index].id = item_index;
				strcpy(itens[item_index].nome, linha);
			}
			break;
			// Preço
			case 1: {
				itens[item_index].valor = str_para_double(linha);
			}
			break;
			// Descrição do item
			case 2: {
				strcpy(itens[item_index].desc, linha);
			}
			break;
		}

		item_dado_tipo++;
	}

	fclose(f);
}
