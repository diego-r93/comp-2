/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipo da funcao
 * GerarDigitosVerificadoresRg recebendo uma string como argumento

 * $Author: diego.silva $
 * $Date: 2022/01/13 00:56:12 $
 * $Log: aula0502b.c,v $
 * Revision 1.1  2022/01/13 00:56:12  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0501.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define COMPRIMENTO_ARGUMENTO_INVALIDO 2
#define ARGUMENTO_INVALIDO 3
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO 4

#define NUMERO_ARGUMENTOS 2
#define TAMANHO_MAX_ARGUMENTO 10

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   byte rg[NUMERO_DIGITOS];
   byte indice, indiceEntrada;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   if (strlen(argv[1]) != TAMANHO_MAX_ARGUMENTO)
   {
      printf("Argumento apresenta comprimento invalido\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
      exit(COMPRIMENTO_ARGUMENTO_INVALIDO);
   }

   if (argv[1][2] != '.' || argv[1][6] != '.')
   {
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
      exit(ARGUMENTO_INVALIDO);
   }

   for (indice = 0, indiceEntrada = 0; indiceEntrada < TAMANHO_MAX_ARGUMENTO; indiceEntrada++)
   {
      if (indiceEntrada == 2 || indiceEntrada == 6)
         continue;

      if (argv[1][indiceEntrada] < '0' || argv[1][indiceEntrada] > '9')
      {
         printf("Argumento contem caractere invalido. Primeira ocorrencia: %c\n", argv[1][indiceEntrada]);
         exit(ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
      }

      rg[indice] = (byte)argv[1][indiceEntrada] - '0';
      indice++;
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

/* $RCSfile: aula0502b.c,v $ */
