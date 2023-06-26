/******************************************************************************
*
* File Name: stack.c
*
*
* COMMENTS
*    stack implementation
*
*****************************************************************************/

#include "stack.h"
#include "util.h"


struct _element
{
	int i;
	int j;
	int energy;
};

struct _stack
{
	ELEMENT element;
	STACK * next;
};

void stackInit(STACK ** pstack)
{
	*pstack = NULL;
}

int stackEmpty(STACK * pstack)
{
	return(pstack == NULL);
}

void stackPrint(STACK *pstack)
{
	if(pstack==NULL)
	{
		return;
	}
	printf("i: %d, j: %d, e: %d\n", pstack->element.i, pstack->element.j, pstack->element.energy);
	stackPrint(pstack->next);

}


void stackPut(STACK **pstack, int row, int col, int e)
{
	STACK *ap;
	ap = (STACK*)malloc(sizeof(STACK));
	if (ap == NULL) {
		return;
	}
	ap->element.i = row;
	ap->element.j = col;
	ap->element.energy = e;
	ap->next = *pstack;
	*pstack = ap;
}

void stackGet(STACK ** pstack)
{
	STACK *ap = *pstack;
	if(stackEmpty(*pstack)){
		return;
	}
	*pstack = (*pstack)->next;
	free(ap);
}

void fill_stack(STACK **pstack, STACK **bjork, int *values)
{
	int k = 0;
	STACK *ap = *pstack;

	for(k = 0; k < values[5]; k++){
		stackPut(bjork, ap->element.i, ap->element.j, ap->element.energy);
		ap = ap->next;
	}
}

void copy_to_file(FILE *fp_out, STACK *stack_p)
{
	if(stack_p == NULL){
		return;
	}
	fprintf(fp_out,"%d %d %d\n",stack_p->element.i, stack_p->element.j, stack_p->element.energy);
	copy_to_file(fp_out, stack_p->next);
}
