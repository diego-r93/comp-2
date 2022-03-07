/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao:Implementacao das funcoes CodificarBase16,
 * DecodificarBase16, CodificarBase32, DecodificarBase32
 * CodificarBase64 e DecodificarBase64.

 * $Author: diego.silva $
 * $Date: 2022/03/07 03:52:36 $
 * $Log: aula0801.c,v $
 * Revision 1.7  2022/03/07 03:52:36  diego.silva
 * *** empty log message ***
 *
 * Revision 1.6  2022/02/19 00:45:53  diego.silva
 * *** empty log message ***
 *
 * Revision 1.5  2022/02/18 23:33:42  diego.silva
 * *** empty log message ***
 *
 * Revision 1.4  2022/02/18 22:26:32  diego.silva
 * *** empty log message ***
 *
 * Revision 1.3  2022/02/17 20:14:06  diego.silva
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/17 19:37:17  diego.silva
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/16 22:59:04  diego.silva
 * Initial revision
 *
 */

#include "aula0801.h"
#include <string.h>

tipoErros
CodificarBase16(byte *entrada, unsigned long long numeroBytes, char *saida)
{
   unsigned long long indice;

   if (!entrada || !saida)
      return ponteiroNulo;

   if (numeroBytes == 0)
      return comprimentoInvalido;

   for (indice = 0; indice < numeroBytes; indice++)
   {
      saida[indice << 1] = TABELA_BASE_16[entrada[indice] >> 4];
      saida[(indice << 1) + 1] = TABELA_BASE_16[entrada[indice] & (0x0F)]; /* 0b00001111 */
   }
   saida[numeroBytes << 1] = END_OF_STRING;

   return ok;
}

tipoErros
DecodificarBase16(char *entrada, byte *saida, unsigned long long *numeroBytes)
{
   unsigned long long tamanhoEntrada, indiceEntrada = 0, indiceSaida = 0;
   unsigned short indice, contador;

   if (!entrada || !saida)
      return ponteiroNulo;

   if (!numeroBytes)
      return comprimentoInvalido;

   tamanhoEntrada = strlen(entrada);

   while (indiceEntrada < tamanhoEntrada)
   {
      for (indice = 0; TABELA_BASE_16[indice] != entrada[indiceEntrada]; indice++)
         ;

      indiceEntrada++;

      for (contador = 0; TABELA_BASE_16[contador] != entrada[indiceEntrada]; contador++)
         ;

      saida[indiceSaida++] = ((indice << 4) & 0xF0) | (contador & 0x0F);
      indiceEntrada++;
   }
   *numeroBytes = indiceSaida;

   return ok;
}

