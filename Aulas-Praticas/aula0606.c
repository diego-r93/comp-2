/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para a funcao CalcularComplementoAlgebrico

 * $Author: diego.silva $
 * $Date: 2022/01/26 08:02:24 $
 * $Log: aula0606.c,v $
 * Revision 1.1  2022/01/26 08:02:24  diego.silva
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

#define NUMERO_ARGUMENTOS 4

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
   uint16_t ordem, linhaElemento, colunaElemento;
   uint16_t linha, coluna, indice;
   double cofator;
   char *validacao;
   tipoErros codigoRetorno;

   double matrizEntrada[MAX_LINHAS][MAX_COLUNAS];

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <ordem da matriz> <linha do elemento> <coluna do elemento>\n", argv[0]);
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
         printf("O valor %lu excede a dimensao maxima de 100. Insira valores entre 0 e 100.\n", argumento);
         exit(DIMENSAO_MAXIMA_EXCEDIDA);
      }

      if (indice == 1)
         ordem = (uint16_t)argumento;
      else if (indice == 2)
         linhaElemento = (uint16_t)argumento;
      else if (indice == 3)
         colunaElemento = (uint16_t)argumento;
   }

   numeroDeArgumentos = NUMERO_ARGUMENTOS + (ordem * ordem);

   if (argc != numeroDeArgumentos)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <ordem da matriz> <linha do elemento> <coluna do elemento> a11 a12 ... a%u%u\n", argv[0], ordem, ordem);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (linha = 0, indice = NUMERO_ARGUMENTOS; linha < ordem; linha++)
      for (coluna = 0; coluna < ordem; coluna++)
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

   printf("\nMatriz recebida:\n\n");
   for (linha = 0; linha < ordem; linha++)
   {
      for (coluna = 0; coluna < ordem; coluna++)
         printf("%.5g\t", matrizEntrada[linha][coluna]);
      printf("\n\n");
   }

   codigoRetorno = CalcularComplementoAlgebrico(ordem, linhaElemento, colunaElemento, matrizEntrada, &cofator);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
      printf("\nCofator do elemento %.5g na linha %u e coluna %u: %.5g\n\n",
             matrizEntrada[linhaElemento - 1][colunaElemento - 1], linhaElemento,
             colunaElemento, cofator);

   return SUCESSO;
}

/* $RCSfile: aula0606.c,v $ */
