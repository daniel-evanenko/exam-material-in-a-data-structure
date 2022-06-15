void reverse(node** head) // function to reverse single linked list : 1234 -> 4321 (L3_Ex1)
{
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

node2* createList(node* head1) // get single linked list and create double linked list from the same values.
{ // (l3_Ex2)
    int number = 0;
    node2 *head = NULL, *tail = NULL, *temp = NULL;
    node* itr = head1;
    while (itr!=NULL)
    {
        temp = (node2*)malloc(sizeof(node2));
        if (temp == NULL)
        {
            printf("Error: out of memory, allocation failed!\n");
            return NULL;
        }
        if(head == NULL) // make head
        {
            temp->data = itr->data;
            temp->next = head;
            head = temp;
            head->prev = NULL;
            tail = head;
        }
        else // add the data to the tail
        {
            temp->data = itr->data;
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = tail->next;
        }
        itr = itr->next;
    }
    return head;
}
