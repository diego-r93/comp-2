/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para DecodificarBase16.

 * $Author: diego.silva $
 * $Date: 2022/03/07 03:53:16 $
 * $Log: aula0803.c,v $
 * Revision 1.2  2022/03/07 03:53:16  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/17 19:37:17  diego.silva
 * Initial revision
 *
 */

#include "aula0801.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_ARGUMENTOS 2

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2

int main(int argc, char *argv[])
{
   unsigned long long numeroBytes, indice;
   unsigned long long numeroBytesConvertido;
   char *entrada;
   byte *saida;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <string>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   numeroBytes = strlen(argv[1]);

   entrada = malloc(numeroBytes * sizeof(char));
   saida = malloc((numeroBytes / 2) * sizeof(byte));

   for (indice = 0; argv[1][indice] != END_OF_STRING; indice++)
   {
      entrada[indice] = argv[1][indice];

      if (argv[1][indice] == '\n')
      {
         entrada[indice] = END_OF_STRING;
      }
   }

   codigoRetorno = DecodificarBase16(entrada, saida, &numeroBytesConvertido);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
   {
      for (indice = 0; indice < numeroBytesConvertido; indice++)
         printf("%hhu ", saida[indice]);
      printf("\n");
   }

   free(entrada);
   free(saida);

   return SUCESSO;
}

/* $RCSfile: aula0803.c,v $ */
