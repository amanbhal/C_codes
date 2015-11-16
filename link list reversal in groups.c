#include<stdio.h>
#include<conio.h>

struct node
{
    int val;
    struct node* next;
};

void create(struct node** head ,int a)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->val=a;
    new_node->next=*head;
    *head=new_node;
}

struct node* reverse(struct node* head, int k)
    {
        struct node* current=head;
        struct node* prev=NULL;
        struct node* next;
        int count=0;
        while(current!=NULL && count<k)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            count++;
        }

        if(next!=NULL)
        {
            head->next=reverse(next,k);
        }
        return prev;

    }

void print(struct node* head)
{
    struct node* current=head;
    while(current!=NULL)
    {
        printf("%d -> ",current->val);
        current=current->next;
    }
    printf("\n");
}

void main()
{
    struct node* head=NULL;

    create(&head,8);
    create(&head,7);
    create(&head,6);
    create(&head,5);
    create(&head,4);
    create(&head,3);
    create(&head,2);
    create(&head,1);

    printf("original list:\n");
    print(head);
    struct node* new_head=reverse(head,3);
    printf("reversed list:\n");
    print(new_head);
    return 0;
}
