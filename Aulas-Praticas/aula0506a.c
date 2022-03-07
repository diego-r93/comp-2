/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para a funcao
 * ValidarRg

 * $Author: diego.silva $
 * $Date: 2022/01/17 07:26:37 $
 * $Log: aula0506a.c,v $
 * Revision 1.3  2022/01/17 07:26:37  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/17 07:24:18  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/17 07:18:08  diego.silva
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

#define NUMERO_ARGUMENTOS 10

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char rg[COMPRIMENTO_TOTAL];
   byte indice, indiceRg;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <d1> <d2> ... <d7> <d8> <d9>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indiceRg = 0, indice = 1; indice < NUMERO_ARGUMENTOS; indice++, indiceRg++)
   {
      if (strlen(argv[indice]) != 1)
      {
         printf("Uso: %s <d1> <d2> ... <d7> <d8> <d9>\n", argv[0]);
         printf("Insira digitos entre '0' e '9'\n");
         exit(ARGUMENTO_INVALIDO);
      }

      if (indiceRg == 2 || indiceRg == 6)
      {
         rg[indiceRg] = '.';
         indiceRg++;
      }
      else if (indiceRg == 10)
      {
         rg[indiceRg] = '-';
         indiceRg++;
      }

      rg[indiceRg] = argv[indice][0];
   }

   codigoRetorno = ValidarRg(rg);

   if (codigoRetorno == argumentoNulo)
   {
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
      printf("Argumento de entrada nulo.\n");
      printf("Uso: %s <d1> <d2> ... <d7> <d8> <d9>\n", argv[0]);
   }
   else if (codigoRetorno == digitoInvalido)
   {
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
      printf("Argumento possui digito invalido.\n");
      printf("Uso: %s <d1> <d2> ... <d7> <d8> <d9>\n", argv[0]);
   }
   else if (codigoRetorno == ok || codigoRetorno == rgInvalido)
   {
      printf("RG: %s - %s\n", rg, codigoRetorno == rgInvalido ? "invalido." : "valido.");
   }

   return SUCESSO;
}

/* $RCSfile: aula0506a.c,v $ */
