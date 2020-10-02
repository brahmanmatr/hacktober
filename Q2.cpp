#include<iostream>
using namespace std;
struct Node
{
    int n;
    Node *ptr;
};

void addtolist(Node **head,int v)
{
    Node *t=new Node;
    t->n=v;
    t->ptr=NULL;
    if((*head)==NULL)
    {
        (*head)=t;
    }
    else
    {
        Node *curr=(*head);
        while(curr->ptr!=NULL)
            curr=curr->ptr;
        curr->ptr=t;
    }
}

// following function deletesa Node from the list
void deleteNode(Node **head,Node *s )
{
    if((*head)==NULL)
        cout<<"List empty!\n";
    if(s==*head)
    {
        *head=(*head)->ptr;
        free(s);
    }
    else
    {
        Node *p;
        p=*head;
        while(p->ptr!=NULL&&p->ptr!=s)
        {
            p=p->ptr;
        }
        p->ptr=s->ptr;
        free(s);
    }
}

Node *searchnode(Node *head, int n)
{
    if(n==1)
        return head;
    else
        return searchnode(head->ptr,n-1);
}

void printlist(Node *head)
{
    Node *t=head;
    if(head==NULL)
    {
        cout<<"list empty\n";
        return;
    }
    do
    {
        cout<<t->n;
        t=t->ptr;
        if(t!=NULL)
            cout<<" -> ";
    } while (t!=NULL);
}

int main(void)
{
    Node *p=NULL,*s=NULL;
    int q=1;
    while(q!=4)
    {
        cout<<"\n1)Add element \n2)Delete Element \n3)Print list \n4)Exit\n    :";
        cin>>q;
        switch (q)
        {
        case 1:
        {
            cout<<"Enter element :";
            int x;
            cin>>x;
            addtolist(&p,x);
            break;
        }
        case 2:
        {
           cout<<"Enter position of element to delete (1-n) :";
           int x;
           cin>>x;
           s=searchnode(p,x);
           deleteNode(&p,s); 
        }
        case 3:
        {
            printlist(p);
            break;
        }
        case 4:
        {
            break;
        }
        default:
            cout<<"Invalid input!\n";
            break;
        }
    }
    deleteNode(&p,s); // to delete the Node;
    return 0;
}
