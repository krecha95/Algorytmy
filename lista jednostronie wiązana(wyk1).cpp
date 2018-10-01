#include<iostream>
#include<fstream>
using namespace std;

struct node {
    int vol;
    node *next;
};


int main() {
    node *H=NULL;
    H=new node;
    H->vol=3;
    H->next= NULL;
    node *p;
    p=new node;
    p->vol=8;
    p->next=H;
    H=p;
    //cout<<H->vol<<endl;
    //cout<<H->next->vol<<endl;
}
