#ifndef STACK_LLIST_LIB
#define STACK_LLIST_LIB

struct stack_node
{
    int data;
    struct stack_node *next;
};
typedef struct stack_node stack_node;
typedef struct stack_node *stack_link;

int push(stack_link top, int val);
int pop(stack_link top);
bool isEmpty(stack_link top);
void print_stack(stack_link top);

#endif