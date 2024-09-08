// isme hume kya krna h ki hume pairs diye honge numbers ke usme se 1 number odd times hoga usse find krna h , isme koi bhi element but sath mai 2 baar se zyada nhi ho skta for eg:- 3,3,3 but 3,3,2,2,3,3 aise ho skta h

#include<iostream>
using namespace std;

int FindOddOccurenceElement(int arr[],int size)
{
    int s=0;
    int e=size-1;
    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(s==e)  //jab sirf 1 hi number bacha hoga
        {
            return s;
        }

        int currentValue=arr[mid];

        int leftValue=-1;
        if((mid-1)>=0)
        {
            leftValue=arr[mid-1];
        }

        int rightValue=-1;
        if(mid+1<size)
        {
            rightValue=arr[mid+1];
        }

        if( currentValue!=leftValue && currentValue!=rightValue) //main odd number pr hi mid aa gya toh uska case hai
        {
            return mid;
        }
        if(currentValue==rightValue )
        {
            int PairStartingIndex=mid;
            if(PairStartingIndex &1) // kisi bhi number ko 1 se & krenge toh agar 0 aaya toh wo number even and 1 aaya toh odd
            {
                //answer ke right side h because uss pair of number ke first element ka index odd aaya
                e=mid-1;
            }
            else
            {
                // even aaya mtlb answer ke left side h
                s=mid+1;
            }
        }
        if(currentValue==leftValue)
        {
            int PairStartingIndex= mid-1;
            if( PairStartingIndex &1) // kisi bhi number ko 1 se & krenge toh agar 0 aaya toh wo number even and 1 aaya toh odd
            {
                //answer ke right side h because uss pair of number ke first element ka index odd aaya
                e=mid-1;
            }
            else
            {
                // even aaya mtlb answer ke left side h
                s=mid+1;
            }
        }
        //ye mai humesha bhul jaata hu
        mid=s+(e-s)/2;

    }
}


int main()
{

    int arr[]={1,1,2,2,3,3,4,4,5,6,6};
    int size=11;

    int ans= FindOddOccurenceElement(arr,size);
    cout<<"Index of the ans: "<<ans<<endl;
    cout<<"Odd Occurence Number: "<<arr[ans]<<endl;
    


    return 0;
}