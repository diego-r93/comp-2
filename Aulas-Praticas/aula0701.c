/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Implementacao das funcoes
 * para o algoritmo de preenchimento.

 * $Author: diego.silva $
 * $Date: 2022/02/01 07:11:30 $
 * $Log: aula0701.c,v $
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

#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

tipoErros
MostrarMonitor(useconds_t tempoEspera,
               tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
               unsigned numeroMaximoLinhas,
               unsigned numeroMaximoColunas)
{
   unsigned short linha, coluna, indice;

   system("clear");

   if (monitor == NULL)
      return argumentoNulo;

   if (numeroMaximoLinhas == 0)
      return linhaInvalida;

   if (numeroMaximoColunas == 0)
      return colunaInvalida;

   if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
      return dimensaoInvalida;

   for (indice = 0; indice < numeroMaximoColunas + 4; indice++)
      printf("-");
   printf("\n|");

   for (indice = 0; indice < numeroMaximoColunas + 2; indice++)
      printf(" ");
   printf("|\n");

   for (linha = 0; linha < numeroMaximoLinhas; linha++)
   {
      printf("| ");
      for (coluna = 0; coluna < numeroMaximoColunas; coluna++)
         printf("%c", (monitor[linha][coluna] == aceso ? ACESO : (monitor[linha][coluna] == apagado ? APAGADO : DEFEITUOSO)));
      printf(" | \n");
   }

   printf("|");
   for (indice = 0; indice < numeroMaximoColunas + 2; indice++)
   {
      printf(" ");
   }
   printf("|\n");

   for (indice = 0; indice < numeroMaximoColunas + 4; indice++)
      printf("-");
   printf("\n\n");

   usleep(tempoEspera);

   return ok;
}

tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                         unsigned numeroMaximoLinhas,
                         unsigned numeroMaximoColunas,
                         float percentualDefeituosos,
                         float percentualApagados)
{

   unsigned linha, coluna, indice;

   unsigned totalPixels = numeroMaximoLinhas * numeroMaximoColunas;
   unsigned pixelsApagados = (unsigned)((totalPixels * percentualApagados) / 100);
   unsigned pixelsDefeituosos = (unsigned)((totalPixels * percentualDefeituosos) / 100);

   if (monitor == NULL)
      return argumentoNulo;

   if (numeroMaximoLinhas == 0)
      return linhaInvalida;

   if (numeroMaximoColunas == 0)
      return colunaInvalida;

   if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
      return dimensaoInvalida;

   if (percentualDefeituosos + percentualApagados > 100)
      return percentualInvalido;

   for (linha = 0; linha != numeroMaximoLinhas; linha++)
      for (coluna = 0; coluna != numeroMaximoColunas; coluna++)
         monitor[linha][coluna] = aceso;

   srand((unsigned)time(NULL));
   for (indice = 0; indice < pixelsDefeituosos;)
   {
      linha = rand() % numeroMaximoLinhas;
      coluna = rand() % numeroMaximoColunas;

      if (monitor[linha][coluna] == aceso)
      {
         monitor[linha][coluna] = defeituoso;
         indice++;
      }
   }

   for (indice = 0; indice < pixelsApagados;)
   {
      linha = rand() % numeroMaximoLinhas;
      coluna = rand() % numeroMaximoColunas;

      if (monitor[linha][coluna] == aceso)
      {
         monitor[linha][coluna] = apagado;
         indice++;
      }
   }

   return ok;
}

tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
              unsigned numeroMaximoLinhas,
              unsigned numeroMaximoColunas)
{
   unsigned linha, coluna;

   if (monitor == NULL)
      return argumentoNulo;

   if (numeroMaximoLinhas == 0)
      return linhaInvalida;

   if (numeroMaximoColunas == 0)
      return colunaInvalida;

   if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
      return dimensaoInvalida;

   for (linha = 0; linha != numeroMaximoLinhas; linha++)
   {
      for (coluna = 0; coluna != numeroMaximoColunas; coluna++)
      {
         if (monitor[linha][coluna] == defeituoso)
            monitor[linha][coluna] = defeituoso;
         else
            monitor[linha][coluna] = apagado;
      }
   }

   return ok;
}

