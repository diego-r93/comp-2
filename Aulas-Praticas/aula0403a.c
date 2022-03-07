/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Calcula a Serie Harmonica Alternada utilizando recursividade

 * $Author: diego.silva $
 * $Date: 2022/01/10 00:01:55 $
 * $Log: aula0403a.c,v $
 * Revision 1.3  2022/01/10 00:01:55  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/08 19:15:07  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/08 19:10:13  diego.silva
 * Initial revision
 *
 */

#include "aula0401.h"

float CalcularSerieHarmonicaAlternada(unsigned short int numero)
{
   if (numero == 0)
      return 0;

   if (numero % 2 == 0)

      return -CalcularExponencial(numero, -numero) + CalcularSerieHarmonicaAlternada(numero - 1);

   else
      return CalcularExponencial(numero, -numero) + CalcularSerieHarmonicaAlternada(numero - 1);
}

/* $RCSfile: aula0403a.c,v $ */