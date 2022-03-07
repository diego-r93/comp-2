/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para a funcao
 * ConverterArquivoFormatoDosParaFormatoUnix

 * $Author: diego.silva $
 * $Date: 2022/02/25 03:14:02 $
 * $Log: aula0904.c,v $
 * Revision 1.2  2022/02/25 03:14:02  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/23 03:02:44  diego.silva
 * Initial revision
 *
 */

#include "aula0901.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMERO_ARGUMENTOS 3

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO_EXCEDIDO 2

int main(int argc, char *argv[])
{
   char *original, *convertido;
   tipoErros codigoRetorno;

   if (argc < 2 || argc > 3)
   {
      printf("Uso %s <nome-arquivo-origem> <nome-arquivo-destino-opcional>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   if (strlen(argv[1]) > (COMPRIMENTO_MAXIMO_NOME_ARQUIVO - COMPRIMENTO_NOME_BACKUP - 7))
   {
      printf("Comprimento do nome do arquivo origem excede o valor maximo.\n");
      exit(COMPRIMENTO_MAXIMO_NOME_ARQUIVO_EXCEDIDO);
   }

   if (argc == 3 && strlen(argv[2]) > (COMPRIMENTO_MAXIMO_NOME_ARQUIVO))
   {
      printf("Comprimento do nome do arquivo destino excede o valor maximo.\n");
      exit(COMPRIMENTO_MAXIMO_NOME_ARQUIVO_EXCEDIDO);
   }

   original = argv[1];

   convertido = argc == 2 ? NULL : argv[2];

   codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix(original, convertido);

   switch (codigoRetorno)
   {
   case ok:
      break;
   case argumentoInvalido:
      printf("Erro numero %u. O nome do arquivo não pode ser vazio.\n", codigoRetorno);
      break;
   case erroAbrindoArquivo:
      printf("Erro numero %u. Não foi possível encontrar o arquivo.\n", codigoRetorno);
      break;
   case erroFechandoArquivo:
      printf("Erro numero %u. Não foi possível fechar o arquivo.\n", codigoRetorno);
      break;
   }

   return SUCESSO;
}

/* $RCSfile: aula0904.c,v $ */
