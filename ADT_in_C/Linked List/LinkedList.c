//
//  LinkedList.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "LinkedList.h"


LIST* createList(int(*compare)(void* argu1, void* argu2)){
    LIST* list = (LIST*)malloc(sizeof(LIST));
    
    if(!list){
        printf("Failed to create LIST.\n");
        return NULL;
    }
    
    list->count = 0;
    list->head = list->rear = NULL;
    list->pos = NULL;
    list->compare = compare;
    
    return list;
    
}
LIST* destroyList (LIST* list){
    LIST_NODE* delPtr;
    
    if (list){
        while (list->count > 0){
            free(list->head->dataPtr);
            
            delPtr = list->head;
            list->head = list->head->next;
            list->count--;
            free(delPtr);
        }
        free(list);
    }
    
    return NULL;
}




int getListCount(LIST* list){
    return list->count;
}
bool isEmptyList(LIST* list){
    return (list->count == 0);
}

bool isFullList(LIST* list){
    LIST_NODE* temp;
    if ( (temp = (LIST_NODE*)malloc(sizeof(*(list->head ))))){
        free(temp);
        return false;
    }
    return true;
}




int _compareData(void* pArgu, void* curArgu){
    if (pArgu == curArgu){
        return 0;
    }
    else{
        return -1;
    }
}
