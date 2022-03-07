/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para calcular o Exponencial

 * $Author: diego.silva $
 * $Date: 2022/01/08 19:15:07 $
 * $Log: aula0402.c,v $
 * Revision 1.3  2022/01/08 19:15:07  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/05 09:34:48  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/05 09:00:39  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "aula0401.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO 4
#define VALOR_MAXIMO_INT_EXCEDIDO 5

#define NUMERO_ARGUMENTOS 3

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char *validacao;
   double base;
   long expoenteEntrada;
   int expoente;
   long double resultado;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso %s <base: numero real> <expoente: numero inteiro>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   base = strtod(argv[1], &validacao);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (errno == ERANGE)
   {
      printf("Valor maximo permitido (%g) do tipo double foi excedido.\n", __DBL_MAX__);
      exit(VALOR_MAXIMO_DOUBLE_EXCEDIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   expoenteEntrada = strtol(argv[2], &validacao, 10);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (expoenteEntrada > __INT_MAX__)
   {
      printf("Valor maximo permitido (%i) do tipo int foi excedido.\n", __INT_MAX__);
      exit(VALOR_MAXIMO_INT_EXCEDIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   expoente = (int)expoenteEntrada;

   resultado = CalcularExponencial(base, expoente);

   printf("\n (Base, Expoente) (%g, %i) = %Lg\n\n", base, expoente, resultado);

   return SUCESSO;
}

/* $RCSfile: aula0402.c,v $ */
