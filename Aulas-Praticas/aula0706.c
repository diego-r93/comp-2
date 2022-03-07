/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para as funcoes
 * MostrarMonitor, GerarDistribuicaoInicial,
 * LimparMonitor, DesenharPoligono e PreencherPoligono.


 * $Author: diego.silva $
 * $Date: 2022/02/01 07:11:30 $
 * $Log: aula0706.c,v $
 * Revision 1.1  2022/02/01 07:11:30  diego.silva
 * Initial revision
 *
 */

#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#define NUMERO_ARGUMENTOS 9

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 4
#define VALOR_MAXIMO_FLOAT_EXCEDIDO 4
#define POLIGONO_INVALIDO 5

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   useconds_t tempoCongelamento;
   unsigned short numeroLinhas, numeroColunas, indice;
   unsigned linhaPonto, colunaPonto, numeroVertices;
   float percentualDefeituoso, percentualApagados;
   char *validacao;
   tipoErros codigoRetorno;

   unsigned linhasVertices[NUMERO_MAXIMO_LINHAS];
   unsigned colunasVertices[NUMERO_MAXIMO_COLUNAS];
   tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>", argv[0]);
      printf(" <linha-ponto> <coluna-ponto> <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . .");
      printf(" <linha-vertice-N> <coluna-vertice-N>\n");
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 1; indice < NUMERO_ARGUMENTOS; indice++)
   {
      switch (indice)
      {
      case 1:
         tempoCongelamento = strtol(argv[indice], &validacao, 10);
         break;

      case 2:
         numeroLinhas = strtoul(argv[indice], &validacao, 10);
         break;

      case 3:
         numeroColunas = strtoul(argv[indice], &validacao, 10);
         break;

      case 4:
         percentualDefeituoso = strtof(argv[indice], &validacao);
         break;

      case 5:
         percentualApagados = strtof(argv[indice], &validacao);
         break;

      case 6:
         linhaPonto = strtoul(argv[indice], &validacao, 10);
         break;

      case 7:
         colunaPonto = strtoul(argv[indice], &validacao, 10);
         break;

      case 8:
         numeroVertices = strtoul(argv[indice], &validacao, 10);
         break;
      }

      if (errno == EINVAL)
      {
         printf("Base invalida.\n");
         exit(BASE_INVALIDA);
      }

      if (*validacao != END_OF_STRING)
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }
   }

   if (argc != NUMERO_ARGUMENTOS + 2 * numeroVertices)
   {
      printf("Numero de argumentos invalido\n");
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   if (numeroVertices < 3)
   {
      printf("Poligonos devem ter pelo menos 3 vertices.\n");
      exit(POLIGONO_INVALIDO);
   }

   for (indice = 0; indice < numeroVertices; indice++)
   {
      linhasVertices[indice] = strtoul(argv[9 + 2 * indice], &validacao, 10);

      if (*validacao != END_OF_STRING)
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }

      colunasVertices[indice] = strtoul(argv[10 + 2 * indice], &validacao, 10);

      if (*validacao != END_OF_STRING)
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }
   }

   codigoRetorno = GerarDistribuicaoInicial(monitor, numeroLinhas, numeroColunas, percentualDefeituoso, percentualApagados);

   switch (codigoRetorno)
   {

   case linhaInvalida:
      printf("Linha (%u) invalida. Digite numeros entre 0 e 250.\n", numeroLinhas);
      exit(ARGUMENTO_INVALIDO);
      break;

   case colunaInvalida:
      printf("Coluna (%u) invalida. Digite numeros entre 0 e 800.\n", numeroColunas);
      exit(ARGUMENTO_INVALIDO);
      break;

   case dimensaoInvalida:
      printf("Dimensoes invalidas.\n");
      break;

   case percentualInvalido:
      printf("Percentuais (%g e %g) invalidos. A soma dos percentuais nao deve ser maior do que 100.\n",
             percentualDefeituoso, percentualApagados);
      exit(ARGUMENTO_INVALIDO);
      break;
   case ok:
      LimparMonitor(monitor, numeroLinhas, numeroColunas);
      codigoRetorno = DesenharPoligono(monitor, numeroLinhas, numeroColunas, numeroVertices, linhasVertices, colunasVertices);

      if (codigoRetorno == pixelDefeito)
         printf("Pixel com defeito durante a execucao da funcao.\n");
      else if (codigoRetorno == numeroForaDaMatriz)
         printf("O ponto selecionado esta fora da matriz.\n");
      else if (codigoRetorno == ok)
      {
         MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas);
         PreencherPoligono(tempoCongelamento, monitor, numeroLinhas, numeroColunas, linhaPonto, colunaPonto);
      }

      break;

   default:
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   }

   return SUCESSO;
}

/* $RCSfile: aula0706.c,v $ */
