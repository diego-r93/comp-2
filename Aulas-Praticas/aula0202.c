/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para calcular o termo da
 * serie de Fibonacci

 * $Author: diego.silva $
 * $Date: 2021/12/10 03:47:24 $
 * $Log: aula0202.c,v $
 * Revision 1.2  2021/12/10 03:47:24  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2021/12/09 16:46:38  diego.silva
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

#include "aula0201.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 4
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO 5
#define VALOR_MAXIMO_EXCEDIDO 6

#define NUMERO_ARGUMENTOS 2

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char *validacao;
   unsigned long termoLongo;
   us indice, termo;
   ull resultado, resultadoAnterior;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso: %s <inteiro-nao-negativo>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   termoLongo = strtoul(argv[1], &validacao, 10);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (errno == ERANGE)
   {
      printf("Valor maximo permitido (%lu) do tipo unsigned long foi excedido.\n", ULONG_MAX);
      exit(VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
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

   if (termoLongo > USHRT_MAX)
   {
      printf("Valor fornecido (%lu) ultrapassa o valor maximo permitido para unsigned short (%hu)\n",
             termoLongo, (unsigned short)USHRT_MAX);
      exit(VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
   }

   termo = (unsigned short)termoLongo;

   resultado = CalcularTermoSerieFibonacci(termo);
   resultadoAnterior = CalcularTermoSerieFibonacci(termo - 1);

   for (indice = 0; indice <= termo; indice++)
   {
      resultado = CalcularTermoSerieFibonacci(indice);
      if (resultado > 0)
      {
         resultadoAnterior = CalcularTermoSerieFibonacci(indice - 1);

         if (resultado < resultadoAnterior)
         {
            printf("\nValor maximo do tipo unsigned long long foi excedido.\n\n");
            exit(VALOR_MAXIMO_EXCEDIDO);
         }
      }
      printf("\nF(%i) = %llu", indice, resultado);
   }

   printf("\n\n");

   return SUCESSO;
}

/* $RCSfile: aula0202.c,v $ */
