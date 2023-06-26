/******************************************************************************
*
* File Name: solve.c
*
*
* COMMENTS
*    Problem resolution regarding the value of the step given
*
*****************************************************************************/
#include "solve.h"


void max_energy(STACK **pstack, int row, int col, int **matrix, int **m_aux, int _depth, int *values, int var, STACK **pointer)
{
  int i = 1, dir = 4;
  int x = 0, y = 0;

  if(matrix[1][0] == 1 || matrix[1][0] == 2){
    return;
  }

  if(_depth > 0){

    for(i = 1; i <= dir; i++){
      x = row;
      y = col;
      if(advance(matrix, m_aux, i, &x, &y, values)){
        matrix[0][0] += matrix[x][y];
        stackPut (pstack, x, y, matrix[x][y]);
        lights(m_aux, x, y, values, 1);
        _depth -= 1;
        max_energy(pstack, x, y, matrix, m_aux, _depth, values, var, pointer);

        if(_depth == 0){
          if(matrix[0][0]>matrix[0][1]){ /* matrix[0][0] = sum of the current path*/
            matrix[0][1] = matrix[0][0]; /*matrix[0][1] = best path so far */
            while(!stackEmpty(*pointer)){
              stackGet(pointer);
            }
            fill_stack(pstack, pointer, values);
          }
          /* first goal: minimum positive energy */
          if(var == 1){ 
            /*if it reaches the minimum energy, stops*/
            if (matrix[0][1] >= values[2]){ 
              while(!stackEmpty(*pointer)){
                stackGet(pointer);
              }
              matrix[1][0] = 2;
              fill_stack(pstack, pointer, values);
              return;
            }
          }
        }
        _depth += 1;
        lights(m_aux, x, y, values, 0);
        matrix[0][0] -= matrix[x][y];
        stackGet(pstack);
      }

    }
  }
}

