//
//  LinkList.c
//  Jane_c_test
//
//  Created by Jane Jane on 7/12/17.
//  Copyright © 2017 Johnny. All rights reserved.
//

#include <stdio.h>
#include "Linklist.h"
#include "math.h"
#include "stdbool.h"



#pragma mark -
#pragma mark Link List
Node* newNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

List* createList() {
    List *newList = malloc(sizeof(List));
    newList->length = 0;
    newList->root = NULL;
    return newList;
}

void pushBackTolist(List *list, int value) {
    Node *currentNode = list->root;
    bool nodeExisted = false;
    
    if (currentNode == NULL) {
        list->root= newNode(value);
        list->length++;
        return;
    }
    
    while (1) {
        if (currentNode->value == value) {
            nodeExisted = true;
            break;
        } else if (currentNode->next == NULL) {
            nodeExisted = false;
            break;
        } else {
            currentNode = currentNode->next;
        }
    }
    
    if (nodeExisted) {
        currentNode->count++;
    } else {
        currentNode->next = newNode(value);
    }
    list->length++;
    return;
}



int lengthOfList(List *list){
    return (list->length);
}


void removeFromList(List *list, int value){
    
    Node *currentNode = list->root;
    bool nodeExisted = false;
    
    if (currentNode == NULL) {
        printf("Error: List Does Not Exist!");
        return;
    }else if (currentNode->value == value){ //first Node of the list
        if (currentNode->count != 1) {
            currentNode->count--;
        }else{ //count=1
            if (currentNode->next==NULL) {
                free(list->root);
                list->root=NULL;
            }else{
                Node* storeNode = currentNode->next;
                free(currentNode);
                list->root=storeNode;
            }
        }
        (list->length)--;
        return;
    }
    
    while (1) {
        if ((currentNode->next)->value == value) { //exist
            nodeExisted = true;
            break;
        }else if ((currentNode->next)->next == NULL){ //not exist
            nodeExisted = false;
            break;
        }else{
            currentNode = currentNode->next; //continue finding
        }
    }
    
    if (nodeExisted == true) {
        if ((currentNode->next)->count!=1) { //more the one exist
            (currentNode->next)->count--;
        }else if((currentNode->next)->next==NULL){ //only one exist at the last node
            free(currentNode->next);
            currentNode->next=NULL;
        }else{ //Only one locate in the middle of the list
            Node *storeNode;
            storeNode=(currentNode->next)->next;
            free(currentNode->next);
            currentNode->next=storeNode;
        }
    }else{ //Node does not exit
        printf("the value does not exit in the list\n");
        return;
    }
    list->length--;
    return;
    
}


void removeAll(List *list){
    
    
    Node* currentNode =list->root;
    Node* nextNode=NULL;
    
    if (list->root==NULL) {
        printf("nothing to remove, the list is empty");
        return;
    }
    while (currentNode!=NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode=nextNode;
    }
    
    list->length=0;
    list->root=NULL;
    return;
}

bool findValue(List *list, int value){
    Node* currentNode =list->root;
    
    if (list->root==NULL) {
        printf("The list is empty, nothting to find");
        return false;
    }
    while (currentNode!=NULL) {
        if (currentNode->value==value) {
            printf("We can find %d\n", value);
            return true;
        }
        currentNode = currentNode->next;
    }
    printf("We cannot find %d\n", value);
    return false;
}


void printList(List *list) {
    Node *currentNode = list->root;
    int i;
    if (list->root==NULL) {
        printf("list is empty, nothing to print\n");
        return;
    }
    
    while (1) {
        if (currentNode == NULL) {
            break;
        } else {
            for (i = 0; i < currentNode->count; i++) {
                printf("%d ", currentNode->value);
            }
            currentNode = currentNode->next;
        }
    }
    
    printf("(length of the list is %d)\n", list->length);
    return;
}


