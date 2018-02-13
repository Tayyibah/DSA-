#include <iostream>
#include <cmath>
#include "fULL_B_TREE.h"
using namespace std;

FullBinaryTree::FullBinaryTree(int n)
{
	int x =ceil(log2(n))+1;
	int i = x;
	sortSize = n;
	treeSize = 2;
	while (i>1)
	{
		treeSize = treeSize * 2;
		i--;
	}
	tree = new int[treeSize];
	sorted = new int[sortSize];
}
void FullBinaryTree::loadValues(int * arr, int n)
{
	E = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i]>E)
			E = arr[i];
	}
	E += 1;
	int leaf = treeSize / 2;
	int i = 0;
	while (i<n)
	{
		tree[leaf++] = arr[i++];

	}
	while (leaf<treeSize)
	{
		tree[leaf++] = E;
	}
}

void FullBinaryTree::sortValues()
{
	int i = treeSize - 1;
	int j = 0;
	while (j<sortSize)
	{
		while (i>1)
		{
			if (tree[i]>tree[i - 1])
				tree[i/2] = tree[i - 1];
			else
				tree[i/2] = tree[i];
			i -= 2;
		}
		sorted[j] = tree[1];

		i = 1;
		while (i<treeSize)
		{
			if (tree[i] == sorted[j])
				tree[i] = E;
			i++;
		}
		i -= 1;
		j++;
	}
}
void  FullBinaryTree::display()
{
	for (int i = 0; i < sortSize; i++)
	{
		cout << sorted[i] << " ";
	}
	cout << endl;
}