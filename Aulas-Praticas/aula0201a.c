/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o termo da serie de Fibonacci utilizando recursividade

 * $Author: diego.silva $
 * $Date: 2021/12/09 16:46:38 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2021/12/09 16:46:38  diego.silva
 * Initial revision
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci(us termo)
{
   if (termo <= 1)
      return termo;

   return CalcularTermoSerieFibonacci(termo - 1) + CalcularTermoSerieFibonacci(termo - 2);
}

/* $RCSfile: aula0201a.c,v $ */
