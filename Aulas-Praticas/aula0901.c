/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Implementacao das funcoes
 * ExibirConteudoArquivo, ConverterArquivoFormatoUnixParaFormatoDos
 * e ConverterArquivoFormatoDosParaFormatoUnix

 * $Author: diego.silva $
 * $Date: 2022/02/23 03:02:44 $
 * $Log: aula0901.c,v $
 * Revision 1.3  2022/02/23 03:02:44  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/23 02:50:44  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/22 23:38:32  diego.silva
 * Initial revision
 *
 */

#include "aula0901.h"

#include <stdio.h>
#ifdef __linux__
#include <stdio_ext.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <time.h>

tipoErros
ExibirConteudoArquivo(char *nomeArquivo)
{
   FILE *leitura;
   byte buffer[COMPRIMENTO_MAXIMO];
   size_t tamanho;
   int indice, posicao = 0;

   if (!nomeArquivo)
      return argumentoInvalido;

   if (!(leitura = fopen(nomeArquivo, "r")))
      return erroAbrindoArquivo;

   while ((tamanho = fread(buffer, 1, sizeof buffer, leitura)) > 0)
   {
      printf("%08X |", posicao);
      posicao += COMPRIMENTO_MAXIMO;

      for (indice = 0; indice < COMPRIMENTO_MAXIMO; indice++)
         if (buffer[indice] == (byte)EOF)
            printf("   ");
         else
            printf(" %02X", buffer[indice]);

      printf(" | ");
      for (indice = 0; indice < COMPRIMENTO_MAXIMO; indice++)
         if (buffer[indice] == (byte)EOF)
            printf(" ");
         else
            printf("%c", buffer[indice] >= 0x20 && buffer[indice] < 0x7F ? buffer[indice] : '.');
      printf("\n");

      for (indice = 0; indice < COMPRIMENTO_MAXIMO; indice++)
         buffer[indice] = (byte)EOF;
   }
   printf("\n");

   fclose(leitura);

   return ok;
}

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos(char *original, char *convertido)
{
   FILE *leitura, *escrita;
   time_t myTime = time(NULL);
   struct tm tm = *localtime(&myTime);
   int arquivoTemporario;
   char buffer[COMPRIMENTO_MAXIMO_BUFFER];
   char nomeArquivoTemporario[COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1 + COMPRIMENTO_NOME_BACKUP];
   char tempName[COMPRIMENTO_NOME_BACKUP];

   if (!original)
      return argumentoInvalido;

   sprintf(tempName, "%sbackup-%d%02d%02d_%02d%02d%02d", original, tm.tm_year + 1900,
           tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

   strcpy(nomeArquivoTemporario, tempName);
   strcat(nomeArquivoTemporario, ".XXXXXX");

   if (!(leitura = fopen(original, "r")))
      return erroAbrindoArquivo;

   if (!convertido)
   {
      arquivoTemporario = mkstemp(nomeArquivoTemporario);
      printf("Nome temporario: \"%s\"\n", nomeArquivoTemporario);

      if ((escrita = fdopen(arquivoTemporario, "w")) == NULL)
      {
         return erroAbrindoArquivo;

         if (!(fclose(leitura)))
            return erroFechandoArquivo;
      }
   }
   else if (!(escrita = fopen(convertido, "w")))
      return erroAbrindoArquivo;

   while (fgets(buffer, COMPRIMENTO_MAXIMO_BUFFER, leitura))
   {
      if (buffer[strlen(buffer) - 1] == '\n')
      {
         buffer[strlen(buffer) - 1] = '\0';
         fprintf(escrita, "%s\r\n", buffer); /* sempre que tiver \n bota o \r\n */
      }

      else                               /* nao encontrou o \n. seria o caso que a linha tem mais que 1024 caracteres */
         fprintf(escrita, "%s", buffer); /* entao nao bota o \r\n porque nao pulou de linha */
   }

   fclose(leitura);
   fclose(escrita);

   return ok;
}

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix(char *original, char *convertido)
{

   FILE *leitura, *escrita;
   time_t myTime = time(NULL);
   struct tm tm = *localtime(&myTime);
   int arquivoTemporario;
   char buffer[COMPRIMENTO_MAXIMO_BUFFER];
   char nomeArquivoTemporario[COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1 + COMPRIMENTO_NOME_BACKUP];
   char tempName[COMPRIMENTO_NOME_BACKUP];

   if (!original)
      return argumentoInvalido;

   sprintf(tempName, "%sbackup-%d%02d%02d_%02d%02d%02d", original, tm.tm_year + 1900,
           tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

   strcpy(nomeArquivoTemporario, tempName);
   strcat(nomeArquivoTemporario, ".XXXXXX");

   if (!(leitura = fopen(original, "r")))
      return erroAbrindoArquivo;

   if (!convertido)
   {
      arquivoTemporario = mkstemp(nomeArquivoTemporario);
      printf("Nome temporario: \"%s\"\n", nomeArquivoTemporario);

      if ((escrita = fdopen(arquivoTemporario, "w")) == NULL)
      {
         return erroAbrindoArquivo;

         if (!(fclose(leitura)))
            return erroFechandoArquivo;
      }
   }
   else if (!(escrita = fopen(convertido, "w")))
      return erroAbrindoArquivo;

   while (fgets(buffer, COMPRIMENTO_MAXIMO_BUFFER, leitura))
   {
      if ((buffer[strlen(buffer) - 1] == '\n') && (buffer[strlen(buffer) - 2] == '\r'))
      {
         buffer[strlen(buffer) - 2] = '\0';
         fprintf(escrita, "%s\n", buffer); /* sempre que tiver \r\n bota o \n */
      }

      /* fgets nao encontrou o \r\n. seria o caso que a linha tem mais que 1024 caracteres */
      /* entao nao bota o\n porque nao pulou de linha */
      else
         fprintf(escrita, "%s", buffer);
   }

   fclose(leitura);
   fclose(escrita);

   return ok;
}

/* $RCSfile: aula0901.c,v $ */