//9-29-2016 spent 30mins to wirte the reverseList function
void reverseList(List *list){
    
    Node* currentNode = list->root;
    Node* lastNode = NULL;
    Node* tempNode = NULL;
    Node* processedNode = NULL;
    
    if (list->root == NULL) {
        printf("The list is empty. Nothing to reverse");
        return;
    }
    if ((list->root)->next == NULL){
        printf("There is only one Node on the list, nothing to reverse");
        return;
    }
    
    while (currentNode->next != NULL) { //find the last Node
        if (currentNode == list->root) {
            //make root Node the last Node
            currentNode = currentNode->next;
            lastNode = list->root;
            lastNode->next = NULL;
            processedNode = lastNode;
        }else{
            tempNode = currentNode;
            currentNode = currentNode->next;
            tempNode->next = processedNode;
            processedNode = tempNode;
        }
    }
    //now currentNode is the last Node which is the root Node
    list->root = currentNode;
    (list->root)->next = processedNode;
    
    return;
}

// 07-12-2017 rewrite reverse list function


List* interleaveList(List *listA, List *listB){
    //1. if B is empty, output A onlu. if A is empty, output B only
    //2. the first element is always the first Node of list A
    //3. there is only one Node in both list
    
    //initialize combinedList
    List* combinedList = malloc(sizeof(List));
    combinedList->length = 0;
    combinedList->root = NULL;
    
    //variable used in the function
    Node* currentNodeA = listA->root;
    Node* currentNodeB = listB->root;
    Node* previousNode = NULL;
    
    
    //1. if B is empty, output A only. if A is empty, output B only
    if (listA->root == NULL && listB->root == NULL) {
        return combinedList;
    }
    if (listA->root == NULL && listB->root != NULL) {
        return listB;
    }
    if (listA->root != NULL && listB->root == NULL) {
        return listA;
    }
    
    
    //there is only one Node in both list
    if (listA->root->next == NULL && listB->root->next == NULL) {
        combinedList->root = listA->root;
        combinedList->root->next = listB->root;
        return combinedList;
    }
    
    //////////// All the special cases have been considered above./////////////
    
    // the first element is always the first Node of list A
    combinedList->root = listA->root;
    currentNodeA = currentNodeA->next; //save the next starting NodeA
    currentNodeB = currentNodeB->next; //save the next starting NodeB
    listA->root->next = listB->root; //cancade the Node;
    previousNode = listB->root; //save the last processed Node in the combinedList
    
    //special case for 2 Node on listA, 1 Node on listB
    if(currentNodeB == NULL){
        previousNode->next=currentNodeA;
        return combinedList;
    }
    
    //special case for 2 Node on listB, 1 Node on listA
    if(currentNodeA==NULL){
        previousNode->next=currentNodeB;
        return combinedList;
    }
    
    //if we get here, means there are more than 1 node in both list;
    while (currentNodeA != NULL && currentNodeB != NULL) {
        previousNode->next = currentNodeA;
        currentNodeA = currentNodeA->next;
        previousNode->next->next = currentNodeB;
        previousNode = currentNodeB;
        currentNodeB = currentNodeB->next;
    }
    
    
    //if we get here, means one of the list is at the last Node
    
    // if listB's Node is more than listA
    if(currentNodeB != NULL && currentNodeA == NULL){
        previousNode->next = currentNodeB;
        return combinedList;
    }
    
    
    // if listA's Node is more than listB
    if(currentNodeA != NULL && currentNodeB == NULL){
        previousNode->next = currentNodeA;
        return combinedList;
    }
    
    //if listA has the same node number with listB
    if (currentNodeB == NULL && currentNodeA == NULL){
        previousNode->next = NULL;
        return combinedList;
    }
    
    
    return combinedList;
}

//2016-10-10 sort list
// put the Node onto the output list in the correct space

