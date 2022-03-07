/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para as funcoes
 * getopt_long e getsubopt.

 * $Author: diego.silva $
 * $Date: 2022/02/25 18:14:16 $
 * $Log: aula0907.c,v $
 * Revision 1.1  2022/02/25 18:14:16  diego.silva
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

typedef enum
{
   argumentoInput,
   argumentoOutput,
} indicesArgumentos;

int main(int argc, char **argv)
{
   int opcaoCurta;
   int opcaoLonga;
   int indiceArgumento;
   char *argumentos, *valorArgumento;
   char *opcoesCurtas = "dDhHsSuU";
   char *original, *convertido = NULL;
   tipoErros codigoRetorno;
   struct option opcoesLongas[5] =
       {
           {"dos", 0, NULL, 'd'},
           {"help", 0, NULL, 'h'},
           {"show", 0, NULL, 's'},
           {"unix", 0, NULL, 'u'},
           {NULL, 0, NULL, 0} /* demarca o final do vetor */
       };

   char *nomesArgumentos[3] =
       {
           "input",
           "output",
           NULL,
       };

   opterr = 0; /* FALSO */

   while ((opcaoCurta = getopt_long(argc, argv, opcoesCurtas, opcoesLongas, &opcaoLonga)) != -1)
   {
      switch (opcaoCurta)
      {
      case 'd':
      case 'D':
         while (optind < argc)
         {
            argumentos = argv[optind];
            indiceArgumento = getsubopt(&argumentos, nomesArgumentos, &valorArgumento);

            switch (indiceArgumento)
            {
            case argumentoInput:
               original = valorArgumento;
               break;

            case argumentoOutput:
               convertido = valorArgumento;
               break;

            default:
               printf("Opcao invalida \"%s\"\n", argv[optind]);
               break;
            }

            optind++;
         }
         printf("Convertendo arquivo \"%s\" do formato Unix para o formado Microsoft.\n\n", original);
         codigoRetorno = ConverterArquivoFormatoUnixParaFormatoDos(original, convertido);
         break;

      case 'h':
      case 'H':
         ShowHelp(argv[0]);
         break;

      case 's':
      case 'S':
         while (optind < argc)
         {
            argumentos = argv[optind];
            indiceArgumento = getsubopt(&argumentos, nomesArgumentos, &valorArgumento);

            switch (indiceArgumento)
            {
            case argumentoInput:
               original = valorArgumento;
               break;

            default:
               printf("Opcao invalida \"%s\"\n", argv[optind]);
               break;
            }

            optind++;
         }
         printf("Exibindo o conteudo do arquivo \"%s\":\n\n", original);
         codigoRetorno = ExibirConteudoArquivo(original);
         break;

      case 'u':
      case 'U':
         while (optind < argc)
         {
            argumentos = argv[optind];
            indiceArgumento = getsubopt(&argumentos, nomesArgumentos, &valorArgumento);

            switch (indiceArgumento)
            {
            case argumentoInput:
               original = valorArgumento;
               break;

            case argumentoOutput:
               convertido = valorArgumento;
               break;

            default:
               printf("Opcao invalida \"%s\"\n", argv[optind]);
               break;
            }

            optind++;
         }
         printf("Convertendo arquivo \"%s\" do formato Microsoft para o formado Unix.\n\n", original);
         codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix(original, convertido);
         break;

      default:
         printf("Opcao invalida \"%c\".\n", opcaoCurta);
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

/* $RCSfile: aula0907.c,v $ */
