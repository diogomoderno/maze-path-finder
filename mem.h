/******************************************************************************
*
* File Name: mem.h
*	      (c) 2018 AED
*
* COMMENTS
*    Memory operations
*
*****************************************************************************/
#ifndef _MEM_H
#define _MEM_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "stack.h"


/******************************************************************************
* free_matrix()
*
* Arguments: pointer to matrix, pointer to values
* Returns: (void)
* Side-Effects: none
*
* Description: frees matrix
*
*****************************************************************************/
void free_matrix(int **matrix, int* values);

/******************************************************************************
* alloc_matrix()
*
* Arguments: pointer to matrix, pointer to values
* Returns: pointer to matrix
* Side-Effects: none
*
* Description: allocates memory for matrix
*
*****************************************************************************/
int** alloc_matrix(int **matrix, int *values);

/******************************************************************************
* free_matrix_aux()
*
* Arguments: pointer to auxiliary matrix, pointer to values
* Returns: (void)
* Side-Effects: none
*
* Description: frees auxiliary matrix
*
*****************************************************************************/
void free_matrix_aux(int **m_aux, int *values);


/******************************************************************************
* matrix_k()
*
* Arguments: m_aux, k
* Returns: aux matrix for lights
* Side-Effects: none
*
* Description: allocates space for matrix
*
*****************************************************************************/
int **matrix_k(int **m_aux, int *values);

/****************************************************************************
* dim_matrix_aux()
*
* Arguments: pointer to values, pointer to row, pointer to column
* Returns: (void)
* Side-Effects: none
*
* Description: calculates dimension of auxiliar matrix
*
*****************************************************************************/
void dim_matrix_aux(int *values, int *l, int *c);





#endif
