//
//  list_add.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 8/6/15.
//  Copyright (c) 2015 jz. All rights reserved.
//

#include "LinkedList.h"


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
