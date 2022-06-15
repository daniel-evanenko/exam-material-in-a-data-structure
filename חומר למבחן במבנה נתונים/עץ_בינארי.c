#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct dataNode
{
    int data; 
    struct dataNode *left;
    struct dataNode *right;
} node;
void addNum(node** root,int num);
int isFound(node* root,int num);
int main()
{
    node* root = NULL;
    int choise,num;
    printf("to add number press 1, to search press 2, to exit 3\n");
    scanf("%d",&choise);
    while(choise!=3)
    {
        switch (choise)
        {
        case 1:
            printf("enter a number\n");
            scanf("%d",&num);
            addNum(&root,num);
            break;
        case 2:
            printf("enter a number\n");
            scanf("%d",&num);
            printf("%s\n" , isFound(root,num) ? "found" : "not found"); 
            break;                     
        default:
            break;
        }
        printf("to add number press 1, to search press 2, to exit 3\n");
        scanf("%d",&choise);
    }
    return 0;
}
int isFound(node* root,int num)
{
    while(root!=NULL)
    {   
        if(num > root->data)
        {
            root = root->right;
        }
        else if(num < root->data)
        {
            root = root->left;
        }    
        else
            return 1;
    }
    return 0;

}
void addNum(node** root,int num)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->left = temp->right = NULL;
    if(*root==NULL)
    {
        *root = temp;
        return;
    }
    node* curr = *root;
    while(curr!=NULL)
    {
        if(num > curr->data)
        {
            if(curr->right == NULL)
            {
                curr->right = temp;     
                return;           
            }
            curr = curr->right;
        }
        else
        {
            if(curr->left == NULL)
            {
                curr->left = temp;     
                return;           
            }
            curr = curr->left;
        }           
    }
}