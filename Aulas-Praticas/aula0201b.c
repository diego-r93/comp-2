/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o termo da serie de Fibonacci utilizando do...while

 * $Author: diego.silva $
 * $Date: 2021/12/10 03:53:49 $
 * $Log: aula0201b.c,v $
 * Revision 1.1  2021/12/10 03:53:49  diego.silva
 * Initial revision
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci(us termo)
{
   ull resultado, termoAnterior;
   us contador;

   resultado = contador = 1;
   termoAnterior = 0;

   if (termo <= 1)
      return termo;

   do
   {
      resultado += termoAnterior;
      termoAnterior = resultado - termoAnterior;
      ++contador;
   } while (contador < termo);

   return resultado;
}

/* $RCSfile: aula0201b.c,v $ */
