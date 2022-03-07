/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Implementacao da funcao GerarDigitosVerificadoresRg

 * $Author: diego.silva $
 * $Date: 2022/01/16 21:08:11 $
 * $Log: aula0501.c,v $
 * Revision 1.2  2022/01/16 21:08:11  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/12 23:58:32  diego.silva
 * Initial revision
 *
 */

#include "aula0501.h"

tipoErros
GerarDigitosVerificadoresRg(byte rg[NUMERO_DIGITOS])
{
   byte indice, verificador;
   unsigned soma = 0;
   byte pesos[] = {2, 3, 4, 5, 6, 7, 8, 9};

   if (!rg)
      return argumentoNulo;

   for (indice = 0; indice < NUMERO_DIGITOS - 1; indice++)
   {
      if (rg[indice] > 9)
         return digitoInvalido;
      soma += rg[indice] * pesos[indice];
   }

   if (soma % 11 == 0)
      verificador = 0;
   else if (soma % 11 == 1)
      verificador = 'X';
   else
      verificador = 11 - (soma % 11);

   rg[indice] = verificador;

   return ok;
}

tipoErros ValidarRg(byte rg[NUMERO_DIGITOS])
{
   byte rgValidado[NUMERO_DIGITOS];
   byte codigoRetorno, indice;

   for (indice = 0; indice < NUMERO_DIGITOS; indice++)
      rgValidado[indice] = rg[indice];

   codigoRetorno = GerarDigitosVerificadoresRg(rgValidado);

   if (codigoRetorno != ok)
      return codigoRetorno;
   else if (rgValidado[NUMERO_DIGITOS - 1] != rg[NUMERO_DIGITOS - 1])
      return rgInvalido;

   return ok;
}

/* $RCSfile: aula0501.c,v $ */
