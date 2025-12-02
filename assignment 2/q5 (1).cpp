#include<iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter size of matrix(n x n):";
    cin>>n;

    // Diagonal
    int diag[n];
    cout <<"\nEnter "<<n<<"diagonal elements:\n";
    for(int i=0;i<n;i++) 
    cin>>diag[i];

    cout<<"Diagonal Matrix:\n";
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            if(i==j) 
            cout<<diag[i]<<" ";
            else 
            cout<<"0";
        }
        cout<<endl;
    }

    // Tri-diagonal
   int size=3*n-2;
    int a[size];
    cout <<"Enter"<<size<<"elements(first lower,then main,then upper):\n";
    for(int i=0;i<size;i++)
    cin>>a[i];
    cout<<"Tri-diagonal Matrix is:\n";
    for(int i=1;i<=n;i++) 
	{
        for(int j=1;j<=n;j++) 
		{
            if(i-j==1)
            cout<<a[i-2]<<" ";            
            else if(i==j) 
            cout<<a[(n-1)+(i-1)]<<" "; 
            else if(i-j==-1) 
            cout<<a[(2*n-1)+(i-1)]<< " "; 
            else cout<<"0";
        }
        cout<<endl;
    }
    // Lower Triangular
    int sizeLower=(n*(n+1))/2;
    int lower[sizeLower];
    cout << "\nEnter "<<sizeLower<<"elements (row-wise lower triangle):\n";
    for(int i=0;i<sizeLower;i++) cin>>lower[i];

    int k=0;
    cout <<"Lower Triangular Matrix:\n";
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            if(i>=j) 
            cout<<lower[k++]<<" ";
            else cout<< "0";
        }
        cout<<endl;
    }

    //  Upper Triangular 
    int sizeUpper=(n*(n+1))/2;
    int upper[sizeUpper];
    cout<< "\nEnter "<< sizeUpper<<"elements(row-wise upper triangle):\n";
    for(int i=0;i<sizeUpper;i++) 
	cin>>upper[i];

    k=0;
    cout<<"Upper Triangular Matrix:\n";
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            if(i<=j) 
			cout<<upper[k++]<< " ";
            else cout<<"0";
        }
        cout<<endl;
    }

    //Symmetric 
    int sizeSym=(n*(n+1))/2;
    int sym[sizeSym];
    cout <<"\nEnter"<<sizeSym <<"elements(lower triangle only):\n";
    for(int i=0; i<sizeSym; i++) 
	cin>>sym[i];

    cout <<"Symmetric Matrix:\n";
    k=0;
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            if(i>=j) 
			{
                cout<<sym[k]<<" ";
                k++;
            } else 
			{
                int index=(j*(j+1))/2+i;
                cout<<sym[index]<< " ";
            }
        }
        cout<<endl;
    }

    return 0;
}
