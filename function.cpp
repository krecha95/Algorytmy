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
void ChangexToPrev(node *&H, int x) {
	if (H != NULL && x != NULL) {
		node *p = H;
		node *pp = H;
		int i=0;
		while (p != NULL && p->val != x) {
			p = p->next;
			i=i+1;
		}
		//cout<<i<<endl;
        for (int j=0;j<i-1;j++)
            pp = pp->next;
        if (p == NULL) {
            cout<<"Nie ma podanej wartosci w liscie lub x zamieni sie z nullem"<<endl;
        }
        else {
            node *e = new node;
            node *y = new node;
            //cout<<p->val<<endl;
            //cout<<pp->val<<endl;
            e->next = NULL;
            y->next = NULL;
            e->val = pp->next->val;
            y->val = pp->val;
            pp->val = e->val;
            pp->next->val = y->val;
        }
	}
    else {
	    cout<<"zle- nie ma takiej wartosci"<<endl;
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
void DelEverySecondElement (node *&H) {
    node *p=H;
    while(p!=NULL && p->next != NULL) {
        DeleteList(p->next);
        p=p->next;
    }
}
void InverseList (node *&H1) {
    node *H2=NULL;
    node *p=H1;
    while(p != NULL ) {
        H1=p->next;
        p->next=H2;
        H2=p;
        p=H1;
    }
    H1=H2;
    H2=NULL;
}
void CopyInverseListBehind(node *&H) {
    node *p=H;
    while(p!=NULL) {
        AddToList(H,p->val);
        p=p->next;
    }
}
void CopyListBehind(node *&H)  {
        node *H2=NULL;
        node *p=H;
        while (p->next != NULL) {
            AddToList(H2,p->val);
            p=p->next;
        }
        InverseList(H2);
        node *p2=H2;
        while (p2->next!=NULL)
            p2=p2->next;
        p2->next=H;
        H=H2;
        H2=NULL;

}
void CopyEqualVal(node *&H) {
    node *p=H;
    while (p != NULL) {
        for (int i=1;i<p->val;i++) {
            AddToList(p->next,p->val);
            p=p->next;
        }
        p=p->next;
        }
}
void DelEvenNumb(node *&H) {
		node *p = H;

		while (p->next != NULL)
		{
			if (p->next->val % 2 == 0)
			{
				DeleteList(p->next);
			}
			else {
				p=p->next;
		}
}
}
void Add10RandNumb (node *&H) {
    //node *p=H;
    for(int i=0;i<10;i++) {
        int liczba = std::rand()%50+1;
        AddToList(H,liczba);
	}
}
