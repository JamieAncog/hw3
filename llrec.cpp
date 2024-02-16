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
    if (smaller != NULL && smaller->next != NULL && smaller->next->val > pivot){
        smaller->next = NULL;
    }
    if (larger != NULL && larger->next != NULL && larger->next->val <= pivot){
        larger->next = NULL;
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
        hasBoth(head->next, smaller, larger, pivot);
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
        hasBoth(head, smaller, larger, pivot);
    }
}

void hasBoth(Node *head, Node *smaller, Node *larger, int pivot){
    if (head == NULL){
        return;
    }
    else if (head->next != NULL && head->next->next == NULL){
        if (head->val > pivot){
            if (larger != head){
                larger->next = head;
            }
            if (head->next->val <= pivot){
                smaller->next = head->next;
                larger->next->next = NULL;
            }
        }
        else {
            if (smaller != head){
                smaller->next = head;
            }
            if (head->next->val > pivot){
                larger->next = head->next;
                smaller->next->next = NULL;
            }
        }
        
    }
    else if (head->val > pivot){
        larger->next = head;
        hasBoth(head->next, smaller, larger->next, pivot);
    }
    else {
        smaller->next = head;
        hasBoth(head->next, smaller->next, larger, pivot);
    }
}
