#include<iostream>
using namespace std;
#include "BST.h"
int main()
{
	BST obj;
	int choice;
	do
	{
		cout<<"1- ......To Insert a number..... Press 1..."<<endl;
		cout<<"2- ......To Search a number..... Press 2..."<<endl;
		cout<<"3- ......To Remove a number ..... Press 3..."<<endl;
		cout<<"4- ......Display InOrder .....  Press 4..."<<endl;
		cout<<"5- ......Display preOrder ..... Press 5..."<<endl;
		cout<<"6- ......Display PostOrder ..... Press 6 ..."<<endl;
		cout<<"7- ...... To count total numbers Press 7...."<<endl;
		cout<<"8- ...... To double tree Press 8......."<<endl;
		cout<<"9- ....... to print all paths Press 9 ..... "<<endl;
		cout<<"10- ......To Quit ...... Press 0 ..."<<endl;
		cout <<"........... Enter your choice .......";
		cin>> choice;
		if(choice==1)
		{
			cout<<"Enter a number";
			int num;
			cin>>num;
			if (obj.insert(num))
			{
				cout<<"Number has been inserted sucessfully "<<endl;
			}
			else
			{
				cout<<"Sorry !!! Number cannot inserted as it is already exist in the list..."<<endl;
			}
		}
		else if(choice==2)
		{
			cout<<"Enter the number which you want to search";
			int num;
			cin>>num;
			if(obj.recSearch(num))
			{
				cout<<"Number has been found"<<endl;
			}
			else 
			{
				cout<<"Sorry !!! Number you are searching in the list is not exist inthe list ....."<<endl;

			}
		}
		else if(choice==3)
		{
			cout<<"Enter the number which you want to remove"<<endl;
			int num;
			cin>>num;
			if (obj.remove(num))
			{
				cout<<"Number has been removerd sucessfully"<<endl;
			}
			else
			{

				cout<<"Sorry !!! Number you want to remove does not exist in the list.... "<<endl;
			}
		}
		else if(choice==4)
		{
			cout<<"--------------- InOrder Representation is ---------------"<<endl;
			obj.inOrder();
		}
		else if(choice==5)
		{
			cout<<"--------------- PreOrder Representation is ---------------"<<endl;
			obj.preOrder();
		}
		else if(choice==6)
		{
			cout<<"--------------- PostOrder Representation is ---------------"<<endl;
			obj.postOrder();
		}
		else if(choice==7)
		{
			cout<<" Total number of integers is : "<<obj.countNodes()<<endl;
		}
		else if (choice==8)
		{
			cout<<".......... double tree output is ......... "<<endl;
			obj.doubleTree();
			obj.inOrder();
		}
		else if(choice==9)
		{
			cout<<"All Paths are ..... "<<endl;
			obj.printAllPaths();
		}
	}while( choice!=0);

}