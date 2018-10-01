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
void AddAfter(node *&H, int x, int y)
{
	if (H != NULL)
	{
	
		node *P = H;
		node *P1 = H;
		
		while (P->val!= y)
			P = P->next;

			P1 = P->next;

			AddToList(P->next, x);
			P = P->next;
			P->next = P1;
	}
}
void Max(node *&H)
{
	if (H != NULL && H->next != NULL)
		node *p = H;
	while (p->next != NULL)
		p = p->next;
	node *p1 = p->next;
	p->next = NULL;
	p1->next = H;
	H = p1;


		
		
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

	node *P;
	P = new node;
	P->val = 8;
	P->next = H;
	H = P;
	showlist(H);
	AddToList(H, 5);
	AddToList(H->next, 20);
	DeleteList(H);
	showlist(H);
	AddToEnd(H, 10);
	showlist(H);
	AddAfter(H, 11, 8);
	showlist(H);
	Max(H);
	showlist(H);
	system("pause");
	return 0;
}