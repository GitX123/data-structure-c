#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAXSTACK 100

// stack creation
int stack[MAXSTACK];
int top = -1;

// check whether stack is empty
bool isEmpty() {
    if(top == -1) 
        return true;
    else
        return false;
}

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

int main(int argc, char *argv) {
    bool card[52]; // stack indicator, true means in stack
    int card_val;

    // shuffle 16 cards into stack
    shuffle(card, 52, 16);

    printf("1\t2\t3\t4\n");
    printf("=============================\n");
    // deal everyone 5 cards
    for(int i=0; i<5; i++) {
        if(!isEmpty()) {
            card_val = pop();
            printf("[%c%2d]\t", card_val_to_suit(card_val), card_val % 13 + 1);
            card_val = pop();
            printf("[%c%2d]\t", card_val_to_suit(card_val), card_val % 13 + 1);
            card_val = pop();
            printf("[%c%2d]\t", card_val_to_suit(card_val), card_val % 13 + 1);
            card_val = pop();
            printf("[%c%2d]\t", card_val_to_suit(card_val), card_val % 13 + 1);
            printf("\n");
        }
    }

    return 0;
}