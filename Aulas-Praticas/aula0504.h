/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipo das funcoes
 * GerarDigitosVerificadoresRg e Validar Rg


 * $Author: diego.silva $
 * $Date: 2022/01/17 07:18:31 $
 * $Log: aula0504.h,v $
 * Revision 1.2  2022/01/17 07:18:31  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/17 04:37:59  diego.silva
 * Initial revision
 *
 */

#ifndef _AULA0504_
#define _AULA0504_ "@(#)aula0504.h $Revision: 1.2 $"

#define NUMERO_DIGITOS 8 + 2
#define COMPRIMENTO_TOTAL 8 + 1 + 3

typedef unsigned char byte;
typedef enum
{
   ok,
   argumentoNulo,
   digitoInvalido,
   rgInvalido
} tipoErros;

tipoErros GerarDigitosVerificadoresRg(char *rg, char *digitoVerificador);
tipoErros ValidarRg(char *);

#endif

/* $RCSfile: aula0504.h,v $ */
