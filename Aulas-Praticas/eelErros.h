/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Diego Rodrigues da Silva
 * Descricao:
 
 * $Author$
 * $Date$
 * $Log$
 */

#ifndef _EELERROS_
#define _EELERROS_ "@(#)eelErros.h $Revision$"

#include "eelTipos.h"

typedef enum
{
   
} eelTipoErros;

char *
EelObterMensagemErroCli (eelTipoIdiomas, eelTipoErros);

char *
EelObterMensagemErroWeb (eelTipoIdiomas, eelTipoErros);

#endif

/* $RCSfile$ */
