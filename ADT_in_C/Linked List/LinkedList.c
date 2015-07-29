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
    return NULL;
}


bool removeNode(LIST* pList, void* keyPtr){
    bool found;
    LIST_NODE *pPre, *pLoc;
    
    found = _search(pList, &pPre, &pLoc, keyPtr);
    if (found)
        _delete(pList, pPre, pLoc);
    
    return found; 
}

bool searchList(LIST* pList, void* pArgu, void** dataOut){
    bool found;
    
    LIST_NODE* pPre;
    LIST_NODE* pLoc;
    
    found = _search(pList, &pPre, &pLoc, pArgu);
    if (found){
        *dataOut = pLoc->dataPtr;
    }
    else{
        *dataOut = NULL;
    }
    
    return found;
}

bool retrieveNode(LIST* pList, void* pArgu, void** dataOut);

bool traverse(LIST* pList, int fromWhere, void** dataOut);

int getListCount(LIST* list);
bool isEmptyList(LIST* list);
bool isFullList(LIST* list);


int addNode (LIST* pList, void* dataInput){
    bool found;
    bool success;
    
    LIST_NODE* pPre;
    LIST_NODE* pLoc;
    
    found = _search(pList, &pPre, &pLoc, dataInput);
    if (found){
        return  +1; // duplicate keys not allowed
    }
    success = _insert(pList, pPre, dataInput);// O(1) insert because the pre location was found
    
    if(!success){
        return -1;// memory overflow
    }
    return 0;
}

static bool _insert (LIST *pList, LIST_NODE* pPre, void* dataInput){
    LIST_NODE* pNew;
    
    if ( !(pNew = (LIST_NODE*)malloc(sizeof(LIST_NODE)))){
        return false;
    }
    
    pNew->dataPtr = dataInput;
    pNew->next = NULL;
    
    if (pPre == NULL){ // if the is the max/min data, insert it in the first place
        pNew->next = pList->head;
        pList->head = pNew;
        if (pList->count == 0) // if this is the first node
            pList->rear = pNew;
        
    }
    else{
        pNew->next = pPre->next;
        pPre->next = pNew;
        
        if ( pNew->next == NULL) // if this node is the last node in the list
            pList->rear = pNew; //
    }
    
    (pList->count)++;
    return true;
}

static void _delete (LIST *pList, LIST_NODE* pPre, LIST_NODE* pLoc){
    
    // if deleting the first node
    if (pPre == NULL){
        pList->head = pLoc->next;
    }
    else{
        pPre->next = pLoc->next;
    }
    
    if (pLoc->next == NULL){
        pList->rear = pPre;
    }
    
    (pList->count)--;
    free(pLoc);
    
    return;
}
static bool _search (LIST *pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* dataInput){
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
