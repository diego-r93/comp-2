/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula a Serie Harmonica Alternada utilizando while


 * $Author: diego.silva $
 * $Date: 2022/01/10 00:01:55 $
 * $Log: aula0403d.c,v $
 * Revision 1.2  2022/01/10 00:01:55  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/08 20:02:54  diego.silva
 * Initial revision
 *
 */

#include "aula0401.h"

float CalcularSerieHarmonicaAlternada(unsigned short int numero)
{
   float resultado = 0;

   if (numero == 0)
      return 0;

   while (numero > 0)
   {
      if (numero % 2 == 0)
         resultado -= CalcularExponencial(numero, -numero);

      else
         resultado += CalcularExponencial(numero, -numero);

      numero--;
   }
   return resultado;
}

/* $RCSfile: aula0403d.c,v $ */
