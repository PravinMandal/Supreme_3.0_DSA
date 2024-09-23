#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &v)
{
    int n=v.size();
    for(int i=0 ; i<n-1 ; i++)
    {
        int minindex=i; //filhal ith element hi min value carry krta h aisa maan lo
        for(int j=i+1 ; j<n ; j++)
        {
            if(v[j]<v[minindex])
            {
                minindex=j;
            }
        }
        swap(v[i], v[minindex]);
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
    SelectionSort(v);
    Print(v);



    return 0;
}
