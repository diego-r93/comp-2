/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Descricao: Programa de testes para a funcao
 * GerarDigitosVerificadoresRg recebendo uma string como argumento.

 * $Author: diego.silva $
 * $Date: 2022/01/17 05:25:07 $
 * $Log: aula0505b.c,v $
 * Revision 1.2  2022/01/17 05:25:07  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/17 05:22:55  diego.silva
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
#define TAMANHO_MAX_ARGUMENTO 10

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char rg[NUMERO_DIGITOS];
   char digitoVerificador;
   byte indice;
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

   for (indice = 0; indice < TAMANHO_MAX_ARGUMENTO; indice++)
      rg[indice] = argv[1][indice];

   codigoRetorno = GerarDigitosVerificadoresRg(rg, &digitoVerificador);

   if (codigoRetorno == argumentoNulo)
   {
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
      printf("Argumento de entrada nulo.\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
   }
   else if (codigoRetorno == digitoInvalido)
   {
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
      printf("Argumento possui digito invalido.\n");
      printf("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
   }
   else if (codigoRetorno == ok)
   {
      printf("RG: ");
      for (indice = 0; indice <= NUMERO_DIGITOS; indice++)
         printf("%c", rg[indice]);
      printf("-%c ", digitoVerificador);
      printf("\n");
   }

   return SUCESSO;
}

/* $RCSfile: aula0505b.c,v $ */
