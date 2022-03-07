/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipos das funcoes
 * para o algoritmo de preenchimento.

 * $Author: diego.silva $
 * $Date: 2022/02/01 07:11:30 $
 * $Log: aula0701.h,v $
 * Revision 1.5  2022/02/01 07:11:30  diego.silva
 * *** empty log message ***
 *
 * Revision 1.4  2022/02/01 06:46:43  diego.silva
 * *** empty log message ***
 *
 * Revision 1.3  2022/02/01 04:40:35  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/01 03:31:08  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/01 03:17:28  diego.silva
 * Initial revision
 *
 */

#ifndef _AULA0701_
#define _AULA0701_ "@(#)aula0701.h $Revision: 1.5 $"

#ifdef __linux__
#define _XOPEN_SOURCE 600
#include <unistd.h>
#undef _XOPEN_SOURCE
#endif

#ifdef __FreeBSD__
#include <unistd.h>
#endif

#define APAGADO ' '
#define ACESO 'O'
#define DEFEITUOSO '.'
#define NUMERO_MAXIMO_LINHAS 250
#define NUMERO_MAXIMO_COLUNAS 800

typedef enum
{
   ok = 0,
   argumentoNulo,
   linhaInvalida,
   colunaInvalida,
   dimensaoInvalida,
   percentualInvalido,
   entradaInvalida,
   numeroForaDaMatriz,
   pixelDefeito,
} tipoErros;

typedef enum
{
   apagado = 0,
   aceso = 1,
   defeituoso = -1
} tipoPixel;

tipoErros
MostrarMonitor(useconds_t tempoEspera,                                         /*E*/
               tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /*E*/
               unsigned numeroMaximoLinhas,                                    /*E*/
               unsigned numeroMaximoColunas /*E*/);

tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                         unsigned numeroMaximoLinhas,                                    /* E */
                         unsigned numeroMaximoColunas,                                   /* E */
                         float percentualDefeituosos,                                    /* E */
                         float percentualApagados);                                      /* E */

tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
              unsigned numeroMaximoLinhas,                                    /* E */
              unsigned numeroMaximoColunas);

tipoErros
DesenharReta(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
             unsigned numeroMaximoLinhas,                                    /* E */
             unsigned numeroMaximoColunas,                                   /* E */
             unsigned linhaA,                                                /* E */
             unsigned colunaA,                                               /* E */
             unsigned linhaB,                                                /* E */
             unsigned colunaB /* E */);

tipoErros
DesenharPoligono(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                 unsigned numeroMaximoLinhas,                                    /* E */
                 unsigned numeroMaximoColunas,                                   /* E */
                 unsigned numeroVertices,                                        /* E */
                 unsigned linhasVertices[NUMERO_MAXIMO_LINHAS],                  /* E */
                 unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS] /* E */);

tipoErros
PreencherPoligono(useconds_t tempoEspera,                                         /* E */
                  tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                  unsigned numeroMaximoLinhas,                                    /* E */
                  unsigned numeroMaximoColunas,                                   /* E */
                  unsigned linha,                                                 /* E */
                  unsigned coluna /* E */);

#endif

/* $RCSfile: aula0701.h,v $ */
