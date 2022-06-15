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
bool checkString(char *string) // checks if the string is valid by using stack with array
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
bool isCorrect (char str[])
{ 
() {} [] -> not vaild {] )( {( ...
    for (int i=0; i<strlen(str); i++)
    {
    if(str[i]=='(' || str[i]=='[' || str[i]=='{')
         push(str[i]);
	else if ((str[i] == ')' || str[i] == ']' || str[i] == '}') && !isEmpty())
		if ((str[i] == ')' && peek() == '(') || (str[i] == ']' && peek() == '[') || (str[i] == '}' && peek() = '{'))
			pop();
		else
			break;
    }
	if (isempty() && i == strlen(str))
		return true;
	while (!isEmpty())
		pop();
	return false;
}
