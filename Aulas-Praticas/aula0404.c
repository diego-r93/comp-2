/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para calcular a Serie Harmonica Alternada

 * $Author: diego.silva $
 * $Date: 2022/01/10 00:31:10 $
 * $Log: aula0404.c,v $
 * Revision 1.5  2022/01/10 00:31:10  diego.silva
 * *** empty log message ***
 *
 * Revision 1.4  2022/01/10 00:01:55  diego.silva
 * *** empty log message ***
 *
 * Revision 1.3  2022/01/09 15:01:35  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/08 19:15:07  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/08 19:10:13  diego.silva
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined(__FreeBSD__) && defined(__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#endif

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#include "aula0401.h"

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define VALOR_MINIMO_FLOAT_EXCEDIDO 3
#define VALOR_MAXIMO_FLOAT_EXCEDIDO 4
#define NUMERO_FORA_DO_INTERVALO 5

#define NUMERO_ARGUMENTOS 2

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   char *validacao;
   float percentual;
   float resultado, resultadoAnterior, diferenca;
   unsigned short numero = 0;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalidos.\n");
      printf("Uso %s <percentual: numero real maior do que 0 e menor do que 1>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   percentual = strtof(argv[1], &validacao);

   if (errno == ERANGE)
   {
      if (argv[1][1] == '.')
      {
         printf("Valor minimo permitido (%g) do tipo float foi excedido.\n", __FLT_MIN__);
         exit(VALOR_MINIMO_FLOAT_EXCEDIDO);
      }

      printf("Valor maximo permitido (%g) do tipo float foi excedido.\n", FLT_MAX);
      exit(VALOR_MAXIMO_FLOAT_EXCEDIDO);
   }

   if (*validacao != END_OF_STRING)
   {
      printf("Argumento contem caractere(s) invalido(s): %c \n", *validacao);
      exit(ARGUMENTO_INVALIDO);
   }

   if (percentual <= 0 || percentual >= 1)
   {
      printf("Uso %s <percentual: numero real maior do que 0 e menor do que 1>\n", argv[0]);
      exit(NUMERO_FORA_DO_INTERVALO);
   }

   do
   {
      resultado = CalcularSerieHarmonicaAlternada(numero);
      printf("S(%u) = %.10f \n", numero, resultado);
      resultadoAnterior = resultado;
      resultado = CalcularSerieHarmonicaAlternada(++numero);
      diferenca = resultado - resultadoAnterior;

      if (diferenca < 0)
         diferenca = -diferenca;

   } while (diferenca >= percentual * resultadoAnterior);

   printf("S(%u) = %.10f \n", numero, resultado);

   /*  Mesmo resultado
   #include <math.h>
   do
   {
      resultado = CalcularSerieHarmonicaAlternada(numero);
      printf("S(%u) = %.10f \n", numero, resultado);
      numero++;
   } while (pow(numero, -numero) >= percentual * CalcularSerieHarmonicaAlternada(numero - 1));
   */

   return SUCESSO;
}

/* $RCSfile: aula0404.c,v $ */
