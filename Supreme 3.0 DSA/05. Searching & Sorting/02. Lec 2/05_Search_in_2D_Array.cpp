#include<iostream>
using namespace std;

int main()
{
    int target=11;
    int arr[3] [4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    int row=3;
    int col=4;

    //Total elements
    int n= row*col;

    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        int rowIndex= mid/col;
        int colIndex= mid%col;
        //Ye dono yaad krlo


        if(arr[rowIndex][colIndex]== target)
        {
            cout<<"Element Found"<<endl;
            break;
        }
        else if ( arr[rowIndex][colIndex] < target)
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }



    return 0;
}