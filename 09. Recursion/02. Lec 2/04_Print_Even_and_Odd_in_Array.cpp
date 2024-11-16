#include<iostream>
using namespace std;

 void printAllOddinArray(int arr[],int size,int index){

    //base case
    if(index==size){
        return;
    }
    if(((arr[index])&1 ==1 )){//odd hoga toh hi enter krega
    //(n&&1==0) aaya toh wo n even hai
    //(n&&1==1) aaya toh wo n odd hai
    cout<<arr[index]<<" ";
    }

    printAllOddinArray(arr,size,index+1);

 }

 void printAlleveninArray(int arr[],int size, int index){

    if(index==size){
        return;
    }
    if((arr[index]&1) ==0){// for even 
        cout<<arr[index]<<" ";
    }

    printAlleveninArray(arr,size,index+1);

 }
 


int main(){

    int arr[]={10,11,23,33,45,63,18,17};
    int size=8;
    int index=0;

    printAllOddinArray(arr,size,index);
    cout<<endl;
    printAlleveninArray(arr,size,index);


    return 0;
}