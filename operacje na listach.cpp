#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node {
	int val;
	node *next;
};
void showlist(node *H) {
	node *p = H;
	cout << "H->";
	while (p != NULL)
	{
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void AddToList(node *&H, int x) {
	node *p;
	p = new node;
	p->val = x;
	p->next = H;
	H = p;
}
void AddToEnd(node *&H, int x) {
	if (H == NULL)
	{
		node *p;
		p = new node;
		p->val = x;
		p->next = H;
		H = p;
	}
	else
	{
		node *p = H;

		while (p->next != NULL)
			p = p->next;
		AddToList(p->next, x);
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
void DeleteList(node*&H) {
	if (H != NULL) {
		node*p = H;
		H = H->next;
		delete p;
	}
}
void DelNodex (node *&H, int x) {
    if(H!=NULL) {
        if (H->val == x) {
            node *p=H;
            H=H->next;
            delete p;
        }
        else {
            node *p=H;
            while (p->next != NULL && p->next->val !=x)
                p=p->next;
            if(p->next!= NULL) {
                node *p1=p->next;
                p->next=p1->next;
                delete p1;
            }
        }
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
void ChangeLastToFirst(node *&H) {
    if (H != NULL && H->next != NULL) {
        node *f = H;
        node *e = H;
        while (e->next != NULL)
            e = e->next;
        H=f->next;
        AddToList(H,e->val);
        e->val=f->val;
    }
}
void CopyEveryElements(node *&H) {
	node*p = H;
	while(p != NULL) {
		for(int i=0;i<1;i++) {
			node*p1 = new node;
			p1->next = p->next;
			p1->val = p->val;
			p->next = p1;
			p = p->next;
		}
		p = p->next;
	}
}


int main()
{
	node *H = NULL;
	H = new node;
	H->val = 3;
	H->next = NULL;
	showlist(H);
	cout<<"dodanie 3 do listy"<<endl<<endl;

    AddToList(H,5);
    showlist(H);
    cout<<"dodanie 5 do listy- przed glowe"<<endl<<endl;
    AddToList(H,15);
    showlist(H);
    cout<<"dodanie 15 do listy- przed glowe"<<endl<<endl;

	AddToList(H->next, 16);
	showlist(H);
	cout<<"dodanie 16 do listy- na drugie miejsce przed glowe"<<endl<<endl;

	DeleteList(H);
	showlist(H);
	cout<<"usuniecie elementu sprzed glowy"<<endl<<endl;

	AddToEnd(H, 10);
	showlist(H);
	cout<<"dodanie 10 na koniec listy"<<endl<<endl;

	AddToEnd2(H, 18);
	showlist(H);
	cout<<"dodanie 18 na koniec listy"<<endl<<endl;

	AddLastToFirst(H);
	showlist(H);
	cout<<"Przeniesienie ostatniego elementu listy na pierwsze miejsce - przed glowe"<<endl<<endl;

	ChangeFirstElements(H);
	showlist(H);
	cout<<"Zamiana elementu pierwszego z drugim"<<endl<<endl;

    AddToAfterx(H,12,3);
    showlist(H);
	cout<<"Dodanie elementu przed podany- 12 przed 3"<<endl<<endl;


	return 0;
}
