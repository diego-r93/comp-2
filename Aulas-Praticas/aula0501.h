/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipo da funcao GerarDigitosVerificadoresRg

 * $Author: diego.silva $
 * $Date: 2022/01/17 05:43:32 $
 * $Log: aula0501.h,v $
 * Revision 1.4  2022/01/17 05:43:32  diego.silva
 * *** empty log message ***
 *
 * Revision 1.3  2022/01/17 05:27:13  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/16 21:08:11  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/12 23:58:32  diego.silva
 * Initial revision
 *
 */

#ifndef _AULA0501_
#define _AULA0501_ "@(#)aula0501.h $Revision: 1.4 $"

#define NUMERO_DIGITOS 9

typedef unsigned char byte;
typedef enum
{
   ok,
   argumentoNulo,
   digitoInvalido,
   rgInvalido
} tipoErros;

tipoErros GerarDigitosVerificadoresRg(byte[NUMERO_DIGITOS]);
tipoErros ValidarRg(byte rg[NUMERO_DIGITOS]);

#endif

/* $RCSfile: aula0501.h,v $ */
