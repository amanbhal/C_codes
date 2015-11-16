/*Given an array ‘pre[]‘ that represents Preorder traversal of a spacial binary tree where every node has either 0 or 2 children.
One more array ‘preLN[]‘ is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in ‘preLN[]‘ indicates that the
corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.Write a
function to construct the tree from the given two arrays.*/

#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode (int data)
{
    struct node *temp =(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* convert(int pre[],char preLN[],int* index_ptr, int n)
{
    int index=*index_ptr;

    if(index==n)
    return NULL;

    struct node* temp= newNode(pre[index]);
    (*index_ptr)++;

    if(preLN[index]=='N')
    {
        temp->left=convert(pre,preLN,index_ptr,n);
        temp->right=convert(pre,preLN,index_ptr,n);
    }
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
       /  \
      20   5 */
    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);
    int index=0;
    // construct the above tree
    root = convert(pre,preLN,&index, n);

    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder(root);

    return 0;
}
