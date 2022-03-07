/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Programa de testes para CodificarBase64
 * utilizando arquivos.

 * $Author: diego.silva $
 * $Date: 2022/02/19 01:11:44 $
 * $Log: aula0808.c,v $
 * Revision 1.1  2022/02/19 01:11:44  diego.silva
 * Initial revision
 *
 */

#include "aula0801.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS 3

#define SUCESSO 0
#define NUMERO_ARGUMENTOS_INVALIDO 1
#define ARGUMENTO_INVALIDO 2
#define ABRIR_ARQUIVO_INVALIDO 3
#define ESCREVER_ARQUIVO_INVALIDO 4
#define ALOCAR_MEMORIA_INVALIDO 5

int main(int argc, char *argv[])
{
   unsigned long long indice = 0;
   FILE *leitura, *escrita;
   byte aux;
   char *saida;
   byte *entrada;
   tipoErros codigoRetorno;

   if (argc != NUMERO_ARGUMENTOS)
   {
      printf("Uso %s <nome do arquivo>  <nome do arquivo codificado>\n", argv[0]);
      exit(NUMERO_ARGUMENTOS_INVALIDO);
   }

   if ((leitura = fopen(argv[1], "r")) == NULL)
   {
      printf("Erro ao abrir o arquivo %s\n", argv[1]);
      printf("Erro (#%i) : %s\n", errno, strerror(errno));
      exit(ABRIR_ARQUIVO_INVALIDO);
   }

   if ((escrita = fopen(argv[2], "w")) == NULL)
   {
      printf("Erro ao abrir o arquivo %s\n", argv[2]);
      printf("Erro (#%i) : %s\n", errno, strerror(errno));
      fclose(leitura);
      exit(ABRIR_ARQUIVO_INVALIDO);
   }

   while (fread(&aux, 1, 1, leitura) > 0)
   {
      if (aux != '\n' && aux != END_OF_STRING)
         indice++;
   }

   fclose(leitura);

   if ((leitura = fopen(argv[1], "r")) == NULL)
   {
      printf("Erro ao abrir o arquivo %s\n", argv[1]);
      printf("Erro (#%i) : %s \n", errno, strerror(errno));
      exit(ABRIR_ARQUIVO_INVALIDO);
   }

   if (!(entrada = malloc(1 * indice)))
   {
      printf("Erro de memoria\n");
      exit(ALOCAR_MEMORIA_INVALIDO);
   }

   indice = 0;

   while (fread(&aux, 1, 1, leitura) > 0)
   {
      if (aux != '\n' && aux != END_OF_STRING)
      {
         entrada[indice] = aux;
         indice++;
      }
   }

   if (!(saida = malloc(((indice / 3) * 4) + ((indice % 3) * 4))))
   {
      printf("Erro de memoria\n");
      exit(ALOCAR_MEMORIA_INVALIDO);
   }

   codigoRetorno = CodificarBase64(entrada, indice, habilitado, saida);

   if (codigoRetorno != ok)
      printf("Erro executando a funcao. Erro numero %u.\n", codigoRetorno);
   else
   {
      fprintf(escrita, "%s", saida);
      if (ferror(escrita))
      {
         printf("Erro ao escrever no arquivo %s\n", argv[2]);
         printf("Erro (#%i) : %s \n", errno, strerror(errno));
         fclose(leitura);
         fclose(escrita);
         exit(ESCREVER_ARQUIVO_INVALIDO);
      }
   }

   fclose(leitura);
   fclose(escrita);
   free(entrada);
   free(saida);

   return SUCESSO;
}

/* $RCSfile: aula0808.c,v $ */
