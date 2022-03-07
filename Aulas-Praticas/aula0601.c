/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Implementacao das funcoes
 * para manipulacao de matrizes

 * $Author: diego.silva $
 * $Date: 2022/01/26 11:57:03 $
 * $Log: aula0601.c,v $
 * Revision 1.6  2022/01/26 11:57:03  diego.silva
 * *** empty log message ***
 *
 * Revision 1.5  2022/01/26 08:02:24  diego.silva
 * *** empty log message ***
 *
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

#include "aula0601.h"

tipoErros
MultiplicarMatrizes(uint16_t linhas_1, uint16_t colunas_1, uint16_t linhas_2, uint16_t colunas_2,
                    double matriz_1[MAX_LINHAS][MAX_COLUNAS],
                    double matriz_2[MAX_LINHAS][MAX_COLUNAS],
                    double matrizProduto[MAX_LINHAS][MAX_COLUNAS])
{
   uint16_t indiceLinhas, indiceColunas, contador;

   if (!matriz_1 || !matriz_2 || !matrizProduto)
      return argumentoNulo;

   for (indiceLinhas = 0; indiceLinhas < linhas_1; indiceLinhas++)
      for (indiceColunas = 0; indiceColunas < colunas_2; indiceColunas++)
      {
         matrizProduto[indiceLinhas][indiceColunas] = 0;
         for (contador = 0; contador < colunas_1; contador++)
            matrizProduto[indiceLinhas][indiceColunas] += matriz_1[indiceLinhas][contador] * matriz_2[contador][indiceColunas];
      }

   return ok;
}

tipoErros
ObterMatrizTransposta(uint16_t linhas, uint16_t colunas,
                      double matrizOriginal[MAX_LINHAS][MAX_COLUNAS],
                      double matrizTransposta[MAX_LINHAS][MAX_COLUNAS])
{
   uint16_t indiceLinhas, indiceColunas;

   if (!matrizOriginal || !matrizTransposta)
      return argumentoNulo;

   for (indiceLinhas = 0; indiceLinhas < colunas; indiceLinhas++)
      for (indiceColunas = 0; indiceColunas < linhas; indiceColunas++)
         matrizTransposta[indiceLinhas][indiceColunas] = matrizOriginal[indiceColunas][indiceLinhas];

   return ok;
}

tipoErros
CalcularMenorComplementar(uint16_t ordemMatriz,
                          uint16_t linhaElemento,
                          uint16_t colunaElemento,
                          double matrizEntrada[MAX_LINHAS][MAX_COLUNAS],
                          double *menorComplementar)
{
   uint16_t indiceLinhas, indiceColunas, linhaAuxiliar, colunaAuxiliar, indice;

   uint16_t ordemAuxiliar = ordemMatriz - 1;
   double matrizAuxiliar[MAX_LINHAS][MAX_COLUNAS];

   if (!matrizEntrada)
      return argumentoNulo;

   if (ordemMatriz < 2)
      return ordemInvalida;

   for (indice = 0; indice < ordemMatriz; indice++)
   {
      linhaAuxiliar = 0;
      colunaAuxiliar = 0;

      for (indiceLinhas = 0; indiceLinhas < ordemMatriz; indiceLinhas++)
      {
         colunaAuxiliar = 0;

         if (indiceLinhas == (linhaElemento - 1))
            continue;

         for (indiceColunas = 0; indiceColunas < ordemMatriz; indiceColunas++)
         {
            if (indiceColunas == (colunaElemento - 1))
               continue;

            matrizAuxiliar[linhaAuxiliar][colunaAuxiliar] = matrizEntrada[indiceLinhas][indiceColunas];

            colunaAuxiliar++;
         }
         linhaAuxiliar++;
      }
   }

   CalcularDeterminanteMatriz(ordemAuxiliar, matrizAuxiliar, menorComplementar);

   return ok;
}

tipoErros
CalcularComplementoAlgebrico(uint16_t ordemMatriz,
                             uint16_t linhaElemento,
                             uint16_t colunaElemento,
                             double matrizEntrada[MAX_LINHAS][MAX_COLUNAS],
                             double *cofator)
{
   if (!matrizEntrada)
      return argumentoNulo;

   if (ordemMatriz < 2)
      return ordemInvalida;

   CalcularMenorComplementar(ordemMatriz, linhaElemento, colunaElemento, matrizEntrada, cofator);

   if ((linhaElemento + colunaElemento) % 2 == 1)
      *cofator *= -1;

   return ok;
}

tipoErros
CalcularDeterminanteMatriz(uint16_t ordemMatriz,
                           double matrizEntrada[MAX_LINHAS][MAX_COLUNAS],
                           double *determinante)
{
   uint16_t linha, coluna;
   double cofator = 0;
   double somaResultado = 0;

   if (!matrizEntrada)
      return argumentoNulo;

   if (ordemMatriz == 1)
      *determinante = matrizEntrada[0][0];

   else if (ordemMatriz == 2)
      *determinante =
          matrizEntrada[0][0] * matrizEntrada[1][1] - matrizEntrada[0][1] * matrizEntrada[1][0];

   else if (ordemMatriz == 3)
   {

      *determinante = (matrizEntrada[0][0] * matrizEntrada[1][1] * matrizEntrada[2][2]) +
                      (matrizEntrada[0][1] * matrizEntrada[1][2] * matrizEntrada[2][0]) +
                      (matrizEntrada[0][2] * matrizEntrada[1][0] * matrizEntrada[2][1]) -
                      ((matrizEntrada[0][1] * matrizEntrada[1][0] * matrizEntrada[2][2]) +
                       (matrizEntrada[0][0] * matrizEntrada[1][2] * matrizEntrada[2][1]) +
                       (matrizEntrada[0][2] * matrizEntrada[1][1] * matrizEntrada[2][0]));
   }

   else
   {
      for (linha = 0, coluna = 0; linha < ordemMatriz; linha++)
      {
         CalcularComplementoAlgebrico(ordemMatriz, linha + 1, coluna + 1, matrizEntrada, &cofator);
         somaResultado += matrizEntrada[linha][coluna] * cofator;
      }

      *determinante = somaResultado;
   }

   return ok;
}

/* $RCSfile: aula0601.c,v $ */
