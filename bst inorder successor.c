#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* succ(struct node* root,struct node* n)
{
    struct node* p=NULL;

    if(n->right!=NULL)
    {
        p=n->right;
        while(p->left!=NULL)
        p=p->left;
        return p;
    }

    while(root!=NULL)
    {
        if(n->data < root->data)
        {
            p=root;
            root=root->left;
        }
        else if(n->data > root->data)
        root=root->right;
        else
        break;
    }

    return p;
}

int main()
{
    struct node* root;
    root->data=20;
    root->left->data=8;
    root->right->data=22;
    root->right->left=NULL;
    root->right->right=NULL;
    root->left->left->data=4;
    root->left->left->left=NULL;
    root->left->left->right=NULL;
    root->left->right->data=12;
    root->left->right->left->data=10;
    root->left->right->left->left=NULL;
    root->left->right->left->right=NULL;
    root->left->right->right->data=14;
    root->left->right->right->left=NULL;
    root->left->right->right->right=NULL;

    struct node* temp=root->left->right->right;
    struct node* successor=succ(root,temp);
    printf("SUCCESSOR of %d is %d",temp->data,successor->data);
    return 0;
}
