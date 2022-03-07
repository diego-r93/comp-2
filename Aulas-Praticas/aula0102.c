/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Exibe o tamanho em bytes dos tipos basicos,
 * modificadores de sinal e modificadores de largura.

 * $Author: diego.silva $
 * $Date: 2021/12/02 22:05:54 $
 * $Log: aula0102.c,v $
 * Revision 1.1  2021/12/02 22:05:54  diego.silva
 * Initial revision
 *
 */

#include <stdio.h>

#define SUCESSO 0

#define TAMANHO_TERMINAL 100

int main(int argc, const char *argv[])
{
   unsigned char indice;

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Tipos Basicos\n\n");

   printf("void:%86lu %s \n", sizeof(void), (sizeof(void) > 1) ? "bytes" : "byte");

   printf("char:%86lu %s \n", sizeof(char), (sizeof(char) > 1) ? "bytes" : "byte");

   printf("int:%87lu %s \n", sizeof(int), (sizeof(int) > 1) ? "bytes" : "byte");

   printf("float:%85lu %s \n", sizeof(float), (sizeof(float) > 1) ? "bytes" : "byte");

   printf("double:%84lu %s \n", sizeof(double), (sizeof(double) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Modificadores de Sinal\n\n");

   printf("signed:%84lu %s \n", sizeof(signed), (sizeof(signed) > 1) ? "bytes" : "byte");

   printf("unsigned:%82lu %s \n", sizeof(unsigned), (sizeof(unsigned) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Modificadores de Largura\n\n");

   printf("short:%85lu %s \n", sizeof(short), (sizeof(short) > 1) ? "bytes" : "byte");

   printf("long:%86lu %s \n", sizeof(long), (sizeof(long) > 1) ? "bytes" : "byte");

   printf("long long:%81lu %s \n", sizeof(long long), (sizeof(long long) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n\n");

   return SUCESSO;
}

/* $RCSfile: aula0102.c,v $ */
