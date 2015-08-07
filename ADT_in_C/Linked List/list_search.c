//
//  list_search.c
//  ADT_in_C
//
//  Created by JIAYU ZENG on 8/6/15.
//  Copyright (c) 2015 jz. All rights reserved.
//


#include "LinkedList.h"


// TODO: need more comment
// fromeWher: 0 to start at frist element
// return true if node located; return false if it's end of list
bool traverse(LIST* pList, int fromWhere, void** dataOut){
    if (pList->count == 0) return false;
    
    if (fromWhere == 0){
        pList->pos = pList->head;
        *dataOut = pList->pos->dataPtr;
        return true;
    }
    else{
        pList->pos = pList->pos->next;
        *dataOut = pList->pos->dataPtr;
        return true;
    }
}

bool retrieveNode(LIST* pList, void* pArgu, void** dataOut){
    bool found;
    
    LIST_NODE* pPre;
    LIST_NODE* pLoc;
    
    found = _search(pList, &pPre, &pLoc, pArgu);
    if (found){
        *dataOut = pLoc->dataPtr;
        return true;
    }
    
    *dataOut = NULL;
    return false;
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

static bool _search (LIST *pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* dataInput){
    
    #define COMPARE ( (( *pList->compare) (dataInput, (*pLoc)->dataPtr)) )
    
    #define COMAPRE_LAST ( (( *pList->compare) (dataInput, pList->rear->dataPtr)) )
    
    int result;
    
    *pPre = NULL;
    *pLoc = pList->head;
    
    if (pList->count == 0) return false;
   
    // Test for argument > last node in list
    if ( COMAPRE_LAST > 0){
        *pPre = pList->rear;
        *pLoc = NULL;
        return false;
    }
    
    while ( (result = COMPARE) > 0){
        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;
    }// end while
    
    if (result == 0){
        return true;
    }
    
    return false;
}

