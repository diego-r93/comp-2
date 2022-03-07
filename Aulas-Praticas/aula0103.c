/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Exibe o tamanho em bytes das cominacoes entre
 * tipos basicos, modificadores de sinal e modificadores de largura.

 * $Author: diego.silva $
 * $Date: 2021/12/02 23:55:47 $
 * $Log: aula0103.c,v $
 * Revision 1.1  2021/12/02 23:55:47  diego.silva
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

   printf("\nTamanhos dos Modificadores de Sinal combinados com Modificadores de Largura\n\n");

   printf("signed short:%78lu %s \n", sizeof(signed short), (sizeof(signed short) > 1) ? "bytes" : "byte");

   printf("unsigned short:%76lu %s \n", sizeof(unsigned short), (sizeof(unsigned short) > 1) ? "bytes" : "byte");

   printf("signed long:%79lu %s \n", sizeof(signed long), (sizeof(signed long) > 1) ? "bytes" : "byte");

   printf("unsigned long:%77lu %s \n", sizeof(unsigned long), (sizeof(unsigned long) > 1) ? "bytes" : "byte");

   printf("signed long long:%74lu %s \n", sizeof(signed long long), (sizeof(signed long long) > 1) ? "bytes" : "byte");

   printf("unsigned long long:%72lu %s \n", sizeof(unsigned long long), (sizeof(unsigned long long) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Tipos Basicos combinados com Modificadores de Sinal\n\n");

   printf("signed char:%79lu %s \n", sizeof(signed char), (sizeof(signed char) > 1) ? "bytes" : "byte");

   printf("unsigned char:%77lu %s \n", sizeof(unsigned char), (sizeof(unsigned char) > 1) ? "bytes" : "byte");

   printf("signed int:%80lu %s \n", sizeof(signed int), (sizeof(signed int) > 1) ? "bytes" : "byte");

   printf("unsigned int:%78lu %s \n", sizeof(unsigned int), (sizeof(unsigned int) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Tipos Basicos combinados com Modificadores de Largura\n\n");

   printf("short int:%81lu %s \n", sizeof(short int), (sizeof(short int) > 1) ? "bytes" : "byte");

   printf("long int:%82lu %s \n", sizeof(long int), (sizeof(long int) > 1) ? "bytes" : "byte");

   printf("long long int:%77lu %s \n", sizeof(long long int), (sizeof(long long int) > 1) ? "bytes" : "byte");

   printf("long double:%80lu %s \n", sizeof(long double), (sizeof(long double) > 1) ? "bytes" : "byte");

   printf("\n");
   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n");

   printf("\nTamanhos dos Tipos Basicos combinados com Modificadores de Sinal e com Modificadores de Largura\n\n");

   printf("signed short int:%74lu %s \n", sizeof(signed short int), (sizeof(signed short int) > 1) ? "bytes" : "byte");

   printf("signed long int:%75lu %s \n", sizeof(signed long int), (sizeof(signed long int) > 1) ? "bytes" : "byte");

   printf("signed long long int:%70lu %s \n", sizeof(signed long long int), (sizeof(signed long long int) > 1) ? "bytes" : "byte");

   printf("unsigned short int:%72lu %s \n", sizeof(unsigned short int), (sizeof(unsigned short int) > 1) ? "bytes" : "byte");

   printf("unsigned long int:%73lu %s \n", sizeof(unsigned long int), (sizeof(unsigned long int) > 1) ? "bytes" : "byte");

   printf("unsigned long long int:%68lu %s \n", sizeof(unsigned long long int), (sizeof(unsigned long long int) > 1) ? "bytes" : "byte");

   for (indice = 0; indice < TAMANHO_TERMINAL; indice++)
   {
      printf("-");
   }
   printf("\n\n");

   return SUCESSO;
}

/* $RCSfile: aula0103.c,v $ */
