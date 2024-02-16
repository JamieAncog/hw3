#include "llrec.h"
//delete this
#include <iostream>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if (head == NULL){
        return;
    }
    else if (head->val > pivot){
        larger = head;
        hasLarge(head->next, smaller, larger, pivot);
    }
    else {
        smaller = head;
        hasSmall(head->next, smaller, larger, pivot);
    }
}

void hasLarge(Node *&head, Node *&smaller, Node *larger, int pivot){
    if (head == NULL){
        return;
    }
    else if (head->val > pivot){
        hasLarge(head->next, smaller, larger->next, pivot);
    }
    else {
        smaller = head;
        hasBoth(head->next, smaller, larger, pivot, smaller, larger);
    }
}

void hasSmall(Node *&head, Node *smaller, Node *&larger, int pivot){
    if (head == NULL){
        return;
    }
    else if (head->val <= pivot){
        hasSmall(head->next, smaller->next, larger, pivot);
    }
    else {
        larger = head;
        hasBoth(head->next, smaller, larger, pivot, smaller, larger);
    }
}

void hasBoth(Node *head, Node *smaller, Node *larger, int pivot, Node* lastS, Node* lastL){
    if (head == NULL){
        lastS->next = NULL;
        lastL->next = NULL;
        return;
    }
    else if (head->val > pivot){
        larger->next = head;
        larger = larger->next;
        lastL = larger;
        hasBoth(head->next, smaller, larger, pivot, lastS, lastL);
    }
    else {
        smaller->next = head;
        smaller = smaller->next;
        lastS = smaller;
        hasBoth(head->next, smaller, larger, pivot, lastS, lastL);
    }
}