void goSort (Node* workingNode, List* outputList){
    
    int compareValue = workingNode->value;
    Node* currentNode = outputList->root;
    
    //Special case
    if (currentNode ->next == NULL) {
        if (outputList->root->value < workingNode->value) {
            outputList->root->next = workingNode;
            workingNode->next = NULL;
            return;
        }else {
            outputList->root = workingNode;
            workingNode->next = currentNode;
            currentNode->next = NULL;
            return;
        }
    }
    
    while (currentNode->next->next != NULL) {
        if (currentNode->next->next->value > compareValue) {
            break; //found the Node
        }else{
            currentNode = currentNode->next;
        }
    }
    
    if (currentNode->next->next == NULL) { //last 2nd Node
        if (compareValue > currentNode->value && compareValue < currentNode->next->value) { //middle
            workingNode->next = currentNode->next;
            currentNode->next = workingNode;
            return;
        }else if(compareValue < currentNode->value){ //first  ????
            workingNode->next = currentNode;
            outputList->root = workingNode;
            return;
        }else { //last
            currentNode->next->next = workingNode;
            workingNode->next = NULL;
            return;
        }
    }else{ // break out from the while loop-> in the middle of the list
        workingNode->next = currentNode->next->next;
        currentNode->next->next = workingNode;
        return;
    }
    
    return;
}

void addNodeToSortedList(Node* workingNode, List* outputList) {
    Node *currentNode = outputList->root;
    Node *prevNode = NULL;
    
    while (currentNode != NULL) {
        if (currentNode->value > workingNode->value) {
            // found location (always insert node before)
            break;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    
    if (currentNode == outputList->root) {
        // 1st node
        outputList->root = workingNode;
        workingNode->next = currentNode;
    } else {
        prevNode->next = workingNode;
        workingNode->next = currentNode;
    }
}

void sortList(List *inputList){
    
    List* sortedList = malloc(sizeof(List));
    sortedList->root = NULL;// first element in the new list
    sortedList->length = 0;
    Node* workingNode = NULL;
    
    while (inputList->root != NULL) { //Node in the input list will decrease
        if (sortedList->root == NULL) {
            //fist Node
            sortedList->root = inputList->root;
            inputList->root = inputList->root->next; //update the input list
            sortedList->root->next = NULL;
            
        } else {
            
            workingNode = inputList->root;
            inputList->root = inputList->root->next; //update the input list
            workingNode->next = NULL; // unlink the first Node of the input list
            // put the Node onto the output list in the correct space. This funciton will modify the output list
            //goSort (workingNode, sortedList);
            addNodeToSortedList(workingNode, sortedList);
        }
    }
    
    //make inputlist = output list
    inputList->root = sortedList->root;
    free(sortedList);
    return;
}

//2016-10-12

Node* copyNode(Node* inputNode) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = inputNode->value;
    newNode->count = inputNode->count;
    newNode->next = NULL;
    return newNode;
}

void pushNodeToList(List *list, Node* inputNode) {
    Node *currentNode = list->root;
    
    if (currentNode == NULL) {
        list->root = copyNode(inputNode);;
        return;
    }
    
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = copyNode(inputNode);
    return;
}

void alternativeSplit(const List* inputList, List* outputList1, List* outputList2) {
    
    Node* currentNode = inputList->root;
    
    while (currentNode != NULL) {
        pushNodeToList(outputList1, currentNode);
        currentNode = currentNode->next;
        
        if (currentNode != NULL) {
            pushNodeToList(outputList2, currentNode);
            currentNode = currentNode->next;
        }
    }
    return;
}

// 2017-07-12 copy node- Created by Johnny Wu - very clear mind
List* copyList(List *src){
    List* newList;
    newList = createList();
    newList->length = src->length;
    
    Node *currentNode_src = src->root;
    Node *previousNode_new = NULL;
    bool isRootNode = true;
    
    while (currentNode_src != NULL) {

        // create a new node equal to the tracking src node
        Node* node = newNode(currentNode_src->value);
        node->count = currentNode_src->count;
        
        if (isRootNode) {
            // handle root node
            newList->root = node;
            isRootNode = false;
        } else {
            // handle new node next pointer
            previousNode_new->next = node;
        }
        
        // increment
        previousNode_new = node;
        currentNode_src = currentNode_src->next;
    }
    
    return newList;
}
