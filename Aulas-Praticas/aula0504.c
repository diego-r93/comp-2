/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Implementacao das funcoes GerarDigitosVerificadoresRg
 * e ValidarRg

 * $Author: diego.silva $
 * $Date: 2022/01/17 07:18:31 $
 * $Log: aula0504.c,v $
 * Revision 1.2  2022/01/17 07:18:31  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/17 04:37:59  diego.silva
 * Initial revision
 *
 */

#include "aula0504.h"

tipoErros
GerarDigitosVerificadoresRg(char *rg, char *digitoVerificador)
{
   byte indice, indiceRg;
   byte rgByte[NUMERO_DIGITOS];
   unsigned soma = 0;
   byte pesos[] = {2, 3, 4, 5, 6, 7, 8, 9};

   if (!rg)
      return argumentoNulo;

   if (rg[2] != '.' || rg[6] != '.')
   {
      return digitoInvalido;
   }

   for (indiceRg = 0, indice = 0; indice < NUMERO_DIGITOS; indice++)
   {
      if (indice == 2 || indice == 6)
         continue;

      if (rg[indice] < '0' || rg[indice] > '9')
         return digitoInvalido;

      rgByte[indiceRg] = rg[indice] - '0';
      soma += rgByte[indiceRg] * pesos[indiceRg];
      indiceRg++;
   }

   if (soma % 11 == 0)
      *digitoVerificador = '0';
   else if (soma % 11 == 1)
      *digitoVerificador = 'X';
   else
      *digitoVerificador = 11 - (soma % 11) + '0';

   return ok;
}

tipoErros
ValidarRg(char *rg)
{
   char tempRg[NUMERO_DIGITOS];
   char digitoVerificador;
   byte codigoRetorno, indice;

   if (!rg)
      return argumentoNulo;

   if (rg[2] != '.' || rg[6] != '.' || rg[10] != '-')
      return digitoInvalido;

   if ((rg[COMPRIMENTO_TOTAL - 1] < '0' || rg[COMPRIMENTO_TOTAL - 1] > '9') && rg[COMPRIMENTO_TOTAL - 1] > 'X')
      return digitoInvalido;

   for (indice = 0; indice < NUMERO_DIGITOS; indice++)
      tempRg[indice] = rg[indice];

   codigoRetorno = GerarDigitosVerificadoresRg(tempRg, &digitoVerificador);

   if (codigoRetorno != ok)
      return codigoRetorno;
   else if (digitoVerificador != rg[COMPRIMENTO_TOTAL - 1])
      return rgInvalido;

   return ok;
}

/* $RCSfile: aula0504.c,v $ */
