/**************************************************************************************/
/**                                                                                \n**/
/**             i  n  i  t  _  a  n  n  u  a  l  .  c                              \n**/
/**                                                                                \n**/
/**     C implementation of LPJmL                                                  \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "lpj.h"

void init_annual(Cell *cell,   /**< Pointer to cell */
                 int npft,     /**< number of natural pfts */
                 int nbiomass, /**< number of biomass pfts */
                 int nwft,     /**< number of WFTs */
                 int ncft      /**< number of crop pfts */
                )
{
  int s,p;
#if defined IMAGE && defined COUPLED
  int m;
#endif
  Pft *pft;
  Stand *stand;
  init_climbuf(&cell->climbuf);
  cell->balance.aprec=cell->balance.npp=cell->balance.gpp=cell->balance.rh=cell->balance.awater_flux=0.0;
  cell->afire_frac=cell->balance.biomass_yield=0.0;
  cell->balance.total_irrig_from_reservoir=cell->balance.total_reservoir_out=0.0;
#if defined IMAGE && defined COUPLED
  cell->npp_nat=cell->npp_wp=cell->flux_estab_nat=cell->flux_estab_wp=cell->rh_nat=cell->rh_wp=0.0;
#endif
  foreachstand(stand,s,cell->standlist)
  {
#ifdef DEBUG3
    printf("init npft=%d\n",stand->pftlist.n);
#endif
    stand->fire_sum=0;
    stand->soil.maxthaw_depth=0;
    foreachpft(pft,p,&stand->pftlist)
      init(pft);
  } /* of foreachstand */
  initoutput_annual(&cell->output,npft,nbiomass,nwft,ncft);
#if defined IMAGE && defined COUPLED
  cell->ml.image_data->anpp=cell->ml.image_data->arh=
    cell->ml.image_data->prod_turn_fast=
    cell->ml.image_data->prod_turn_slow=0.0;
  for(m=0;m<NMONTH;m++)
  {
    cell->ml.image_data->mirrwatdem[m]=0.0;
    cell->ml.image_data->mevapotr[m] = 0.0;
    cell->ml.image_data->mpetim[m] = 0.0;
  }
#endif
} /* of 'init_annual' */
