//
//  QueueADT.h
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#ifndef __ADT_in_C__QueueADT__
#define __ADT_in_C__QueueADT__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node{
    void* dataPtr;
    struct queue_node* link;
}QUEUE_NODE;

typedef struct{
    int count;
    QUEUE_NODE *front;
    QUEUE_NODE *rear;
}QUEUE;


QUEUE* creatQueue(void);
bool enqueue(QUEUE* queue, void* dataInput);
void* dequeue(QUEUE* queue);
void* getQueueFront(QUEUE* queue);
void* getQueueRear(QUEUE* queue);
int getQueueCount(QUEUE* queue);
bool isEmptyQueue(QUEUE* queue);
bool isFullQueue(QUEUE* queue);
QUEUE* destroyQUEUE(QUEUE* queue);

#endif /* defined(__ADT_in_C__QueueADT__) */
