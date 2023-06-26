/******************************************************************************
*
* File Name: util.h
*
*
* COMMENTS
*    Other functions
*
*****************************************************************************/
#ifndef _UTIL_H
#define _UTIL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "mem.h"
#include "file.h"


/******************************************************************************
* check_val()
*
* Arguments: pointer to values
* Returns: 1 if values are valid, 0 if not
* Side-Effects: none
*
* Description: checks if parameters from file are valid
*
*****************************************************************************/
int check_val(int *values); /* retorna 1 se os valores estao correctos */


/******************************************************************************
* verify()
*
* Arguments: pointer to file out, pointer to stack,  pointer to values,
* pointer to matrix
*
* Returns: (void)
* Side-Effects: none
*
* Description: choice of objective
*
*****************************************************************************/
void verify(FILE *fp_out, STACK **pstack, int *values, int **matrix);


/******************************************************************************
* lights()
*
* Arguments: pointer to auxiliary matrix, int lines of original matrix,
*  int cols of original matrix, pointer to values, int state
*
* Returns: (void)
* Side-Effects: none
*
* Description: turns light on or off
*
*****************************************************************************/
void lights(int **m_aux, int row, int col, int *values, int state);


/******************************************************************************
* verify_light()
*
* Arguments: pointer to auxiliary matrix, int lines of original matrix,
*  int cols of original matrix, pointer to values
* pointer to matrix
*
* Returns: light of specific entry of matrix
* Side-Effects: none
*
* Description: checks if light is on or off
*
*****************************************************************************/
int verify_light(int **m_aux, int row, int col, int *values);


/******************************************************************************
* posso_ir()
*
* Arguments: pointer to matrix, pointer to auxiliary matrix,
* int i(choice of direction)
* int lines of original matrix, int cols of original matrix, pointer to values
*
* Returns: int (1 or 0)
* Side-Effects: none
*
* Description: checks if next move is worth taking
*
*****************************************************************************/
int advance(int **matrix, int **m_aux, int i, int *row, int *col, int *values);


/******************************************************************************
* light_agent()
*
* Arguments: pointer to auxiliary matrix, pointer to values
*
* Returns: (void)
* Side-Effects: none
*
* Description: turns on light of agent in aux matrix
*
*****************************************************************************/
void light_agent(int **m_aux, int *values);


/******************************************************************************
* well_defined()
*
* Arguments: pointer to file, pointer to values
*
* Returns: int (0 or 1)
* Side-Effects: none
*
* Description: returns 1 if there is no solution within
*
*****************************************************************************/
int well_defined(FILE *fp_out, int *values);


void print_matrix(int** m_aux, int *values); /* aux function not used */


#endif
