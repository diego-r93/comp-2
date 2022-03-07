/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o termo da serie de Fibonacci utilizando while

 * $Author: diego.silva $
 * $Date: 2021/12/10 04:31:26 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2021/12/10 04:31:26  diego.silva
 * Initial revision
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci(us termo)
{
   ull resultado, termo1, termo2;
   us contador;

   if (termo <= 1)
      return termo;

   termo1 = 0;
   termo2 = 1;
   contador = 1;

   while (contador < termo)
   {
      resultado = termo1 + termo2;
      termo1 = termo2;
      termo2 = resultado;
      ++contador;
   }

   return resultado;
}

/* $RCSfile: aula0201d.c,v $ */
