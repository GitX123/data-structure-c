#include <stdio.h>
#include <stdlib.h>

struct llist
{
    int num;
    struct llist *next;
};
typedef struct llist node;
typedef node *llink;


void printllist(llink ptr) {
    while (ptr != NULL)
    {
        printf("[%d] ", ptr->num);
        ptr = ptr->next;
    }
    printf("\n");
}

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

llink concatllist(llink ptr1, llink ptr2) {
    llink tail = ptr1;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = ptr2;
    return ptr1;
}

int main(int argc, char *argv) {
    int llist1[6] = {1, 2, 3, 4, 5, 6};
    int llist2[5] = {8, 19, 13, 24, 35};

    llink ptr, ptr1, ptr2;
    ptr1 = createllist(llist1, 6);
    ptr2 = createllist(llist2, 5);

    ptr = concatllist(ptr1, ptr2);
    printllist(ptr);
    return 0;
}