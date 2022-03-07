/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para manipulacao de matrizes

 * $Author: diego.silva $
 * $Date: 2022/01/24 15:10:29 $
 * $Log: aula0603.c,v $
 * Revision 1.1  2022/01/24 15:10:29  diego.silva
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#include "aula0601.h"

#define NUMERO_ARGUMENTOS 3

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO 4
#define DIMENSAO_MAXIMA_EXCEDIDA 5

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   uint64_t argumento, numeroDeArgumentos;
   uint16_t linhas, colunas;
   uint16_t linha, coluna, indice;
   char *validacao;

   double matrizEntrada[MAX_LINHAS][MAX_COLUNAS];
   double matrizResultado[MAX_LINHAS][MAX_COLUNAS];

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <numero de linhas da matriz> <numero de colunas da matriz>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 1; indice < NUMERO_ARGUMENTOS; indice++)
   {
      argumento = strtoul(argv[indice], &validacao, 10);

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

      if (*validacao != END_OF_STRING)
      {
         printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argumento > MAX_LINHAS || argumento > MAX_COLUNAS)
      {
         printf("Dimensao %lu da matriz excede o valor maximo de 100. Insira dimencoes entre 0 e 100.\n", argumento);
         exit(DIMENSAO_MAXIMA_EXCEDIDA);
      }

      if (indice == 1)
         linhas = (uint16_t)argumento;
      else if (indice == 2)
         colunas = (uint16_t)argumento;
   }

   numeroDeArgumentos = NUMERO_ARGUMENTOS + (linhas * colunas);

   if (argc != numeroDeArgumentos)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <numero de linhas da matriz> <numero de colunas da matriz> ", argv[0]);
      printf("a11 a12 ... a%u%u\n",
             linhas, colunas);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (linha = 0, indice = NUMERO_ARGUMENTOS; linha < linhas; linha++)
      for (coluna = 0; coluna < colunas; coluna++)
      {
         matrizEntrada[linha][coluna] = strtod(argv[indice], &validacao);
         indice++;
         if (*validacao != END_OF_STRING)
         {
            printf("Caractere Invalido. Primeira ocorrencia: %c\n", *validacao);
            exit(ARGUMENTO_INVALIDO);
         }

         if (errno == ERANGE)
         {
            printf("Valor maximo permitido (%g) do tipo double foi excedido.\n", __DBL_MAX__);
            exit(VALOR_MAXIMO_DOUBLE_EXCEDIDO);
         }
      }

   ObterMatrizTransposta(linhas, colunas, matrizEntrada, matrizResultado);

   printf("\nMatriz Transposta:\n\n");
   for (linha = 0; linha < colunas; linha++)
   {
      for (coluna = 0; coluna < linhas; coluna++)
         printf("%.5g\t", matrizResultado[linha][coluna]);
      printf("\n\n");
   }

   return SUCESSO;
}

/* $RCSfile: aula0603.c,v $ */
