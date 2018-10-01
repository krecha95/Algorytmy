#include<iostream>
#include<cmath>
#include<ctime>
#include <time.h>
#include <stdlib.h>
using namespace std;

void kalkulator(int a, int x);

int main()
{
	srand(time(NULL));  /////tworzenie tablicy
	
	int a, n, liczba, x;
    int suma=0;
	cout<<"wprowadz wymiary tablicy ";
	cin>>n;
	int *tab=new int[n];
	cout<<"Podaj liczbe w systemie dziesietnym: ";
	cin>>a;
	x=a;
	kalkulator (a,x);
	cout<<endl;
	///////////////////////////// DRUGI SPOSOB
	
	cout<<" TO TERAZ TO SAMO TYLKO INNYM SPOSOBEM (tylko czytaj od prawej): "<<endl;
	cout<<endl;
	cout<<"jeszcze raz podaj liczbe: ";
	cin>>liczba;
	x=liczba;
	for(int b=0; b=x; b++)
	{
		x=x/2;
		suma++;
	}
	for(int i=suma; i>0; i--)
	{
	
		int reszta=0;
		reszta=liczba%2;
		liczba=liczba/2;
		tab[i]=reszta;
		cout<<tab[i];			
	}  	
}

void kalkulator(int a, int x)
{
	int suma=0;
	int suma_dzielen=0;
	///funkcja co liczy ile razy trzeba dzielic liczbe przez 2 az do 0
	for(int b=0; b=x; b++)
	{
		x=x/2;
		
		suma_dzielen++;
	}
	
	
	
	///funkcja co przelicza dziesietna na binarna
	for(int i=suma_dzielen-1; i>=0; i--)
	{
		cout<<(a>>i&1); ///przesuniecie bitowe w prawo, iloczyn logiczny
		suma=suma+1;
		
	}
	
	
	
}
