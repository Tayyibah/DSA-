#include<iostream>
#include"TwoDMatrix.h"
using namespace std;
TwoDMatrix::TwoDMatrix()
{
	rows=0;
	columns=0;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			matrix[i][j]=0;
		}
	}
}		
TwoDMatrix::TwoDMatrix(int row,int col)
{
	rows=row;
	columns=col;
	matrix=new int *[rows];
	for(int i=0;i<rows;i++)
	{
		matrix[i]=0;
	}
	for(int j=0;j<rows;j++)
	{
		matrix[j]=new int[j];
	}
}
TwoDMatrix::~TwoDMatrix()
{
	if(!matrix)
		return;
	else
	{
		for(int i=0;i<rows;i++)
		{
			delete[] matrix[i];
			matrix[i]=0;
		}
	}
	delete[]matrix;
	matrix=0;
	rows=0;
	columns=0;
}
bool TwoDMatrix::get(int i, int j, int& val)
{
	if(i<0&&i>rows || j<0&&j>columns)
		return false;
	else
	{
		val=matrix[i][j];
		return true;
	}
}
bool TwoDMatrix::set(int i, int j, int val)
{
	if(i<0&&i>rows || j<0&&j>columns)
		return false;
	else
	{
		matrix[i][j]=val;
		return true;
	}
}
void TwoDMatrix::display()
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
void TwoDMatrix::transpose()
{
	int ** newMatrix=new int*[rows];
	for(int i=0;i<rows-1;i++)
	{
		for(int j=i+1;j<columns;j++)
		{
			newMatrix[i][j]=matrix[i][j];
			matrix[i][j]=matrix[j][i];
			matrix[j][i]=newMatrix[i][j];
		}
	}
}
void TwoDMatrix::add (const TwoDMatrix& first, const TwoDMatrix& second)
{
	if(first.rows!=second.rows && first.columns!=second.columns)
		exit(0);
	else
	{
		int ** newMatrix=new int*[rows];
		for(int j=0;j<rows;j++)
		{
			newMatrix[j]=new int[j];
		}	
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				newMatrix[i][j]=matrix[i][j];
				matrix[i][j]=matrix[j][i];
				matrix[j][i]=newMatrix[i][j];
				//newMatrix[i][j]=first[i][j]+second[i][j];
			}
		}
	}
}
void TwoDMatrix::displaySubMatrix (int r1, int r2, int c1, int c2)
{
	if(r1<0&&r2>0 &&c1<columns &&c2>columns)
		exit(0);
	for(int i=r1;i<r2;i++)
	{
		for(int j=c1;j<c2;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
TwoDMatrix::TwoDMatrix(TwoDMatrix&ref)
{
	rows=ref.rows;
	columns=ref.columns;
	matrix=ref.matrix;
}
TwoDMatrix TwoDMatrix::operator=(TwoDMatrix &ref)
{
	if(!ref.matrix)
	{
		rows=0;
		columns=0;
		matrix=0;
		return *this;
	}
	else
	{
		rows=ref.rows;
		columns=ref.columns;
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				matrix[i][j]=ref.matrix[i][j];
			}
		}
		return *this;	
	}
}
void TwoDMatrix::multiply (const TwoDMatrix& first, const TwoDMatrix& second)
{
	if(first.rows!=second.columns && first.columns!=second.rows)
		exit(0);
	else
	{
		int ** newMatrix=new int*[rows];
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<columns;j++)
			{
				newMatrix[i][j]=0;
				for(int k=0;k<columns;k++)
				{
					//newMatrix[i][j]+=first[i][k]*second[k][j];
				}
			}
		}
	}
}
TwoDMatrix TwoDMatrix::operator[](const int m1)
{
	if(m1<0&&m1>columns)
		return *this;
}