#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printDouble(int a)
{
    cout<<2*a<<" ";
}

bool checkEven(int a)
{
    return a%2==0;
}



int main()
{
    vector<int> arr(6);

    arr[0]=11;
    arr[1]=11;
    arr[2]=12;
    arr[3]=13;
    arr[4]=13;
    arr[5]=60;



    // for_each(arr.begin() , arr.end() , printDouble );



    ////find
    // int target=50;
    // auto it = find(arr.begin() , arr.end() , target);
    // //Hum auto use kr rhe h taaki wo khud hi find out krle ki konsa iterator h 
    // cout<<*it<<endl;



    ////find_if
    // auto it= find_if( arr.begin() , arr.end() , checkEven);
    // cout<<*it<<endl;



    ////count
    // int target = 11;
    // int ans= count(arr.begin(), arr.end() , target);
    // cout<<ans;



    ////count_if
    // int ans= count_if(arr.begin(), arr.end() , checkEven);
    // cout<<ans;



    ////sort and reverse
    // sort(arr.begin(), arr.end());
    // for(int a: arr)
    // {
    //     cout<< a <<" ";
    // }
    // cout<<endl;
    // reverse(arr.begin(), arr.end());
    // for( int a: arr)
    // {
    //     cout<< a <<" ";
    // }



    // //Rotate
    // cout<<"Before"<<endl;
    // for(int a:arr)
    // {
    //     cout<<a<<" ";
    // }
    // cout<<endl;

    // rotate(arr.begin(), arr.begin()+3 , arr.end());

    // cout<<"After"<<endl;
    // for(int a:arr)
    // {
    //     cout<<a<<" ";
    // }



    // //unique
    // auto it= unique(arr.begin() , arr.end());
    // //ye bhi iterator return krta h 
    // // it ke pehle sb unique element honge and 
    ////uske baad se lekr end tk saare duplicate elements honge
    // arr.erase(it,arr.end()); //saare duplicate elements delete ho gye
    // for(int a: arr)
    // {
    //     cout<<a<<" ";
    // }



    // //partition
    // auto it= partition(arr.begin() , arr.end() , checkEven);
    // // it ke piche partition kiya hua hoga as per the condition
    // // and it ke baad bacha hua
    // // in out case it ke pehle even numbers honge and baad mai odd
    // for(int a:arr)
    // {
    //     cout<<a<<" ";
    // }










    return 0;
}