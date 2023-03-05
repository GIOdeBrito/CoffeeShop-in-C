#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

double str_para_double (char* str)
{
	/*
	Converte uma string para tipo double
	*/

	if(e_numero(str) == false)
	{
		return 0.0;
	}

	char* str_ptr;
	double d = strtod(str, &str_ptr);

	return d;
}

bool e_numero (char* str)
{
	/*
	Verifica se a string é na verdade um número
	*/

	const char alfa[] = "abcdefghijklmnopqrstuvxyzABCDEFGHIJKLMNOPQRSTUVXYZ";

	for(int i = 0; i < strlen(alfa); i++)
	{
		if(tem_char(str,alfa[i]))
		{
			return false;
			break;
		}
	}

	return true;
}

bool comparar_charv (char* str1, char* str2)
{
	/*
	Compara se dois vetores de caracteres são iguais
	*/

	if(strcmp(str1,str2) == 0)
	{
		return true;
	}

	return false;
}

void realocar_objeto (void* obj_dest, void* obj_font)
{
	/*
	Copia o valor de qualquer objeto com outro objeto
	*/

	memcpy(obj_dest, obj_font, sizeof *obj_font);
}

void* alterar_vetor (void* vetor, int tamanho)
{
	/*
	Altera o tamanho de um vetor para o valor desejado
	*/

	size_t n = (tamanho + 1) * sizeof *vetor;
	void* n_vetor = realloc(vetor, n);

	if(n_vetor == NULL && tamanho != 0)
	{
		printf("Falha em alocar novo objeto-vetor\n");
		// Se o realloc falhar é necessário limpar o objeto da memória
		free(n_vetor);
		return NULL;
	}

	return n_vetor;
}
