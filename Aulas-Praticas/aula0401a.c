/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o Exponencial utilizando recursividade

 * $Author: diego.silva $
 * $Date: 2022/01/09 23:29:04 $
 * $Log: aula0401a.c,v $
 * Revision 1.2  2022/01/09 23:29:04  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/05 09:00:39  diego.silva
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
   if (base == 0 && expoente < 0)
      return (INFINITY);

   if (expoente == 0)
      return 1;

   if (base == 1)
      return base;

   if (expoente > 0)
      return base * CalcularExponencial(base, expoente - 1);

   return ((1.0 / base) * (CalcularExponencial(base, expoente + 1)));
}

/* $RCSfile: aula0401a.c,v $ */
