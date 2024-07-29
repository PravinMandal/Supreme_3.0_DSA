#include<iostream>
using namespace std;

bool find2Darray(int arr[][4] , int n , int m , int target)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(arr[i][j]==target)
            {
                return true;
            }
        }
    }
    // agar yaha tak pohoch gya h mtlb target kahin nhi mila

    return false;
}


int main()
{
    int arr[3][4]=
    {
        {10,11,12,13},
        {20,21,22,23},
        {30,31,41,55}
    };

    int rowsize = 3;
    int columnsize=4;
    int target=55;

    bool ans=find2Darray(arr,rowsize,columnsize,target);
    cout<<"Ans is: "<<ans;

    return 0;
}