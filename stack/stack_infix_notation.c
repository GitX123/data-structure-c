#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_llist_lib.h"

bool isOperator(char op) {
    switch (op)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

int priority(char op) {
    switch (op)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

int calculate(char op, int operand1, int operand2) {
    switch (op)
    {
    case '*': return operand1 * operand2;
    case '/': 
        if (operand2 != 0) return operand1 / operand2;
        printf("[Err] Divisor cannot be zero.");
        return -1;
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    default:
        printf("[Err] Something went wrong.");
        return -1;
    }
}

int main() {
    char expression[100];
    int pos = 0;
    char operator;
    int operand1, operand2;
    int result = 0;
    // stack tops of operator and operand
    stack_link top_operator = NULL;
    stack_link top_operand = NULL;

    printf("Enter expression in infix notation: ");
    fgets(expression, sizeof(expression), stdin);
    // gets_s(expression);

    // push into stack
    while (expression[pos] != '\0' && expression[pos] != '\n') {
        if (isOperator(expression[pos])) {
            // TODO
            while (!isEmpty(top_operator))
            {
                if (priority(expression[pos]) <= priority((char)top_operator->data))
                {
                    operator = pop(top_operator);
                    operand1 = pop(top_operand);
                    operand2 = pop(top_operand);
                    push(top_operand, calculate(operator, operand1, operand2));
                } else 
                    break;
            }
            push(top_operator, expression[pos]);
        } else {
            push(top_operand, expression[pos] - 48);
        }
        pos++;
    }

    // pop from stack
    while (!isEmpty(top_operator))
    {
        operator = pop(top_operator);
        operand1 = pop(top_operand);
        operand2 = pop(top_operand);
        push(top_operand, calculate(operator, operand1, operand2));
    }

    result = pop(top_operand);
    printf("%s = %d\n", expression, result);
    return 0;
}