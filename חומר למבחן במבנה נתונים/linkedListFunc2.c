node* circle(node* head1, node* head2) // get to single linked list and make them circle 
// (the shorter one will be first) 123 , 4567 , -> 1234567
{
    node* itr1 = head1;
    node* itr2 = head2;
    int cntHead1=0;
    int cntHead2=0;
    
    if(head1 == NULL && head2!= NULL)
        return head2;

    else if(head1!= NULL && head2==NULL)
        return head1;

    else if(head1 == NULL && head2 == NULL)
        return NULL;
    
    while(itr1->next!=NULL)
    {
        cntHead1++;
        itr1 = itr1->next;
    }

    while(itr2->next!=NULL)
    {
        cntHead2++;
        itr2 = itr2->next;
    }

    if(cntHead1<cntHead2)
    {
        itr1->next = head2;
        itr2->next = head1;
        return head1;
    }
    else
    {
        itr2->next = head1;
        itr1->next = head2;
        return head2;
    }
    
}
node* merge_sort(node* head1, node* head2)
// gets 2 sorted single linked and merge them into one sorted 
// 1 3 5 7 , 2 4 6 8 -> 1 2 3 4 5 6 7 8
{
    if (head1 == NULL)
        return head2;

    else if (head2 == NULL)
        return head1;
    
    node* mergedHead = (node*)malloc(sizeof(node));
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    if (head1->data <= head2->data)
    {
        temp->data = head1->data;
        mergedHead = temp;
        head1 = head1->next;
    } 
   else
   {
        temp->data = head2->data;
        mergedHead = temp;
        head2 = head2->next;
   }
   node* mergedTail = mergedHead;
   while (head1 != NULL && head2 != NULL)
   {   
       node* temp = (node*)malloc(sizeof(node));
       if (head1->data <= head2->data)
       {
           temp->data = head1->data;
           head1 = head1->next;
       }
       else
       {
           temp->data = head2->data;
           head2 = head2->next;
       }
       
    mergedTail->next = temp;
    mergedTail = temp;
   }
    if (head1 != NULL)
        mergedTail->next = head1; 
    else if (head2 != NULL)
        mergedTail->next = head2;   
    return mergedHead;
}
node2* merged_Two_Way(node* head1, node* head2)
// gets two sorted single lists and merge them for double linked list
// 1 2 3 4 , 5 6 7 8 -> (1 5 2 6 3 7 4 8)
{
    node2* mergedHead = (node2*)malloc(sizeof(node2));
    if (head1 == NULL && head2!=NULL)
    {
        tail = (node2*)malloc(sizeof(node2));
        mergedHead->data = head2->data;
        mergedHead->next = NULL;;
        mergedHead->prev = NULL;
        head2 = head2->next;
        tail = head2;
        while(tail!=NULL && tail->next != NULL)
        {
            temp = (node*)malloc(sizeof(node));
            temp->data = head2->data;
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            head2 = head2->next;
        }
        
        return mergedHead;
    }
    mergedHead->data = head1-data;
    mergedHead->prev = NULL;
    head1 = head1->next;
    while(head1!=NULL && head2 != NULL)
    {
        node2* temp = (node2*)malloc(sizeof(node2));
        
    } 
}