tipoErros
CodificarBase32(byte *entrada, unsigned long long numeroBytes, tipoAlfabetoBase32 alfabeto, char *saida)
{
   unsigned long long indice = 0, contador = 0;
   char stringBase32[32];

   if (!entrada || !saida)
      return ponteiroNulo;

   if (!numeroBytes)
      return comprimentoInvalido;

   strcpy(stringBase32, alfabeto == basico ? TABELA_BASE_32_BASICO : TABELA_BASE_32_ESTENDIDO);

   for (indice = 0; numeroBytes - indice >= 5; indice += 5)
   {
      saida[contador] = stringBase32[entrada[indice] >> 3 & 0x1F];
      saida[contador + 1] = stringBase32[(entrada[indice] << 2 & 0x1C) | (entrada[indice + 1] >> 6 & 0x03)];
      saida[contador + 2] = stringBase32[(entrada[indice + 1] >> 1 & 0x1F)];
      saida[contador + 3] = stringBase32[(entrada[indice + 1] << 4 & 0x10) | (entrada[indice + 2] >> 4 & 0x0F)];
      saida[contador + 4] = stringBase32[(entrada[indice + 2] << 1 & 0x1E) | (entrada[indice + 3] >> 7 & 0x01)];
      saida[contador + 5] = stringBase32[(entrada[indice + 3] >> 2 & 0x1F)];
      saida[contador + 6] = stringBase32[(entrada[indice + 3] << 3 & 0x18) | (entrada[indice + 4] >> 5 & 0x07)];
      saida[contador + 7] = stringBase32[(entrada[indice + 4] & 0x1F)];
      contador += 8;
   }

   if (numeroBytes % 5 == 4)
   {
      saida[contador] = stringBase32[entrada[indice] >> 3 & 0x1F];
      saida[contador + 1] = stringBase32[(entrada[indice] << 2 & 0x1C) | (entrada[indice + 1] >> 6 & 0x03)];
      saida[contador + 2] = stringBase32[(entrada[indice + 1] >> 1 & 0x1F)];
      saida[contador + 3] = stringBase32[(entrada[indice + 1] << 4 & 0x10) | (entrada[indice + 2] >> 4 & 0x0F)];
      saida[contador + 4] = stringBase32[(entrada[indice + 2] << 1 & 0x1E) | (entrada[indice + 3] >> 7 & 0x01)];
      saida[contador + 5] = stringBase32[(entrada[indice + 3] >> 2 & 0x1F)];
      saida[contador + 6] = stringBase32[(entrada[indice + 3] << 3 & 0x18)];
      saida[contador + 7] = '=';
      contador += 8;
   }

   if (numeroBytes % 5 == 3)
   {
      saida[contador] = stringBase32[entrada[indice] >> 3 & 0x1F];
      saida[contador + 1] = stringBase32[(entrada[indice] << 2 & 0x1C) | (entrada[indice + 1] >> 6 & 0x03)];
      saida[contador + 2] = stringBase32[(entrada[indice + 1] >> 1 & 0x1F)];
      saida[contador + 3] = stringBase32[(entrada[indice + 1] << 4 & 0x10) | (entrada[indice + 2] >> 4 & 0x0F)];
      saida[contador + 4] = stringBase32[(entrada[indice + 2] << 1 & 0x1E)];
      saida[contador + 5] = '=';
      saida[contador + 6] = '=';
      saida[contador + 7] = '=';
      contador += 8;
   }

   if (numeroBytes % 5 == 2)
   {
      saida[contador] = stringBase32[entrada[indice] >> 3 & 0x1F];
      saida[contador + 1] = stringBase32[(entrada[indice] << 2 & 0x1C) | (entrada[indice + 1] >> 6 & 0x03)];
      saida[contador + 2] = stringBase32[(entrada[indice + 1] >> 1 & 0x1F)];
      saida[contador + 3] = stringBase32[(entrada[indice + 1] << 4 & 0x10)];
      saida[contador + 4] = '=';
      saida[contador + 5] = '=';
      saida[contador + 6] = '=';
      saida[contador + 7] = '=';
      contador += 8;
   }

   if (numeroBytes % 5 == 1)
   {
      saida[contador] = stringBase32[entrada[indice] >> 3 & 0x1F];
      saida[contador + 1] = stringBase32[(entrada[indice] << 2 & 0x1C)];
      saida[contador + 2] = '=';
      saida[contador + 3] = '=';
      saida[contador + 4] = '=';
      saida[contador + 5] = '=';
      saida[contador + 6] = '=';
      saida[contador + 7] = '=';
      contador += 8;
   }

   saida[contador] = END_OF_STRING;

   return ok;
}

int EscolheIndiceBase32(char entrada, tipoAlfabetoBase32 alfabeto)
{
   unsigned indice;
   char stringBase32[32];

   strcpy(stringBase32, alfabeto == basico ? TABELA_BASE_32_BASICO : TABELA_BASE_32_ESTENDIDO);

   for (indice = 0; indice < strlen(stringBase32); indice++)
      if (entrada == stringBase32[indice])
         return indice;

   return -1;
}

