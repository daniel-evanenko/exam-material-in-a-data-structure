node* merge(node* head1, node* head2)
{
    node* mergedHead , *tail, *temp;
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    
    mergedHead = (node*) malloc(sizeof(node));
    mergedHead-> data = head1->data;
    mergedHead->next = (node*) malloc(sizeof(node));
    tail = mergedHead->next;
    tail->data = head2->data;
    head1 = head1->next;
    head2 = head2->next;
    while(head1!= NULL && head2 != NULL)
    {
        temp = (node*)malloc(sizeof(node));
        temp->data = head1->data;
        tail->next = temp;
        tail = tail->next;
        temp = (node*) malloc(sizeof(node));
        temp->data = head2->data;
        tail->next = temp;
        tail = tail->next;
        head1 = head1->next;
        head2 = head2->next;
        
    }
    while(head1 != NULL)
    {
        temp = (node*) malloc(sizeof(node));
        temp->data = head1->data;
        tail->next = temp;
        tail = tail->next;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        temp = (node*) malloc(sizeof(node));
        temp->data = head2->data;
        tail->next = temp;
        tail = tail->next;
        head2 = head2->next;
    }
    tail->next = NULL;
    return mergedHead;
    
}