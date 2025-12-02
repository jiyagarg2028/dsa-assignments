#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int target) 
{
    int left=0,right=n-1;

    while(left<=right) 
	{
        int mid=left+right/2;  

        if(arr[mid]==target) 
		{
            return mid; 
        }
        else if(arr[mid]<target) 
		{
            left=mid+1;  
        }
        else 
		{
            right=mid-1; 
        }
    }
    return -1; 
}

int main() 
{
    int arr[]={2,4,7,10,14,18,21};
    int n =sizeof(arr)/sizeof(arr[0]);

    int target;
    cout<<"Enter element to search:";
    cin>>target;

    int result=binarySearch(arr, n, target);
    if(result!=-1)
        cout<<"Element found at index "<<result<<endl;
    else
        cout<<"Element not found."<<endl;
    return 0;
}