tipoErros
DecodificarBase32(char *entrada, tipoAlfabetoBase32 alfabeto, byte *saida, unsigned long long *numeroBytes)
{
   unsigned long long tamanhoEntrada, indiceEntrada = 0, indiceSaida = 0;
   unsigned short numeroPads = 0;
   char stringBase32[32];

   if (!entrada || !saida)
      return ponteiroNulo;

   if (!numeroBytes)
      return comprimentoInvalido;

   tamanhoEntrada = strlen(entrada);

   strcpy(stringBase32, alfabeto == basico ? TABELA_BASE_32_BASICO : TABELA_BASE_32_ESTENDIDO);

   while (indiceEntrada < tamanhoEntrada)
   {
      saida[indiceSaida + 0] = (byte)((EscolheIndiceBase32(entrada[indiceEntrada], alfabeto) << 3) & (0xF8)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 1], alfabeto) >> 2) & (0x07));

      saida[indiceSaida + 1] = (byte)((EscolheIndiceBase32(entrada[indiceEntrada + 1], alfabeto) << 6) & (0xC0)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 2], alfabeto) << 1) & (0x3E)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 3], alfabeto) >> 4) & (0x01));

      saida[indiceSaida + 2] = (byte)((EscolheIndiceBase32(entrada[indiceEntrada + 3], alfabeto) << 4) & (0xF0)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 4], alfabeto) >> 1) & (0x0F));

      saida[indiceSaida + 3] = (byte)((EscolheIndiceBase32(entrada[indiceEntrada + 4], alfabeto) << 7) & (0x80)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 5], alfabeto) << 2) & (0x7C)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 6], alfabeto) >> 3) & (0x03));

      saida[indiceSaida + 4] = (byte)((EscolheIndiceBase32(entrada[indiceEntrada + 6], alfabeto) << 5) & (0xE0)) |
                               ((EscolheIndiceBase32(entrada[indiceEntrada + 7], alfabeto) & (0x1F)));

      indiceSaida += 5;
      indiceEntrada += 8;
   }
   *numeroBytes = indiceSaida;

   for (indiceEntrada = 0; indiceEntrada < tamanhoEntrada; indiceEntrada++)
      if (entrada[indiceEntrada] == '=')
         numeroPads++;

   switch (numeroPads)
   {
   case 0:
      break;
   case 1:
      *numeroBytes -= 1;
      break;
   case 3:
      *numeroBytes -= 2;
      break;
   case 4:
      *numeroBytes -= 3;
      break;
   case 6:
      *numeroBytes -= 4;
      break;
   default:
      return argumentoInvalido;
   }

   return ok;
}

tipoErros
CodificarBase64(byte *entrada, unsigned long long numeroBytes, tipoFinalLinha finalLinha, char *saida)
{
   unsigned indiceSaida = 0;
   unsigned indiceEntrada = 0;

   if (!entrada || !saida)
      return ponteiroNulo;

   if (!numeroBytes)
      return comprimentoInvalido;

   while (numeroBytes >= 3)
   {
      saida[indiceSaida] = TABELA_BASE_64[(entrada[indiceEntrada] >> 2) & (0x3F)];

      saida[indiceSaida + 1] = TABELA_BASE_64[(entrada[indiceEntrada] << 4 | entrada[indiceEntrada + 1] >> 4) & (0x3F)];

      saida[indiceSaida + 2] = TABELA_BASE_64[(entrada[indiceEntrada + 1] << 2 | entrada[indiceEntrada + 2] >> 6) & (0x3F)];

      saida[indiceSaida + 3] = TABELA_BASE_64[(entrada[indiceEntrada + 2]) & (0x3F)];

      indiceSaida += 4;

      if (indiceSaida % COMPRIMENTO_MAXIMO == 0)
      {
         saida[indiceSaida] = '\r';
         saida[indiceSaida + 1] = '\n';
         indiceSaida += 2;
      }

      indiceEntrada += 3;
      numeroBytes -= 3;
   }

   if (finalLinha == habilitado)
   {
      if (numeroBytes == 2)
      {
         saida[indiceSaida] = TABELA_BASE_64[(entrada[indiceEntrada] >> 2) & (0x3F)];

         saida[indiceSaida + 1] = TABELA_BASE_64[(entrada[indiceEntrada] << 4 | entrada[indiceEntrada + 1] >> 4) & (0x3F)];

         saida[indiceSaida + 2] = TABELA_BASE_64[(entrada[indiceEntrada + 1] << 2) & (0x3C)];

         saida[indiceSaida + 3] = '=';

         indiceSaida += 4;

         if (indiceSaida % COMPRIMENTO_MAXIMO == 0)
         {
            saida[indiceSaida] = '\r';
            saida[indiceSaida + 1] = '\n';
            indiceSaida += 2;
         }

         indiceEntrada += 2;
      }

      if (numeroBytes == 1)
      {

         saida[indiceSaida] = TABELA_BASE_64[(entrada[indiceEntrada] >> 2) & (0x3F)];

         saida[indiceSaida + 1] = TABELA_BASE_64[(entrada[indiceEntrada] << 4 & (0x30))];

         saida[indiceSaida + 2] = '=';

         saida[indiceSaida + 3] = '=';

         indiceSaida += 4;

         if (indiceSaida % COMPRIMENTO_MAXIMO == 0)
         {
            saida[indiceSaida] = '\r';
            saida[indiceSaida + 1] = '\n';
            indiceSaida += 2;
         }

         indiceEntrada += 1;
      }
   }

   saida[indiceSaida] = END_OF_STRING;
   indiceSaida += 1;

   return ok;
}

