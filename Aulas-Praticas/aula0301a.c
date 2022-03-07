/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o MDC utilizando recursividade

 * $Author: diego.silva $
 * $Date: 2021/12/17 15:31:23 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2021/12/17 15:31:23  diego.silva
 * Initial revision
 *
 */

#include "aula0301.h"

ull CalcularMaximoDivisorComum(ull numeroX, ull numeroY)
{
   /* Algoritmo de Euclides */

   if ((numeroX == 0) && (numeroY == 0))
      return MDC_INVALIDO;

   if (numeroX == 0)
      return numeroY;

   if (numeroY == 0)
      return numeroX;

   if ((numeroX % numeroY) == 0)
      return numeroY;

   return CalcularMaximoDivisorComum(numeroY % numeroX, numeroX);
}

/* $RCSfile: aula0301a.c,v $ */
