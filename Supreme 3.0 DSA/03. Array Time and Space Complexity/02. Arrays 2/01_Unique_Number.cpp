#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int uniquenumber( int arr[] , int n)
{
    int ans=0;
    for(int i=0 ;i<n ; i++)
    {
         ans= ans^arr[i];
    }
    return ans;
}


//method 2

int uniquenumber2(vector<int>& brr){ //2,2,3,4,4

    sort(brr.begin() , brr.end());
    int n=brr.size();
    int ans=-1;
    int i=0;
    while(i<n){
        if(brr[i]==brr[i+1] && (i+1<n))
        {
            i=i+2;
        }
        else{
            ans=brr[i];
            return ans;
        }

    }
    return ans;
}

int main()
{
    int arr[]={2,2,3,4,4};
    int size=5;

    
    int ans= uniquenumber(arr , size);
    cout<<"Unique number is : "<<ans<<endl;


    //method 2
    vector<int>brr;

    brr.push_back(2);
    brr.push_back(2);
    brr.push_back(3);
    brr.push_back(4);
    brr.push_back(4);

    int ans2= uniquenumber2(brr);
    cout<<"Unique number is : "<<ans2<<endl;


    



    return 0;
}