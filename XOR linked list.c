#include<stdio.h>


struct node
{
    int data;
    struct node* npx;
};

struct node* XOR(struct node* a,struct node* b)
{
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}

void insert(struct node** head,int n)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=n;
    new_node->npx=XOR(*head,NULL);

    if(*head!=NULL)
    {
        struct node* next=XOR((*head)->npx,NULL);
        (*head)->npx=XOR(new_node,next);
    }

    *head=new_node;
}

void print(struct node* head)
{
    struct node* prev=NULL;
    struct node* next;
    struct node* curr=head;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
printf("\n");
}

void deleteNode(struct node** head,int n)
{
    struct node* curr=*head;
    struct node* prev=NULL;
    struct node* prev0=NULL;
    int flag=0;
    struct node* next;

    while(curr->data!=n)
    {
        next=XOR(prev,curr->npx);
        if(flag==1)
        prev0=prev;
        prev=curr;
        curr=next;
        flag=1;
    }
    next=XOR(prev,curr->npx);
    prev->npx=XOR(prev0,next);
}

int main()
{
    struct node* head=NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);

    print(head);

    deleteNode(&head,3);

    print(head);

    return 0;
}
