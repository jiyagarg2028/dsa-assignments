#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    string str="Hello";
    string str1="aksh";
    string str2="Goyal";
    
    // a. Concatenate
    string concat=str1+str2;
    cout<<"Concatenated string:"<<concat<<endl;

    // b. Reverse
    string rev=str;
    reverse(rev.begin(), rev.end());
    cout <<"Reversed string:"<<rev<<endl;

    // c. Delete all vowels 
    string result="";
    for (int i=0;i<str.length();i++) 
	{
        char c=str[i];
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) 
		{
            result+=c;
        }
    }
    cout<<"String without vowels:"<<result<<endl;

    // d. Sort multiple strings alphabetically
    string arr[3]={"Hello","aksh","Goyal"};
    int n=3;
    sort(arr,arr+n);
    cout <<"Sorted strings:";
    for(int i=0;i<n;i++) 
	cout<<arr[i]<<" ";
    cout<<endl;

    // e. Convert char from uppercase to lowercase
    char c='A';
    cout<<"Lowercase:"<<char(tolower(c))<<endl;

    return 0;
}
