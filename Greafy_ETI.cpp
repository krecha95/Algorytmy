#include<iostream>
#include<fstream>
using namespace std;

struct node //Lista krawêdzi
{
	int from;
	int too;
	int dist;
	node *next;
};

struct macMN // macierz s¹siedztwa
{
	int **matrix; //macierz
	int size;    // rozmiar
};

void AddNodeToLN(node *&H, int too1, int distance)
{
	node *p=new node;
	p->too=too1;
	p->dist=distance;
	p->next=H;
	H=p;
}
void showLE(node *Head)
{
	if(Head!=NULL){
		node *HE=Head;
		cout<<"LE ->dist/from/too -> ";
			while(HE!=NULL){
				cout<<HE->dist<<"/"<<HE->from<<"/"<<HE->too<<"/"<<"->";
				HE=HE->next;
			}
			cout<<"NULL"<<endl;
	}
	cout<<endl;
}

void AddNodeToSortedLE(node *&LE, int distance, int from, int too)
{
	node *p=new node;
	p->dist=distance;
	p->from=from;
	p->too=too;

	if(LE==NULL)
	{
		LE=p;
		LE->next=NULL;
	}
	else
	{
		if(distance<LE->dist)
		{
			p->next=LE;
			LE=p;
		}
		else
		{
			node *p1=LE;
			while(p1->next!=NULL&&p1->next->dist<distance)
				p1=p1->next;
			if(p1->next!=NULL)
			{
				p->next=p1->next;
				p1->next=p;
			}
			else
			{
				p1->next=p;
				p->next=NULL;
			}
		}
	}
}



macMN GenerateMN(string FileName)
{
	macMN MN;
	fstream czytaj;
	czytaj.open(FileName);
	int n;
	czytaj>>n;
	MN.matrix =new int*[n];
	for(int i=0;i<n;i++)
		MN.matrix[i]=new int[n];
	MN.size=n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			czytaj>>MN.matrix[i][j];
	czytaj.close();
	return MN;
}

node **GenerateLN(string FileName)
{
	node **LN;
	fstream czytaj;
	int value=0;
	czytaj.open(FileName);
	int n;
	czytaj>>n;

	LN=new node*[n];
	for(int i=0;i<n;i++)
		LN[i]=NULL;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			czytaj>>value;
			if(value>0)
				AddNodeToLN(LN[i], j, value);
		}
	}
	czytaj.close();
	cout<<endl;
	return LN;

}

node *SortedListOfEdge(string FileName)
{
	node *LE;
	fstream czytaj;
	int value=0;
	czytaj.open(FileName);
	int n;
	czytaj>>n;

	LE=NULL;


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			czytaj>>value;
			if(j>=i && value>0)
				AddNodeToSortedLE(LE, value, i, j);
			
		}
	}
	czytaj.close();
	return LE;

}


void showMN(macMN MN)
{
	for(int i=0;i<MN.size;i++)
	{
		for(int j=0;j<MN.size;j++)
		{
			cout<<MN.matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}



void showLN(node **LN, int size)
{
	node *p=NULL;
	for(int i=0;i<size;i++)
	{
		p=LN[i];
		cout<<"H["<<i<<"]=";
		while(p!=NULL)
		{
			cout<<p->too<<"/"<<p->dist<<"->";
			p=p->next;
		}
		cout<<"NULL"<<endl;
	}
	cout<<endl;
}



int main()
{
	node **LN=NULL;
	node *LE=NULL;
	macMN MN;
	int n=0; // graf size
	fstream czytaj;
	string FileName = "graf2.txt";
	

	czytaj.open(FileName);
	czytaj>>n;
	czytaj.close();

	MN=GenerateMN(FileName); //Matrix of neighbourhood
	showMN(MN);
	LN=GenerateLN(FileName);//List of neighbourhood
	showLN(LN, n);
	LE=SortedListOfEdge(FileName);//
	showLE(LE);

	system("pause");

return 0;
}



