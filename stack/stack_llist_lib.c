#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_llist_lib.h"

int push(stack_link top, int val) {
    stack_link new_stack_node;
    new_stack_node = (stack_link) malloc(sizeof(stack_node));
    if(!new_stack_node) {
        printf("[Err] memory allocation failed.\n");
        return -1;
    }

    new_stack_node->data = val;
    new_stack_node->next = top;
    top = new_stack_node;
    return val;
}

int pop(stack_link top) {
    int val;
    if(!isEmpty(top)) {
        val = top->data;
        top = top->next;
        free(top);
        return val;
    } else {
        return -1;
    }
}

bool isEmpty(stack_link top) {
    if(top == NULL) {
        return true;
    } 
    return false;
}

void print_stack(stack_link top) {
    
}