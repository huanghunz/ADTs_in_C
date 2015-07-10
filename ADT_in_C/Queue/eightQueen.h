//
//  eightQueen.h
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#ifndef __ADT_in_C__eightQueen__
#define __ADT_in_C__eightQueen__

#include <stdio.h>
#include "StackADT.h"

typedef struct{
    int row;
    int col;
}E_Q_POSITION;

int     getBoardSize();
void    fillBoard(STACK* stack, int boardSize);
bool    guarded(int board[][9], int chkRow, int chkCol, int boardSize);
void    printBoard(STACK* stack, int boardSize);
#endif /* defined(__ADT_in_C__eightQueen__) */
