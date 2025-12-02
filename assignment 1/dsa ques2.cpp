#include<iostream>
using namespace std ;
int a[] = {1,2,3,7,5};
int n = sizeof(a) / sizeof(a[0]);

int duplicate(int a[],int n)
{
for(int i=0;i<n;i++)
{
for(int j=i+1; j<n;j++)
{
   if(a[i]==a[j])
   return i;
}
}
}

int result = duplicate(a,n) ;

void Deletionduplicate () {

if(result>=0){


for(int i=result;i<n;i++)
{
    a[i]=a[i+1];
    
    }
    n--;
for(int i=0;i<n;i++)
{
    cout<<a[i]<<" ";   
}
 } else {cout<<"duplicate element not found "<<endl; 
    for(int i=0;i<n;i++){
    cout<<a[i]<<" "; }
    } }
int main () {
Deletionduplicate();
}
