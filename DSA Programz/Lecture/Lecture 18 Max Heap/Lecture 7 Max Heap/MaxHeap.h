#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap
{
private:

	int *arr; 
	int maxSize;
	int currSize;
public:
	void swap(int &a,int &b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	MaxHeap(int s)
	{
		arr=new int[s+1];
		maxSize=s;
		currSize=0;
	}
	bool isEmpty()
	{
		if(currSize==0)
			return true;
		return false;
	}
	bool isFull()
	{
		if(currSize==maxSize)
			return true;
		return false;
	}
	~MaxHeap ()
	{
		if(arr!=0)
		{
			delete[]arr;
			arr=0;
		}
		maxSize=0;
		currSize=0;
	}
	MaxHeap(const MaxHeap &orig)
	{
		if (orig.arr==0)
		{
			arr=0;
			maxSize=0;
		}
		maxSize=orig.maxSize;
		arr=new int [maxSize];
		arr=orig.arr;
		currSize=orig.currSize;
	}

	MaxHeap operator=(MaxHeap& val)
	{
		if (val.arr==0)
		{
			arr=0;
		}
		maxSize=val.maxSize;
		arr=new int [maxSize];
		arr=val.arr;
		currSize=val.currSize;
		return *this;
	}
	bool insert(int val)
	{
		if(isFull())
		{
			return false;
		}
		else
		{
			currSize++;
			int i=currSize;
			while(i>1&& val>arr[i/2])
			{
				arr[i]=arr[i/2];
				i=i/2;
			}
			arr[i]=val;
			return true;
		}
	}
	bool removeMax(int &max)
	{
		if(isEmpty())
			return false;
		else
		{
			max = arr[1];
			arr[1]=arr[currSize];
			currSize--;
			int i=1;
			int left,right,largest;
			while(i*2<=currSize)
			{
				left=i*2;
				right=i*2+1;
				largest=i;
				if(left<=currSize && arr[left]>arr[largest])
					largest=left;
				if(right<=currSize && arr[right]>arr[largest])
					largest=right;
				if(largest!=i)
				{
					swap(arr[i],arr[largest]);
					i=largest;
				}
				else
					return true;
			}
			return true;
		}
	}
	void heapify(int i)
	{
		int left,right,largest;
		while(i*2<=currSize)
		{
			left=i*2;
			right=i*2+1;
			largest=i;
			if(left<=currSize && arr[left]>arr[largest])
				largest=left;
			if(right<=currSize && arr[right]>arr[largest])
				largest=right;
			if(largest!=i)
			{
				swap(arr[i],arr[largest]);
				i=largest;
			}
			else
				break;
		}
	}
	void buildHeap(int *a,int n)
	{
		if(arr!=0)
		{
			delete[]arr;arr=0;
		}
		arr=new int[n+1];
		maxSize=n;
		for(int i=0;i<n;i++)
		{
			arr[i+1]=a[i];
		}
		currSize=n;
		for(int i=n/2;i>=1;i--)
		{
			heapify(i);
		}
	}
	void HeapSort(int *a,int n)
	{
		MaxHeap mH(n);
		mH.buildHeap(a,n);
		for(int i=n-1;i>=0;i--)
		{
			mH.removeMax(a[i]);
		}
	}
};
#endif

