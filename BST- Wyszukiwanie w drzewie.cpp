#include <iostream>
#include <iomanip>

using namespace std;

// Typ węzłów drzewa BST

struct BSTNode
{
  BSTNode * left;
  BSTNode * right;
  int key;
};

// Funkcja wczytuje drzewo BST ze standardowego
// wejścia i zwraca wskazanie korzenia.
//-----------------------------------------------
BSTNode * readBST()
{
  BSTNode ** vp;    // Tablica wskazań węzłów
  int key,l,r,i,n;

  cin >> n;                 // Odczytujemy liczbę węzłów drzewa

  vp = new BSTNode * [n];   // Tworzymy dynamiczną tablicę wskazań węzłów

  // Tablicę dynamiczną wypełniamy wskazaniami węzłów,
  // które również tworzymy dynamicznie

  for(i = 0; i < n; i++) vp[i] = new BSTNode;

  // Teraz wczytujemy definicję drzewa i tworzymy jego strukturę
  // w pamięci wypełniając odpowiednie pola węzłów.

  for(i = 0; i < n; i++)
  {
    cin >> key >> l >> r;   // Czytamy klucz, numer lewego i prawego syna

    vp[i]->key = key;       // Ustawiamy klucz

    vp[i]->left  = l ? vp[l]: NULL;  // Ustawiamy lewego syna

    vp[i]->right = r ? vp[r]: NULL;  // Ustawiamy prawego syna

  }

  BSTNode * p = vp[0];      // Zapamiętujemy korzeń

  delete [] vp;             // Usuwamy tablicę dynamiczną

  return p;
}

// Funkcja szuka w drzewie BST węzła o zadanym kluczu.
// Jeśli go znajdzie, zwraca jego wskazanie. Jeżeli nie,
// to zwraca wskazanie puste.
// Parametrami są:
// p - wskazanie korzenia drzewa BST
// k - klucz poszukiwanego węzła
//----------------------------------------------------
BSTNode * findBST(BSTNode * p, int k)
{
  while(p && p->key != k)
    p = (k < p->key) ? p->left: p->right;

  return p;
}

// Funkcja zwraca wskazanie węzła o najmniejszym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * minBST(BSTNode * p)
{
  if(p) while(p->left) p = p->left;

  return p;
}

// Funkcja zwraca wskazanie węzła o największym kluczu.
// Parametrem jest wskazanie korzenia drzewa BST.
//------------------------------------------------------
BSTNode * maxBST(BSTNode * p)
{
  if(p) while(p->right) p = p->right;

  return p;
}

// Procedura DFS:postorder usuwająca drzewo
//-----------------------------------------
void DFSRelease(BSTNode * v)
{
  if(v)
  {
    DFSRelease(v->left);   // usuwamy lewe poddrzewo
    DFSRelease(v->right);  // usuwamy prawe poddrzewo
    delete v;              // usuwamy sam węzeł
  }
}

// **********************
// *** PROGRAM GŁÓWNY ***
// **********************

int main()
{
  BSTNode * root, * p;
  int k, mink, maxk;

  root = readBST();     // Odczytujemy drzewo BST

  if(root)
  {
    mink = minBST(root)->key; // Odczytujemy klucz minimalny
    maxk = maxBST(root)->key; // Odczytujemy klucz maksymalny

    // Przechodzimy przez kolejne wartości kluczy

    for(k = mink; k <= maxk; k++)
    {
      p = findBST(root,k);    // szukamy węzła o kluczu k

      cout << "KEY = " << setw(3) <<  k << " : ";

      if(p)
      {
        if (!p->left && !p->right) cout << "LEAF";
        else                       cout << "INNER NODE";
      }
      else cout << "NONE";

      cout << endl;
    }
  }
  else cout << "BST is empty!!!" << endl;

  DFSRelease(root);    // usuwamy drzewo z pamięci

  return 0;
}
