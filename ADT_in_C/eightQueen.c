//
//  eightQueen.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "eightQueen.h"

int getBoardSize(){
    int boardSize;
    
    printf("Please enter a number that is \ngreater than 3 and less than 9 \nfor board size: ");
    
    while (scanf("%d", &boardSize),  boardSize < 4|| boardSize > 8){
        printf("\nYour input is %d, \nplease enter a number that is \ngreater than 3 and less than 9: ", boardSize);
    }
    
    return boardSize;
    
}

void fillBoard(STACK* stack, int boardSize){
    int row = 0;
    int col = 0;
    int board[9][9] = {0};
   
    E_Q_POSITION* eqPos;
    
    
    row = 1;
    col = 0;
    
    while( row <= boardSize){
        while (col <= boardSize && row <= boardSize){
            col++;
            if (!guarded(board, row, col, boardSize)){
                board[row][col] = 1;
                eqPos = (E_Q_POSITION*)malloc(sizeof(E_Q_POSITION));
                
                eqPos->row = row;
                eqPos->col = col;
                pushStack(stack, eqPos);
                
                row++;
                col = 0;
            }
            while (col >= boardSize) {
                eqPos = popStack(stack);
                row = eqPos->row;
                col = eqPos->col;
                board[row][col] = 0;
                free(eqPos);
            }// while col >=
        }//while col <=
    }//while row <=
    
    return;

}



// board[0][9] the first dimension is actually unnecessary. It's ignored by the compiler.
// also "9" should be a constant not a variable
bool guarded(int board[][9], int chkRow, int chkCol, int boardSize){
    int row = 0;
    int col = chkCol;
    
    // current col
    for (row = 1; row<= chkRow; row++){
        if (board[row][col] == 1)
            return true;
    }
    
    
    // check diagonal right-up
    for (row = chkRow - 1, col = chkCol+1; row > 0 && col <= boardSize; row--, col++){
        
        if (board[row][col] == 1 ){
            return true;
        }
    }
    
    // check diagonal left-up
    for (row = chkRow-1, col = chkCol-1; row >0 && col >0; row--, col--){
        if (board[row][col] == 1){
            return  true;
        }
    }
    
    return false;
}


void printBoard(STACK* stack, int boardSize){
    int col;
    E_Q_POSITION* eqPos;
    STACK* pOutStack;
    
    if (isEmptyStack(stack)){
        printf("There are no positions on this board.\n");
        return;
    }
    
    printf("Place queens in following positions:\n");
    
    pOutStack = createStack();
    
    while(!isEmptyStack(stack)){
        eqPos = popStack(stack);
        pushStack(pOutStack, eqPos);
    }
    
    while (!isEmptyStack(pOutStack)) {
        eqPos = popStack(pOutStack);
        printf("Row %d-Col %d: \t|", eqPos->row, eqPos->col);
        
        for (col =1; col <= boardSize; col++){
            if (eqPos->col == col){
                printf(" Q |");
            }
            else{
                printf("   |");
            }
        }// end for
        printf("\n");
    }// end while
    
    destroyStack(pOutStack);
    return;
    
}


