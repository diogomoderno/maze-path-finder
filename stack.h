/******************************************************************************
*
* File Name: stack.h
*          (c) 2018 AED
*
* COMMENTS
*    stack implementation
*
*****************************************************************************/
#ifndef _stack_H
#define _stack_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _element ELEMENT;
typedef struct _stack STACK;


/******************************************************************************
* stackInit()
*
* Arguments: pointer to stack
* Returns: stack
* Side-Effects: none
*
* Description: initialises stack with NULL
*
*****************************************************************************/
void stackInit(STACK**pstack);


/******************************************************************************
* stackEmpty()
*
* Arguments: pointer to stack
* Returns: NULL
* Side-Effects: none
*
* Description: empties stack
*
*****************************************************************************/
int stackEmpty(STACK *pstack);


/******************************************************************************
* stackPut()
*
* Arguments: pointer to stack and parameters for  new element
* Returns: (void)
* Side-Effects: none
*
* Description: adds an element to stack
*
*****************************************************************************/
void stackPut (STACK ** pstack, int row, int col, int e);


/******************************************************************************
* stackGet()
*
* Arguments: pointer to stack
* Returns: (void)
* Side-Effects: none
*
* Description: removes element from stack
*
*****************************************************************************/
void stackGet(STACK **pstack);


/******************************************************************************
* preenche_bjork()
*
* Arguments: pointer to stack, pointer to aux stack, pointer to values
* Returns: (void)
* Side-Effects: none
*
* Description: copies best path to a different stack
*
*****************************************************************************/
void preenche_bjork(STACK **pstack, STACK **bjork, int *values);


/******************************************************************************
* copy_to_file()
*
* Arguments: pointer to file out, pointer to aux stack
* Returns: (void)
* Side-Effects: none
*
* Description: prints path in file out
*
*****************************************************************************/
void copy_to_file(FILE *fp_out, STACK *bjork);


void stackPrint(STACK *pstack); /* aux function not used */





#endif
