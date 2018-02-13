#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include<iostream>
using namespace std;
#include <string>
class StudentBST;
class StudentNode 
{
friend class StudentBST;
private:
	int rollNo; // Student’s roll number (must be unique)
	string name; // Student’s name
	double cgpa; // Student’s CGPA
	StudentNode *left; // Pointer to the left subtree of a node
	StudentNode *right; // Pointer to the right subtree of a node
};
#endif

