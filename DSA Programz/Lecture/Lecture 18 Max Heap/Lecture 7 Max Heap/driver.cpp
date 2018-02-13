#include<iostream>
using namespace std;
#include"MaxHeap.h"

int main()
{
	MaxHeap heap(5);
	heap.isEmpty();
	heap.isFull();
	int val=0;
	heap.insert(1);
	heap.insert(2);
	heap.insert(3);
	heap.insert(4);
	heap.insert(5);
	heap.insert(6);
	heap.insert(7);
	heap.removeMax(val);
	heap.heapify(4);
	int arr[10]={1,2,3,4,5,6,7,8};
	heap.buildHeap(arr,4);
	heap.HeapSort(arr,4);
	return 0;
}