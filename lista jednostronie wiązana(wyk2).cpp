#include<iostream>
#include<fstream>
using namespace std;

struct node {
	int vol;
	node *next;
};

void showlist(node *H) {
	node *p = H;
	cout << "H->";
	while (p!=NULL) {
		cout << p->vol << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

void AddToList(node *&H, int x) {
	node *p = new node;
	p->vol = x;
	p->next = H;
	H = p;
}

void DeleteList(node*&H) {
	if (H != NULL) {
		node *p = H;
		H = H->next; //H=p->next;
		delete p;
	}
}

void DelNode(node *&H, int x) {
    node *p = H;
    if (H != NULL) {
        if (H->vol==x) {
            H=H->next;
            delete p;
        } else {
            node *p=H;
            while (p->next=NULL&&p->next->vol!=x)
                p=p->next;
            if (p->next!=NULL) {
                node *p1=p->next;
                p->next=p1->next;
                delete p1;
            }
        }
    }
}


int main() {
	node *H = NULL;
	H = new node;
	H->vol = 3;
	H->next = NULL;
	node *p;
	p = new node;
	p->vol = 8;
	p->next = H;
	H = p;

	//cout << H->vol << endl;
	//cout << H->next->vol << endl;
	showlist(H);
	AddToList(H, 5);
	showlist(H);
	AddToList(H->next, 20);
	showlist(H);
	DeleteList(H);
	showlist(H);
	DelNode(H->next, 8);
	showlist(H);

	return 0;
}
