#include<stdio.h>
#include<limits.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* construct(int pre[],int* index,int key,int min,int max,int size)
{
    if(*index>=size)
    return NULL;

    struct node* root=NULL;

    if(key>min && key<max)
    {
        root=newNode(key);
        *index = *index + 1;

        root->left=construct(pre,index,pre[*index],min,key,size);
        root->right=construct(pre,index,pre[*index],key,max,size);
    }
    return root;
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
    int index=0;
    struct node *root = construct(pre,&index,pre[0],INT_MIN,INT_MAX,size);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}
