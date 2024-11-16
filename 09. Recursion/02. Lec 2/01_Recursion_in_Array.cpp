#include<iostream>
using namespace std;

void PrintArray(int arr[] , int size , int index){

    //Base case
    if(index==size){
        //array se bahar aa gye ho 
        return;
    }

    //processing
    //1 case mai krunga 
    cout<<arr[index]<<" ";

    //recursive call
    //baaki recursion samhal lega
    PrintArray(arr, size , index+1);

}


int main(){

    int arr[]={10,20,30,40,50,60};
    int size=6;
    int index=0;

    PrintArray(arr,size,index);




    return 0;
}