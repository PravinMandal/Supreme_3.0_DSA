#include<iostream>
using namespace std;

void RowAdditionOfElementsInArrays(int arr[][3] , int rowsize , int columnsize)
{
    for(int i=0 ; i<rowsize ; i++)
    {
        //har row ke liye starting mai sum 0 hai
        int sum=0;
        for(int j=0 ; j<columnsize ; j++)
        {
            sum=sum+arr[i][j];
        }
        cout<<sum<<endl;

    }
}

void ColAdditionofElementsInArrays(int arr[][3] , int rowsize , int columnsize)
{
    for(int col=0 ; col<columnsize ; col++)
    {
        //har column ke baad sum 0 hona chahiye 
        int sum=0;
        for(int row=0 ; row<rowsize ; row++)
        {
            sum=sum+arr[row][col];
        }
        cout<<sum<<endl;
    }
}

void printdiagonalSum(int arr[][3], int rowsize , int columnsize)
{
    int sum=0;
    for(int i=0 ; i<rowsize ; i++)
    {
        sum=sum+arr[i][i];
    }
     cout<<sum<<endl;

}
void printRightdiagonalsum(int arr[][3] , int rowsize , int columnsize)
{
    int sum=0;
    for(int i=0 ; i<rowsize ; i++)
    {
        for(int j=0 ; j<columnsize ; j++)
        {
            if(i+j==2)
            {
                sum=sum+arr[i][j];
            }
        }
    }
    cout<<sum<<endl;
}
void transposeMatrix(int arr[][3] , int rowsize , int columnsize)
{
    for(int i=0 ; i<rowsize ; i++)
    {
        for(int j=0 ; j<columnsize ; j++)
        {
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
}



int main()
{

    int arr[3][3]=
    {
        {10,11,12},
        {20,21,22},
        {30,31,32}
    };

    int rowsize = 3;
    int columnsize=3;

   RowAdditionOfElementsInArrays(arr, rowsize,columnsize);
   cout<<endl;
   ColAdditionofElementsInArrays(arr , rowsize, columnsize);
   cout<<endl;
   printdiagonalSum(arr,rowsize,columnsize);
   cout<<endl;
   printRightdiagonalsum(arr,rowsize,columnsize);
   cout<<endl;
   transposeMatrix(arr,rowsize,columnsize);


    return 0;
}