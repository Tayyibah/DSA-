#include<iostream>
using namespace std;
#include<iomanip>
#include<fstream>

const int NAME_LENGTH = 25;

struct BowlingFigures
{
	char name[NAME_LENGTH+1]; // Name of the bowler
	int wickets; // Wickets taken by the bowler
	int runs; // Runs conceded by the bowler
};
void displayBowlingFigures (BowlingFigures * bp, int count)
{
	cout<<"Following 5 Bowling figures were read from the input file: "<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<setw(15)<<bp[i].name<<"     "<<bp[i].wickets<<"-"<<bp[i].runs<<endl;
	}
}
BowlingFigures* readFromFile (char* fileName, int &count)
{
	ifstream myfile;
	int i=0; 
	myfile.open(fileName);
	if (myfile)
	{
		myfile>>count;
		myfile.ignore();
		BowlingFigures* newBp=new BowlingFigures[count];
		while(i<count)
		{
			myfile.getline(newBp[i].name,25);
			myfile>>newBp[i].wickets;
			myfile>>newBp[i].runs;
			myfile.ignore();
			i++;
		}
		myfile.close();
		return newBp;
	}
	else 
	{
		cout << "file not opened";
		return 0;
	}
}

void swap(int &arr1,int &arr2)
{
	int temp;
	temp=arr1;
	arr1=arr2;
	arr2=temp;
}

void sortBowlingFigures (BowlingFigures * bp, int count)
{
	for(int i=0;i<count-1;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			int min=i;
			if(bp[j].wickets<bp[min].wickets)
			{
				min=j;
			}
			swap(bp[j].wickets,bp[min].wickets);
			swap(bp[j].name,bp[min].name);
			swap(bp[j].runs,bp[min].runs);
		}
	}
}


void sortBowlingFiguresByInsertionSort (BowlingFigures * bp, int count)
{
	for(int i=1;i<count;i++)
	{
		BowlingFigures* b=bp;
		int w=bp[i].wickets;
		int j=i-1;
		while(j>=0&&w>bp[j].wickets)
		{
			b[j+1]=bp[j];
			j--;
		}
		bp=b;
	}
}
//or do it like this
//void sortBowlingFiguresByInsertionSort (BowlingFigures * bp, int count)
//{
//	for(int i=1;i<count;i++)
//	{
//		int w=bp[i].wickets;
//		char* n=bp[i].name;
//		int r=bp[i].runs;
//		int j=i-1;
//		while(j>=0&&w>bp[j].wickets)
//		{
//			bp[j+1].wickets=bp[j].wickets;
//			//bp[j+1].name=bp[j].name;
//			bp[j+1].runs=bp[j].runs;
//			j--;
//		}
//		bp[j+1].wickets=w;
//		//bp[j+1].name=n;
//		bp[j+1].runs=r;
//	}
//}

int main()
{
	BowlingFigures* bp;
	int count=0;
	bp= readFromFile ("file.txt", count);
	displayBowlingFigures (bp,  count);
	sortBowlingFigures (bp,  count);
	displayBowlingFigures (bp,  count);
	sortBowlingFiguresByInsertionSort(bp,  count);
	displayBowlingFigures (bp,  count);
	return 0;
}
