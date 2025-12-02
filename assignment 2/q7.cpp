#include<iostream>
using namespace std;
int Inversions(int arr[],int n) 
{
    int count = 0;

    for(int i=0;i<n-1;i++) 
	{
        for(int j=i+1;j<n;j++) 
		{
            if(arr[i]>arr[j]) 
			{
                count++;
            }
        }
    }
    return count;
}
int main() 
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
	{
        cin>>arr[i];
    }
    int result=Inversions(arr,n);
    cout<<"Total Inversions ="<<result<<endl;
    return 0;
}
