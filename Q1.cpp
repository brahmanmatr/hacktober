#include<iostream>
using namespace std;
struct Node
{
    int n;
    Node *ptr;
};

void addtofront(Node **head,int v)
{
    Node *t=new Node;
    t->n=v;
    t->ptr=*head;
    *head=t;
}
// following function return the length of the list
int length(Node *p)
{
    if(p==NULL)
        return 0;
    else
    {
        return 1+length(p->ptr);
    }
}

int main(void)
{
    Node *head;
    head=NULL;
    char c='Y';
    while(c=='Y')
    {
        int x;
        cout<<"Enter value of element to be added to the list: ";
        cin>>x;
        addtofront(&head,x);
        cout<<"Do you want to enter more ? (Y/N) : ";
        cin>>c;
    }
    cout<<"\n Length of the list is : ";
    cout<<length(head); // to print the length of the list;
    return 0;
}