tipoErros
DesenharReta(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
             unsigned numeroMaximoLinhas,
             unsigned numeroMaximoColunas,
             unsigned linhaA,
             unsigned colunaA,
             unsigned linhaB,
             unsigned colunaB)
{
   short dx, dy, sx, sy, err, e2;
   int x0 = linhaA - 1;
   int y0 = colunaA - 1;
   int x1 = linhaB - 1;
   int y1 = colunaB - 1;

   if (monitor == NULL)
      return argumentoNulo;

   if (numeroMaximoLinhas == 0)
      return linhaInvalida;

   if (numeroMaximoColunas == 0)
      return colunaInvalida;

   if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
      return dimensaoInvalida;

   if (linhaA > numeroMaximoLinhas || linhaB > numeroMaximoLinhas || colunaA > numeroMaximoColunas || colunaB > numeroMaximoColunas)
   {
      printf("%u %u %u %u\n", linhaA, linhaB, colunaA, colunaB);
      return numeroForaDaMatriz;
   }

   dx = abs(x1 - x0);
   dy = abs(y1 - y0);
   sx = x0 < x1 ? 1 : -1;
   sy = y0 < y1 ? 1 : -1;
   err = dx > dy ? dx / 2 : -dy / 2;

   while (1)
   {
      if (monitor[x0][y0] == defeituoso)
      {
         return pixelDefeito;
      }
      else
      {
         if ((x0 == x1) && (y0 == y1))
         {
            break;
         }
         e2 = err;
         if (e2 > -dx)
         {
            err -= dy;
            x0 += sx;
         }
         if (e2 < dy)
         {
            err += dx;
            y0 += sy;
         }
      }
   }
   x0 = linhaA - 1;
   y0 = colunaA - 1;
   err = dx > dy ? dx / 2 : -dy / 2;

   while (1)
   {
      monitor[x0][y0] = aceso;

      if ((x0 == x1) && (y0 == y1))
      {
         break;
      }
      e2 = err;
      if (e2 > -dx)
      {
         err -= dy;
         x0 += sx;
      }
      if (e2 < dy)
      {
         err += dx;
         y0 += sy;
      }
   }

   return ok;
}

tipoErros
DesenharPoligono(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                 unsigned numeroMaximoLinhas,
                 unsigned numeroMaximoColunas,
                 unsigned numeroVertices,
                 unsigned linhasVertices[NUMERO_MAXIMO_LINHAS],
                 unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS])
{
   unsigned indice;
   tipoErros codigoRetorno;

   for (indice = 0; indice < numeroVertices; indice++)
   {
      if (indice == numeroVertices - 1)
      {
         codigoRetorno = DesenharReta(monitor, numeroMaximoLinhas, numeroMaximoColunas, linhasVertices[indice], colunasVertices[indice], linhasVertices[0], colunasVertices[0]);
         if (codigoRetorno != ok)
            return codigoRetorno;
      }
      else
      {
         codigoRetorno = DesenharReta(monitor, numeroMaximoLinhas, numeroMaximoColunas, linhasVertices[indice], colunasVertices[indice], linhasVertices[indice + 1], colunasVertices[indice + 1]);
         if (codigoRetorno != ok)
            return codigoRetorno;
      }
   }
   return ok;
}

tipoErros
PreencherPoligono(useconds_t tempoEspera,
                  tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                  unsigned numeroMaximoLinhas,
                  unsigned numeroMaximoColunas,
                  unsigned linha,
                  unsigned coluna)
{
   if (monitor == NULL)
      return argumentoNulo;

   if (numeroMaximoLinhas == 0)
      return linhaInvalida;

   if (numeroMaximoColunas == 0)
      return colunaInvalida;

   if (monitor[linha - 1][coluna - 1] == aceso)
      return ok;

   if (monitor[linha - 1][coluna - 1] == defeituoso)
      return pixelDefeito;

   monitor[linha - 1][coluna - 1] = aceso;

   usleep(tempoEspera);

   MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);

   if (linha < numeroMaximoLinhas)
      PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha + 1, coluna);

   if (linha >= 1)
      PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha - 1, coluna);

   if (coluna < numeroMaximoColunas)
      PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna + 1);

   if (coluna >= 1)
      PreencherPoligono(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna - 1);

   return ok;
}

/* $RCSfile: aula0701.c,v $ */
