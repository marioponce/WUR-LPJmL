/**************************************************************************************/
/**                                                                                \n**/
/**               o  p  e  n  m  e  t  a  f  i  l  e  .  c                         \n**/
/**                                                                                \n**/
/**     C implementation of LPJmL                                                  \n**/
/**                                                                                \n**/
/**     Functions opens input desription file and opens specified binary           \n**/
/**     file. Description file has the following format:                           \n**/
/**                                                                                \n**/
/**     remark "metafile for LPJmL input"                                          \n**/
/**     file inputfile.bin                                                         \n**/
/**     firstyear 1901                                                             \n**/
/**     nyear 109                                                                  \n**/
/**     nbands 12                                                                  \n**/
/**     endian little                                                              \n**/
/**     firstcell 0                                                                \n**/
/**     ncell 67420                                                                \n**/
/**     scalar 0.1                                                                 \n**/
/**     cellsize 0.5 0.5                                                           \n**/
/**     offset 0                                                                   \n**/
/**     datatype short                                                             \n**/
/**                                                                                \n**/
/**     JSON file format is also supported:                                        \n**/
/**                                                                                \n**/
/**     {                                                                          \n**/
/**       "filename : "inputfile.bin",                                             \n**/
/**       "firstyear" : 1901,                                                      \n**/
/**       "nyear" :  109,                                                          \n**/
/**       "nbands" :  12,                                                          \n**/
/**       "bigendian" :  false,                                                    \n**/
/**       "firstcell" :  0,                                                        \n**/
/**       "ncell" :  67420,                                                        \n**/
/**       "scaling" :  0.1,                                                        \n**/
/**       "cellsize" :  [0.5,0.5],                                                 \n**/
/**       "offset" :  0,                                                           \n**/
/**       "datatype" :  "short"                                                    \n**/
/**     }                                                                          \n**/
/**                                                                                \n**/
/** (C) Potsdam Institute for Climate Impact Research (PIK), see COPYRIGHT file    \n**/
/** authors, and contributors see AUTHORS file                                     \n**/
/** This file is part of LPJmL and licensed under GNU AGPL Version 3               \n**/
/** or later. See LICENSE file or go to http://www.gnu.org/licenses/               \n**/
/** Contact: https://github.com/PIK-LPJmL/LPJmL                                    \n**/
/**                                                                                \n**/
/**************************************************************************************/

#ifdef USE_JSON
#include <json-c/json.h>
#endif
#include "lpj.h"

const char *ordernames[]={"cellyear","yearcell","cellindex","cellseq"};

#ifdef USE_JSON

