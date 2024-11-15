#include<iostream>
using namespace std;

void Merge(int arr[], int s, int e,int mid){

    //create left and right array
    int leftLen=mid-s+1;
    int rightLen=e-mid;

    int *leftArr=new int[leftLen];
    int *rightArr=new int[rightLen];

    //left array mai fill krdo 
    //copy original array values
    int index=s;

    for(int i=0; i<leftLen; i++){
        leftArr[i]=arr[index];
        index++;
    }

    //right array mai fill krdo
    index=mid+1; //ye nhi dalunga do bhi chalega but just for understandin....
    for(int i=0; i<rightLen; i++){
        rightArr[i]=arr[index];
        index++;
    }

    //merge logic
    int i=0; //left array ka pointer
    int j=0; //right array ka pointer
    int mainArrayIndex=s;

    while(i<leftLen && j<rightLen){
        if(leftArr[i]<rightArr[j]){
        arr[mainArrayIndex]=leftArr[i];
         i++;
         mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex]=rightArr[j];
            j++;
            mainArrayIndex++;
        }
    }

    //agar koi ek array durse se chhota ho toh ye krte h as discussed in previous question: merge 2 sorted array
    while(i<leftLen){
        arr[mainArrayIndex]=leftArr[i];
         i++;
         mainArrayIndex++;
    }

    while(j<rightLen){
        arr[mainArrayIndex]=rightArr[j];
            j++;
            mainArrayIndex++;
    }

    //delete heap memory
    delete[] leftArr;
    delete[] rightArr;
}

void MergeSort(int arr[], int s, int e){
    //Base case
    if(s>=e) return;

    int mid=s+(e-s)/2;

    //left wala part recursion se solve krwa lunga
    MergeSort(arr,s,mid);

    //right wala part bhi recursion se solve krwao
    MergeSort(arr,mid+1,e);

    //ab dono ko merge krdo
    Merge(arr,s,e,mid);
}


int main(){

    int arr[]={10,30,150,70,20,90,40,120,50,60};
    int size=10;
    int s=0;
    int e=size-1;


    cout<<"Before: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    MergeSort(arr,s,e);

    cout<<"After: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}