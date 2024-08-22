#include<iostream>
#include<vector>
using namespace std;

int main()
{

    vector<vector<int>>arr(5,vector<int>(4,-1));
    int totalrows = arr.size();
    int totalcols = arr[0].size();

    //2D array created
    //with 5 rows
    //with 4 columns
    //with initial value of each cell as "-1"


    //creating jaggered 2d vector
    //mtlb 2d vector jisme number of rows same rhe but number of elements har column mai different ho

    vector<vector<int>>brr(4);
    brr[0]= vector<int>(4);
    brr[1]= vector<int>(2);
    brr[2]= vector<int>(5);
    brr[3]= vector<int>(3);


    int totalrowcount = brr.size();
    cout<<totalrowcount<<endl;

    //ab saare coumns ke size alag alag h toh hume loop lagake har ek ka check krna pdega

    for(int i=0 ; i<4 ; i++)
    {
        cout<<brr[i].size()<<" ";
    }



    return 0;
}