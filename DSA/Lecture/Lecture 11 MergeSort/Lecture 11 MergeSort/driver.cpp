#include<iostream>
using namespace std; 

void merge(int *a,int l1,int l2,int r1,int r2)
{
	int i=l1;
	int j=r1;
	int index=0;
	int *temp=new int(r2-l1+1);
	while(i<=l2 && j<=r2)
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
			index++;
		}
		else
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	while(i<=l2)
	{
		temp[index]=a[i];
		i++;
		index++;
	}
	while(j<=r2)
	{
		temp[index]=a[j];
		j++;
		index++;
	}
	int k=l1;
	index=0;
	while(k<=r2)
	{
		a[k]=temp[index];
		k++;
		index++;
	}
	k=0;
	index=0;
	delete[]temp;
	temp=0;
}
void mergeSort(int *a,int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);
		merge(a,start,mid,mid+1,end);
	}
}
int main()
{
	int a[10]={1,2,6,3,5,8,9,2,3,0};
	mergeSort(a,0,10);
	return 0;
}