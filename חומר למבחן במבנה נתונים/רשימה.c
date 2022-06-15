#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode
{
    int data;
    struct dataNode* next;
    struct dataNode* prev;
} node;

node* enter_numbers();
node* add_number(node* head ,int num);
int choose_number();
int main()
{
    int num;
    node* curr;
    node* head1 = enter_numbers(); // enter the number from the biggest to the smallest (9,7,5...)
    num = choose_number(); // choose a number you want to add
    head1 = add_number(head1,num); // returns the list with the added number
    curr = head1;
    if (curr == NULL)
        return 0;
    printf("%d ", curr->data); // print the list
    curr = curr->next;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
int choose_number()
{
    int num=-1;
    while (num<0)
    {
       printf("please enter a positive number you want to add\n");
       scanf("%d",&num);
    }
    return num;
    
}

node* enter_numbers()
{
    int number = 0;
    node* head = NULL, * temp = NULL;
    printf("enter positive numbers, enter negative number to stop\n");
    scanf("%d", &number);
    while (number >= 0)
    {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        temp->data = number;
        temp->next = head;
        if (head != NULL)
            head->prev = temp;
        head = temp;
        head->prev = NULL;
        scanf("%d", &number);
    }
    return head;
}
node* add_number(node* head ,int num)
{
    node* itr,*temp,*tail;
    itr = head;
   if(itr->data > num) // checks the first number
   {
        temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        temp->data = num;
        temp->next = itr;
        temp->prev = itr->prev; // NULL
        itr->prev = temp;
        head=temp;
        return head; 
   }

   while (tail!=NULL && tail->next != NULL) // find tail 
    {
        tail = tail->next;
    }

    if(tail->data <= num)
    {
        temp = (node*)malloc(sizeof(node)); // checks the last number
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        temp->data = num;
        temp->next = tail->next; // NULL
        temp->prev = tail;
        tail->next = temp;
        return head;
    }

    while (itr!=NULL)
    {
        if(itr->data <= num && itr->next->data >= num)
        {
            temp = (node*)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
            temp->data = num;
            temp->prev = itr;
            temp->next = itr->next;
            itr->next->prev = temp;
            itr->next=temp;
            return head;
        }
        else
            itr=itr->next;
    }

}