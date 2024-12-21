#include<iostream>
using namespace std;

int main(){

    //integer -> stack(small)
    //used to store local variables and fix size creation
    int a=5;
    cout<<a<<endl;

    //integer -> Heap(big)
    //used to store dynamic memory allocation
    int* p=new int;
    *p=5;
    cout<<*p<<endl;



    //array -> stack
    int arr[5]={0};
    cout<<arr[0]<<arr[1]<<arr[2]<<endl;

    //array -> Heap
    int* brr=new int[10]; //default 0 se inisialize rhta h. compiler dependet
    cout<<brr[0]<<brr[1]<<brr[2]<<endl;





    //2D array -> stack memory
    int crr[2][4]={
                    {1,2,3,4},
                    {5,6,7,8}
                  };


    //2D array -> Heap memory
    // 4 row count
    // 3 col count
    int** drr=new int*[4];
    for(int i=0 ; i<4 ; i++){
        //har pointer ke liye ek 1D array create krna h
        drr[i]=new int[3];
    }
    //taking input. jaise normal 2D array mai lete h waise hi lena h
    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<3 ;j++){
            cin>> drr[i][j];
        }
    }

    cout<<endl<<"Printing the 2D array"<<endl;
    //printing 
    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<3 ;j++){
            cout<<drr[i][j]<<" ";
        }
        cout<<endl;
    }
    //delete bhi krna pdega warna memory leak hone ki sambhawana badh jayegi
    for(int i=0 ; i<4 ; i++){
        delete[] drr[i];
    }
    delete[] drr;


    return 0;
}