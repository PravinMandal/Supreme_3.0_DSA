#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printvv(vector<vector<int>>&v)
{
    for(int i=0 ; i<v.size() ; i++)
    {
    vector<int>&temp =v[i];
    int a=temp[0];
    int b=temp[1];
    cout<<a<<" "<<b<<endl;
    }
}
bool mycomparatorsForIndex1(vector<int>&a , vector<int>&b)
{
    // return a[0] < b[0]; //ye ho jayega for 0 index sorting ke liye
    // return a[1] > b[1]; //ye ho jayega for 1 index sorting ke liye // decending order mai
    return a[1] < b[1]; //ye ho jayega for 1 index sorting ke liye // ascending order mai

}

int main()
{
    vector<vector<int>>v;
    int n;
    cout<<"Enter the size: \n";
    cin>>n;
    for(int i=0 ; i<n ; i++)
    {
        int a,b;
        cout<<"Enter a , b"<<endl;
        cin>>a>>b;
        vector<int>temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Here are the values without sorted"<<endl;
    printvv(v);
    cout<<"Here are the valuse after sorted"<<endl;
    sort(v.begin(),v.end() , mycomparatorsForIndex1);
    printvv(v);

    return 0;
}