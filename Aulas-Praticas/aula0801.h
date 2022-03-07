/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipos das funcoes
 * CodificarBase16, DecodificarBase16, CodificarBase32,
 * DecodificarBase32, CodificarBase64 e DecodificarBase64.

 * $Author: diego.silva $
 * $Date: 2022/02/19 00:45:53 $
 * $Log: aula0801.h,v $
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

#ifndef _AULA0801_
#define _AULA0801_ "@(#)aula08.h $Revision: 1.6 $"

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined(__FreeBSD__) && defined(__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#define __LONG_LONG_SUPPORTED
#endif

#define TABELA_BASE_16 "0123456789ABCDEF"

#define TABELA_BASE_32_BASICO "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
#define TABELA_BASE_32_ESTENDIDO "0123456789ABCDEFGHIJKLMNOPQRSTUV"

#define TABELA_BASE_64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

#define COMPRIMENTO_MAXIMO 76

#define END_OF_STRING '\0'

typedef unsigned char byte;

typedef enum
{
   ok,
   argumentoInvalido,
   ponteiroNulo,
   comprimentoInvalido,
} tipoErros;

typedef enum
{
   basico,
   estendido
} tipoAlfabetoBase32;

typedef enum
{
   desabilitado,
   habilitado
} tipoFinalLinha;

tipoErros
CodificarBase16(byte * /* (E) */, unsigned long long /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase16(char * /* (E) */, byte * /* (S) */, unsigned long long * /*  (S) */);

tipoErros
CodificarBase32(byte * /* (E) */, unsigned long long /*  (E) */, tipoAlfabetoBase32 /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase32(char * /* (E) */, tipoAlfabetoBase32 /* (E) */, byte * /* (S) */, unsigned long long * /* (S) */);

tipoErros
CodificarBase64(byte * /* (E) */, unsigned long long /*  (E) */, tipoFinalLinha /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase64(char * /* (E) */, tipoFinalLinha /* (E) */, byte * /* (S) */, unsigned long long * /* (S) */);

#endif

/* $RCSfile: aula0801.h,v $ */
