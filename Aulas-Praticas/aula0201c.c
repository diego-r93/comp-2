/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula o termo da serie de Fibonacci utilizando for

 * $Author: diego.silva $
 * $Date: 2021/12/10 04:14:09 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2021/12/10 04:14:09  diego.silva
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

   for (contador = 1; contador < termo; contador++)
   {
      resultado = termo1 + termo2;
      termo1 = termo2;
      termo2 = resultado;
   }

   return resultado;
}

/* $RCSfile: aula0201c.c,v $ */
