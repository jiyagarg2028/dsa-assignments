#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the size of array(mxn):"<<endl;
    cin>>m>>n;
    int a[m][n];
       cout<<"Enter the elements of array :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int size=0;
    cout<<"The array is: "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            size++;
        }
    }
    int sparse[size][3],row=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                sparse[row][0]=i;
                sparse[row][1]=j;
                sparse[row][2]=a[i][j];
                row++;
            }
        }
    }
     cout<<"The Sparse Matrix is : "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<sparse[i][j]<<" ";
        }
        cout<<endl;
    }

   int trans[size][3], rowT=0;
    for(int col=0; col<n; col++)   
    {
        for(int i=0;i<row;i++)     
        {
            if(sparse[i][1]==col)  
            {
                trans[rowT][0]=sparse[i][1]; 
                trans[rowT][1]=sparse[i][0];
                trans[rowT][2]=sparse[i][2];
                rowT++;
            }
        }
    }


    cout<<"\nTranspose of Sparse Matrix is:"<<endl;
    for(int i=0;i<rowT;i++)
        cout<<trans[i][0]<<" "<<trans[i][1]<<" "<<trans[i][2]<<endl;

}
