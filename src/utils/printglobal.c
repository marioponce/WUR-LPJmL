/**************************************************************************************/
/**                                                                                \n**/
/**                     p  r  i  n  t  g  l  o  b  a  l  .  c                      \n**/
/**                                                                                \n**/
/**     Program prints global area weighted sum or mean of raw binary output files \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#include "lpj.h"

#define USAGE "Usage: %s [-firstyear year] [-nbands n] [-cellsize size] [-day|month] [-noheader] [-csv] [-mean] [-yearsum] grid.bin out.bin ...\n"

int main(int argc,char **argv)
{
  Real *area;
  Coord coord,resolution;
  Intcoord intcoord;
  FILE *gridfile;
  FILE **file;
  int i,n,nyear,cell,year,iarg,firstyear,step,nstep,nbands,band,nyear_min;
  Bool header,ismean,csv,yearsum;
  float data;
  Real sum,area_sum,*sum_array;
  char *endptr;
  /* set default values */
  firstyear=1901;
  nstep=1;
  nbands=1;
  header=TRUE;
  ismean=csv=FALSE;
  yearsum=FALSE;
  resolution.lon=resolution.lat=0.5;
  for(iarg=1;iarg<argc;iarg++)
    if(argv[iarg][0]=='-')
    {
      if(!strcmp(argv[iarg],"-firstyear"))
      {
        if(iarg==argc-1)
        {
          fprintf(stderr,"Error: Missing argument after option '-firstyear'.\n"
                  USAGE,argv[0]);
          return EXIT_FAILURE;
        }
        firstyear=strtol(argv[++iarg],&endptr,10);
        if(*endptr!='\0')
        {
          fprintf(stderr,"Error: Invalid number '%s' for option '-firstyear'.\n",argv[iarg]);
          return EXIT_FAILURE;
        }
      }
      else if(!strcmp(argv[iarg],"-nbands"))
      {
        if(iarg==argc-1)
        {
          fprintf(stderr,"Error: Missing argument after option '-nbands'.\n"
                  USAGE,argv[0]);
          return EXIT_FAILURE;
        }
        nbands=strtol(argv[++iarg],&endptr,10);
        if(*endptr!='\0')
        {
          fprintf(stderr,"Error: Invalid number '%s' for option '-nbands'.\n",argv[iarg]);
          return EXIT_FAILURE;
        }
      }
      else if(!strcmp(argv[iarg],"-cellsize"))
      {
        if(iarg==argc-1)
        {
           fprintf(stderr,"Missing argument after option '-cellsize'.\n"
                   USAGE,argv[0]);
           return EXIT_FAILURE;
        }
        resolution.lon=resolution.lat=strtod(argv[++iarg],&endptr);
        if(*endptr!='\0')
        {
          fprintf(stderr,"Invalid number '%s' for '-cellsize' option.\n",argv[iarg]);
          return EXIT_FAILURE;
        }
      }
      else if(!strcmp(argv[iarg],"-day"))
        nstep=NDAYYEAR;
      else if(!strcmp(argv[iarg],"-month"))
        nstep=NMONTH;
      else if(!strcmp(argv[iarg],"-noheader"))
        header=FALSE;
      else if(!strcmp(argv[iarg],"-mean"))
        ismean=TRUE;
      else if(!strcmp(argv[iarg],"-csv"))
        csv=TRUE;
      else if(!strcmp(argv[iarg],"-yearsum"))
        yearsum=TRUE;
      else
      {
        fprintf(stderr,"Error: Invalid option '%s'.\n"
                USAGE,argv[iarg],argv[0]);
        return EXIT_FAILURE;
      }
    }
    else
      break;
  if(iarg+1>=argc)
  {
    fprintf(stderr,"Error: Missing arguments.\n"
            USAGE,argv[0]);
    return EXIT_FAILURE;
  }
  gridfile=fopen(argv[iarg],"rb");
  if(gridfile==NULL)
  {
    fprintf(stderr,"Error opening '%s': %s.\n",
            argv[iarg],strerror(errno));
    return EXIT_FAILURE;
  }
  n=getfilesizep(gridfile)/sizeof(Intcoord);
  if(n==0)
  {
    fprintf(stderr,"Error: No coordinates written in grid file.\n");
    return EXIT_FAILURE;
  }
  area=newvec(Real,n);
  area_sum=0;
  for(i=0;i<n;i++)
  {
    fread(&intcoord,sizeof(Intcoord),1,gridfile);
    coord.lon=intcoord.lon*0.01;
    coord.lat=intcoord.lat*0.01;
    area[i]=cellarea(&coord,&resolution);
    area_sum+=area[i];
  }
  fclose(gridfile);
  file=newvec(FILE *,argc-iarg-1);
  for(i=iarg+1;i<argc;i++)
  {
    file[i-iarg-1]=fopen(argv[i],"rb");
    if(file[i-iarg-1]==NULL)
    {
      fprintf(stderr,"Error opening '%s': %s.\n",
              argv[i],strerror(errno));
      return EXIT_FAILURE;
    }
    nyear=getfilesizep(file[i-iarg-1])/sizeof(float)/n/nstep/nbands;
    if(nyear==0)
    {
      fprintf(stderr,"No data written for on year in '%s'.\n",argv[i]);
      return EXIT_FAILURE;
    }
    if(getfilesizep(file[i-iarg-1]) % (sizeof(float)*n*nstep*nbands))
      fprintf(stderr,"Warning: Filesize of '%s' is not multiple of cell size and number and years.\n",argv[i]);
    if(i==iarg+1)
      nyear_min=nyear;
    else if(nyear<nyear_min)
    {
      fprintf(stderr,"Warning: Number of years=%d in '%s' is less than number of years=%d in '%s'.\n",nyear,argv[i],nyear_min,argv[iarg+1]);
      nyear_min=nyear;
    }
  }
  if(header)
  {
    printf("Year");
    if(!yearsum)
      switch(nstep)
      {
        case NMONTH:
          printf("%cMonth",(csv) ? ',' : ' ');
          break;
        case NDAYYEAR:
          printf("%cDay",(csv) ? ',' : ' ');
          break;
      }
    for(i=iarg+1;i<argc;i++)
    {
      if(nbands==1)
        printf("%c%s",(csv) ? ',' : ' ' ,argv[i]);
      else
      {
        for(band=0;band<nbands;band++)
          printf("%c%s[%d]",(csv) ? ',' : ' ' ,argv[i],band+1);
      }
    }
    printf("\n");
  }
  if(yearsum)
  {
    sum_array=newvec(Real,nbands*(argc-iarg-1));
    if(sum_array==NULL)
    {
      printallocerr("sum");
      return EXIT_FAILURE;
    }
  }
  for(year=firstyear;year<firstyear+nyear_min;year++)
  {
    if(yearsum)
    {
      printf("%d",year);
      for(i=0;i<nbands*(argc-iarg-1);i++)
        sum_array[i]=0;
      for(step=0;step<nstep;step++)
        for(i=0;i<argc-iarg-1;i++)
          for(band=0;band<nbands;band++)
            for(cell=0;cell<n;cell++)
            {
              fread(&data,sizeof(float),1,file[i]);
              sum_array[i*nbands+band]+=data*area[cell];
            }
      for(i=0;i<argc-iarg-1;i++)
        for(band=0;band<nbands;band++)
          printf((csv) ? ",%g" : " %g",(ismean) ? sum_array[i*nbands+band]/area_sum/nstep : sum_array[i*nbands+band]);
      printf("\n");
    }
    else
      for(step=0;step<nstep;step++)
      {
        if(nstep==1)
          printf("%d",year);
        else
          printf((csv) ? ",%d,%d" : "%d %d",year,step+1);
        for(i=0;i<argc-iarg-1;i++)
          for(band=0;band<nbands;band++)
          {
            sum=0;
            for(cell=0;cell<n;cell++)
            {
              fread(&data,sizeof(float),1,file[i]);
              sum+=data*area[cell];
            }
            printf((csv) ? ",%g" : " %g",(ismean) ? sum/area_sum : sum);
          }
        printf("\n");
      }
  }
  for(i=0;i<argc-iarg-1;i++)
    fclose(file[i]);
  return EXIT_SUCCESS;
} /* of 'main' */
