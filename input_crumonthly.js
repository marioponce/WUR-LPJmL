/**************************************************************************************/
/**                                                                                \n**/
/**       i  n  p  u  t  _  c  r  u  m  o  n  t  h  l  y  .  j  s                  \n**/
/**                                                                                \n**/
/** Configuration file for input dataset for LPJ C Version 5.1.002                 \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "include/conf.h" /* include constant definitions */

"inpath" : "/p/projects/lpjml/input/historical",

/* the following array describes the order of the CFT bands in the land use file */

"cftmap" : ["temperate cereals","rice", "maize", "tropical cereals", "pulses",
            "temperate roots", "tropical roots", "oil crops sunflower",
            "oil crops soybean", "oil crops groundnut", "oil crops rapeseed",
            "sugarcane","others","grassland"],

"input" :
{
  "soil" :         { "fmt" : "meta", "name" : "input_VERSION2/soil.descr"},
  "coord" :        { "fmt" : "clm",  "name" : "input_VERSION2/grid.bin"},
  "countrycode" :  { "fmt" : "clm",  "name" : "input_VERSION2/cow_full_2018.bin"},
  "no3deposition" : { "fmt" : "clm",  "name" : "input_VERSION2/no3_deposition_rcp8p5.clm"},
  "nh4deposition" : { "fmt" : "clm",  "name" : "input_VERSION2/nh4_deposition_rcp8p5.clm"},
  "soilpH" :        { "fmt" : "clm",  "name" : "input_VERSION2/soil_ph.clm"},
  "landuse" :      { "fmt" : "clm",  "name" : "input_VERSION2/cft1700_2005_irrigation_systems_64bands.bin"},
  "fertilizer_nr" : { "fmt" : "clm",  "name" : "input_VERSION2/fertilizer_ggcmi.clm2"},
  /* insert prescribed sdate file name here */
  "grassland_fixed_pft" : { "fmt" : "raw", "name" : "/p/projects/landuse/users/rolinski/Newinput/scenario_MO0.bin"},
  "grass_harvest_options" : { "fmt" : "raw", "name": "/p/projects/landuse/users/rolinski/Newinput/scenario_MO2.bin"},
  "lakes" :        { "fmt" : "meta", "name" : "input_VERSION2/glwd_lakes_and_rivers.descr"},
  "drainage" :     { "fmt" : "clm",  "name" : "input_VERSION2/drainagestn.bin"},
  "neighb_irrig" : { "fmt" : "clm",  "name" : "input_VERSION2/neighb_irrig_stn.bin"},
  "elevation" :    { "fmt" : "clm",  "name" : "input_VERSION2/elevation.bin"},
  "reservoir" :    { "fmt" : "clm",  "name" : "input_VERSION2/reservoir_info_grand5.bin"},
  "temp" :         { "fmt" : "clm",  "name" : "CRUDATA_TS3_23/cru_ts3.23.1901.2014.tmp.dat.clm"},
  "prec" :         { "fmt" : "clm",  "name" : "CRUDATA_TS3_23/gpcc_v7_cruts3_23_precip_1901_2013.clm"},
  "lwnet" :        { "fmt" : "clm",  "name" : "input_VERSION2/lwnet_erainterim_1901-2011.clm"},
  "swdown" :       { "fmt" : "clm",  "name" : "input_VERSION2/swdown_erainterim_1901-2011.clm"},
  "cloud":         { "fmt" : "clm",  "name" : "CRUDATA_TS3_23/cru_ts3.23.1901.2014.cld.dat.clm"},
  "wind":          { "fmt" : "clm",  "name" : "input_VERSION2/mwindspeed_1860-2100_67420.clm"},
  "tamp":          { "fmt" : "clm",  "name" : "CRUDATA_TS3_23/cru_ts3.23.1901.2014.dtr.dat.clm"}, /* diurnal temp. range */
  "lightning" :    { "fmt" : "clm",  "name" : "input_VERSION2/mlightning.clm"},
  "human_ignition": { "fmt" : "clm", "name" : "input_VERSION2/human_ignition.clm"},
  "popdens" :      { "fmt" : "clm",  "name" : "input_VERSION2/popdens_HYDE3_1901_2011_bi.clm"},
  "burntarea" :    { "fmt" : "clm",  "name" : "/data/biosx/mforkel/input_new/GFED_CNFDB_ALFDB_Interp.BA.360.720.1901.2012.30days.clm"},
  "landcover":     { "fmt" : "clm",  "name" : "/data/biosx/mforkel/input_new/landcover_synmap_koeppen_vcf_newPFT_forLPJ_20130910.clm"},/*synmap_koeppen_vcf_NewPFT_adjustedByLanduse_SpinupTransitionPrescribed_forLPJ.clm*/
  "co2" :          { "fmt" : "txt",  "name" : "input_VERSION2/co2_1841-2012.dat"},
  "wetdays" :      { "fmt" : "clm",  "name" : "CRUDATA_TS3_23/gpcc_v7_cruts3_23_wet_1901_2013.clm"},
  "wateruse" :     { "fmt" : "clm",  "name" : "input_VERSION2/wateruse_1900_2000.bin" } /* water consumption for industry,household and livestock */
},
