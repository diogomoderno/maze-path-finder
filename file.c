/******************************************************************************
*
* File Name: file.c
*	      (c) 2018 AED
*
* COMMENTS
*    Open/read/write files
*
*****************************************************************************/

#include "file.h"
#include "mem.h"

FILE *open_file(char *name, char *mode)
{
  FILE *f;
  f = fopen(name, mode);
  if (f == NULL) {
    /*printf("\nERROR IN OPENING FILE\n");*/
    exit (1);
  }
  return f;
}

void check_file (char *fich)
{
  char *verif;
  int occurence = '.';
  char extension[] = ".maps";

  verif = strrchr(fich, occurence);  /* strrchr retorna ultima occorencia guardada, neste caso, em verif (suposto ser ".1maps") */

  if( strcmp(verif, extension) != 0){
    /*printf("\nInvalid file name\nMust have .maps extension\n\n");*/
    exit(1);
  }
}

int* get_values(FILE *fp_entry, FILE *fp_out, int *values)
{
  int i = 0, number = 0;

  if(fscanf(fp_entry, "%d", &number) != 1){
    values = NULL;
    return values;
  }
  else{
    values = (int*)malloc(7*sizeof(int));
    values[0] = number;   /*o fscanf anterior faz uma leitura*/
    fprintf(fp_out, "%d ", values[0]);
  }

  for(i = 1; i < 7; i++){
    if(fscanf(fp_entry, "%d", &values[i]) == 1){
      fprintf(fp_out, "%d ", values[i]);
    }
    else{
      values = NULL;
    }
  }
  return values;
}

int **read_matrix(FILE *fp_entry, int *values, int** matrix)
{
  int i, j;
  matrix = alloc_matrix(matrix, values);
  for(i = 0; i <= values[0]; i++){
    for(j = 0; j <= values[1]; j++){
      if((i == 0) || (j == 0)){
        matrix[i][j] = 0;
      }
      else{
        fscanf(fp_entry, "%d", &(matrix[i][j]));
      }
      /*printf("[%d] ", matrix[i][j]);*/
    }
    /*printf("\n");*/
  }
  /*printf("\n");*/
  return matrix;
}


void skip(FILE *fp_entry, int *values)
{
  int zezinho = 0, i = 0;
  for(i = 0; i<values[0]*values[1]; i++){
    fscanf(fp_entry, "%d", &zezinho);
  }
}
