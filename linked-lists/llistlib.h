#ifndef LLISTLIB_H
#define LLISTLIB_H

struct llist {
    int num;
    struct llist *next;
};
typedef struct llist node;
typedef node *llink;

llink createllist(int *arr, int len);
llink deletenode(llink head, llink target_ptr);
llink findnode(llink head, int num);
void freellist(llink head);
void printllist(llink ptr);

#endif