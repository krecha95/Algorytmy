#include <iostream>
using namespace std;

struct node
{
	int val;
	node *next;
};
void showlist(node *H)
{
	node *P = H;
	cout << "H->";
	while (P != NULL)
	{
		cout << P->val << "->";
		P = P->next;
	}
	cout << "NULL" << endl;
}
void AddToList(node *&H, int x)
{
	node *P;
	P = new node;
	P->val = x;
	P->next = H;
	H = P;
}
void AddToEnd(node *&H, int x)
{
	if (H == NULL)
	{
		node *P;
		P = new node;
		P->val = x;
		P->next = H;
		H = P;
	}
	else
	{
		node *P = H;

		while (P->next != NULL)
			P = P->next;
		AddToList(P->next, x);
	}
}
void AddToEnd2(node *&H, int x) {
	if (H == NULL)
		AddToList(H, x);
	else {
		node *p = H;
		while (p->next != NULL)
			p = p->next;
		AddToList(p->next, x);
	}
}
void AddToAfterx(node *&H, int x, int y) {
	if (H != NULL) {
		node *p = H;
		node *p1 = H;
		while (p->val!= y)
			p = p->next;
        p1 = p->next;
        AddToList(p->next, x);
        p = p->next;
        p->next = p1;
	}
}
void ChangexToNext(node *&H, int x) {
	if (H != NULL && x != NULL) {
		node *p = H;
		while (p != NULL && p->val != x)
			p = p->next;
        if (p == NULL ) {
            cout<<"Nie ma podanej wartoœci w liœcie"<<endl;
        }
        else if (p->next != NULL) {
            node *e = new node;
            node *y = new node;
            // cout<<p->val<<endl;
            e->next = NULL;
            y->next = NULL;
            e->val = p->next->val;
            y->val=p->val;
            p->val = e->val;
            p->next->val = y->val;
        }
        else {
            cout<<"nie mozna bo x zamieni sie z nuLLEM"<<endl;
        }
	}
    else {
	    cout<<"zle"<<endl;
    }
}
void ChangexToPrev(node *&H, int x) { //think
	if (H != NULL && x != NULL) {
		node *p = H;
		while (p != NULL && p->val != x)
			p = p->next;
        if (p == NULL ) {
            cout<<"Nie ma podanej wartoœci w liœcie"<<endl;
        }
        else if (p->next != NULL) {
            node *e = new node;
            node *y = new node;
            // cout<<p->val<<endl;
            e->next = NULL;
            y->next = NULL;
            e->val = p->next->val;
            y->val=p->val;
            p->val = e->val;
            p->next->val = y->val;
        }
        else {
            cout<<"nie mozna bo x zamieni sie z nuLLEM"<<endl;
        }
	}
    else {
	    cout<<"zle"<<endl;
    }

}
void AddLastToFirst(node *&H) {
	if (H != NULL && H->next != NULL) {
		node *p = H;
		while (p->next->next != NULL)
			p = p->next;
		node *e = p->next;
		p->next = NULL;
		e->next = H;
		H = e;
	}
}
void ChangeFirstElements(node *&H) {
	if (H != NULL && H->next != NULL) {
		node *p = H;
		H = p->next;
		p->next = H->next;
		H->next = p;
	}
}

void DeleteList(node *&H)
{
	{if (H != NULL)
		node *P;
	node *P = H;
	H = H->next;
	delete P; }
}
int main()
{
	node *H = NULL;
	H = new node;
	H->val = 3;
	H->next = NULL;
	showlist(H);

	node *P;
	P = new node;
	P->val = 8;
	P->next = H;
	H = P;
	showlist(H);
	AddToList(H, 5);
	AddToList(H->next, 16);
	DeleteList(H);
	showlist(H);
	AddToEnd(H, 10);
	showlist(H);
	AddToEnd2(H, 18);
	showlist(H);
	AddLastToFirst(H);
	showlist(H);
	ChangeFirstElements(H);
	showlist(H);
    AddToAfterx(H,12,10);
    showlist(H);
	cout << endl;

    ChangexToNext(H,18);
	showlist(H);




	return 0;
}
