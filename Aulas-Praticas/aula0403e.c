/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula a Serie Harmonica Alternada utilizando a biblioteca Math


 * $Author: diego.silva $
 * $Date: 2022/01/10 00:01:55 $
 * $Log: aula0403e.c,v $
 * Revision 1.2  2022/01/10 00:01:55  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/09 15:01:35  diego.silva
 * Initial revision
 *
 */

#include <math.h>
#include "aula0401.h"

float CalcularSerieHarmonicaAlternada(unsigned short int numero)
{
   float resultado = 0;

   if (numero == 0)
      return 0;

   do
   {
      if (numero % 2 == 0)
         resultado -= pow(numero, -numero);

      else
         resultado += pow(numero, -numero);

      numero--;
   } while (numero > 0);

   return resultado;
}

/* $RCSfile: aula0403e.c,v $ */