char *parse_json(LPJfile *lpjfile,   /**< pointer to JSON file */
                 char *s,            /**< first string of JSON file */
                 Header *header,     /**< pointer to file header */
                 size_t *offset,     /**< offset in binary file */
                 Bool *swap,         /**< byte order has to be changed (TRUE/FALSE) */
                 Verbosity verbosity /**< verbosity level */
                )                    /** \return filename of binary file or NULL */
{
  FILE *file;
  String filename;
  char *line;
  enum json_tokener_error json_error;
  struct json_tokener *tok;
  Real cellsize[2];
  Bool endian;
  file=lpjfile->file.file;
  lpjfile->isjson=TRUE;     /* enable JSON parsing */
  tok=json_tokener_new();
  lpjfile->file.obj=json_tokener_parse_ex(tok,s,strlen(s));
  while((line=fscanline(file))!=NULL)  /* read line from file */
  {
    lpjfile->file.obj=json_tokener_parse_ex(tok,line,strlen(line));
    json_error=json_tokener_get_error(tok);
    if(json_error!=json_tokener_continue)
      break;
    free(line);
  }
  json_tokener_free(tok);
  if(json_error!=json_tokener_success)
  {
    if(verbosity)
    {
      fprintf(stderr,"ERROR228: Cannot parse json file '%s' in line %d, %s:\n",
              getfilename(),getlinecount()-1,(json_error==json_tokener_continue) ? "missing closing '}'" : json_tokener_error_desc(json_error));
      if(json_error!=json_tokener_continue)
        fprintf(stderr,"%s:%d:%s",getfilename(),getlinecount()-1,line);
    }
    free(line);
    json_object_put(lpjfile->file.obj);
    lpjfile->file.file=file;
    return NULL;
  }
  free(line);
  if(iskeydefined(lpjfile,"firstcell"))
  {
    if(fscanint(lpjfile,&header->firstcell,"firstcell",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"ncell"))
  {
    if(fscanint(lpjfile,&header->ncell,"ncell",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"firstyear"))
  {
    if(fscanint(lpjfile,&header->firstyear,"firstyear",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"lastyear"))
  {
    if(fscanint(lpjfile,&header->nyear,"lastyear",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
    header->nyear-=header->firstyear-1;
  }
  if(iskeydefined(lpjfile,"nyear"))
  {
    if(fscanint(lpjfile,&header->nyear,"nyear",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"nstep"))
  {
    if(fscanint(lpjfile,&header->nstep,"nstep",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"nbands"))
  {
    if(fscanint(lpjfile,&header->nbands,"nbands",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"order"))
  {
    if(fscankeywords(lpjfile,&header->order,"order",ordernames,4,FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"offset"))
  {
    if(fscansize(lpjfile,offset,"offset",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"bigendian"))
  {
    if(fscanbool(lpjfile,&endian,"bigendian",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
    *swap=(endian) ? !bigendian() : bigendian();
  }
  if(iskeydefined(lpjfile,"scaling"))
  {
    if(fscanfloat(lpjfile,&header->scalar,"scaling",FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"datatype"))
  {
    if(fscankeywords(lpjfile,(int *)&header->datatype,"datatype",typenames,5,FALSE,verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
  }
  if(iskeydefined(lpjfile,"cellsize"))
  {
    if(fscanrealarray(lpjfile,cellsize,2,"cellsize",verbosity))
    {
      json_object_put(lpjfile->file.obj);
      lpjfile->file.file=file;
      return NULL;
    }
    header->cellsize_lon=(float)cellsize[0];
    header->cellsize_lat=(float)cellsize[1];
  }
  if(fscanstring(lpjfile,filename,"filename",FALSE,verbosity))
  {
    json_object_put(lpjfile->file.obj);
    lpjfile->file.file=file;
    return NULL;
  }
  json_object_put(lpjfile->file.obj);
  lpjfile->file.file=file;
  return strdup(filename);
}
#endif

FILE *openmetafile(Header *header, /**< pointer to file header */
                   Bool *swap, /**< byte order has to be changed (TRUE/FALSE) */
                   size_t *offset, /**< offset in binary file */
                   const char *filename, /**< file name */
                   Bool isout /**< error output (TRUE/FALSE) */
                  )           /** \return file pointer to open file or NULL */
{
  LPJfile file;
  FILE *data;
  String key,value;
  char *name,*path,*fullname;
  int index;
  file.isjson=FALSE;
  /* open description file */
  if((file.file.file=fopen(filename,"r"))==NULL)
  {
    if(isout)
      printfopenerr(filename);
    return NULL;
  }
  initscan(filename);
  /* set default values for swap and offset */
  *swap=FALSE;
  *offset=0;
  name=NULL;
  while(!fscantoken(file.file.file,key))
    if(key[0]=='{')
    {
#ifdef USE_JSON
      name=parse_json(&file,key,header,offset,swap,isout ? ERR : NO_ERR);
      break;
#else
      if(isout)
        printf(stderr,"ERROR229: JSON format not supported for metafile '%s' in this version of LPJmL.\n",
               filename);
      free(name);
      fclose(file.file.file);
      return NULL;
#endif
    }
    else if(!strcmp(key,"firstcell"))
    {
      if(fscanint(&file,&header->firstcell,"firstcell",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"ncell"))
    {
      if(fscanint(&file,&header->ncell,"ncell",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"firstyear"))
    {
      if(fscanint(&file,&header->firstyear,"firstyear",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"lastyear"))
    {
      if(fscanint(&file,&header->nyear,"lastyear",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      header->nyear-=header->firstyear-1;
    }
    else if(!strcmp(key,"nyear"))
    {
      if(fscanint(&file,&header->nyear,"nyear",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"nbands"))
    {
      if(fscanint(&file,&header->nbands,"nbands",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"nstep"))
    {
      if(fscanint(&file,&header->nstep,"nstep",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"order"))
    {
      if(fscanstring(&file,value,"order",FALSE,isout ? ERR : NO_ERR))
      {
        if(isout)
          readstringerr("order");
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      index=findstr(value,ordernames,4);
      if(index==NOT_FOUND)
      {
        if(isout)
          fprintf(stderr,"ERROR221: Invalid order '%s' in '%s'.\n",value,filename);
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      header->order=index+1;
    }
    else if(!strcmp(key,"offset"))
    {
      if(fscansize(&file,offset,"offset",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"scalar"))
    {
      if(fscanfloat(&file,&header->scalar,"scalar",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"cellsize"))
    {
      if(fscanfloat(&file,&header->cellsize_lon,"cellsize_lon",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      if(fscanfloat(&file,&header->cellsize_lat,"cellsize_lat",FALSE,isout ? ERR : NO_ERR))
      {
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"datatype"))
    {
      if(fscanstring(&file,value,"datatype",FALSE,isout ? ERR : NO_ERR))
      {
        if(isout)
          readstringerr("datatype");
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      index=findstr(value,typenames,5);
      if(index==NOT_FOUND)
      {
        if(isout)
          fprintf(stderr,"ERROR221: Invalid datatype '%s' in '%s'.\n",value,filename);
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      header->datatype=(Type)index;
    }
    else if(!strcmp(key,"endian"))
    {
      if(fscanstring(&file,value,"endian",FALSE,isout ? ERR : NO_ERR))
      {
        if(isout)
          readstringerr("endian");
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      if(!strcmp(value,"little"))
        *swap=bigendian();
      else if(!strcmp(value,"big"))
        *swap=!bigendian();
      else
      {
        if(isout)
          fprintf(stderr,"ERROR221: Invalid endianness '%s' in line %d of '%s'.\n",value,getlinecount(),filename);
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else if(!strcmp(key,"file"))
    {
      if(fscanstring(&file,value,"file",FALSE,isout ? ERR : NO_ERR))
      {
        if(isout)
          readstringerr("file");
        free(name);
        fclose(file.file.file);
        return NULL;
      }
      name=strdup(value);
      if(name==NULL)
      {
        printallocerr("name");
        return NULL;
      }
    }
    else if(!strcmp(key,"remark"))
    {
      if(fscanstring(&file,value,"remark",FALSE,isout ? ERR : NO_ERR))
      {
        if(isout)
          readstringerr("remark");
        free(name);
        fclose(file.file.file);
        return NULL;
      }
    }
    else
    {
      if(isout)
        fprintf(stderr,"ERROR222: Invalid key word '%s' in line %d of '%s'.\n",key,getlinecount(),filename);
      free(name);
      fclose(file.file.file);
      return NULL;
    }
  fclose(file.file.file);
  if(name==NULL)
  {
    if(isout)
      fprintf(stderr,"ERROR223: No filename specified in '%s'.\n",filename);
    return NULL;
  }
  if(name[0]=='^')
  {
     /* if filename starts with a '^' then path of description file is added to filename */
     path=getpath(filename);
     if(path==NULL)
     {
       printallocerr("path");
       free(name);
       return NULL;
     }
     fullname=malloc(strlen(path)+strlen(name)+1);
     if(fullname==NULL)
     {
       printallocerr("name");
       free(path);
       free(name);
       return NULL;
     }
     strcpy(fullname,path);
     strcat(fullname,"/");
     strcat(fullname,name+1);
     free(name);
     free(path);
     name=fullname;
  }
  /* open data file */
  if((data=fopen(name,"rb"))==NULL  && isout)
    printfopenerr(name);
  /* check file size of binary file */
  if(isout && data!=NULL)
  {
    if((header->order==CELLINDEX  && getfilesizep(data)!=sizeof(int)*header->ncell+typesizes[header->datatype]*header->ncell*header->nbands*header->nstep*header->nyear+*offset) || (header->order!=CELLINDEX && getfilesizep(data)!=typesizes[header->datatype]*header->ncell*header->nbands*header->nyear*header->nstep+*offset))
      fprintf(stderr,"WARNING032: File size of '%s' does not match settings in description file '%s'.\n",name,filename);
  }
  free(name);
  return data;
} /* of 'openmetafile' */
