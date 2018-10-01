#include<iostream>
#include<cstdlib>
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
/*void merge_sort(node *&H) {
  node *h1=H,*h2=H;
  if(H && H->next)
  {
    split(h1,h2);
    h1.merge_sort();
    h2.merge_sort();
    merge(h1,h2);
  }
}*/

void swap(node *&H) {
    node *p=H;
    node *p1 = H;
    node *p2 = H;
        p1->next=p2->next;
        p2->next=p1;
        p->next=p2;
}
void swap2 (node *&H) {
    node *p=H->next;
    H->next = H->next->next;
    p->next = H->next->next;
    H->next->next=p;
}
void BubbleSort(node *&H) {
    node *p=H;
    int zamiana=0;
do
{
    int zamiana=0;//przed ka¿dym "przejazdem" pêtli for zmienna zamiana jest zerowana
    while (p->next != 0)
    {
    if (p->val>p->next->val)// jeœli element tablicy jest wiêkszy od nastêpnego elementu
    {
        swap2(p); //jeœli jest jakaœ zmiana, to zmienne zamiana powiêksza swoj¹ wartoœæ
        //int schowek=t[i];//wartoœæ t[i] jest kopiowana do schowka
        //t[i]=t[i+1];//t[i] przyjmuje wartoœæ nastêpnego elementu, gdy¿ jest on mniejszy
        //t[i+1]=schowek;//kolejny element tablicy przejmuje wczeœniejsz¹ wartoœæ poprzedniego elementu, gdy¿ jest on wiêkszy
    }
    p=p->next;
    }
}
while(zamiana!=0);
}



int main()
{
	//srand( time( NULL ) );
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

    /* node *H2 = NULL;
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
    */



    //swap2(H1);
    //swap(H1);
    BubbleSort(H1);
    showlist(H1);



	system("pause");
	return 0;
}
