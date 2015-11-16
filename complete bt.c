#include<stdio.h>

#define N 10
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void enqueue(struct node** queue,int* rear,struct node* new_node)
{
    queue[*rear]=new_node;
    (*rear)++;
}

struct node* dequeue(struct node** queue,int* front)
{
    (*front)++;
    return queue[*front-1];
}


int isQEmpty(int* front,int* rear)
{
    if(*front==*rear)
    return 1;
}

int check(struct node* root)
{
    int flag=0;

    int rear=0,front=0;
    struct node** queue=(struct node**)malloc(sizeof(struct node*)*N);
    enqueue(queue,&rear,root);

    while(isQEmpty(&front,&rear)!=1)
    {
        struct node* temp=dequeue(queue,&front);
        if(temp->left!=NULL)
        {
            if(flag==1)
            return 1;

            enqueue(queue,&rear,temp->left);
        }
        else
        flag=1;

        if(temp->right!=NULL)
        {
            if(flag==1)
            return 1;

            enqueue(queue,&rear,temp->right);
        }
        else
        flag=1;
    }
    return 0;
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */

  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->right = newNode(6);

  if ( check(root) == 0 )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");

  return 0;
}
