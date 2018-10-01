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
void ChangeFirstElements(node *&H) {
	if (H != NULL && H->next != NULL) {
		node *p = H;
		showlist(H);
		cout<<"node *p = H;"<<endl;
		cout << p->val<<"-p"<<endl;
		cout << p->next->val<<"-p->next"<<endl;
		cout << H->val<<"-H"<<endl;
		cout << p->next->val<<"-H->next"<<endl;
		H = p->next;
		showlist(H);
		cout<<"H = p->next;"<<endl;
		cout << p->val<<"-p"<<endl;
		cout << p->next->val<<"-p->next"<<endl;
		cout << H->val<<"-H"<<endl;
		cout << p->next->val<<"-H->next"<<endl;
		p->next = H->next;
		showlist(H);
		cout<<"p->next = H->next;"<<endl;
		cout << p->val<<"-p"<<endl;
		cout << p->next->val<<"-p->next"<<endl;
		cout << H->val<<"-H"<<endl;
		cout << p->next->val<<"-H->next"<<endl;
		H->next = p;
		showlist(H);
		cout<<"H->next = p;"<<endl;
		cout << p->val<<"-p"<<endl;
		cout << p->next->val<<"-p->next"<<endl;
		cout << H->val<<"-H"<<endl;
		cout << p->next->val<<"-H->next"<<endl;
	}
}

void change2 (node *&H) {
    node *p;
    p->val = 4;
    p->next=H;
    H=p;

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

    ChangeFirstElements(H1);
    //change2(H1);
    showlist(H1);


}
