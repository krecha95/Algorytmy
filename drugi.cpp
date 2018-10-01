#include  <iostream>
#include  <windows.h>
#include  <cstdlib>
#include  <time.h>
#include  <stdio.h>
#include  "string"
#include <fstream>

using namespace std;

struct node
{
    int dist;
    int too;
    int from;
    node *next;
};

//void czytaj {
    //fstream
//}

/*void MoS() {
    int **MS = new int*[size]
    for (int i=0;i<size;i++)
        MS[i]=new int[size];
}
*/
void AddNodeToLN(node * &L, int too, int dist) {
 node *p = new node;
 p->too = too;
 p->dist = dist;
 p->next = L;
 L = p;
}
void show(node * H) {
 cout << "H->";
 node* p = H;
 while (p != NULL)
 {
 cout << p->dist << "/" << p->too << "->";

 p = p-> next;

 }
 cout << "NULL" << endl;
}


int main()
{
    cout << endl;
     fstream czytaj;
     czytaj.open("graf.txt");
     int size;
     czytaj >> size;

     int** tab = new int*[size];
     for (int i = 0; i < size; i++) {
        tab[i] = new int[size];
     }
     for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
         czytaj >> tab[i][j];
         }
     }
     node **LN = new node *[size];
     for (int i = 0; i < size; i++) {
     LN[i] = NULL;
     }
     for (int i = 0; i < size; i++) {
     for (int j = 0; j < size; j++) {
     if (tab[i][j] > 0) {
     AddNodeToLN(LN[i], j, tab[i][j]);
     }
     }
     }
     for (int i = 0; i < size; i++) {
     show(LN[i]);
     }

	system("pause");

    return 0;
}

