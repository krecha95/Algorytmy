#include <cmath>
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main ()
{
    int a,b,c;
    
	cin>>a>>b;
	cout<<"NWD ("<<a<<" , "<<b<<") : ";
	if(b==0)
		{
			cout<<a;
		}
	
	while(b!=0)
	{
		c=a % b;
		a=b;
		b=c;
		
	}
	cout<<a;		 
    return 0;
    system("pause");
}	


