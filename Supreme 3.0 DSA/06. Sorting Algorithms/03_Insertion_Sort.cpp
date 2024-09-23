#include<iostream>
#include<vector>
using namespace std;

void InsertionSort( vector<int> &v )
{
    int n=v.size();

    for(int i=1 ; i<n ; i++)
    {
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;

    }

    
}

void Print(vector<int> &v)
{
    int n=v.size();
    for(int i=0 ; i<n ; i++ )
    {
        cout<<v[i]<<" ";
    }
}


int main()
{
    vector<int> v={5,4,3,2,1,0};
    InsertionSort(v);
    Print(v);



    return 0;
}
