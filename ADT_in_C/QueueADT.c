//
//  QueueADT.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "QueueADT.h"

QUEUE* creatQueue(void){
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    
    if (!queue){
        printf("Failed to create queue.");
        return NULL;
    }
    
    queue->count = 0;
    queue->front = queue->rear = NULL;

    return queue;
}

bool enqueue(QUEUE* queue, void* dataInput){
    QUEUE_NODE *newData = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    
    if (!newData){
        printf ("Fail to allocate new queue node");
        return false;
        
    }
    newData->dataPtr = dataInput;
    newData->link = NULL;
    
    if (queue->front == NULL){
        queue->front  = newData;
    }
    else{
        queue->rear->link = newData;
    }
    
    queue->rear= newData;
    (queue->count)++;
    
    return  true;
    
}

void* dequeue(QUEUE* queue){
    void* returnData;
    QUEUE_NODE* temp;
    
    if (queue->count == 0){
        printf ("Fail to dequeue, no data in the queue");
        return NULL;
    }
    
    temp = queue->front;
    returnData = queue->front->dataPtr;
    if(queue->count == 1){
        queue->rear = queue->front = NULL;
    }
    else{
        queue->front = queue->front->link;
    }
    
    (queue->count)--;
    free(temp);
    
    return returnData;
    
}


void* getQueueFront(QUEUE* queue){
    if(queue->count != 0)
        return queue->front->dataPtr;
    return NULL;
}

void* getQueueRear(QUEUE* queue){
    if(queue->count != 0)
        return queue->rear->dataPtr;
    return NULL;
}

int getQueueCount(QUEUE* queue){
    return queue->count;
}

bool isEmptyQueue(QUEUE* queue){
    return (queue->count == 0)? true:false;
}

bool isFullQueue(QUEUE* queue){
    QUEUE_NODE* temp = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if (!temp){
        return true;
    }
    free(temp);
    temp = NULL;
    return false;
}

QUEUE* destroyQUEUE(QUEUE* queue){
    QUEUE_NODE* temp;
    
    if(queue){
        while ((queue->front != NULL)) {
            temp = queue->front;
            queue->front = queue->front->link;
            
            free(temp->dataPtr);
            free(temp);
        }
        free(queue);
    }
    return NULL;
}
