//ye search space pattern pr based hai


#include<iostream>
using namespace std;

int main()
{

    int num= 52; //iska sqrt nikalna hai , filhal nearest one

    int s=0;
    int e=num; // search space pattern ki wajah se end point num liye hai
    // e=(num/2) bhi le skte h kyuki sqrt krenge toh wo half se kam hi hota h humesha
    int mid=s+(e-s)/2;
    int ans=-1;
    
    

    while(s<=e)
    {
        int product=mid*mid;
        
        if(product == num)
        {
            cout<<"sqrt of the number is: "<<mid<<endl;
        }
        else if( product < num)
        {
            //store and compute
            ans=mid;
            s=mid+1;
        }
        else
        {
           
            e=mid-1;
        }
        mid=s+(e-s)/2;

    }

    cout<<"sqrt of the number is: "<<ans<<endl;



    return 0;
}