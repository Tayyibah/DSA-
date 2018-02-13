//#include<iostream>
//using namespace std;
//#include<iostream>
//using namespace std;
//bool LinearSearch(int * a,int start,int end,int key)
//{
//	if(start>end)
//	{
//		return false;
//	}
//
//	if(a[start]==key)
//	{
//		//cout<<start;
//		return true;
//	}
//	else
//		return LinearSearch(a,start+1,end,key);
//}
//bool checkSum (int* arr, int start, int end, int k)
//{
//	if(start==end)
//	{
//		return false;
//	}
//	if(arr[start]+arr[end]==k)
//	{
//		LinearSearch(arr,start,end,k);
//		cout<<start;
//		cout<<end;
//		cout<<" ";
//		return true;
//	}
//	else 
//	{
//		int num1=arr[start];
//		int num2=num1-k;
//		if(LinearSearch(arr,start+1,end,num2)==true)
//			return true;
//		else
//			checkSum(arr,start+1,end,k);
//	}
//}
//int main()
//{
//	int k=-6;
//	int arr[6]={5,6,1,0,1,2};
//	/*int SIZE,k=1;
//	cout<<"Enter the size of array: "; 
//	cin>>SIZE;
//	int arr[5];
//	cout<<"Enter the "<< SIZE<<" elements of the array: "; 
//	for(int i=0;i<SIZE;i++)
//	{
//		cin>>arr[i];
//	}	
//	char state='y';
//	char choice=*/cout<<checkSum(arr,0,5,k);
//	/*while(state=='y')
//	{
//		if(choice==true)
//		{
//			cout<<"Enter k: "; 
//			cin>>k;
//			cout<<endl;
//			cout<<"Yes, "<< k << " can be obtained by adding two elements of the array. "<<endl;
//		}
//		else
//		{
//			cout<< " No, "<< k << " can NOT be obtained by adding two elements of the array. "<<endl;
//		}
//		cout<<"Continue (y/n)?";
//		cin>>state;
//		choice=checkSum(arr,0,5,k);
//	}*/
//	return 0;
//}