#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int *stack;
int top = -1;
void push(char num);
char pop();
char peek();
bool empty();
int N;
bool checkString(char *string);
int main()
{
    return 0;
}
void push(char value)
{
    if(top <N-1)
        stack[++top] = value;
    else
        printf("ERROR - stack is full (push)\n");
}
char pop()
{
    if(!empty())
        return stack[top--];
    return -1;
}

char peek()
{
    if(!empty())
        return stack[top];
    else
        printf("ERROR - stack is empty\n");
        
}
bool empty()
{
    if(top == -1)
        return true;
    else
        return false;
}





