/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao: Definicoes de tipos e prototipos das funcoes
 * ExibirConteudoArquivo, ConverterArquivoFormatoUnixParaFormatoDos
 * e ConverterArquivoFormatoDosParaFormatoUnix

 * $Author: diego.silva $
 * $Date: 2022/02/23 03:02:44 $
 * $Log: aula0901.h,v $
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

#ifndef _AULA0901_
#define _AULA0901_ "@(#)aula0901.h $Revision: 1.3 $"

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined(__FreeBSD__) && defined(__STRICT_ANSI__)
#define __ISO_C_VISIBLE 1999
#endif

#define COMPRIMENTO_MAXIMO 16
#define COMPRIMENTO_MAXIMO_BUFFER 1024
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO 256
#define COMPRIMENTO_NOME_BACKUP 22

#define END_OF_STRING '\0'

typedef unsigned char byte;

typedef enum
{
   ok,
   argumentoInvalido,
   erroAbrindoArquivo,
   erroFechandoArquivo,
} tipoErros;

tipoErros
ExibirConteudoArquivo(char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos(char *original, char *convertido);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix(char *original, char *convertido);

#endif

/* $RCSfile: aula0901.h,v $ */