//
//  StackADT.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "StackADT.h"


STACK* createStack(void){
    STACK* stack = NULL;
    
    stack = (STACK*)malloc(sizeof(STACK));
    if (stack){
        stack->count = 0;
        stack->top = NULL;
    }
    else{
        printf ("Fail to create stack, return NULL");
    }
    return stack;
}// create stack


bool pushStack(STACK* stack, void* dataInput){
    STACK_NODE* newPtr;
    
    newPtr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if (!newPtr){
        printf ("Fail to allocate new stack node");
        return false;
    }
    
    newPtr->dataPtr = dataInput;
    newPtr->link = stack->top; // connect to the latest node in the stack
    stack->top = newPtr;
    
    (stack->count)++;
    
    return true;
}// push stack

void* popStack(STACK* stack){
    void* dataPopped;
    STACK_NODE* temp;
    
    if (stack->count == 0){
        printf ("Fail to pop, no data in the stack");
        dataPopped = NULL;
    }
    else{
        temp = stack->top;
        dataPopped = stack->top->dataPtr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;
    }
    return dataPopped;
}

void* peekStack(STACK* stack){
    
    if (stack->count == 0){
        printf("Fail to peek, no data in the stack ");
        return  NULL;
    }
    else{
        return stack->top->dataPtr;
    }
    
}

bool isEmptyStack(STACK* stack){
    return (stack->count == 0);
}

bool isFullStack (STACK* stack){
    STACK_NODE* temp;
    
    temp = (STACK_NODE*)malloc(sizeof(*(stack->top)));
    if (!temp){
        return true;
    }
    free(temp);
    temp = NULL;
    return false;
}

int getStackCount(STACK* stack){
    return (stack->count);
}


STACK* destroyStack(STACK* stack){
    STACK_NODE* temp;
    
    if (stack){
        while(stack->top){
            
            free(stack->top->dataPtr); // free the data of the pointer stack
            temp = stack->top;
            
            stack->top = stack->top->link;
            
            free(temp);// then free the pointer of the stack
            
        }
        free((stack));
    }
    return NULL;
}



