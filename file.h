/******************************************************************************
*
* File Name: file.h
*
*
* COMMENTS
*    Open/read/write files
*
*****************************************************************************/
#ifndef _FILE_H
#define _FILE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/******************************************************************************
* check_file()
*
* Arguments: pointer to file
* Returns: (void)
* Side-Effects: none
*
* Description: checks if extension is correct
*
*****************************************************************************/
void check_file(char *fich);


/******************************************************************************
* get_values()
*
* Arguments: pointer to file in, pointer to file out, pointer to vector values
* Returns: pointer to vector with parameters from file
* Side-Effects: none
*
* Description: allocates memory for values vector and creates the vector
*
*****************************************************************************/
int* get_values(FILE *fp_entry, FILE *fp_out, int *values);


/******************************************************************************
* open_file()
*
* Arguments: pointer to name of file, pointer to (read/append)
* Returns: pointer to file
* Side-Effects: none
*
* Description: opens file
*
*****************************************************************************/
FILE *open_file(char *name, char *mode);


/******************************************************************************
* read_matrix()
*
* Arguments: pointer to file in, pointer to values, pointer to matrix
* Returns: pointer to matrix
* Side-Effects: none
*
* Description: allocates memory for matrix and writes positions from file
*
*****************************************************************************/
int **read_matrix(FILE *fp_entry, int *values, int** matrix);


/******************************************************************************
* skip()
*
* Arguments: pointer to file in, pointer to values
* Returns: (void)
* Side-Effects: none
*
* Description: skips number of positions in matrix (when the problem has
* no solution)
*
*****************************************************************************/
void skip(FILE *fp_entry, int *values);


#endif
