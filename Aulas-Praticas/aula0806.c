/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para CodificarBase64.

 * $Author: diego.silva $
 * $Date: 2022/02/18 23:33:42 $
 * $Log: aula0806.c,v $
 * Revision 1.1  2022/02/18 23:33:42  diego.silva
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
#define FINAL_LINHA_INVALIDO 4
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO 5
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 6
#define ERRO_ALOCANDO_MEMORIA 7

int main(int argc, char **argv)
{
   unsigned long long numeroBytes, indice;
   unsigned long argumento;
   char *validacao, *saida;
   byte *entrada;
   tipoFinalLinha finalLinha;
   tipoErros codigoRetorno;

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <final Linha (0 - Desabilitado) (1 - Habilitado)> <numero-bytes> <byte-1> <byte-2>...<byte-n-1> <byte-n>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   argumento = strtoul(argv[1], &validacao, 10);

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
      printf("\nArgumento contem caractere invalido: (%c)\n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   if (argumento > 1)
   {
      printf("O tipo Final Linha deve ser 0 ou 1.\n");
      exit(FINAL_LINHA_INVALIDO);
   }

   finalLinha = (unsigned)argumento;

   numeroBytes = strtoul(argv[2], &validacao, 10);

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

   if (!(entrada = malloc(numeroBytes * sizeof(byte))))
   {
      printf("Erro alocando memoria\n");
      exit(ERRO_ALOCANDO_MEMORIA);
   }

   if (!(saida = malloc(numeroBytes / 3 * (4 * sizeof(char)) + ((numeroBytes % 3) * 4) + 1)))
   {
      printf("Erro alocando memoria\n");
      exit(ERRO_ALOCANDO_MEMORIA);
   }

   if (argc != 3 + numeroBytes)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <final Linha (0 - Desabilitado) (1 - Habilitado)> <numero-bytes> <byte-1> <byte-2>...<byte-n-1> <byte-n>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 3; indice < (numeroBytes + 3); indice++)
   {
      argumento = strtoul(argv[indice], &validacao, 16);

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

      entrada[indice - 3] = (byte)argumento;
   }

   codigoRetorno = CodificarBase64(entrada, numeroBytes, finalLinha, saida);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
      printf("%s\n", saida);

   free(entrada);
   free(saida);

   return SUCESSO;
}

/* $RCSfile: aula0806.c,v $ */
