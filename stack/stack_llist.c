#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// stack
struct stack_node
{
    int data;
    struct stack_node *next;
};
typedef struct stack_node stack_node;
typedef stack_node *stack_link;

stack_link stack_top = NULL;

int push(int value) {
    stack_link new_stack_node;
    new_stack_node = (stack_link) malloc(sizeof(stack_node));
    if(!new_stack_node) {
        printf("[Err] memory allocation failed.\n");
        return -1;
    }

    new_stack_node->data = value;
    new_stack_node->next = stack_top;
    stack_top = new_stack_node;
    return value;
}

int pop() {
    int value;
    stack_link top = stack_top;
    if(stack_top != NULL) {
        value = stack_top->data;
        stack_top = stack_top->next;
        free(top);
        return value;
    }
    else {
        return -1;
    }
}

bool isEmpty() {
    if(stack_top == NULL)
        return true;
    else
        return false;
}

void shuffle(bool *card, int len, int num) {
    int card_val;
    srand(time(NULL));
    
    // reset indicator
    for(int i=0; i<len; i++)
        card[i] = false;

    // push num number of cards into stack
    int i = 0;
    while(i < num) {
        card_val = rand() % len;
        if(!card[card_val]) {
            push(card_val);
            card[card_val] == true;
            i++;
        }
    }
}

char card_val_to_suit(int car_val) {
    switch (car_val / 13)
    {
    case 0:
        return 'H'; // heart
        break;
    case 1:
        return 'D'; // diamond
        break;
    case 2:
        return 'C'; // club
        break;
    case 3:
        return 'S'; // spade
    default:
        return 'N'; // wrong value
        break;
    }
}

int main() {
    bool card[52];
    int card_val;
    shuffle(card, 52, 52);

    printf("1\t2\t3\t4\n");
    printf("=============================\n");
    // deal 4 people each 5 cards
    for(int i=0; i<5; i++) {
        if(!isEmpty()) {
            for(int j=0; j<4; j++) {
                card_val = pop();
                printf("[%c%2d]\t", card_val_to_suit(card_val), card_val % 13 + 1);
            }
            printf("\n");
        }
    }
    return 0;
}