/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para CodificarBase16.

 * $Author: diego.silva $
 * $Date: 2022/02/16 22:59:04 $
 * $Log: aula0802.c,v $
 * Revision 1.1  2022/02/16 22:59:04  diego.silva
 * Initial revision
 *
 */

#include "aula0801.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define NUMERO_ARGUMENTOS 2

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO 4
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 5

int main(int argc, char *argv[])
{
   unsigned long long numeroBytes, indice;
   unsigned long argumento;
   char *validacao, *saida;
   byte *entrada;
   tipoErros codigoRetorno;

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <numero-bytes> <byte-1> <byte-2>...<byte-n-1> <byte-n>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   numeroBytes = strtoul(argv[1], &validacao, 10);

   if (errno == EINVAL)
   {
      printf("Base invalida.\n");
      exit(BASE_INVALIDA);
   }

   if (errno == ERANGE)
   {
      printf("Valor maximo permitido (%llu) do tipo unsigned long long foi excedido.\n", ULLONG_MAX);
      exit(VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("\nArgumento contem caractere invalido: (%c)\n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   entrada = malloc(numeroBytes * sizeof(byte));
   saida = malloc(numeroBytes * (2 * sizeof(char) + 1));

   if (argc != 2 + numeroBytes)
   {
      printf("Uso: %s <numero-bytes> <byte-1> <byte-2>...<byte-n-1> <byte-n>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 2; indice < (numeroBytes + 2); indice++)
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
         printf("\nArgumento n#%llu contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argumento > 255)
      {
         printf("Argumento excede o valor maximo de 255.\n");
         exit(ARGUMENTO_INVALIDO);
      }

      entrada[indice - 2] = (byte)argumento;
   }

   codigoRetorno = CodificarBase16(entrada, numeroBytes, saida);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
      printf("%s\n", saida);

   free(entrada);
   free(saida);

   return SUCESSO;
}

/* $RCSfile: aula0802.c,v $ */
