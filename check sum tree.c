/*
Write a function that returns true if the given Binary Tree is SumTree else false. A SumTree is a Binary Tree where the value of a node is equal to sum of the nodes present in its left subtree and right subtree. An empty tree is SumTree and sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Following is an example of SumTree.

          26
        /   \
      10     3
    /    \     \
  4      6      3
*/

#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int sum(struct node* root)
{
    if(root==NULL)
    return 0;
    return sum(root->left)+root->data+sum(root->right);
}

int isSumTree(struct node* root)
{
    int ls,rs;


    if((root==NULL) || (root->left==NULL && root->right==NULL))
    return 1;

    ls=sum(root->left);
    rs=sum(root->right);

    if((root->data == ls + rs)&&isSumTree(root->left) &&isSumTree(root->right))
    return 1;

    return 0;
}

struct node* newNode(int data)
{
    struct node* node =
        (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/* Driver program to test above function */
int main()
{
    struct node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);
    if(isSumTree(root))
        printf("The given tree is a SumTree ");
    else
        printf("The given tree is not a SumTree ");

    return 0;
}
