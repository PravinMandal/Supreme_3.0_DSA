#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ShiftAnArray(int arr[] , int size , int n)
{
     n=n%size;
    if(n==0)
    {
        //no need to do anything
        return ; 
    }

    //temp variable create kr rhe h jidr store krenge erase hone wale numbers ko

    int index=0;
    int temp[10000];
    for(int i=size-n ; i<size ; i++)
    {
        temp[index]= arr[i];
        index++;
    }
    //idhr hum shift kr rhe h array ko
    for(int i=size-1 ; i>=0 ; i--)
    {
        arr[i]=arr[i-n];
    }
    //yaha pr erase hue number ko temp variable se fetch krke wapas add kr rhe h array mai
    for(int i=0 ; i<n ; i++)
    {
        arr[i]=temp[i];
    }
    
}

void reverseAnArray(vector<int>& brr , int l , int h ) {// l -> low , h-> high;

    while(l<h){
        swap(brr[l] , brr[h]);
        l++;
        h--;
    }

}

int main()
{

    int arr[]={10,20,30,40,50,60};
    int size =6;

    //number of shift --> n
    int n=3;

    cout<<"Before"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    ShiftAnArray(arr,size,n);

    cout<<"After"<<endl;
    for(int i=0 ; i<size ; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;



    //method 2

    vector<int> brr;
    brr.push_back(10);
    brr.push_back(20);
    brr.push_back(30);
    brr.push_back(40);
    brr.push_back(50);
    brr.push_back(60);

    int k=3;
    // int b=brr.begin();  // ye kaam nhi krega kyuki begin() aur end() ek iterator return kr rha h usse int mai store nhi kr skte
    // int e=brr.end();    // aur iterator h toh fucntion mai bhi pass nhi kr paa rha hu kyuki function int expect kr rha h

    //10,20,30,40,50,60

    //pura reverse krdo -> 60,50,40,30,20,10
    reverseAnArray(brr , 0 , brr.size()-1);

    // k baar rotate krna h toh first k ko reverse krdo (for ex. k=3)
    // 40,50,60,30,20,10
    reverseAnArray(brr , 0 , k-1);

    //ab brr+k se last tk reverse krdo
    // 40,50,60,10,20,30 ( ho gya rotate k=3 ka)
    reverseAnArray(brr , k , brr.size()-1);

    for(int i=0 ; i<brr.size() ; i++)
    {
        cout<<brr[i]<<" ";
    }




    return 0; 
}