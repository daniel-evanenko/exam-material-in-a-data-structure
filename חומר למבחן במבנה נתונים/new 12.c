void inOrder(node* root)
{
    if (root == NULL)
        return;
 
    inOrder(root->left);
 
    printf("%d ", root->data);
 
    inOrder(root->right);
}
void preOrder(node* root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
 
    preOrder(root->left);
 
    preOrder(root->right);
}
void postOrder(node* root)
{
    if (root == NULL)
        return;

     postOrder(root->left);

     postOrder(root->right);

     printf("%d ", root->data);
}

