#include <stdio.h>
#include <stdlib.h>

struct llist {
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

llink findnode(llink head, int num) {
    llink ptr = head;
    while(ptr != NULL) {
        if(ptr->num == num) return ptr;
        ptr = ptr->next;
    }
    return ptr;
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

void freellist(llink head) {
    llink ptr = head;
    while(ptr != NULL) {
        free(ptr);
        ptr = ptr->next;
    }
}

int main(int argc, char *argv) {
    int llist1[6] = {1, 2, 3, 4, 5, 6};
    llink head, ptr;
    int num;

    // create llist
    head = createllist(llist1, 6);
    if(!head) {
        printf("[Err] malloc failed.");
        return 1;
    }

    // delete node
    printf("Original list: ");
    printllist(head);
    while(1) {
        printf("Enter the number to delete (-1 exit, -2 delete all): ");
        scanf("%d", &num);
        if(num == -1) {
            break;
        } 
        else if(num == -2) {
            freellist(head);
            printf("List has been deleted.\n");
        }
        else {
            ptr = findnode(head, num);
            if(!ptr) {
                printf("Node not found");
            }
            else {
                head = deletenode(head, ptr);
                printf("List after deletion: ");
                printllist(head);
            }
        }
    }

    return 0;
}