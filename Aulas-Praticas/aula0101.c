/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Imprime o nome digitado pelo usuario

 * $Author: diego.silva $
 * $Date: 2021/12/02 04:12:15 $
 * $Log: aula0101.c,v $
 * Revision 1.1  2021/12/02 04:12:15  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2

#define NUMERO_ARGUMENTOS 2
#define TAMANHO_NOME 50
#define TAMANHO_TERMINAL 80

int main(int argc, char const *argv[])
{
   unsigned comprimentoDoNome;
   unsigned char indice;
   unsigned char posicaoAtual;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso: %s <nome>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   comprimentoDoNome = strlen(argv[1]);

   if (comprimentoDoNome > TAMANHO_NOME)
   {
      printf("O nome %s excede o tamanho suportado.\n", argv[1]);
      exit(ARGUMENTO_INVALIDO);
   }

   printf("\n");
   for (posicaoAtual = 0; posicaoAtual < TAMANHO_TERMINAL / 10; posicaoAtual++)
   {
      for (indice = 0; indice < 10; indice++)
      {
         printf("%i", posicaoAtual);
      }
   }

   printf("\n");
   for (posicaoAtual = 0; posicaoAtual < TAMANHO_TERMINAL / 10; posicaoAtual++)
   {
      for (indice = 0; indice < 10; indice++)
      {
         printf("%i", indice);
      }
   }

   printf("\n\n");
   for (indice = 0; indice < (TAMANHO_TERMINAL - (comprimentoDoNome + 2)) / 2; indice++)
   {
      printf(" ");
   }
   printf("\"%s\"\n\n", argv[1]);

   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n\n");

   return SUCESSO;
}

/* $RCSfile: aula0101.c,v $ */
