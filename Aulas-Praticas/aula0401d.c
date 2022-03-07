/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o Exponencial utilizando while

 * $Author: diego.silva $
 * $Date: 2022/01/05 10:21:13 $
 * $Log: aula0401d.c,v $
 * Revision 1.1  2022/01/05 10:21:13  diego.silva
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

   resultado = 1;
   contador = expoente;

   if (expoente > 0)
      while (contador != 0)
      {
         resultado = (base * resultado);
         --contador;
      }

   else
      while (contador != 0)
      {
         resultado = ((1.0 / base) * resultado);
         ++contador;
      }

   return resultado;
}

/* $RCSfile: aula0401d.c,v $ */
