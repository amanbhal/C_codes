
#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void convert(struct node* root,struct node** head)
{
    if(root==NULL)
    return;

    static struct node* prev;

    convert(root->left,head);

    if(*head==NULL)
    *head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }

    prev=root;

    convert(root->right,head);
}

struct node* newNode(int data)
{
    struct node* new_node = (struct nodee*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d\t",node->data);
        node = node->right;
    }
}

int main()
{
    struct node *root        = newNode(10);
    root->left        = newNode(6);
    root->right       = newNode(12);
    root->left->left  = newNode(4);
    root->left->right = newNode(9);
    root->left->right->left = newNode(7);

    // Convert to DLL
    struct node *head = NULL;
    convert(root, &head);

    // Print the converted list
    printList(head);

    return 0;
}
