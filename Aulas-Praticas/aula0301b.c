/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o MDC utilizando do...while

 * $Author: diego.silva $
 * $Date: 2021/12/17 10:43:20 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2021/12/17 10:43:20  diego.silva
 * Initial revision
 *
 */

#include "aula0301.h"

ull CalcularMaximoDivisorComum(ull numeroX, ull numeroY)
{
   /* Algoritmo de Euclides */

   ull numeroZ;

   do
   {
      if ((numeroX == 0) && (numeroY == 0))
         return MDC_INVALIDO;

      if (numeroY == 0)
         numeroY = numeroX;

      else
         numeroZ = (numeroX % numeroY);

      if (numeroZ != 0)
      {
         numeroX = numeroY;
         numeroY = numeroZ;
      }
   } while (numeroZ != 0);
   return numeroY;
}

/* $RCSfile: aula0301b.c,v $ */