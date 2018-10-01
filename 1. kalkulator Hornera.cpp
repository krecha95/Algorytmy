#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
	int suma;
	int n, cyfra, size;
	int t;
	
	do
	{
	suma=0;
	cout<< "KALKULATOR ZMIENIA LICZBE NA SYSTEM DZIESIETNY "<<endl;
	
	cout<<"podaj dlugosc liczby: ";
	cin>>size;
	int *tab=new int[size];
	
	cout<<"Z jakiego systemu? [Podaj liczbe 2-dwujkowy, 8-osemkowy, 16-szesnastkowy ]"<<endl;
	cin>>n;
	cout<<"podaj liczbe: ";

		
		for(int i=0; i<size; i++)
		{
			cin>>cyfra;
			tab[i]=cyfra;
		
		}
		for(int i=0; i<size; i++)
		{
			if(tab[i]>n)
			{
				cout<<"Blad, jeszcze raz zacznij!"<<endl;
				break;
			}
			else
			{
				suma=tab[0];
				if(size<=2)
				{
					suma=tab[0]*n+tab[1];
				}
				if(size>2)
				{		
					for(int i=0; i<size-1; i++)	
						suma=suma*n+tab[i+1];
				}	
			}
		}
		cout<<"liczba w systemie dziesietnym : "<<suma<<endl;
		cout<<"Przerwij liczenie, wcisnij '1'"  ;
		cin>>t;
	} while(t!=1);
	
  
    return 0;   
    system("pause");
}

