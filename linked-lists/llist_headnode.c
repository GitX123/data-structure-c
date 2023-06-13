#include <stdio.h>
#include <stdlib.h>

struct llist {
    int num;
    struct llist *next;
};
typedef struct llist node;
typedef node *llink;

void printllist(llink head) {
   llink ptr; 
   ptr = head->next;

   while (ptr != NULL)
   {
        printf("[%d] ", ptr->num);
        ptr = ptr->next;
   }
   printf("\n");
}

llink createllist(int *arr, int len) {
    llink head, ptr;

    // head
    head = malloc(sizeof(node));
    if(!head) {
        printf("[ERR] Memory allocation failed.\n");
        return NULL;
    }

    // nodes
    ptr = head;
    for(int i=0; i<len; i++) {
        llink ptr_new = malloc(sizeof(node));
        if(!ptr) {
            printf("[ERR] Memory allocation failed.\n");
            return NULL;
        }
        ptr_new->num = arr[i];
        ptr_new->next = NULL;
        ptr->next = ptr_new;
        ptr = ptr->next;
    }

    return head;
}

llink insertnode(llink head, llink ptr, int value) {
    llink new = (llink) malloc(sizeof(node));
    if(!new) 
        return NULL;

    new->num = value;
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

llink deletenode(llink head, llink ptr) {
    llink previous = head;
    while(previous->next != ptr)
        previous = previous->next;
    previous->next = ptr->next;
    free(ptr);
    return head;
}

int main(int argc, char *argv) {
    // create llist
    int llist1[6] = {1, 2, 3, 4, 5, 6};
    llink head = createllist(llist1, 6);
    if(!head) {
        printf("[ERR] Memory allocation failed.\n");
        return 1;
    }
    printf("List: ");
    printllist(head);

    // insert node
    head = insertnode(head, head, 0);
    if(!head) {
        printf("[ERR] Memory allocation failed.\n");
        return 1;
    }

    // delete node
    head = deletenode(head, head->next->next->next);
    printf("List: ");
    printllist(head);

    return 0;
}