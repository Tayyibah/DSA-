#ifndef STUDENTMAXHEEP
#define STUDENTMAXHEEP
#include"StudentBST.h"/*
class StudentMaxHeap;
class Student {
	friend class StudentMaxHeap;
private:
	double cgpa;
	int rollNo; 
public:
	double getCgpa()
	{
		return cgpa;
	}
	int getRollNo()
	{
		return rollNo;
	}
};*/
class StudentMaxHeap {
private:
	StudentBST* st;   
	int currSize;   
	int maxSize;     
public:
	StudentMaxHeap(int size);
	~StudentMaxHeap();    
	bool isEmpty();      
	bool isFull(); 
	bool insert(int rollNo, double cgpa);
	void display();
	bool removeMax(StudentBST & max);
	void heepify(int i);
};

#endif