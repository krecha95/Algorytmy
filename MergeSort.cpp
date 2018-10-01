#include<iostream>
#include<cstdlib>
using namespace std;

int *pom; //tablica pomocnicza, potrzebna przy scalaniu

//scalenie posortowanych podtablic
void scal(int tab[], int lewy, int srodek, int prawy)
{
	int i = lewy, j = srodek + 1;

  //kopiujemy lew� i praw� cz�� tablicy do tablicy pomocniczej
  for(int i = lewy;i<=prawy; i++)
    pom[i] = tab[i];

  //scalenie dw�ch podtablic pomocniczych i zapisanie ich
  //we w�asciwej tablicy
  for(int k=lewy;k<=prawy;k++)
  if(i<=srodek)
    if(j <= prawy)
         if(pom[j]<pom[i])
             tab[k] = pom[j++];
         else
             tab[k] = pom[i++];
    else
        tab[k] = pom[i++];
  else
      tab[k] = pom[j++];
}

void sortowanie_przez_scalanie(int tab[],int lewy, int prawy)
{
	//gdy mamy jeden element, to jest on ju� posortowany
	if(prawy<=lewy) return;

	//znajdujemy srodek podtablicy
	int srodek = (prawy+lewy)/2;

	//dzielimy tablice na cz�s� lew� i prawa
	sortowanie_przez_scalanie(tab, lewy, srodek);
	sortowanie_przez_scalanie(tab, srodek+1, prawy);

	//scalamy dwie ju� posortowane tablice
	scal(tab, lewy, srodek, prawy);
}

int main()
{
	int *tab,
	n; //liczba element�w tablicy

	cin>>n;
	tab = new int[n]; //przydzielenie pami�ci na tablic� liczb
	pom = new int[n]; //przydzielenie pami�ci na tablic� pomocnicz�

	//wczytanie element�w tablicy
	for(int i=0;i<n;i++)
		cin>>tab[i];

	//sortowanie wczytanej tablicy
	sortowanie_przez_scalanie(tab,0,n-1);

	//wypisanie wynik�w
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";

	system("pause");
	return 0;
}
