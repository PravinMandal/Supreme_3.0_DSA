#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,3,4,5,6,7,8,9};

    int n=8;
    int s=0;
    int e=n-1;
    int ansIndex=-1;

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        int index=mid;
        int Number=arr[mid];
        int diff= Number-index;
        if(diff ==0)
        {
            // 0 aaya iska mtlb ki koi value gayab nhi h waha tk uske aage ho skta h
            //move right
            s=mid+1;
        }
        else if(diff ==1)
        {
            //ans ho bhi sakta h nhi bhi ho skta kyuki uske pehle ka bhi ho skta h
            //store and compute
            ansIndex=index;
            //move left
            e=mid-1;
        }
       
        //ye mai bhool jaata hu
        mid=s+(e-s)/2;
    }

     if(ansIndex==-1)
        {
            //ye wala condition sirf extreme case ke liye h jab ekdum last wala element gayab ho
            ansIndex=n;
        }

    cout<<"Missing numbers is: "<<ansIndex<<endl;



    return 0;
}