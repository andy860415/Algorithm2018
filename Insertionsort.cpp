#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


using namespace std;
ifstream fin;
ofstream fout;

void fread();										//read file function
void fwrite(int A[],int size);						//write file function
void INSERTIONSORT(int A[],int r);


string line;
string name;
int data[999999]={0};



int main()
{
	fread();
	int i=0;
	while(data[i]!=0)
	{
	    i++;											//find the size of array
	}
	INSERTIONSORT(data,i-1);
	fwrite(data,i);
}

/*
set key from second number to last number, every time we  compare the number before
the key, if the nuber is larger than key, move the number to key's location
*/

void INSERTIONSORT(int A[],int r)
{
for (int j =1;j<=r;j++)
{
 	int key = A[j];
 	int i=j-1;											//i is the number before key
	while (i >= 0 && A[i] > key)
	{
		A[i + 1] = A[i];
 		i = i - 1;
 	}
	A[i + 1] = key;										//when finish while loop, we put key back to the proper location where
}														//the number before key is smaller than key
}

void fread()
{
	fin.open("test.txt");								//open data file
	int size=0,i=0;
	fin>>size;											//read first number
	getline(fin,line);									//after getline we can start read second line
	while(fin>>data[i])									//put datas into array
    {
        i++;
    }
}


void fwrite(int A[],int size)
{
	int i=0;
	fout.open("HW2_E24046276.txt") ;					//open output file
	fout<<size;
	fout<<endl;
	for(i=0;i<size;i++)
	fout<<i+1<<" : "<<data[i]<<endl;					//output one data on each line
	fout.close();
}





