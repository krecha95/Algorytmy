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
void ChangexToNext(node *&H, int x) {
	if (H != NULL && x != NULL) {
		node *p = H;
		while (p != NULL && p->val != x)
			p = p->next;
        if (p == NULL ) {
            cout<<"Nie ma podanej wartosci w liscie"<<endl;
        }
        else if (p->next != NULL) {
            node *e = new node;
            node *y = new node;
            // cout<<p->val<<endl;- sprawdzenie
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

void MergeListSort(node *&H1,node *H2) {
    node *H3 = NULL;
    if (H1 != NULL && H2 != NULL) {
        H3=H2;
        H2=NULL;
    }
    else if(H1 !=NULL && H2==NULL) {
        H3=H1;
        H1=NULL;
    }
    else {
        node *p1=H1;
        node *T;
        node *p2=H2;
        while (H1 != NULL && H2 != NULL) {
            if(p1->val<p2->val){
                if(H3 == NULL) {
                    H1=H1->next;
                    p1->next=H3;
                    H3=p1;
                    T=H3;
                    p1=H1;
                }
                else{
                    H1=H1->next;
                    T->next=p1;
                    p1->next=NULL;
                    T=p1;
                    p1=H1;
                }
            }
        }
    }
}

void BubbleSort(node *&H1) {
    node *p = H1;
    while (p->next != NULL)
        while (p->next->next !=NULL)
            if(p->next > p->next->next) ChangexToNext(H1,p->val);
}


int main()
{
	node *H1 = NULL;
	H1 = new node;
	int liczba = std::rand()%50;
	H1->val = liczba;
	H1->next = NULL;
	for(int i=0;i<9;i++) {
        int liczba = std::rand()%50;
        AddToList(H1,liczba);
	}
    showlist(H1);
    cout<<"dodanie 10 dowolnych liczb do listy pierwszej"<<endl<<endl;

    node *H2 = NULL;
	H2 = new node;
	int liczba2 = std::rand()%50;
	H2->val = liczba2;
	H2->next = NULL;
	for(int i=0;i<9;i++) {
        int liczba2 = std::rand()%50;
        AddToList(H2,liczba2);
	}
    showlist(H2);
    cout<<"dodanie 10 dowolnych liczb do listy drugiej"<<endl<<endl;

    MergeListSort(H1,H2);
    showlist(H2);
    //cout<<endl;
    //showlist(H1);

    cout<<endl;
    cout<<endl;

    BubbleSort(H1);
    showlist(H1);

	return 0;
}
