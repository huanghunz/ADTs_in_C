//
//  QueueUseCase.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "QueueUseCase.h"



// This use case generates 25 numbers and categorizing them into 4 queues

void categorizingData(){
    QUEUE* q0to9 = NULL;
    QUEUE* q10to19 = NULL;
    QUEUE* q20to29 = NULL;
    QUEUE* qOver29 = NULL;
    
    q0to9 = creatQueue();
    q10to19 = creatQueue();
    q20to29 = creatQueue();
    qOver29 = creatQueue();
    
    fillQueues(q0to9, q10to19, q20to29, qOver29);
    printQueues (q0to9, q10to19, q20to29, qOver29);
    
}

void fillQueues(QUEUE* q0to9, QUEUE* q10to19, QUEUE* q20to29, QUEUE* qOver29){
    int category = 0;
    int item = 0;
    int *dataPtr = NULL;
    
    srand(79);
    
    printf("Categorizing generated data:\n");
    for (int i = 1; i<=25; i++ ){
        if(!(dataPtr = (int*)malloc(sizeof(int)))){
            printf("Overflow in fillQueues\a\n");
            exit(100);
        }
        *dataPtr = item = rand() % 51;// 51 is just another random number
        category = item / 10;
        
        printf("%3d", item);
        if(!(i%11))
            printf("\n");
        
        switch (category) {
            case 0 :    enqueue(q0to9, dataPtr);
                        break;
            case 1 :    enqueue(q10to19, dataPtr);
                        break;
            case 2 :    enqueue(q20to29, dataPtr);
                        break;
            default:    enqueue(qOver29, dataPtr);
                        break;
        }// switch
    }// for
    
    printf("\nEnd of data categorization\n\n");
    return;
    
}// fillQueues

void printQueues(QUEUE* q0to9, QUEUE* q10to19, QUEUE* q20to29, QUEUE* qOver29){
    printf("Data    0.. 9:  ");
    printOneQueue(q0to9);

    printf("Data   10..19:  ");
    printOneQueue(q10to19);

    printf("Data   20..29:  ");
    printOneQueue(q20to29);

    printf("Data  over 29:  ");
    printOneQueue(qOver29);

}
void printOneQueue(QUEUE* queue){
    int lineCount = 0;
    int *dataPtr = NULL;
    
    while( !isEmptyQueue(queue)){
        dataPtr = dequeue(queue);
        if (lineCount++>= 10){
            lineCount = 1;
            printf("\n");
        }
        printf("%3d", *dataPtr);
    }// while
    
    printf("\n");
    return;
    
}