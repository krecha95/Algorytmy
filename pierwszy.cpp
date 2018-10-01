#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct nodeBST {
    int val;
    nodeBST *R;
    nodeBST *L;
    nodeBST * up;
};
// Zmienne globalne
string cr,cl,cp;      // ³añcuchy do znaków ramek

void printBT(string sp, string sn, nodeBST * v) {
  string s;

  if(v)
  {
    s = sp;
    if(sn == cr) s[s.length() - 2] = ' ';
    printBT(s + cp, cr, v->R);

    s = s.substr(0,sp.length()-2);
    cout << s << sn << v->val << endl;

    s = sp;
    if(sn == cl) s[s.length() - 2] = ' ';
    printBT(s + cp, cl, v->L);
  }
}

void AddBSTTree(nodeBST * &root, int x) {
	//nodeBST *p = new nodeBST;
	if(root=NULL) {
        nodeBST *f=new nodeBST;
        f->L=f->R=NULL;
        f->val = x;
	}
	else
        if(x<root->val)
        AddBSTTree(root->L,x);
        else
        AddBSTTree(root->R,x);
}

void insertBST(nodeBST * & root, int k) {
  nodeBST * w, * p;

  w = new nodeBST;

  w->L = w->R = NULL;
  w->val = k;
  p = root;                  // Wyszukujemy miejsce dla w, rozpoczynaj¹c od korzenia

  if(!p)                     // Drzewo puste?
  root = w;                // Jeœli tak, to w staje siê korzeniem
  else
    while(true)              // Pêtla nieskoñczona
      if(k < p->val)         // W zale¿noœci od klucza idziemy do lewego lub
      {                      // prawego syna, o ile takowy istnieje
        if(!p->L)         // Jeœli lewego syna nie ma,
        {
          p->L = w;       // to wêze³ w staje siê lewym synem
          break;             // Przerywamy pêtlê while
        }
        else p = p->L;
      }
      else
      {
        if(!p->R)        // Jeœli prawego syna nie ma,
        {
          p->R = w;      // to wêze³ w staje siê prawym synem
          break;             // Przerywamy pêtlê while
        }
        else p = p->R;
      }

  w->up  = p;                // Ojcem wêz³a w jest zawsze wêze³ wskazywany przez p

}

bool searchBST(nodeBST *root, int x) {
    if(root!=NULL) {
        if(root->val != x) {
            if(x<root->val)
                searchBST(root->L,x);
            else
                searchBST(root->R,x);
        }
        else
            return root;
    }
    else
        return NULL;
}

int main() {
    //nodeBSD *root=NULL;
    //cout<<root->val<<endl;
    //AddToLN(LN[a1], 5, 7);

    nodeBST * root = NULL;
    //cout<<root->val<<endl;


    cr = cl = cp = "  ";
    cr[0] = 218; cr[1] = 196;
    cl[0] = 192; cl[1] = 196;
    cp[0] = 179;

    srand(time(NULL));        // inicjujemy generator pseudolosowy

    for(int i = 0; i < 20; i++)   // Wype³niamy drzewo BST wêz³ami
    {
    int k = 1 + rand() % 9;     // Generujemy klucz 1...9
    cout << k << " ";       // Wyœwietlamy klucz
    insertBST(root,k);      // Tworzymy nowy wêze³ o kluczu k i umieszczamy go w drzewie
    }
    //AddBSTTree(root,5);

    cout << endl << endl;
    searchBST(root,5);
    cout << endl << endl;

    printBT("","",root);      // Wyœwietlamy drzewo


    return 0;
}
