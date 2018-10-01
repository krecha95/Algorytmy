#include<iostream>
using namespace std;

struct node
{
    int val;
    node* next;
};
void push( node*& H, int x);
void show (node* H);
void pop (node*&H);

void main()
{
    node* H=NULL;
    push (H,5);
    push(H,10);
    show(H);
    pop(H);

    system("pause");
}
void push( node*& H, int x)
{
    node*p=new node;
    p->val = x;
    p->next = H;
    H=p;
}
void show (node* H)
{
    cout<<"H-> ";
    if (H!= NULL)
    {
        node*p = H;
        while (p!=NULL)
        {
            cout<<p->val<<" -> ";
            p=p->next;
        }
        cout<<"NULL ";
    }
}
void pop (node*&H)
{
    if (H!=NULL)
    {
        node*p=H;
        H=p->next;
        delete p;
    }
}
        

