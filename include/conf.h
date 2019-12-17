/**************************************************************************************/
/**                                                                                \n**/
/**                  c  o  n  f  .  h                                              \n**/
/**                                                                                \n**/
/**     Header for LPJ configuration file                                          \n**/
/**     Must be included by LPJmL configuration file                               \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#ifndef CONF_H
#define CONF_H

#define LPJ 0          /* LPJ simulation with natural vegetation only */
#define LPJML 1        /* LPJ simulation with managed land */
#define LPJML_IMAGE 4  /* LPJ simulation with managed land coupled to IMAGE
                          model */
#define LPJML_FMS 5  /* LPJ simulation with managed land coupled to FMS */
#define LANDUSE 1
#define NO_LANDUSE 0
#define CONST_LANDUSE 3
#define ALL_CROPS 4
#define ONLY_CROPS 5
#define NO_FIXED_SDATE 0
#define FIXED_SDATE 1
#define PRESCRIBED_SDATE 2
#define SEMISTATIC_CROP_PHU 0
#define PRESCRIBED_CROP_PHU 1
#define NO_IRRIGATION 0
#define LIM_IRRIGATION 1
#define POT_IRRIGATION 2
#define ALL_IRRIGATION 3
#define GRASS_HARVEST_OPTIONS 1 
#define NO_GRASS_HARVEST_OPTIONS 0 
#define GRASS_FIXED_PFT 1 
#define NO_GRASS_FIXED_PFT 0 
#define LAIMAX_CFT 0
#define LAIMAX_INTERPOLATE 1
#define CONST_LAI_MAX 2
#define LAIMAX_PAR 3
#define NO_RESERVOIR 0
#define RESERVOIR 1
#define NO_DRAINAGE 0
#define DRAINAGE 1
#define PERM 1
#define NO_PERM 0
#define NEW_PERC 1
#define OLD_PERC 0
#define NO_NITROGEN 0
#define LIM_NITROGEN 1
#define UNLIM_NITROGEN 2
#define NO_WATERUSE 0
#define WATERUSE 1
#define ALL_WATERUSE 2
#define NO_RWMANAGEMENT 0
#define RWMANAGEMENT 1
#define NO_TILLAGE 0
#define TILLAGE 1
#define READ_TILLAGE 2
#define NO_RESIDUE_REMOVE 0
#define FIXED_RESIDUE_REMOVE 1
#define READ_RESIDUE_DATA 2
#define RADIATION_LWDOWN 3
#define RADIATION_SWONLY 2
#define RADIATION 1
#define CLOUDINESS 0
#define SWDOWN 2
#define ALL -1
#define RAW 0
#define CLM 1
#define CLM2 2
#define TXT 3
#define FMS 4
#define META 5
#define CDF 6
#define RESTART 1
#define NO_RESTART 0
#define NO_FIRE 0
#define FIRE 1
#define SPITFIRE 2
#define SPITFIRE_TMAX 3
#define NO_PRESCRIBE_BURNTAREA 0
#define PRESCRIBE_BURNTAREA 1
#define NO_LANDCOVER 0
#define LANDCOVEREST 1
#define LANDCOVERFPC 2
#define OLD_PHENOLOGY 0
#define NEW_PHENOLOGY 1
#define NO_POPULATION 0
#define POPULATION 1
#define NO_FIREWOOD 0
#define FIREWOOD 1
#define RANDOM_PREC 1
#define INTERPOLATE_PREC 0
#define NOUT 292           /* number of output files */
#define END -1              /* end marker for output files */
#define GRIDBASED 1         /* pft-specific outputs scaled by stand->frac */
#define PFTBASED 0          /* pft-specific outputs not scaled by stand->frac */
#define DAILY_IRRIG 1       /* daily outputs for irrigated crop */
#define DAILY_RAINFED 0     /* daily outputs for rain-fed crop */
#define CONST_PREC 2
/*monthly and annual output*/
#define GRID 0          
#define FPC 1          
#define MNPP 2          
#define MGPP 3          
#define MRH 4          
#define MTRANSP 5          
#define MRUNOFF 6          
#define MDISCHARGE 7          
#define MEVAP 8          
#define MINTERC 9          
#define MSWC1 10          
#define MSWC2 11          
#define FIREC 12          
#define FIREF 13          
#define VEGC 14          
#define SOILC 15          
#define LITC 16          
#define FLUX_ESTABC 17          
#define FLUX_ESTAB FLUX_ESTABC
#define PFT_NPP 18          
#define PFT_GCGP 19          
#define HARVEST HARVESTC
#define HARVESTC 20          
#define MIRRIG 21          
#define SDATE 22          
#define PFT_HARVESTC 23          
#define PFT_HARVEST PFT_HARVESTC
#define PFT_RHARVESTC 24          
#define PFT_RHARVEST PFT_RHARVESTC
#define COUNTRY 25          
#define REGION 26          
#define MG_VEGC 27          
#define MG_SOILC 28          
#define MG_LITC 29          
#define APREC 30          
#define INPUT_LAKE 31          
#define MRETURN_FLOW_B 32          
#define MEVAP_LAKE 33          
#define ADISCHARGE 34          
#define CFTFRAC 35          
#define CFT_CONSUMP_WATER_G 36          
#define CFT_CONSUMP_WATER_B 37          
#define PROD_TURNOVER 38          
#define DEFOREST_EMIS 39          
#define AIRRIG 40          
#define CFT_AIRRIG 41          
#define HDATE 42          
#define GROWING_PERIOD 43          
#define CFT_PET 44          
#define CFT_TRANSP 45          
#define CFT_EVAP 46          
#define CFT_INTERC 47          
#define CFT_NIR 48          
#define CFT_TEMP 49          
#define CFT_PREC 50          
/* daily outputs for single crops */
#define D_LAI 51          
#define D_PHEN 52          
#define D_CLEAF 53          
#define D_CROOT 54          
#define D_CSO 55          
#define D_CPOOL 56          
#define D_WDF 57          
#define D_GROWINGDAY 58          
#define D_PVD 59          
#define D_PHU 60          
#define D_FPHU 61          
#define D_LAIMAXAD 62          
#define D_LAINPPDEF 63          
#define D_HUSUM 64          
#define D_VDSUM 65          
#define D_WSCAL 66          
#define D_NPP 67          
#define D_GPP 68          
#define D_RD 69          
#define D_RROOT 70          
#define D_RSO 71          
#define D_RPOOL 72          
#define D_GRESP 73          
#define D_TRANS 74          
#define D_EVAP 75          
#define D_PREC 76          
#define D_PERC 77          
#define D_IRRIG 78          
#define D_W0 79          
#define D_W1 80          
#define D_WEVAP 81          
#define D_HI 82          
#define D_FHIOPT 83          
#define D_HIMIND 84          
#define D_FROOT 85          
#define D_TEMP 86          
#define D_SUN 87          
#define D_PAR 88          
#define D_DAYLENGTH 89          
#define D_SWE 90          
#define D_DISCHARGE 91          
#define D_RUNOFF 92          
#define D_RH 93          
#define D_INTERC 94          
#define D_NUPTAKE 95          
#define D_N2O_DENIT 96          
#define D_N2O_NIT 97          
#define D_N2_DENIT 98          
#define D_LEACHING 99          
#define D_BNF 100          
#define D_NLEAF 101          
#define D_NROOT 102          
#define D_NSO 103          
#define D_NPOOL 104          
#define D_NO3 105          
#define D_NH4 106          
#define D_NSOIL_SLOW 107          
#define D_NSOIL_FAST 108          
#define D_ASSIM 109          
#define D_ROT_MODE 110          
#define D_NLIMIT 111          
#define D_VSCAL 112          
#define D_PET 113 /* last daily output ID; Insert additional output before! */
#define MEVAP_RES 114          
#define MPREC_RES 115          
#define MFIREC 116          
#define MNFIRE 117          
#define MFIREDI 118          
#define MFIREEMISSION_CO2 119          
#define MFAPAR 120          
#define FLUX_FIREWOOD 121          
#define RHARVEST_BURNTC 122          
#define RHARVEST_BURNT_IN_FIELDC 123          
#define MTEMP_IMAGE 124          
#define MPREC_IMAGE 125          
#define MSUN_IMAGE 126          
#define MWET_IMAGE 127          
#define FBURN 128      
#define FTIMBER 129          
#define TIMBER_HARVESTC 130          
#define PRODUCT_POOL_FAST 131          
#define PRODUCT_POOL_SLOW 132          
#define LUC_IMAGE 133          
#define MAXTHAW_DEPTH 134          
#define MSOILTEMP1 135          
#define MSOILTEMP2 136          
#define MSOILTEMP3 137          
#define MSOILTEMP4 138          
#define MSOILTEMP5 139          
#define MSOILTEMP6 140          
#define MRES_STORAGE 141          
#define MRES_DEMAND 142          
#define MTARGET_RELEASE 143          
#define MRES_CAP 144          
#define SEASONALITY 145          
#define MPET 146          
#define TRAD_BIOFUEL 147          
#define AFRAC_WD_UNSUST 148          
#define MWD_UNSUST 149          
#define ACONV_LOSS_EVAP 150          
#define MWD_LOCAL 151          
#define MWD_NEIGHB 152          
#define MWD_RES 153          
#define MWD_RETURN 154          
#define MCONV_LOSS_EVAP 155          
#define MPREC 156          
#define MRAIN 157          
#define MSNOWF 158          
#define MMELT 159          
#define MSNOWRUNOFF 160          
#define MSWE 161          
#define SOILC_LAYER 162          
#define MRUNOFF_SURF 163          
#define MRUNOFF_LAT 164          
#define MSEEPAGE 165          
#define MBURNTAREA 166          
#define SOILC_SLOW 167          
#define MSWC3 168          
#define MSWC4 169          
#define MSWC5 170          
#define MROOTMOIST 171          
#define CFT_SRAD 172          
#define CFT_ABOVEGBMC 173
#define MGCONS_RF 174          
#define MGCONS_IRR 175          
#define MBCONS_IRR 176          
#define AWATERUSE_HIL 177          
#define MWATERAMOUNT 178          
#define CFT_ABOVEGBMN 179          
#define PFT_HARVESTN 180          
#define PFT_RHARVESTN 181          
#define RHARVEST_BURNTN 182          
#define RHARVEST_BURNT_IN_FIELDN 183          
#define FLUX_ESTABN 184          
#define VEGN 185          
#define SOILN 186          
#define LITN 187          
#define SOILNH4 188          
#define SOILNO3 189          
#define HARVESTN 190          
#define SOILN_LAYER 191          
#define SOILN_SLOW 192          
#define PFT_NUPTAKE 193          
#define MNUPTAKE 194          
#define MLEACHING 195          
#define MN2O_DENIT 196          
#define MN2O_NIT 197          
#define MN2_EMIS 198          
#define MBNF 199          
#define PFT_NDEMAND 200          
#define MN_MINERALIZATION 201          
#define FIREN 202          
#define MN_IMMO 203          
#define PFT_CLEAF 204          
#define PFT_NLEAF 205          
#define PFT_VEGC 206          
#define PFT_VEGN 207          
#define MIRRIG_RW 208          
#define MTRANSP_B 209          
#define CFT_TRANSP_B 210          
#define MUNMET_DEMAND 211          
#define CFT_FPAR 212          
#define MEVAP_B 213          
#define MINTERC_B 214          
#define CFT_EVAP_B 215          
#define CFT_INTERC_B 216          
#define CFT_RETURN_FLOW_B 217          
#define CFT_IRRIG_EVENTS 218          
#define CFT_CONV_LOSS_EVAP 219          
#define CFT_CONV_LOSS_DRAIN 220
#define MSTOR_RETURN 221          
#define MCONV_LOSS_DRAIN 222          
#define ACONV_LOSS_DRAIN 223          
#define NEGN_FLUXES 224          
#define NEGC_FLUXES 225          
#define PFT_LAIMAX 226          
#define PFT_CROOT 227          
#define PFT_NROOT 228          
#define PFT_CSAPW 229          
#define PFT_NSAPW 230          
#define PFT_CHAWO 231          
#define PFT_NHAWO 232          
#define HDATE2 233          
#define SDATE2 234          
#define PFT_HARVESTC2 235          
#define PFT_HARVEST2 PFT_HARVESTC2
#define PFT_RHARVESTC2 236
#define PFR_RHARVEST2 PFT_RHARVESTC2
#define GROWING_PERIOD2 237          
#define CFT_PET2 238          
#define CFT_TRANSP2 239          
#define CFT_EVAP2 240          
#define CFT_INTERC2 241          
#define CFT_NIR2 242          
#define CFT_TEMP2 243          
#define CFT_PREC2 244          
#define CFT_SRAD2 245          
#define CFT_ABOVEGBMC2 246          
#define CFTFRAC2 247          
#define CFT_AIRRIG2 248          
#define SYEAR 249          
#define SYEAR2 250          
#define PFT_HARVESTN2 251          
#define PFT_RHARVESTN2 252          
#define CFT_ABOVEGBMN2 253          
#define MN_VOLATILIZATION 254          
#define PFT_NLIMIT 255          
#define SOILNO3_LAYER 256          
#define SOILNH4_LAYER 257
#define MWSCAL 258
#define AGB 259
#define MLAKEVOL 260
#define MLAKETEMP 261
#define MFIREEMISSION_CO 262
#define MFIREEMISSION_CH4 263
#define MFIREEMISSION_VOC 264
#define MFIREEMISSION_TPM 265
#define MFIREEMISSION_NOX 266
#define MSOILTEMP 267
#define MSWC 268
#define MALBEDO 269
#define MPHEN_TMIN 270
#define MPHEN_TMAX 271
#define MPHEN_LIGHT 272
#define MPHEN_WATER 273
#define ABURNTAREA 274
#define AGB_TREE 275
#define ALITFALLC 276
#define ALITFALLN 277
#define MMG_SOILC 278
#define RUNOFF_SURF 279
#define RUNOFF_LAT 280
#define LITC_ALL 281
#define LITC_AG 282
#define MNPP_AGR 283
#define MRH_AGR 284
#define SOILC_AGR 285
#define SOILC_AGR_LAYER 286
#define LITC_AGR 287
#define ANPP 288
#define ANPP_AGR 289
#define ARH 290
#define ARH_AGR 291

#define RANDOM_SEED 0

#endif
