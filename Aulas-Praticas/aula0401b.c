/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o Exponencial utilizando do...while

 * $Author: diego.silva $
 * $Date: 2022/01/05 09:35:24 $
 * $Log: aula0401b.c,v $
 * Revision 1.1  2022/01/05 09:35:24  diego.silva
 * Initial revision
 *
 */

#include <math.h>

#ifndef INFINITY
#define INFINITY HUGE_VAL
#endif

#include "aula0401.h"

long double
CalcularExponencial(double base, int expoente)
{
   long double resultado;
   int contador;

   if ((base == 0) && (expoente < 0))
      return (INFINITY);

   if (expoente == 0)
      return 1;

   if (base == 1)
      return base;

   contador = expoente;
   resultado = 1;

   do
   {
      if (expoente > 0)
      {
         resultado = (base * resultado);
         --contador;
      }

      else
      {
         resultado = ((1.0 / base) * resultado);
         ++contador;
      }
   } while (contador != 0);

   return resultado;
}

/* $RCSfile: aula0401b.c,v $ */
