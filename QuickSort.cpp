#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;
ifstream fin;
ofstream fout;

void fread();										//read file function
void fwrite(int A[],int size);						//write file function
void Quicksort(int A[],int p,int r);
int PARTITION(int A[],int p,int r);
void swap(int *A, int *B);							//change data in A and B

string line;
string name;
int data[999999]={0};



int main()
{
	fread();
	int i=0;
	while(data[i]!=0)								//find the size of array
	{
	    i++;
	}
	Quicksort(data,0,i-1);

	fwrite(data,i);

}


void Quicksort(int A[],int p,int r)
{
	if (p < r)										//check if subarrays still have more than 2 datas
 	{
		int q = PARTITION(A, p, r);					//set q is the location between two subarray
 		Quicksort(A, p, q-1);						//the recurrsive sort first part and second part
		Quicksort(A, q+1, r);
	}
}

int PARTITION(int A[],int p,int r)					//p is first number of array, r is last
{
 int x = A[r];										//set last number as key
 int i = p-1;										//first we set i is the number before fist number
 for (int j = p ;j<r;j++)
	{
 		if (A[j]<=x)								//if number is smaller than key
 			{
   			 	i = i + 1;
 				swap (A[i] , A[j]);					//change A[i] and A[j]
 			}
	}
			swap( A[i+1] , A[r]);					//after all number before last done, put key back to the location between two subarray
 			return i+1;								//and return its location
}

/*
	set a temp then :A->temp, B->A, temp->A
	then finish A<->B
*/

void swap(int *A, int *B)
{
	int *temp=A;
	A=B;
	B=temp;
}


void fread()
{
	fin.open("test.txt");
	int size=0,i=0;
	fin>>size;
	getline(fin,line);
	while(fin>>data[i])
    {
        i++;
    }
}


void fwrite(int A[],int size)
{
	int i=0;
	fout.open("HW2_E24046276.txt") ;
	fout<<size;
	fout<<endl;
	for(i=0;i<size;i++)
	fout<<i+1<<" : "<<data[i]<<endl;
	fout.close();
}
