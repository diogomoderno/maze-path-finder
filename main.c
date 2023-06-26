/******************************************************************************
*
* File Name: main.c
*	      (c) 2018 AED
* Authors: Diogo Moderno, Beatriz Silva
*
* values[0] = L   values[1] = C  values[2] = obj  values[3] = l  values[4] = c
* values[5] = k(passo)  values[6] = e
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
  char *fich_out = NULL, *fich_in = NULL;
  int size, *values = NULL, **matrix = NULL;
  STACK *pstack;
  stackInit(&pstack);

  if (argc < 2){
    /*printf("\nERROR: Missing filename in argument!\n");*/
    exit (1);
  }

  fich_in = argv[1];
  check_file(fich_in); /* verificação de ".maps" (em file.c) */
  size = strlen(fich_in) + 1;
  fp_entry = open_file(fich_in, "r");

  fich_out = (char*)malloc((size+1)*sizeof(char));
  if(fich_out == NULL){
    /*printf("\nMemory allocation for fich_out in main\n");*/
    exit(1);
  }

  strncpy(fich_out, fich_in, size-5); /* copia o nome de fich_in sem a extensao */
  fich_out[size-6] = '\0';
  strcat(fich_out, ".paths");
  fp_out = open_file(fich_out, "a");

  for(;;){
    values = get_values(fp_entry, fp_out, values); /* 1º linha (em file.c) */
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
  free(fich_out);


  exit(0);
}
