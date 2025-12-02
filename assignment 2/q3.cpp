#include <iostream>
using namespace std;

int findMissingBinary(int arr[],int n) 
{
    int left=0,right=n-1;
    while(left<=right) 
	{
        int mid=(left+right)/2;
        if(arr[mid]!=mid+1) 
		{
            if(mid==0 ||arr[mid-1]==mid) 
            return mid+1;
            right=mid-1;
        } 
        else 
		{
            left=mid+1;
        }
    }
    return -1; 
}

int main() 
{
    int arr[]={1, 2, 3, 5, 6}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Missing number is"<<findMissingBinary(arr,n);
    return 0;
}
