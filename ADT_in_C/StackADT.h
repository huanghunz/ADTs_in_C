//
//  StackADT.h
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#ifndef __ADT_in_C__StackADT__
#define __ADT_in_C__StackADT__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
// use the following if stdbool.h is not supported
// typedef enum {false true} bool;

typedef struct stack_node{
    void *dataPtr;
    struct stack_node *link;

}STACK_NODE;

typedef struct {
    int count;
    STACK_NODE *top;
}STACK;

STACK* createStack(void);

bool pushStack(STACK* stack, void* dataInput);
void* popStack(STACK* stack);
void* peekStack(STACK* stack);
bool isEmptyStack(STACK* stack);
bool isFullStack (STACK* stack);
int getStackCount(STACK* stack);
STACK* destroyStack(STACK* stack);

#endif /* defined(__ADT_in_C__StackADT__) */
