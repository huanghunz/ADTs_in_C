//
//  QueueUseCase.h
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#ifndef __ADT_in_C__QueueUseCase__
#define __ADT_in_C__QueueUseCase__

#include <stdio.h>
#include "QueueADT.h"

void categorizingData();

void fillQueues(QUEUE* q0to9, QUEUE* q10to19, QUEUE* q20to29, QUEUE* qOver29);
void printQueues(QUEUE* q0to9, QUEUE* q10to19, QUEUE* q20to29, QUEUE* qOver29);
void printOneQueue(QUEUE* queue);

#endif /* defined(__ADT_in_C__QueueUseCase__) */
