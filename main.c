/******************************************************************************
*
* File Name: main.c
*	
* Authors: Diogo Moderno, Beatriz Silva
*
* values[0] = Width of matrix   values[1] = Length of matrix  
* values[2] = goal  values[3] = initial line position  
* values[4] = initial column position
* values[5] = step values[6] = initial points
*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "file.h"
#include "mem.h"
#include "util.h"
#include "solve.h"
#include "stack.h"

int main(int argc, char *argv[])
{
  FILE *fp_entry, *fp_out;
  char *file_out = NULL, *file_in = NULL;
  int size, *values = NULL, **matrix = NULL;
  STACK *pstack;
  stackInit(&pstack);

  if (argc < 2){
    /*printf("\nERROR: Missing filename in argument!\n");*/
    exit (1);
  }

  file_in = argv[1];
  check_file(file_in); /* verifies the ".maps" extension */
  size = strlen(file_in) + 1;
  fp_entry = open_file(file_in, "r");

  file_out = (char*)malloc((size+1)*sizeof(char));
  if(file_out == NULL){
    exit(1);
  }
  /* copies filename without extension*/
  strncpy(file_out, file_in, size-5); 
  file_out[size-6] = '\0';
  strcat(file_out, ".paths");
  fp_out = open_file(file_out, "a");

  for(;;){
    /* gets first line of a file */
    values = get_values(fp_entry, fp_out, values); 
    if(values == NULL){
      free(values);
      break;
    }

    if((check_val(values) == 1) && (well_defined(fp_out, values) == 0)){   /* verificacao dos limites, posicao do agente, etc (em util.c) */
      matrix = read_matrix(fp_entry, values, matrix); /* em file.c */
      verify(fp_out, &pstack, values, matrix); /* em util.c */
      free_matrix(matrix, values); /* em mem.c */
      if(values != NULL){
        free(values);
      }
    }
    else{
      skip(fp_entry, values);
      fprintf(fp_out, "\n\n");
      if(values != NULL){
        free(values);
      }
    }
    while(!stackEmpty(pstack)){
      stackGet(&pstack);
    }
  }




  free(pstack);

  fclose(fp_entry);
  fclose(fp_out);
  free(file_out);


  exit(0);
}
