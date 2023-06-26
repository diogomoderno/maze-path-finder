/******************************************************************************
*
* File Name: file.c
*	 
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
    exit (1);
  }
  return f;
}

void check_file (char *fich)
{
  char *verif;
  int occurence = '.';
  char extension[] = ".maps";
  /*returns the last occurence of the file extension*/
  verif = strrchr(fich, occurence);
  /* checks if the file extension is correct*/
  if( strcmp(verif, extension) != 0){
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
    values[0] = number;
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
    }
  }
  return matrix;
}


void skip(FILE *fp_entry, int *values)
{
  int aux = 0, i = 0;
  for(i = 0; i<values[0]*values[1]; i++){
    fscanf(fp_entry, "%d", &aux);
  }
}
