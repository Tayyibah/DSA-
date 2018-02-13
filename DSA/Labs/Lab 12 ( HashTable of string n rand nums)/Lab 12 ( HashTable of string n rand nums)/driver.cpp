#include<iostream>
using namespace std;
#include<string>
#include <ctime>
#include"HashTable.h"

void initialize ()
{
	srand ( time(NULL) );
}
int getRandomNumber (int start, int end)
{
	return ( rand() % (end - start+1) ) + start;
}
int main()
{
	HashTable table(10);
	initialize ();
	int sum=0;
	for(int i=0;i<10;i++)
	{
		while(table.insert (getRandomNumber (0,100)))
		{
			if(!table.insert (getRandomNumber (0,100)))
				sum++;
		}
	}
	cout<<sum;

	cout<<table.insert ("asad")<<endl;
	cout<<table.insert ("Tayyibah")<<endl;
	cout<<table.insert ("Saira")<<endl;
	cout<<table.insert ("Shameen")<<endl;
	cout<<table.insert ("Amara")<<endl;
	/*cout<<table.search ("Amara")<<endl;
	cout<<table.remove ("Saira")<<endl;*/
	cout << "Removed";
	cout<<table.remove ("Shameen")<<endl;
	cout<<table.search ("Shameen")<<endl;
	table.display ();
	/*int choice;
	do
	{
		int size=0;
		string name;
		cout<<"Enter the size of Hash Table: "<<endl;
		cin>>size;
		HashTable table(size);
		cout<<"******************************************************"<<endl;
		cout<<"1. Insert a name"<<endl;
		cout<<"2. Search for a name"<<endl;
		cout<<"3. Remove a name (See Task # 3 below)"<<endl;
		cout<<"4. Display the Hash Table"<<endl;
		cout<<"5. Display Load Factor of the table"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"******************************************************"<<endl;
		cin>> choice;
		if(choice==1)
		{
			cout<<"Insert a name";
			cin>>name;
			cout << "Name = "<<name;
			if (table.insert(name))
			{
				cout<<"Name has been inserted sucessfully "<<endl;
			}
			else
			{
				cout<<"Sorry !!! Name cannot inserted as it is already exist in the list..."<<endl;
			}
		}
		else if(choice==2)
		{
			cout<<"Enter the Name which you want to search";
			int num;
			cin>>num;
			if(table.search(name) )
			{
				cout<<"Name has been found"<<endl;
			}
			else 
			{
				cout<<"Sorry !!! Name you are searching in the list is not exist inthe list ....."<<endl;

			}
		}
		else if(choice==3)
		{
			cout<<"Enter the Name which you want to remove"<<endl;
			int num;
			cin>>num;
			if (table.remove (name))
			{
				cout<<"Name has been removerd sucessfully"<<endl;
			}
			else
			{

				cout<<"Sorry !!! Name you want to remove does not exist in the list.... "<<endl;
			}
		}
		else if(choice==4)
		{
			table.display ();
		}
		else if(choice==5)
		{
			cout<<table.loadFactor ();
		}
	}while( choice!=6);*/
	return 0;
}
