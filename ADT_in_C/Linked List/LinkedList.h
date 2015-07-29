//
//  LinkedList.h
//  ADT_in_C
//
//  Created by JIAYU ZENG on 7/9/15.
//  Copyright (c) 2015 jz. All rights reserved.
//
// All implementation and example refer to:
//
// Data Structures A Pseudocode Approach with C
//           by Richard F. Gilberg & Behrouz A. Forouzan 2nd Edition

// Some ADTs may have minor changes from the givens examples
//
// **** NOTE *********
//       1. This singly linked list will sort the data with the compare function when the data is inserted
//       2. It doesn't accept duplicate member (based on the key)
//       3. Doesn't contain dummy node


#ifndef __ADT_in_C__LinkedList__
#define __ADT_in_C__LinkedList__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node{
    void* dataPtr;
    struct list_node* next;
}LIST_NODE;

typedef struct{
    int count;
    LIST_NODE* pos;
    LIST_NODE* head;
    LIST_NODE* rear;
    
    int (*compare)(void* argu1, void* argu2);
}LIST;

LIST* createList(int(*compare)(void* argu1, void* argu2));
LIST* destroyList (LIST* list);

int addNode (LIST* pList, void* dataInput);
bool removeNode(LIST* pList, void* keyPtr);

bool searchList(LIST* pList, void* pArgu, void** dataOut);

bool retrieveNode(LIST* pList, void* pArgu, void** dataOut);

bool traverse(LIST* pList, int fromWhere, void** dataOut);

int getListCount(LIST* list);
bool isEmptyList(LIST* list);
bool isFullList(LIST* list);

static bool _insert (LIST *pList, LIST_NODE* pPre, void* dataInput);
static void _delete (LIST *pList, LIST_NODE* pPre, LIST_NODE* pLoc);
static bool _search (LIST *pList, LIST_NODE** pPre, LIST_NODE** pLoc, void* dataInput);

int _compareData(void* pArgu, void* curArgu);
int _compareRear();

#endif /* defined(__ADT_in_C__LinkedList__) */
