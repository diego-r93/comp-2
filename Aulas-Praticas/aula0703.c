/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para as funcoes
 * MostrarMonitor, GerarDistribuicaoInicial e
 * LimparMonitor.

 * $Author: diego.silva $
 * $Date: 2022/02/01 03:31:08 $
 * $Log: aula0703.c,v $
 * Revision 1.1  2022/02/01 03:31:08  diego.silva
 * Initial revision
 *
 */

#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>

#define NUMERO_ARGUMENTOS 6

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
   float percentualDefeituoso, percentualApagados;
   unsigned long argumentoInt;
   float argumentoFloat;
   char *validacao;
   tipoErros codigoRetorno;

   tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

   if (argc < NUMERO_ARGUMENTOS)
   {
      printf("Numero de argumentos invalido\n");
      printf("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n", argv[0]);
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

   for (; indice < NUMERO_ARGUMENTOS; indice++)
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
      MostrarMonitor(tempoCongelamento, monitor, numeroLinhas, numeroColunas);
      break;

   default:
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   }

   return SUCESSO;
}

/* $RCSfile: aula0703.c,v $ */
