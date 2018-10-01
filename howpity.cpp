#include<iostream>
#include<cstdlib>
using namespace std;



void howpity(int *T, int howpsize, int i){
    int l=2*i;
    int r=l+1;
    int largest;
    if(l<howpsize && T[l]>T[i])
        largest=l;
    else
        largest=i;
    if(r<=howpsize && T[r]>T[largest])
        largest=r;
    if(largest!=i) {
        swap(T[i],T[largest]);
        howpity(T,howpsize,largest);
    }
}
void BulidHowpity(int *T, int howpsize) {
    for(int i=howpsize/2;i>0;i--)
        howpity(T,howpsize,i);
}
void HowpitySort(int *T,int howpsize) {
    //int howpsize=size;
    BulidHowpity(T,howpsize);
    while(howpsize>1) {
        swap(T[1],T[howpsize]);
        howpsize--;
        howpity(T,howpsize,1);
    }
}

int main() {
    int *T;
    T = new int[5];
    for(int i=0;i<5;i++)
		cin>>T[i];

    cout<<endl;
    for(int i=0;i<5;i++)
		cout<<T[i]<<" ";

    HowpitySort(T,5);

        cout<<endl;
    for(int i=0;i<5;i++)
		cout<<T[i]<<" ";

    BulidHowpity(T,5);
        cout<<endl;
    for(int i=0;i<5;i++)
		cout<<T[i]<<" ";
    return 0;
    system("pause");
}
