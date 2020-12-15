/**************************************************************************************/
/**                                                                                \n**/
/**                    i  n  i  t  o  u  t  p  u  t  .  c                          \n**/
/**                                                                                \n**/
/**     C implementation of LPJmL                                                  \n**/
/**                                                                                \n**/
/**     Function allocates output data                                             \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "lpj.h"

#define checkptr(ptr) if(ptr==NULL) { printallocerr(#ptr); return TRUE;}

Bool initoutput(Output *output, /**< Output data */
                int cft,        /**< CFT for daily output */
                Bool irrigation,/**< irrigation for daily output */
                int npft,       /**< number of natural PFTs */
                int nbiomass,   /**< number of biomass PFTs */
                int nwft,       /**< number of WFTs */
                int ngrass,     /**< number of grasses */
                int ncft        /**< number of crop PFTs */
               )                /**\ return TRUE on error */
{
  output->sdate=newvec(int,2*ncft);/* allocate memory for output */
  checkptr(output->sdate);
  output->hdate=newvec(int,2*ncft);
  checkptr(output->hdate);
  output->pft_npp=newvec(Real,(npft-nbiomass-nwft)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_npp);
  output->pft_nuptake=newvec(Real,(npft-nbiomass)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_nuptake);
  output->pft_ndemand=newvec(Real,(npft-nbiomass)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  output->mpft_lai=newvec(Real,(npft-nbiomass-nwft)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->mpft_lai);
  output->pft_gcgp=newvec(Real,(npft-nbiomass-nwft)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_gcgp);
  output->gcgp_count=newvec(Real,(npft-nbiomass-nwft)+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->gcgp_count);
  output->pft_harvest=newvec(Harvest,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_harvest);
  output->fpc = newvec(Real, (npft-nbiomass-nwft)+1);
  checkptr(output->fpc);
  output->pft_mort = newvec(Real, (npft-nbiomass-nwft));
  checkptr(output->pft_mort);
  output->cftfrac=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cftfrac);
  output->cft_consump_water_g=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_consump_water_g);
  output->cft_consump_water_b=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_consump_water_b);
  output->growing_period=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->growing_period);
  output->cft_pet=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_pet);
  output->cft_irrig_events=newvec(int,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_irrig_events);
  output->cft_transp=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_transp);
  output->cft_transp_b=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_transp_b);
  output->cft_evap=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_evap);
  output->cft_evap_b=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_evap_b);
  output->cft_interc=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_interc);
  output->cft_interc_b=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_interc_b);
  output->cft_return_flow_b=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_return_flow_b);
  output->cft_nir=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_nir);
  output->cft_temp=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_temp);
  output->cft_prec=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_prec);
  output->cft_srad=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_srad);
  output->cft_aboveground_biomass=newvec(Stocks,2*(ncft+NGRASS));
  checkptr(output->cft_aboveground_biomass);
  output->cft_airrig=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_airrig);
  output->cft_fpar=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_fpar);
  output->cft_luc_image=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_luc_image);
  output->pft_laimax=newvec(Real,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_laimax);
  output->pft_root=newvec(Stocks,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_root);
  output->pft_leaf=newvec(Stocks,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_leaf);
  output->pft_sapw=newvec(Stocks,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_sapw);
  output->pft_hawo=newvec(Stocks,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_hawo);
  output->pft_veg=newvec(Stocks,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_veg);
  output->pft_nlimit=newvec(Real,npft-nbiomass-nwft+2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_nlimit);
#if defined IMAGE || defined INCLUDEWP
  output->wft_vegc = newvec(Real, nwft);
  check(output->wft_vegc);
#endif
  output->cft_conv_loss_evap=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_conv_loss_evap);
  output->cft_conv_loss_drain=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_conv_loss_drain);
  output->nv_lai=newvec(Real, (npft-nbiomass-nwft));
  check(output->nv_lai);
  output->fpc_bft=newvec(Real, (nbiomass+2*ngrass)*2);
  check(output->fpc_bft);
#ifdef DOUBLE_HARVEST
  output->sdate2=newvec(int,2*ncft); /* allocate memory for output */
  checkptr(output->sdate2);
  output->hdate2=newvec(int,2*ncft);
  checkptr(output->hdate2);
  output->syear=newvec(int,2*ncft); /* allocate memory for output */
  checkptr(output->syear);
  output->syear2=newvec(int,2*ncft); /* allocate memory for output */
  checkptr(output->syear2);
  output->pft_harvest2=newvec(Harvest,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->pft_harvest2);
  output->cftfrac2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cftfrac2);
  output->cft_pet2=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_pet2);
  output->cft_transp2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_transp2);
  output->cft_evap2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_evap2);
  output->cft_interc2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_interc2);
  output->cft_nir2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_nir2);
  output->cft_airrig2=newvec(Real,2*(ncft+NGRASS+NBIOMASSTYPE+NWPTYPE));
  checkptr(output->cft_airrig2);
  output->growing_period2=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->growing_period2);
  output->cft_temp2=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_temp2);
  output->cft_prec2=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_prec2);
  output->cft_srad2=newvec(Real,2*(ncft+NGRASS));
  checkptr(output->cft_srad2);
  output->cft_aboveground_biomass2=newvec(Stocks,2*(ncft+NGRASS));
  checkptr(output->cft_aboveground_biomass2);
#endif
  output->daily.cft=cft;
  output->daily.irrigation=irrigation;
  return FALSE;
} /* of 'initoutput' */
