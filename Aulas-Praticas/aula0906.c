/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para a funcao getopt_long.

 * $Author: diego.silva $
 * $Date: 2022/02/25 03:33:18 $
 * $Log: aula0906.c,v $
 * Revision 1.1  2022/02/25 03:33:18  diego.silva
 * Initial revision
 *
 */

#include "aula0901.h"

#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#define SUCESSO 0
#define HELP -1

void ShowHelp(char *name)
{
   fprintf(stderr, "\
            [uso]: %s <opcoes> <argumentos opcionais>\n\
            -d | -D | --dos    Converter um arquivo texto do formato Unix para o formato Microsoft (DOS).\n\
            -h | -H | --help   Exibir uma mensagem contendo as informações sobre o uso do programa.\n\
            -s | -S | --show   Exibir o conteúdo do arquivo.\n\
            -u | -U | --unix   Converter um arquivo texto do formato Microsoft para o formato Unix.\n",
           name);
   exit(HELP);
}

int main(int argc, char **argv)
{
   tipoErros codigoRetorno;
   int opcaoCurta;
   char *opcoesCurtas = "dDhHsSuU";
   struct option opcoesLongas[5] =
       {
           {"dos", 0, NULL, 'd'},
           {"help", 0, NULL, 'h'},
           {"show", 0, NULL, 's'},
           {"unix", 0, NULL, 'u'},
           {NULL, 0, NULL, 0} /* demarca o final do vetor */
       };
   int auxiliar;

   opterr = 0; /* FALSO */

   while ((opcaoCurta = getopt_long(argc, argv, opcoesCurtas, opcoesLongas, &auxiliar)) != -1)
   {
      switch (opcaoCurta)
      {
      case 'd':
      case 'D':
         printf("Convertendo arquivo \"%s\" do formato Unix para o formado Microsoft.\n\n", argv[optind]);
         codigoRetorno = ConverterArquivoFormatoUnixParaFormatoDos(argv[optind], argv[optind + 1]);
         break;

      case 'h':
      case 'H':
         ShowHelp(argv[0]);
         break;

      case 's':
      case 'S':
         printf("Exibindo o conteudo do arquivo \"%s\":\n\n", argv[optind]);
         codigoRetorno = ExibirConteudoArquivo(argv[optind]);
         break;

      case 'u':
      case 'U':
         printf("Convertendo arquivo \"%s\" do formato Microsoft para o formado Unix.\n\n", argv[optind]);
         codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix(argv[optind], argv[optind + 1]);
         break;

      default:
         printf("Opcao invalida.\n");
      }
   }

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

/* $RCSfile: aula0906.c,v $ */
