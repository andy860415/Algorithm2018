#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;
ifstream fin;
ofstream fout;

void fread();
void fwrite(int A[],int size);
void Merge_Sort(int A[],int p,int q);
void Merge(int A[], int p, int q, int m);


string line;
string name;
int data[100]={0};



int main()
{
	cout<<"Input file name:";
	cin>>name;
	fread();
	int i=0;
	while(data[i]!=0)
	{
	    i++;
	}
	Merge_Sort(data,0,i-1);

	fwrite(data,i-1);

}

void Merge_Sort(int A[], int p, int q) {
	if (p < q)
    {
		int m = (p + q) / 2;
		Merge_Sort(A, p, m);
		Merge_Sort(A, m + 1, q);
		Merge(A, p, q, m);
	}
}

void Merge(int A[], int p, int q, int m) {
	int end1 = m - p + 1;
	int end2 = q - m;
	int L [end1];
	int R [end2];

	for (int i = 0; i < end1; i++) {
		L[i] = A[p+i];
	}
	for (int i = 0; i < end2; i++) {
		R[i] = A[i+m+1];
	}
	L[end1] = 999999999;
	R[end2] = 999999999;
	int i = 0, j = 0;
	for (int k = p; k <= q; k++) {
		if (L[i] <= R[j])
        {
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}

void fread()
{
	fin.open((name).c_str());

	int size=0,i=0;
	fin>>size;
//	cout<<size<<endl;
	getline(fin,line);

	while(fin>>data[i])
    {
        i++;
        //fin>>data[i];
    }

//	for(int j=0;j<i;j++)
//	cout<<data[j]<<" *";




}


void fwrite(int A[],int size)
{
	int i=0;
	fout.open("HW1_E24046276.txt") ;

	fout<<size+1;
//	for(i=0;i<size;i++)
//	fout<<data[size]<<" ";
	fout<<endl;
	for(i=0;i<size+1;i++)
	fout<<i+1<<" : "<<data[i]<<endl;

	fout.close();
}