int EscolheIndiceBase64(char number)
{
   unsigned indice;

   for (indice = 0; indice < strlen(TABELA_BASE_64); indice++)
      if (number == TABELA_BASE_64[indice])
         return indice;

   return -1;
}

tipoErros
DecodificarBase64(char *entrada, tipoFinalLinha finalLinha, byte *saida, unsigned long long *numeroBytes)
{
   unsigned tamanhoEntrada = strlen(entrada);
   unsigned indiceSaida = 0;
   unsigned indiceEntrada = 0;
   unsigned tamanhoMaximo = 0;

   if (!entrada || !saida)
      return ponteiroNulo;

   if (!numeroBytes)
      return comprimentoInvalido;

   if (entrada[tamanhoEntrada - 1] == '=')
      tamanhoMaximo = 4;

   while (tamanhoEntrada > tamanhoMaximo)
   {
      if ((indiceEntrada % COMPRIMENTO_MAXIMO) == 0 && indiceEntrada != 0)
         indiceEntrada += 2;

      if (tamanhoEntrada > COMPRIMENTO_MAXIMO && finalLinha == habilitado)
         saida[indiceSaida] = '=';

      saida[indiceSaida] = (byte)((EscolheIndiceBase64(entrada[indiceEntrada] << 2)) & (0xFC)) | ((EscolheIndiceBase64(entrada[indiceEntrada + 1] >> 4) & (0x03)));

      saida[indiceSaida + 1] = (byte)(EscolheIndiceBase64(entrada[indiceEntrada + 1]) << 4 | ((EscolheIndiceBase64(entrada[indiceEntrada + 2] << 2) >> 4)));

      saida[indiceSaida + 2] = (byte)(EscolheIndiceBase64(entrada[indiceEntrada + 2]) << 6 | EscolheIndiceBase64(entrada[indiceEntrada + 3]));

      indiceSaida += 3;
      indiceEntrada += 4;
      if (indiceEntrada % 82 == 0)
         tamanhoEntrada -= 2;

      tamanhoEntrada -= 4;
   }

   if (tamanhoMaximo == 4)
   {
      if (entrada[strlen(entrada) - 2] == '=')
      {
         if ((indiceEntrada % COMPRIMENTO_MAXIMO) == 0 && indiceEntrada != 0)
            indiceEntrada += 2;

         saida[indiceSaida] = (byte)(((EscolheIndiceBase64(entrada[indiceEntrada]) << 2) & (0xFC)) | ((EscolheIndiceBase64(entrada[indiceEntrada + 1]) >> 4) & (0x03)));

         indiceSaida++;
      }

      else
      {
         if ((indiceEntrada % COMPRIMENTO_MAXIMO) == 0 && indiceEntrada != 0)
            indiceEntrada += 2;

         saida[indiceSaida] = (byte)(((EscolheIndiceBase64(entrada[indiceEntrada]) << 2) & (0xFC)) | ((EscolheIndiceBase64(entrada[indiceEntrada + 1]) >> 4) & (0x03)));

         saida[indiceSaida + 1] = (byte)(EscolheIndiceBase64(entrada[indiceEntrada + 1]) << 4 | ((EscolheIndiceBase64(entrada[indiceEntrada + 2]) << 2) >> 4));

         indiceSaida += 2;
      }
   }
   *numeroBytes = indiceSaida;

   return ok;
}

/* $RCSfile: aula0801.c,v $ */
