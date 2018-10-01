#include <iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

void push(node *&H, int x) {
    node *p = new node;
    p->val = x;
    p->next = H;
    H=p;
}

void pop(node *&H) {
    if(H != NULL) {
    node *p = H;
    H = p-> next;
    delete p;
    }
}

void show(node *H) {
    node *p = H;
    cout << "HEAD -> ";
    while(p != NULL) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void enqueue(node *&H, node *&T, int x) {
    node *p = new node;
    p->next = NULL;
    p->val = x;

    if(H == NULL) {
        H = p;
        T = H;
    } else {
        T->next = p;
        T = p;
    }
}

void del(node *&H, node *&T) {
    if(H != NULL) {
    node *p = H;
    H = p-> next;
    T = NULL;
    delete p;
    }
}

void del2(node *&H, node *&T) {
    node *p1 = NULL;
    if(H != NULL && H->next != NULL) {
        node *p = H;
        while(p != NULL && p->next != NULL)
        {
            p1 = p->next;
            p->next = p1->next;
			T = NULL;
            delete p1;
            p=p->next;
        }
    }
}

void primaryLast(node *&H) {
	node *p = H; // wskazuje na pierwszy element
	node *p1 = H; // wskazuje na pierwszy element
	node *tmp = NULL;
	if(H != NULL && H->next != NULL) {
		while(p != NULL && p->next != NULL) { // szuka ostatniego elementu
			p = p->next;
		}
		tmp = p; //ostatni element
		int value = p->val; // zachowanie wartoœci pierwszego elementu
		tmp->val = p1->val; // ustaw na ostatni pierwszy element
		p1->val = value; // ustaw na pierwszy ostatni element
	}
}

void exchange(node *&H, int x) {
	node *p = H;
	node *p1 = p;
	for(int i = 0; i <= x; i++) {
		if(p1->next != NULL) {
		if(i == x) {
			int value = p->val;
			p->val = p1->val;
			p1->val = value;
		}
		p1 = p1->next;
		} else {
			cout << "Nie ma tylu elementow" << endl;
			break;
		}
	}
}

void copy(node *&H) {
	node*p = H;
	while(p != NULL) {
		for(int i=0;i<1;i++) {
			node*p1 = new node; // rezerwacja miejsca w pamiêci
			p1->next = p->next;
			p1->val = p->val;
			p->next = p1;
			p = p->next;
		}
		p = p->next;
	}
}

void changeChoseElements(node*H, int x, int y) {
    node *p = H;
    node *p1 = p;

	node *tmp = p;
	node *tmp2 = p1;


		for(int i = 0; i <= x; i++) {
			if(i == x) {
				tmp = p;

			}
			p = p->next;
		}
		for(int j = 0; j <= y; j++) {
			if(j == y) {
				tmp2 = p1;
			}
			p1 = p1->next;
		}

		int value = tmp->val;
		tmp->val = tmp2->val;
		tmp2->val = value;
}
int main() {
    node *H = NULL;
    node *T = NULL;
    show(H);

    push(H, 5);
    push(H, 15);
    push(H, 20);
    push(H, 100);
    //enqueue(H, T, 10);
    //enqueue(H, T, 15);
    //enqueue(H, T, 20);
    //enqueue(H, T, 30);
    show(H);
    del(H,T);
    show(H);
    pop(H);
    show(H);

	push(H, 5);
    push(H, 15);
    push(H, 20);
    push(H, 100);
	del(H,T);
	primaryLast(H);
	//zamien_krance(H);
	push(H, 15);
	push(H, 100);
	push(H, 20);
	push(H, 40);
	show(H);
	changeChoseElements(H, 0, 2);
	//copy(H);
	//exchange(H, 6);
	show(H);

}
