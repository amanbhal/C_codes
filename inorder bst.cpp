#include<iostream>
#include<stdlib.h>

using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
void add_node(int,struct node**);
void display(struct node*);
int main()
{
int num,i,data;
struct node* head;
head = NULL;
cout<<"enter the no of nodes to be generated"<<endl;
cin>>num;
for (i=0;i<num;i++)
{
    cout<<"enter the data for"<<i<<"th node"<<endl;
    cin>>data;
    (void)add_node(data,&head);
}
    display(head);
return 0;
}
void add_node(int data,struct node** head)
{
    node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        if (*head==NULL)
        *head = temp;
    else if ((*head)->data<data)
    {
        (void)add_node(data,&(*head)->right);
    }
    else {add_node(data,&(*head)->left);}
}
void display(struct node* head)
{
if(head)
{
    display(head->left);
    cout<<head->data<<"\t";
    display(head->right);
}
}
