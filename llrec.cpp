#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if (head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    else if (head->val > pivot){
        larger = head;
        hasLarge(head, head->next, smaller, larger, pivot);
    }
    else {
        smaller = head;
        hasSmall(head, head->next, smaller, larger, pivot);
    }
}

void hasLarge(Node *&head, Node* curr, Node *&smaller, Node *larger, int pivot){
    if (!curr){
        smaller = NULL;
        head = NULL;
        return;
    }
    else if (curr->val > pivot){
        hasLarge(head, curr->next, smaller, larger->next, pivot);
    }
    else {
        smaller = curr;
        hasBoth(head, curr->next, smaller, larger, pivot, smaller, larger);
    }
}

void hasSmall(Node *&head, Node* curr, Node *smaller, Node *&larger, int pivot){
    if (!curr){
        larger = NULL;
        head = NULL;
        return;
    }
    else if (curr->val <= pivot){
        hasSmall(head, curr->next, smaller->next, larger, pivot);
    }
    else {
        larger = curr;
        hasBoth(head, curr->next, smaller, larger, pivot, smaller, larger);
    }
}

void hasBoth(Node*& front, Node *head, Node *smaller, Node *larger, int pivot, Node* lastS, Node* lastL){
    if (head == NULL){
        lastS->next = NULL;
        lastL->next = NULL;
        front = NULL;
        return;
    }
    else if (head->val > pivot){
        larger->next = head;
        larger = larger->next;
        lastL = larger;
        hasBoth(front, head->next, smaller, larger, pivot, lastS, lastL);
    }
    else {
        smaller->next = head;
        smaller = smaller->next;
        lastS = smaller;
        hasBoth(front, head->next, smaller, larger, pivot, lastS, lastL);
    }
}
