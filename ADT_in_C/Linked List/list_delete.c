//
//  list_delete.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 8/6/15.
//  Copyright (c) 2015 jz. All rights reserved.
//


#include "LinkedList.h"


bool removeNode(LIST* pList, void* keyPtr){
    bool found;
    LIST_NODE *pPre, *pLoc;
    
    found = _search(pList, &pPre, &pLoc, keyPtr);
    if (found)
        _delete(pList, pPre, pLoc);
    
    return found;
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
