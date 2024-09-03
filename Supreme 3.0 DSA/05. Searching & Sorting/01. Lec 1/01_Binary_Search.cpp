#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n=7;
    int target=60;
    int start=0;
    int end=n-1;
    
    int arr[]={10,20,30,40,50,60,70};
    int mid=start + (end-start)/2; // ye aache bacche use krte h

    // mid=(start+end)/2;  ye wala nhi use krte h kyuki start and end mai ek integer store ho rha h 
    // and jab int_MAX se zyada exiced krega toh dikkat aa jayegi
    


    while( start<=end)
    {
        if(arr[mid]==target)
        {
            cout<<"Element found at index: "<<mid;
            break;
        }
        else if(arr[mid] < target)
        {
            //right mai jao
            start=mid+1;
        }
        else if (arr[mid] > target)
        {
            //left mai jao
            end=mid-1;
        }
        //ye mai bhul jaata hu
         mid=start + (end-start)/2;
    }
    return -1;
    cout<<endl;

    
    
    
    //binary search using STL
    bool ans= binary_search(arr, arr+n , target);
    cout<<ans<<endl;


    

    return 0;
}
