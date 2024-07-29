#include<iostream>
using namespace std;

int ToPrintRightDiagonals(int arr[] [3] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(j==n-i-1)
            {
                cout<< arr[i][j];     
            }
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    int n=3;
    int arr [3] [3]={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    ToPrintRightDiagonals(arr,n);

    // for(int i=0 ; i<n ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //     {
    //         if(j==n-i-1)
    //         {
    //             cout<< arr[i][j];     
    //         }
    //     }
    //     cout<<endl;
    // }


    return 0;
}

