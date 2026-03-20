#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

int precedence(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    scanf("%s", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
        i++;
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}