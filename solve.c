/******************************************************************************
*
* File Name: solve.c
*	      (c) 2018 AED
*
* COMMENTS
*    Resolucao dos problemas em funcao do valor de k
*
*****************************************************************************/
#include "solve.h"


void max_energy(STACK **pstack, int row, int col, int **matrix, int **m_aux, int _depth, int *values, int var, STACK **bjork)
{
  int i = 1, dir = 4;
  int x = 0, y = 0;

  if(matrix[1][0] == 1 || matrix[1][0] == 2){
    return;
  }
  /*stackPrint(*pstack);*/

  if(_depth > 0){

    /*printf("depth in\n\n\n");*/
    for(i = 1; i <= dir; i++){
      x = row;
      y = col;
      /*printf("x: %d,  y: %d, i: %d\n", x, y, i);*/

      if(posso_ir(matrix, m_aux, i, &x, &y, values)){
        matrix[0][0] += matrix[x][y];
        stackPut (pstack, x, y, matrix[x][y]);
        lights(m_aux, x, y, values, 1);
        _depth -= 1;
        max_energy(pstack, x, y, matrix, m_aux, _depth, values, var, bjork);

        if(_depth == 0){
          if(matrix[0][0]>matrix[0][1]){ /* matrix[0][0] = soma do caminho actual*/
            matrix[0][1] = matrix[0][0]; /*matrix[0][1] = melhor caminho */
            while(!stackEmpty(*bjork)){
              stackGet(bjork);
            }
            preenche_bjork(pstack, bjork, values);
          }
          if(var == 1){ /* objectivo 1 - energia minima */
            if (matrix[0][1] >= values[2]){ /*se atingir a energia minima, para!*/
              while(!stackEmpty(*bjork)){
                stackGet(bjork);
              }
              matrix[1][0] = 2;
              preenche_bjork(pstack, bjork, values);
              /*stackPrint(*bjork);*/

              return;
            }

          }

          /*matrix[0][0] = values[6];*/
        }

        _depth += 1;
        lights(m_aux, x, y, values, 0);
        matrix[0][0] -= matrix[x][y];
        stackGet(pstack);
      }

    }
  }
}

