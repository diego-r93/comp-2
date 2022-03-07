/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipos das funcoes
 * para manipulacao de matrizes

 * $Author: diego.silva $
 * $Date: 2022/01/25 11:10:22 $
 * $Log: aula0601.h,v $
 * Revision 1.4  2022/01/25 11:10:22  diego.silva
 * *** empty log message ***
 *
 * Revision 1.3  2022/01/25 08:15:31  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/24 15:10:29  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/24 11:23:01  diego.silva
 * Initial revision
 *
 */

#ifndef _AULA0601_
#define _AULA0601_ "@(#)aula0601.h $Revision: 1.4 $"

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

typedef unsigned short int uint16_t;
typedef unsigned long int uint64_t;

typedef enum
{
   ok,
   argumentoNulo,
   ordemInvalida
} tipoErros;

tipoErros
MultiplicarMatrizes(uint16_t,                         /* numero de linhas da matriz 1 (E) */
                    uint16_t,                         /* numero de colunas da matriz 1 (E) */
                    uint16_t,                         /* numero de linhas da matriz 2 (E) */
                    uint16_t,                         /* numero de colunas da matriz 2 (E) */
                    double[MAX_LINHAS][MAX_COLUNAS],  /* matriz 1 (E) */
                    double[MAX_LINHAS][MAX_COLUNAS],  /* matriz 2 (E) */
                    double[MAX_LINHAS][MAX_COLUNAS]); /* matriz produto (S) */

tipoErros
ObterMatrizTransposta(uint16_t,                         /* numero de linhas da matriz original (E) */
                      uint16_t,                         /* numero de colunas da matriz original (E) */
                      double[MAX_LINHAS][MAX_COLUNAS],  /* matriz original (E) */
                      double[MAX_LINHAS][MAX_COLUNAS]); /* matriz transposta (S) */

tipoErros
CalcularMenorComplementar(uint16_t,                        /* ordem da matriz (E) */
                          uint16_t,                        /* linha do elemento (E) */
                          uint16_t,                        /* coluna do elemento (E) */
                          double[MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                          double *);                       /* menor complementar (S) */

tipoErros
CalcularComplementoAlgebrico(uint16_t,                        /* ordem da matriz (E) */
                             uint16_t,                        /* linha do elemento (E) */
                             uint16_t,                        /* coluna do elemento (E) */
                             double[MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                             double *);                       /* complemento algebrico ou cofator (S) */

tipoErros
CalcularDeterminanteMatriz(uint16_t,                        /* ordem da matriz (E) */
                           double[MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                           double *);                       /* determinante (S) */

#endif

/* $RCSfile: aula0601.h,v $ */
