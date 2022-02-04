/**************************************************************************************/
/**                                                                                \n**/
/**                      c  o  p  a  n  .  h                                       \n**/
/**                                                                                \n**/
/**     Declaration of COPAN coupler functions and related datatypes               \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#ifndef COPAN_H /* already included? */
#define COPAN_H

#include "copanpar.h"

/* Definition of constants */

#define COPAN_COUPLER_VERSION 3        /* Protocol version */
#define LPJCOPAN "LPJCOPAN"            /* Environment variable for COPAN coupler */
#define LPJWAIT "LPJWAIT"              /* Time to wait for connection */
#define DEFAULT_COPAN_HOST "localhost" /* Default host for COPAN model */
#define DEFAULT_COPAN_PORT 2224        /* Default port for in and outgoing connection */
#define DEFAULT_WAIT 0                 /* Default time to wait for connection */

#define COPAN_OK 0                     /* COPAN status ok */
#define COPAN_ERR -1                   /* error occurred in COPAN */

/* List of tokens */

#define GET_DATA 0      /* Receiving data from COPAN */
#define PUT_DATA 1      /* Sending data to COPAN */
#define GET_DATA_SIZE 2 /* Receiving data size from COPAN */
#define PUT_DATA_SIZE 3 /* Sending data size to COPAN */
#define END_DATA 4      /* Ending communication */
#define GET_STATUS 5    /* Check status of COPAN */
#define FAIL_DATA 6     /* Ending communication on error */

/* Declaration of functions */

extern Bool open_copan(Config *);
extern int check_copan(Config *);
extern void close_copan(Bool,const Config *);
extern Bool receive_copan(int,void *,Type,int,int,const Config *);
extern Bool receive_real_copan(int,Real *,int,int,const Config *);
extern Bool receive_real_scalar_copan(Real *,int,const Config *);
extern Bool send_flux_copan(const Flux *,Real,int,const Config *);
extern Bool send_token_copan(int,int,const Config *);
extern Bool openinput_copan(int,Type,int,int *,const Config *);
extern Bool openoutput_copan(int,int,int,int,Type,const Config *);
extern void send_output_copan(int,int,int,const Config *);

#define receive_int_copan(index,data,size,year,config) receive_copan(index,data,LPJ_INT,size,year,config)

#endif /* COPAN_H */
