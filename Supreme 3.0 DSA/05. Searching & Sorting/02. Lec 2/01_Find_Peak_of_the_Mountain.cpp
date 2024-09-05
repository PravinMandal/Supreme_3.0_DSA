//question mai array mai pehle numbers increase honge then decrease toh usse graph mai put krenge toh peak aayega usse find krna h
#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,30,90,70,60,35,30};
    //90 aana chahiye output mai because ye peak hai
    int n=8;
    int s=0;
    int e=n-1;
    int ansIndex=-1;

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if(arr[mid]<arr[mid+1])
        {
            //peak ke pehle h
            s=mid+1;
        }
        else
        {
            // ab mid peak ke baad bhi ho skta h and maybe peak(answer) ke upar hi khada ho
            ansIndex=mid;
            e=mid-1;
        }
        mid=s+(e-s)/2;
        
    }
    cout<<"Peak of the array mountain is: "<<arr[ansIndex]<<endl;



    return 0;
}