#include<iostream>
using namespace std;

// void fancypyramid(int n)
// {
//     for(int row=0 ; row<n ; row++)
//     {
//         for(int col=0 ; col<row+1 ; col++)
//         {
//             cout<<row+1<<" ";
//             if(col==row)
//             {
//                 break;
//             }
//             cout<<"* ";
//         }
//         cout<<endl;

//     }
//     for(int row=0 ; row<n-1 ; row++)
//     {
//         for(int col=0 ; col<n-row-1 ; col++)
//         {
//             cout<<n-row-1<<" ";
//             if(col==n-row-2)
//             {
//                 break;
//             }
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
    

// }
void fancypyramid(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j < 2*i+1 ; j++)
        {
            if(j%2==0)
            cout<<i+1<<" ";
            else
            cout<<"* ";
        }
        cout<<endl;

    }
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<2*(n-i)-3 ; j++)
        {
            if(j%2==0)
            cout<<n-i-1<<" ";
            else
            cout<<"* ";
        }
        cout<<endl;

    }
}

int main()
{
    int n;
    cout<<"Enter size of Fancy 12 Pyramid :-";
    cin>>n;
    fancypyramid(n);


    return 0;
}