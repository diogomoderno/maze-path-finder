/******************************************************************************
*
* File Name: mem.c
*	      (c) 2018 AED
*
* COMMENTS
*    Memory operations
*
*****************************************************************************/

#include "mem.h"

void free_matrix(int **matrix, int *values)
{
  int i = 0;
  for(i = 0; i <= values[0]; i++){
    free(matrix[i]);
  }
  free(matrix);
}

int** alloc_matrix(int **matrix, int *values)
{
  int i;
  matrix = (int**)malloc((values[0]+1)*sizeof(int*));
  for(i = 0; i < values[0] + 1; i++){
    matrix[i] = (int*)malloc((values[1]+1)*sizeof(int));
  }
  return matrix;
}

void free_matrix_aux(int **m_aux, int *values)
{
  int i = 0;
  int c = 0, l = 0;
  dim_matrix_aux(values, &l, &c);
  for(i = 0; i < (l+1); i++){
    free(m_aux[i]);
  }
  free(m_aux);
}

/* aloca o tamnho da matriz de acordo com o passo e com os limites da matriz inicial */
int **matrix_k(int **m_aux, int *values)
{
  int i = 0, j = 0; /*, l, c,l_up, l_down, c_right, c_left   */

  int c = 0, l = 0;

  dim_matrix_aux(values, &l, &c);
  /*printf("l:%d c:%d\n", l, c);*/
  m_aux = (int**)malloc((l+1)*sizeof(int*));
  for(i = 0; i < (l+1); i++){
    m_aux[i] = (int*)malloc((c+1)*sizeof(int));
  }

  for(i = 0; i < l+1; i++){
    for(j = 0; j < c +1; j++){
      m_aux[i][j] = 0;
    }
  }

  return m_aux;
}

void dim_matrix_aux(int *values, int *l, int *c)
{
  int l_up = 0, l_down = 0, c_right = 0, c_left = 0;

  if(values[3] - values[5] < 0) /* linha do agente - passo */
  {
    l_up = values[3]; /* linha acima do agente igual linha do agente */
  }
  else{
    l_up = values[5]; /* linha acima do agente igual ao passo */
  }
  if(values[3] + values[5] > values[0]){ /* linha do agente + passo */
    l_down = values[0] - values[3] + 1;
  }
  else{
    l_down = values[5]; /* linha abaixo do agente igual ao passo */
  }
  if(values[4] - values[5]< 0){ /* coluna do agente - passo */
    c_left = values[4];
  }
  else{
    c_left = values[5];
  }
  if(values[4] + values[5] > values[1]){ /* coluna do agente + passo */
    c_right = values[1] - values[4] + 1;
  }
  else{
    c_right = values[5];
  }

  *l = l_up + l_down;
  *c = c_right + c_left;
}
