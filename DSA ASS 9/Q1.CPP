#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i,bool asc){
    int extreme=i;
    int l=2*i+1;
    int r=2*i+2;
    if(asc){
        if(l<n&&arr[l]>arr[extreme])
            extreme=l;
        if(r<n&&arr[r]>arr[extreme])
            extreme=r;
    }else{
        if(l<n&&arr[l]<arr[extreme])
            extreme=l;
        if(r<n&&arr[r]<arr[extreme])
            extreme=r;
    }
    if(extreme!=i){
        int t=arr[i];
        arr[i]=arr[extreme];
        arr[extreme]=t;
        heapify(arr,n,extreme,asc);
    }
}
void Heap(int arr[],int n,bool asc){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i,asc);
}
void heapsort(int arr[],int n,bool increasing){
    Heap(arr,n,increasing);        
    for(int i=n-1;i>0;i--){
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        heapify(arr,i,0,increasing);   
    }
}
void printArr(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int b[n];
    for(int i=0;i<n;i++)
        b[i]=arr[i];
    heapsort(arr,n,true);
    cout<<"Increasing order:";
    printArr(arr,n);
    heapsort(b,n,false);
    cout<<"Decreasing order:";
    printArr(b,n);
    return 0;
}