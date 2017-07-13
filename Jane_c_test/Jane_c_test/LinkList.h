//
//  LinkList.h
//  Jane_c_test
//
//  Created by Jane Jane on 7/12/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#pragma mark -
#pragma mark Link List

struct Node {
    int value;
    int count;
    struct Node *next;
};
typedef struct Node Node;


struct List {
    int length;
    Node *root;
};
typedef struct List List;

List* createList();
void pushBackTolist(List *list, int value);

int lengthOfList(List *list);
void removeFromList(List *list, int value);
void removeAll(List *list);
bool findValue(List *list, int value);
void printList(List *list);
List* interleaveList(List *listA, List *listB);
void reverseList(List *list);

// 2016-10-10 sort list
void sortList(List *inputList);

// 2016-10-12
void alternativeSplit(const List* inputList, List* outputList1, List* outputList2);

// 2017-07-12
List* copyList(List *src);


#endif /* LinkList_h */
