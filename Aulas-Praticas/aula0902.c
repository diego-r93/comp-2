/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para a funcao
 * ExibirConteudoArquivo.

 * $Author: diego.silva $
 * $Date: 2022/02/23 02:48:22 $
 * $Log: aula0902.c,v $
 * Revision 1.2  2022/02/23 02:48:22  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/22 23:38:32  diego.silva
 * Initial revision
 *
 */

#include "aula0901.h"

#include <stdlib.h>
#include <stdio.h>

#define NUMERO_ARGUMENTOS 2

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2

int main(int argc, char *argv[])
{
   char *nomeArquivo;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso %s <nome do arquivo>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   nomeArquivo = argv[1];

   codigoRetorno = ExibirConteudoArquivo(nomeArquivo);

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

/* $RCSfile: aula0902.c,v $ */
