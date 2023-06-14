#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAXSTACK 100

// stack creation
int stack[MAXSTACK];
int top = -1;

int push(int value) {
    if(top >= MAXSTACK) {
        printf("Stack if full.\n");
        return -1;
    }
    top++;
    stack[top] = value;
}

int pop() {
    int value;
    if(top < 0) {
        printf("Stack is empty.\n");
        return -1;
    }
    value = stack[top];
    top--;
    return value;
}

void shuffle(bool *card, int len, int num) {
    
    // reset indicator
    for(int i=0; i<len; i++)
        card[i] = false;

    // push card value into stack
}

int main(int argc, char *argv) {
    bool card[52]; // stack indicator, true means in stack
    int card_num;

    shuffle(card, 52, 52);

    printf("\t1 \t2 \t3 \t4 \n");
    printf("===========================\n");
    // deal everyone 5 cards
    for(int i=0; i<5; i++) {
        card_num = pop();
        printf(" [%c%2d] ", card_num / 13 + 3, card_num % 13 + 1);
        card_num = pop();
        printf(" [%c%2d] ", card_num / 13 + 3, card_num % 13 + 1);
        card_num = pop();
        printf(" [%c%2d] ", card_num / 13 + 3, card_num % 13 + 1);
        card_num = pop();
        printf(" [%c%2d] ", card_num / 13 + 3, card_num % 13 + 1);
        printf("\n");
    }

    return 0;
}