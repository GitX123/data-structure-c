#include <stdio.h>
#include <stdlib.h>
#include "llistlib.h"

llink invertllist(llink head) {
    llink ptr, prev_ptr, next_ptr;
    ptr = head;
    prev_ptr = NULL;

    while(ptr != NULL) {
        next_ptr = ptr->next;
        ptr->next = prev_ptr;
        prev_ptr = ptr;
        ptr = next_ptr;
    }

    return prev_ptr;
}

int main(int argc, char *argv) {
    int llist1[6] = {1, 2, 3, 4, 5, 6};
    llink head;

    head = createllist(llist1, 6);
    if(!head) {
        printf("[ERR] Memory allocation failed.\n");
        return 1;
    }

    printf("List: ");
    printllist(head);
    head = invertllist(head);
    printf("List: ");
    printllist(head);
    freellist(head);

    return 0;
}