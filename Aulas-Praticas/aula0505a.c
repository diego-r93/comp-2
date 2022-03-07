/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao:

 * $Author: diego.silva $
 * $Date: 2022/01/17 04:37:59 $
 * $Log: aula0505a.c,v $
 * Revision 1.1  2022/01/17 04:37:59  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "aula0504.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO 3

#define NUMERO_ARGUMENTOS 9

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char rg[NUMERO_DIGITOS];
   char digitoVerificador;
   byte indice, indiceRg;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <d1> <d2> ... <d7> <d8>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indiceRg = 0, indice = 1; indice < NUMERO_ARGUMENTOS; indice++, indiceRg++)
   {
      if (strlen(argv[indice]) != 1)
      {
         printf("Uso: %s <d1> <d2> ... <d7> <d8>\n", argv[0]);
         printf("Insira digitos entre '0' e '9'\n");
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] < '0' || argv[indice][0] > '9')
      {
         printf("Argumento contem caractere invalido. Primeira ocorrencia: %c\n", argv[indice][0]);
         exit(ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
      }

      if (indiceRg == 2 || indiceRg == 6)
      {
         rg[indiceRg] = '.';
         indiceRg++;
      }

      rg[indiceRg] = argv[indice][0];
   }

   codigoRetorno = GerarDigitosVerificadoresRg(rg, &digitoVerificador);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
   {
      printf("RG: ");
      for (indice = 0; indice <= NUMERO_DIGITOS; indice++)
         printf("%c", rg[indice]);
      printf("-%c ", digitoVerificador);
      printf("\n");
   }

   return SUCESSO;
}

/* $RCSfile: aula0505a.c,v $ */
