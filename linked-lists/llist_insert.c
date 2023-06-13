#include <stdio.h>
#include <stdlib.h>
#include "llistlib.h"

llink insertnode(llink head, llink ptr, int value) {
    // create new node
    llink new_ptr = malloc(sizeof(node));
    if(!new_ptr) {
        printf("[ERR] Memory allocation failed.\n");
        return NULL;
    }
    new_ptr->num = value;
    new_ptr->next = NULL;

    if(ptr == NULL) {
        // new node as head
        new_ptr->next = head;
        head = new_ptr;
    }
    else if(ptr->next == NULL) {
        // new node as tail
        new_ptr->next = NULL;
        ptr->next = new_ptr;
    }
    else {
        new_ptr->next = ptr->next->next;
        ptr->next = new_ptr;
    }

    return head;
}

int main(int argc, char *argv) {
    int llist1[6] = {1, 2, 3, 4, 5, 6};
    llink head, ptr;
    int num;
    int value;

    // create llist
    head = createllist(llist1, 6);
    if(!head) {
        printf("[ERR] Memory allocation failed.\n");
        return 1;
    }

    // insert node
    printf("List: ");
    printllist(head);
    while(1) {
        printf("Enter the number to insert a new number after it (-1 exit): ");
        scanf("%d", &num);
        if(num != -1) {
            ptr = findnode(head, num);
            printf("Enter the new number: ");
            scanf("%d", &value);
            head = insertnode(head, ptr, value);
            if(!head) {
                printf("[ERR] Memory allocation failed.\n");
                return 1;
            }
            printf("List: ");
            printllist(head);
        }
        else{
            break;
        }
    }

    freellist(head);
    return 0;
}