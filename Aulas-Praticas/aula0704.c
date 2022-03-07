/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: rograma de testes para as funcoes
 * MostrarMonitor, GerarDistribuicaoInicial,
 * LimparMonitor e DesenharReta.

 * $Author: diego.silva $
 * $Date: 2022/02/01 04:40:35 $
 * $Log: aula0704.c,v $
 * Revision 1.1  2022/02/01 04:40:35  diego.silva
 * Initial revision
 *
 */

#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#define NUMERO_ARGUMENTOS 10

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define BASE_INVALIDA 3
#define VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO 4
#define VALOR_MAXIMO_FLOAT_EXCEDIDO 4

#define END_OF_STRING '\0'

int main(int argc, char *argv[])
{
   useconds_t tempoCongelamento;
   unsigned short numeroLinhas, numeroColunas, indice;
   unsigned short linhaPonto1, colunaPonto1, linhaPonto2, colunaPonto2;
   float percentualDefeituoso, percentualApagados;
   unsigned long argumentoInt;
   float argumentoFloat;
   char *validacao;
   tipoErros codigoRetorno;

   tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>", argv[0]);
      printf(" <linha-ponto-1> <coluna-ponto-1> <linha-ponto-2> <coluna-ponto-2>\n");
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   for (indice = 1; indice <= 3; indice++)
   {
      argumentoInt = strtoul(argv[indice], &validacao, 10);

      if (errno == EINVAL)
      {
         printf("Base invalida.\n");
         exit(BASE_INVALIDA);
      }

      if (errno == ERANGE)
      {
         printf("Valor maximo permitido (%lu) do tipo unsigned long foi excedido.\n", ULONG_MAX);
         exit(VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
      }

      if (*validacao != END_OF_STRING)
      {
         printf("\nArgumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("\nArgumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }

      if (indice == 1)
         tempoCongelamento = (useconds_t)argumentoInt;
      else if (indice == 2)
         numeroLinhas = (unsigned short)argumentoInt;
      else if (indice == 3)
         numeroColunas = (unsigned short)argumentoInt;
   }

   for (; indice < 6; indice++)
   {
      argumentoFloat = strtof(argv[indice], &validacao);

      if (errno == ERANGE)
      {
         printf("Valor maximo permitido (%g) do tipo float foi excedido.\n", FLT_MAX);
         exit(VALOR_MAXIMO_FLOAT_EXCEDIDO);
      }

      if (*validacao != END_OF_STRING)
      {
         printf("Argumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("\nArgumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }

      if (indice == 4)
         percentualDefeituoso = argumentoFloat;
      else if (indice == 5)
         percentualApagados = argumentoFloat;
   }

   for (; indice < NUMERO_ARGUMENTOS; indice++)
   {
      argumentoInt = strtoul(argv[indice], &validacao, 10);

      if (errno == EINVAL)
      {
         printf("Base invalida.\n");
         exit(BASE_INVALIDA);
      }

      if (errno == ERANGE)
      {
         printf("Valor maximo permitido (%lu) do tipo unsigned long foi excedido.\n", ULONG_MAX);
         exit(VALOR_MAXIMO_UNSIGNED_LONG_EXCEDIDO);
      }

      if (*validacao != END_OF_STRING)
      {
         printf("\nArgumento n#%u contem caractere invalido: (%c)\n", indice, *validacao);
         exit(ARGUMENTO_INVALIDO);
      }

      if (argv[indice][0] == '-')
      {
         printf("\nArgumento n#%u contem caractere invalido: (%c)\n", indice, argv[indice][0]);
         exit(ARGUMENTO_INVALIDO);
      }

      if (indice == 6)
         linhaPonto1 = (unsigned short)argumentoInt;
      else if (indice == 7)
         colunaPonto1 = (unsigned short)argumentoInt;
      else if (indice == 8)
         linhaPonto2 = (unsigned short)argumentoInt;
      else if (indice == 9)
         colunaPonto2 = (unsigned short)argumentoInt;
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
      MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas);
      LimparMonitor(monitor, numeroLinhas, numeroColunas);
      codigoRetorno = DesenharReta(monitor, numeroLinhas, numeroColunas, linhaPonto1, colunaPonto1, linhaPonto2, colunaPonto2);

      if (codigoRetorno == pixelDefeito)
         printf("Pixel com defeito durante a execucao da funcao.\n");
      else if (codigoRetorno == numeroForaDaMatriz)
         printf("O ponto selecionado esta fora da matriz.\n");
      else if (codigoRetorno == ok)
         MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas);
      break;

   default:
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   }

   return SUCESSO;
}

/* $RCSfile: aula0704.c,v $ */
