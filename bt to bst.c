#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};



int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int countNodes (struct node* root)
{
    if (root == NULL)
     return 0;
    return countNodes (root->left) +
           countNodes (root->right) + 1;
}

void storeInorder (struct node* node, int inorder[], int *index_ptr)
{
    // Base Case
    if (node == NULL)
        return;

    /* first store the left subtree */
    storeInorder (node->left, inorder, index_ptr);

    /* Copy the root's data */
    inorder[*index_ptr] = node->data;
    (*index_ptr)++;  // increase index for next entry

    /* finally store the right subtree */
    storeInorder (node->right, inorder, index_ptr);
}



void arrayToBST (int *arr, struct node* root, int *index_ptr)
{
    if(root==NULL)
    return;

    arrayToBST(arr,root->left,index_ptr);

    root->data=arr[*index_ptr];
    (*index_ptr)++;

    arrayToBST(arr,root->right,index_ptr);
}

void binaryTreeToBST (struct node *root)
{
    if(root==NULL)
    return;

    int n = countNodes (root);

    int *arr =(int*)malloc(sizeof(int)*n);
    int i = 0;
    storeInorder (root, arr, &i);
    qsort (arr, n, sizeof(arr[0]), compare);
    i = 0;
    arrayToBST (arr, root, &i);


}

struct node* newNode (int data)
{
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printInorder (struct node* node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder (node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder (node->right);
}

int main()
{
    struct node *root = NULL;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    // convert Binary Tree to BST
    binaryTreeToBST (root);

    printf("Following is Inorder Traversal of the converted BST: \n");
    printInorder (root);

    return 0;
}
