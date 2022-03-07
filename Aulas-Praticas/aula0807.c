/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para DecodificarBase64.

 * $Author: diego.silva $
 * $Date: 2022/03/07 03:53:16 $
 * $Log: aula0807.c,v $
 * Revision 1.3  2022/03/07 03:53:16  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/23 03:16:54  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/19 00:45:53  diego.silva
 * Initial revision
 *
 */

#include "aula0801.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define NUMERO_ARGUMENTOS 3

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
   unsigned long long numeroBytesConvertido;
   unsigned long argumento;
   char *validacao;
   char *entrada;
   byte *saida;
   tipoFinalLinha finalLinha;
   tipoErros codigoRetorno;

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <final Linha (0 - Desabilitado) (1 - Habilitado)> <string>\n", argv[0]);
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

   numeroBytes = strlen(argv[2]);

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

   for (indice = 0; argv[2][indice] != END_OF_STRING; indice++)
   {
      entrada[indice] = argv[2][indice];

      if (argv[1][indice] == '\n')
         entrada[indice] = END_OF_STRING;
   }

   codigoRetorno = DecodificarBase64(entrada, finalLinha, saida, &numeroBytesConvertido);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
   {
      for (indice = 0; indice < numeroBytesConvertido; indice++)
         printf("%02X ", saida[indice]);
      printf("\n");
   }

   free(entrada);
   free(saida);

   return SUCESSO;
}

/* $RCSfile: aula0807.c,v $ */
