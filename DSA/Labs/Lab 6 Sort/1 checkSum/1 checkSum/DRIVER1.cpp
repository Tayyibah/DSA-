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
//	bool found=false;
//	if(start>end)
//	{
//		return false;
//	}
//	if(start==end)
//	{
//		return false;
//	}
//	if(arr[start]+arr[end]==k)
//	{
//		//LinearSearch(arr,start,end,k);
//		cout<<start;
//		cout<<end;
//		cout<<" ";
//		return true;
//	}
//	else 
//	{
//		int num=arr[start]-k;
//		LinearSearch(arr,start,end,num);
//		return checkSum(arr,start+1,end,k);
//	}
//	////bool found=false;
//	////if(start>end)
//	////{
//	////	return false;
//	////}
//	////if(start==end)
//	////{
//	////	return false;
//	////}
//	////if(arr[start]+arr[end]==k)
//	////{
//	////	//LinearSearch(arr,start,end,k);
//	////	cout<<start;
//	////	cout<<end;
//	////	cout<<" ";
//	////	return true;
//	////}
//	////else 
//	////{
//	////	int num=arr[start]-k;
//	////	LinearSearch(arr,start,end,num);
//	////	return checkSum(arr,start+1,end,k);
//	////}
//	//	/*else if(LinearSearch(arr,start,end,k)==true)
//	//		return checkSum(arr,start+1,end-1,k);
//	//	else if(LinearSearch(arr,start,end,k)==true)
//	//		return checkSum(arr,start,end-1,k);*/
//	////bool found=false;
//	////if(start>end)
//	////{
//	////	return false;
//	////}
//	////if(start==end)
//	////{
//	////	return false;
//	////}
//	////if(arr[start]+arr[end]==k)
//	////{
//	////	//LinearSearch(arr,start,end,k);
//	////	cout<<start;
//	////	cout<<end;
//	////	cout<<" ";
//	////	return true;
//	////}
//	////else 
//	////{
//	////	if( LinearSearch(arr,start,end,k)==true)
//	////		return checkSum(arr,start+1,end,k);
//	////	else if(LinearSearch(arr,start,end,k)==true)
//	////		return checkSum(arr,start+1,end-1,k);
//	////	else if(LinearSearch(arr,start,end,k)==true)
//	////		return checkSum(arr,start,end-1,k);
//	//bool found=false;
//	//if(start>end)
//	//{
//	//	return false;
//	//}
//	//if(start==end)
//	//{
//	//	return false;
//	//}
//	//if(arr[start]+arr[end]==k)
//	//{
//	//	found=true;
//	//	LinearSearch(arr,start,end,k);
//	//	cout<<start;
//	//	cout<<end;
//	//	cout<<" ";
//	//	return true;
//	//}
//	//else 
//	//{
//	//	int temp=checkSum(arr,start+1,end,k);
//	//	if(temp==1)
//	//		return true;
//	//	else
//	//		checkSum(arr,start+1,end,k);
//	//}
//		//*checkSum(arr,start+1,end-1,k);
//		//if( found==true)*/
//		//	return checkSum(arr,start+1,end-1,k);
//		///*if( found==true)
//		//	return checkSum(arr,start+1,end-1,k);
//		//else if( found==true)
//		//	return checkSum(arr,start+1,end-1,k);
//		//else if( found==true)
//		//	return checkSum(arr,start,end-1,k);*/
//	
//		
//	//else
//	//{
//	
//	//	// sum=0;
//	//	int num1=checkSum(arr,start+1,end,k);
//	//	int num2=checkSum(arr,start,end,k);
//	//	LinearSearch(arr,num1,num2,k);
//	//	int sum=num1+num2;
//	//	//cout<<LinearSearch(arr,0,5,7);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else/*
//	//		sum=sum+checkSum(arr,start,end-1,k);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else
//	//		sum=sum+checkSum(arr,start+1,end-1,k);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else*/
//	//		return false;
//	//}
//	//if(start+end==k)
//	//{
//	//	LinearSearch(arr,start+1,end,k);
//	//}
//	//else
//	//{
//	//	int sum=0;
//	//	sum=sum+checkSum(arr,start+1,end,k);
//	//	//cout<<LinearSearch(arr,0,5,7);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else
//	//		sum=sum+checkSum(arr,start,end-1,k);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else
//	//		sum=sum+checkSum(arr,start+1,end-1,k);
//	//	if (sum==k)
//	//	{
//	//		cout<<sum;
//	//		return true;
//	//	}
//	//	else
//	//		return false;
//	//}
//	//
////}
//
//int main()
//{
//	int k=1;
//	int arr[6]={5,6,1,0,1,2};
//	/*int SIZE,k;
//	cout<<"Enter the size of array: "; 
//	cin>>SIZE;
//	int arr[5];
//	cout<<"Enter the "<< SIZE<<" elements of the array: "; 
//	for(int i=0;i<SIZE;i++)
//	{
//		cin>>arr[i];
//	}	
//	char state='y';
//	while(state=='y')
//	{
//		if(state=='y')
//		{
//			cout<<"Enter k: "; 
//			cin>>k;*/
//			cout<<checkSum(arr,0,5,k);
//		/*	cout<<endl;
//			cout<<"Yes, "<< k << " can be obtained by adding two elements of the array. "<<endl;
//		}
//		else
//		{
//			cout<< " No, "<< k << " can NOT be obtained by adding two elements of the array. "<<endl;
//		}
//		cout<<"Continue (y/n)?";
//		cin>>state;
//	}*/
//	return 0;
//}