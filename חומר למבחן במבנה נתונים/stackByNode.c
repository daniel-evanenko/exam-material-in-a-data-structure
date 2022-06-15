#include <stdio.h> ,#include <stdlib.h>, #include <stdbool.h>, #include <string.h>
typedef struct dataNode
{
    char data; 
    struct dataNode *next;
} node;
void push(char num);
bool isEmpty();
char peek();
bool pop();
node *head;
int main()
{
    head = NULL;
	return 0;
}
bool isEmpty()
{
    if(head==NULL)
        return true;
    else
        return false;
}
char peek()
{
    if(!isEmpty(head))
        return head->data;
    else
        return -1;
}
bool pop()
{
    if(!isEmpty(head))
    {
        node* temp = head;
        head = head->next;
        free(temp);
        return true;
    }
    return false;
}
void push(char value)
{
    node* temp = (node*) malloc(sizeof(node));
    if (temp == NULL) 
    {
		printf("Error: out of memory, allocation failed!\n");
        return;
    }
    temp->data  = value;
    temp->next = head;
    head= temp;
}






