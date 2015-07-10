//
//  StackUseCase.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "StackUseCase.h"



// Convert Decimal to Binary
void converDecimalToBinary(){
    
    unsigned int num = 2 ;
    int numCopy = num;
    int* digit;

    STACK* stack;
    
    stack = createStack(); // memory allocated in create function
    
    
    while (num > 0){
        digit = (int*)malloc(sizeof(int)); // allocate space for each digit
        
        *digit = num % 2; // converting
        
        pushStack(stack, digit);// here digit is a pointer
        num = num/2;
    }
    
    while (getStackCount(stack) < 4){
        digit = (int*)malloc(sizeof(int));
        *digit = 0;
        pushStack(stack, digit);
    }
    
    printf("The binary number of %d is : ", numCopy );
    while (!isEmptyStack(stack)){
        digit = (int*)popStack(stack);// need to cast the void*
        printf("%d", *digit); // deference an int pointer
    }
    printf("\n\n");
    destroyStack(stack);
    
    return ;
}

void eightQueens(){
    int boardSize;
    STACK *stack;
    
    boardSize = getBoardSize();
    stack = createStack();
    
    fillBoard(stack,boardSize);
    printBoard(stack, boardSize);
    destroyStack(stack);
    
    return;
}