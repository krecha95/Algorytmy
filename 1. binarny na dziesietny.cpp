#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{

    string binarna;
    int suma=0; //liczba dziesietna
	int potega1; 
	int potega2;
	

    cout<<"podaj liczbe w systemie binarnym : ";
    cin>>binarna;

    potega1=potega2=binarna.length()-1;  ///zwraca dlugosc stringa
    
	cout<<"potega1: "<<potega1;
    cout<<" potega2: "<<potega2<<endl;
    
    for(int i=0; i<=potega1; i++) 
	{
		if(binarna[i]=='1')
		{
			suma=suma+pow(2,potega2);  ///jak jest "1" to dodaje 2 do potegi
			potega2--;
		}
    	else 
		potega2--; //// jak jest "0" to nic nie robi
	}
        
    cout<<"liczba w systemie dziesietnym : "<<suma<<endl;

    return 0;   
}

