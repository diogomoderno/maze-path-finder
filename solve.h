/******************************************************************************
*
* File Name: solve.h
*	      (c) 2018 AED
*
* COMMENTS
*    Resolucao dos problemas em funcao do valor de k
*
*****************************************************************************/
#ifndef _SOLVE_H
#define _SOLVE_H



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "util.h"


/******************************************************************************
* max_energy()
*
* Arguments: pointer to stack, ints for fields of element, pointer to matrix,
* pointer to aux matrix, int depth, pointer to values, int variante,
* pointer to aux stack
*
* Returns: (void)
* Side-Effects: none
*
* Description: recursion (checks if the move is valid and moves forward or
* backward)
*
*****************************************************************************/
void max_energy(STACK **pstack, int row, int col, int **matrix, int **m_aux, int _depth, int *values, int var, STACK **bjork);




#endif
