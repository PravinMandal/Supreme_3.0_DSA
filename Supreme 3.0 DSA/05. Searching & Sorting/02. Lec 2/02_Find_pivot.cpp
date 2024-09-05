//isme pivot nikalna h mtlb ki monotonic function(ascending or descending) achanak se change ho jaye 
// for example sorted array ko rotate kr diye

#include<iostream>
using namespace std;

int main()
{

    int arr[]={60,70,80,90,100,10,20,30,40,50};
    //pivot 90 hai iss case mai
    int n=9;
    int s=0;
    int e=n-1;
    int ansIndex=-1;

    int mid=s+(e-s)/2;

    while(s<=e)
    {
        if( mid+1<n ,arr[mid]>arr[mid+1])
        {
            ansIndex=mid;
        }
    
        if(arr[mid] < arr[s])
        {
            //mtlb wo pivot ke aage hai
            //mtlb piche jaana h
            e=mid-1;
        }
        else
        {
            //store aur compute kar sakte hai taaki answer lost na ho jaaye
            //abhi wo pivot ke left mai hai warna pivot ke upar bhi ho sakta h toh store and compute kro and aage badho
            s=mid+1;

        }
        //ye mai bhul jaata hu
        mid=s+(e-s)/2;
    }
    cout<<"Pivot in the array is: "<<arr[ansIndex];

    return 0;
}