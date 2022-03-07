/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para calcular o MDC

 * $Author: diego.silva $
 * $Date: 2021/12/17 15:31:23 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2021/12/17 15:31:23  diego.silva
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined(__FreeBSD__) && defined(__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#include "aula0301.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO 4

#define NUMERO_ARGUMENTOS 3

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   ull numeroX, numeroY;

   char *validacao;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso: %s <inteiro-nao-negativo> <inteiro-nao-negativo>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   numeroX = strtoull(argv[1], &validacao, 10);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (errno == ERANGE)
   {
      printf("Valor maximo permitido (%llu) do tipo unsigned long foi excedido.\n", ULLONG_MAX);
      exit(VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
   }

   if (argv[1][0] == '-')
   {
      printf("Uso: %s <inteiro-nao-negativo>\n", argv[0]);
      exit(ARGUMENTO_INVALIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   numeroY = strtoull(argv[2], &validacao, 10);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (errno == ERANGE)
   {
      printf("Valor maximo permitido (%llu) do tipo unsigned long foi excedido.\n", ULLONG_MAX);
      exit(VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
   }

   if (argv[2][0] == '-')
   {
      printf("Uso: %s <inteiro-nao-negativo>\n", argv[0]);
      exit(ARGUMENTO_INVALIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   if (CalcularMaximoDivisorComum(numeroX, numeroY) == 0)
      printf("\nMDC (%llu, %llu) = 0 (INDEFINIDO)\n", numeroX, numeroY);
   else
      printf("\nMDC (%llu, %llu) = %llu\n", numeroX, numeroY, CalcularMaximoDivisorComum(numeroX, numeroY));

   printf("\n");

   return SUCESSO;
}

/* $RCSfile: aula0302.c,v $ */
