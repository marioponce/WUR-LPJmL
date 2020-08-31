/**************************************************************************************/
/**                                                                                \n**/
/**                    w o o d p l a n t a t i o n . c                             \n**/
/**                                                                                \n**/
/**     C implementation of LPJmL                                                  \n**/
/**                                                                                \n**/
/**     Definition of woodplantation stand                                         \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "lpj.h"
#include "agriculture.h"
#include "woodplantation.h"

#if defined IMAGE || defined INCLUDEWP

Standtype woodplantation_stand={WOODPLANTATION,"woodplantation",new_agriculture,
                                free_agriculture,fwrite_agriculture,
                                fread_agriculture,fprint_agriculture,
                                daily_woodplantation,annual_woodplantation,NULL};

#endif