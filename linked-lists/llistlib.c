#include <stdio.h>
#include <stdlib.h>
#include "llistlib.h"

llink createllist(int *arr, int len) {
    llink head, ptr_prev, ptr;
    head = (llink) malloc(sizeof(node));
    if(!head) return NULL;
    head->num = arr[0];
    head->next = NULL;

    ptr_prev = head;
    for(int i=1; i<len; i++) {
        ptr = (llink) malloc(sizeof(node));
        if(!ptr) return NULL;
        ptr->num = arr[i];
        ptr->next = NULL;
        ptr_prev->next = ptr;
        ptr_prev = ptr_prev->next;
    }
    return head;
}

llink deletenode(llink head, llink target_ptr) {
    if(target_ptr == head) {
        return target_ptr->next;
    }

    llink ptr = head;
    while(ptr != NULL) {
        if(ptr->next == target_ptr) {
            ptr->next = target_ptr->next;
            break;
        }
        ptr = ptr->next;
    }

    free(target_ptr);
    return head;
}

llink findnode(llink head, int num) {
    llink ptr = head;
    while(ptr != NULL) {
        if(ptr->num == num) return ptr;
        ptr = ptr->next;
    }
    return ptr;
}

void freellist(llink head) {
    llink ptr = head;
    while(ptr != NULL) {
        free(ptr);
        ptr = ptr->next;
    }
}

void printllist(llink ptr) {
    while (ptr != NULL)
    {
        printf("[%d] ", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}