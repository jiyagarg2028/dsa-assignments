#include<iostream>
using namespace std;
class MaxPQ{
    int arr[100];
    int n;

    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;
            if(arr[parent]<arr[i]){
                int temp=arr[parent];
                arr[parent]=arr[i];
                arr[i]=temp;
                i=parent;
            }else
                break;
        }
    }
    void heapifyDown(int i){
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int largest=i;
            if(left<n&&arr[left]>arr[largest])
                largest=left;
            if(right<n&&arr[right]>arr[largest])
                largest=right;
            if(largest==i)
                break;
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
            i=largest;
        }
    }
public:
    MaxPQ(){
        n=0;
    }
    void push(int x){
        arr[n]=x;
        n++;
        heapifyUp(n-1);
    }
    void pop(){
        if(n==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        arr[0]=arr[n-1];
        n--;
        heapifyDown(0);
    }
    int top(){
        if(n==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[0];
    }
    bool empty(){
        return n==0;
    }
    int size(){
        return n;
    }
};
class MinPQ{
    int arr[100];
    int n;
    void heapifyUp(int i){
        while(i>0){
            int parent=(i-1)/2;
            if(arr[parent]>arr[i]){
                int temp=arr[parent];
                arr[parent]=arr[i];
                arr[i]=temp;
                i=parent;
            }else
                break;
        }
    }
    void heapifyDown(int i){
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            int smallest=i;
            if(left<n&&arr[left]<arr[smallest])
                smallest=left;
            if(right<n&&arr[right]<arr[smallest])
                smallest=right;
            if(smallest==i)
                break;
            int temp=arr[i];
            arr[i]=arr[smallest];
            arr[smallest]=temp;
            i=smallest;
        }
    }
public:
    MinPQ(){
        n=0;
    }
    void push(int x){
        arr[n]=x;
        n++;
        heapifyUp(n-1);
    }
    void pop(){
        if(n==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        arr[0]=arr[n-1];
        n--;
        heapifyDown(0);
    }
    int top(){
        if(n==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[0];
    }
    bool empty(){
        return n==0;
    }
    int size(){
        return n;
    }
};
int main(){
    MaxPQ maxpq;
    MinPQ minpq;
    int a[]={5,1,9,3,7,2,8,6,4};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        maxpq.push(a[i]);
        minpq.push(a[i]);
    }
    cout<<"Max Priority Queue (Top to Bottom):"<<endl;
    while(!maxpq.empty()){
        cout<<maxpq.top()<<" ";
        maxpq.pop();
    }
    cout<<endl;
    cout<<"Min Priority Queue (Top to Bottom):"<<endl;
    while(!minpq.empty()){
        cout<<minpq.top()<<" ";
        minpq.pop();
    }
    cout<<endl;
    return 0;
}