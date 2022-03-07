/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Descricao: Programa de testes para a funcao ValidarRg
 * recebendo uma string como argumento.

 * $Author: diego.silva $
 * $Date: 2022/01/17 07:36:39 $
 * $Log: aula0506b.c,v $
 * Revision 1.1  2022/01/17 07:36:39  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0504.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define COMPRIMENTO_ARGUMENTO_INVALIDO 2

#define NUMERO_ARGUMENTOS 2
#define TAMANHO_MAX_ARGUMENTO 12

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char rg[COMPRIMENTO_TOTAL];
   byte indice;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8-d9>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   if (strlen(argv[1]) != TAMANHO_MAX_ARGUMENTO)
   {
      printf("Argumento apresenta comprimento invalido\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8-d9>\n", argv[0]);
      exit(COMPRIMENTO_ARGUMENTO_INVALIDO);
   }

   for (indice = 0; indice < TAMANHO_MAX_ARGUMENTO; indice++)
      rg[indice] = argv[1][indice];

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

/* $RCSfile: aula0506b.c,v $ */
