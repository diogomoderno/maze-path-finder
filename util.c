/******************************************************************************
*
* File Name: util.c
*	      (c) 2018 AED
*
* COMMENTS
*    Other functions
*
* values[0] = L   values[1] = C  values[2] = obj  values[3] = l  values[4] = c
* values[5] = k(passo)  values[6] = e
*
*****************************************************************************/
#include "stack.h"
#include "util.h"
#include "solve.h"


int check_val(int *values) /* retorna 1 se os valores estao correctos  */
{
  /* se o agente esta fora da matriz */
  if((values[3] < 1) || (values[3] > values[0]) || (values[4] < 1) || (values[4] > values[1])){
    /*printf("\nCoordenadas agente invalidas\n");*/
    return 0;
  }
  if(values[6] < 1){
    /*printf("\nEnergia menor do que 1\n");*/
    return 0;
  }
  if(values[5] < 0){
    /*print("\nPasso inválido"); */
    return 0;
  }
  if((values[2] != -2) && (values[2] < 1)){
    /*printf("\nObjectivo invalido\n"); */
    return 0;
  }
  return 1;
}

void verify(FILE *fp_out, STACK **pstack, int *values, int **matrix)
{
  int **m_aux = NULL; /* m_aux -> matriz luzes */

  int l = values[3], c = values[4];
  int k = values[5];

  STACK *bjork;
  stackInit(&bjork);

  /*sum_prize(fp_out, values, matrix);*/ /* em solve.c */
  m_aux = matrix_k(m_aux, values);
  matrix[0][1] = -1;

  if(values[2] == -2){
    /*print_matrix(m_aux, values);*/
    matrix[0][0] = values[6];
    light_agent(m_aux, values);
    max_energy(pstack, l, c, matrix, m_aux, k, values, 2, &bjork);
    if(matrix[0][1] < 1){
      fprintf(fp_out,"-1\n");
      matrix[1][0] = 10;
    }
    if(matrix[1][0] == 1){
      fprintf(fp_out,"%d\n", -1);
    }
    else if(matrix[1][0] == 0){
      fprintf(fp_out,"%d", matrix[0][1]);
      fprintf(fp_out,"\n");
      copy_to_file(fp_out, bjork);
    }
  }
  else if(values[2]>0){
    /*print_matrix(m_aux, values);*/
    matrix[0][0] = values[6];
    /*m_aux[values[3]][values[4]] = 1;*/
    light_agent(m_aux, values);
    max_energy(pstack, l, c, matrix, m_aux, k, values, 1, &bjork);
    /*printf("matrix[1][0] = %d\n", matrix[1][0]);*/

    if(matrix[0][1] < 1){
      fprintf(fp_out,"-1\n");
    }
    else if(matrix[1][0] == 2){
      fprintf(fp_out,"%d", matrix[0][1]);
      fprintf(fp_out,"\n");
      copy_to_file(fp_out, bjork);
    }
    else if((matrix[1][0] == 1) || (matrix[1][0] == 0)){
      fprintf(fp_out,"%d\n", -1);
    }
    fprintf(fp_out,"\n");
  }

  while(!stackEmpty(bjork)){
    stackGet(&bjork);
  }
  free(bjork);
  free_matrix_aux(m_aux, values);
}

void lights(int **m_aux, int row, int col, int *values, int state)
{
  int f = 0, g = 0, i = 0, j = 0;
  f = values[3] - values[5];
  g = values[4] - values[5];

  if(f <= 0){
    f = 1;
  }
  if(g <= 0){
    g = 1;
  }

  i = row - f + 1;
  j = col - g + 1;

  m_aux[i][j] = state;
}


int posso_ir(int **matrix, int **m_aux, int i, int *row, int *col, int *values)
{
  if(i == 1 && (*row - 1>0)){
	  if(verify_light(m_aux, *row-1, *col, values) == 0){
		if(matrix[*row-1][*col] + matrix[0][0] > 0){
			*row = *row - 1;
			return 1;
		}
		else{
			return 0;
		}
	}
  }
  else if(i == 2 && (*row + 1<=values[0])){
	  if(verify_light(m_aux, *row+1, *col, values) == 0){
		if(matrix[*row+1][*col] + matrix[0][0] > 0){
			*row = *row + 1;
			return 1;
		}
		else{
			return 0;
		}
	}

  }
  else if(i == 3  && (*col - 1>0)){
	  if(verify_light(m_aux, *row, *col-1, values) == 0){
		if(matrix[*row][*col-1] + matrix[0][0] > 0){
			*col = *col - 1;
			return 1;
		}
		else{
			return 0;
		}
	}
  }
  else if(i == 4 && (*col +1<=values[1])){
	  if(verify_light(m_aux, *row, *col+1, values) == 0){
		if(matrix[*row][*col+1] + matrix[0][0] > 0){
			*col = *col + 1;
			return 1;
		}
		else{
			return 0;
		}
	}
  }
  return 0;
}

int verify_light(int **m_aux, int row, int col, int *values)
{

  int f = 0, g = 0, i = 0, j = 0;
  f = values[3] - values[5];
  g = values[4] - values[5];

  if(f <= 0){
    f = 1;
  }
  if(g <= 0){
    g = 1;
  }

  i = row - f + 1;
  j = col - g + 1;

  /*printf("line_aux: %d  col_aux: %d\n", line_aux, col_aux);*/
  return (m_aux[i][j]);

}

void print_matrix(int** m_aux, int *values)
{
  int i = 0, j = 0;
  int l = 0, c = 0;
  dim_matrix_aux(values, &l, &c);
  for(i = 0; i< (l); i++){
    for(j = 0; j < (c); j++){
      printf("[%d]", m_aux[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void light_agent(int **m_aux, int *values)
{
  int f = 0, g = 0, i = 0, j = 0;
  f = values[3] - values[5];
  g = values[4] - values[5];

  if(f <= 0){
    f = 1;
  }
  if(g <= 0){
    g = 1;
  }

  i = values[3] - f + 1;
  j = values[4] - g + 1;
  m_aux[i][j] = 1;
}

int well_defined(FILE *fp_out, int *values)
{
  if(values[5] > values[0]*values[1]){
    fprintf(fp_out, "-1\n");
    return 1;
  }
  if(values[2] == -2){
    if((values[5] == 0) && (values[6] > 0)){
      fprintf(fp_out, "%d", values[6]);
      return 1;
    }
  }
  if((values[2] != -2) && (values[2] > 0)){
    if((values[5] == 0) && (values[6] > values[2])){
      fprintf(fp_out, "%d", values[6]);
      return 1;
    }
    else if((values[5] == 0) && (values[6] < values[2])){
      fprintf(fp_out, "-1\n");
      return 1;
    }
  }

  return 0;
}
