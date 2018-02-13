#include<iostream>
using namespace std;
#include <string.h>
#include"StudentNode.h"
#include"StudentBST.h"

void displayMenu()
{
	cout<<"1. Insert a new student"<<endl;
	cout<<"2. Search for a student"<<endl;
	cout<<"3. See the list of all students"<<endl;
	cout<<"4. Quit"<<endl;
	cout<<"Enter your choice:";
}

int main()
{
	StudentBST tree;
	tree.insert(06,"Ammara Khalid",2.7);
	tree.insert(23,"Zarbab Mushtaq",2.9);
	tree.insert(43,"Shameen Arshad",3.3);
	tree.insert(15,"Zainab Tayyibah",2.4);
	tree.remove (11);
	tree.inOrder ();
	int choice=1;
	int rollNo; 
	string name;
	double cgpa;
	while(choice!=4)
	{
		displayMenu();
		cin>>choice;
		if(choice==1)
		{
			cout<<"Enter roll no. :";
			cin>>rollNo;
			name="Teeba";
			//cout<<"Enter name :";
			//cin.getline(name, 250);
			//getline(cin, name);
			cout<<"Enter cgpa :";
			cin>>cgpa;
			tree.insert(rollNo,"name",cgpa);
		}
		else if(choice==2)
		{
			cout<<"Enter roll no. :";
			cin>>rollNo;
			if(tree.search(rollNo)==1)
			{
				cout<<"The roll no. is in the tree "<<endl;
			}
			else
				cout<<"The roll no. is not present in the tree "<<endl;
		}
		else if(choice==3)
		{
			cout<<"The students in the tree are :";
			tree.inOrder ();
		}
		else if(choice!=4)
			cout<<"Invalid choice "<<endl;
	}
	return 0;
}