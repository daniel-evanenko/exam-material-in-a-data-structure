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
    char string[] = "aaabbb";
    if(checkString(string))
        printf("vaild\n");
    else
        printf("not vaild\n");

    return 0;
}

bool checkString(char *string)
{
    int len = strlen(string);
	if (len < 2)
		return false;
    int i=0;
    while (string[i]=='a')
		push(string[i++]);
	while (string[i] == 'b' && !isEmpty())
	{
		pop();
		i++;
	}
    if(isEmpty()&& i==len)
       return true;
    else
    {
        while(!isEmpty())
            pop();
        return false;    
    }
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





