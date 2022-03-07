/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para calcular o GerarDigitosVerificadoresRg

 * $Author: diego.silva $
 * $Date: 2022/01/13 00:48:57 $
 * $Log: aula0502a.c,v $
 * Revision 1.2  2022/01/13 00:48:57  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/12 23:58:32  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "aula0501.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3

#define NUMERO_ARGUMENTOS 9

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char *validacao;
   byte rg[NUMERO_DIGITOS];
   byte indice;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <d1> <d2> ... <d7> <d8>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 1; indice < NUMERO_ARGUMENTOS; indice++)
   {
      if (strlen(argv[indice]) != 1)
      {
         printf("Uso: %s <d1> <d2> ... <d7> <d8>\n", argv[0]);
         printf("Insira digitos entre '0' e '9'\n");
         exit(ARGUMENTO_INVALIDO);
      }

      rg[indice - 1] = (byte)strtoul(argv[indice], &validacao, 10);

      if (errno == EINVAL)
      {
         printf("Base invalida.\n");
         exit(BASE_INVALIDA);
      }

      if (*validacao != END_OF_STRING)
      {
         printf("Caractere invalido %c\n", *validacao);
         exit(ARGUMENTO_INVALIDO);
      }
   }

   codigoRetorno = GerarDigitosVerificadoresRg(rg);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
      for (indice = 0; indice < NUMERO_DIGITOS; indice++)
      {
         switch (indice)
         {
         case 0:
            printf("RG: ");
            printf("%hhu", rg[indice]);
            break;
         case 2:
         case 5:
            printf(".");
            printf("%hhu", rg[indice]);
            break;
         case NUMERO_DIGITOS - 1:
            printf("-");
            if (rg[indice] == 'X')
            {
               printf("%c", rg[indice]);
               printf("\n");
            }
            else
            {
               printf("%hhu", rg[indice]);
               printf("\n");
            }
            break;
         default:
            printf("%hhu", rg[indice]);
            break;
         }
      }

   return SUCESSO;
}

/* $RCSfile: aula0502a.c,v $ */
