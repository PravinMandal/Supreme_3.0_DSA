#include<iostream>
using namespace std;

void QuickSort(int arr[], int s , int e){
    //base case
    if(s>=e) return;

    int pivot=e;
    int i=s-1;
    int j=s;

    while(j<pivot){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    // i is the right position for the pivot element
    swap(arr[i], arr[pivot]);

    QuickSort(arr,s,i-1);
    QuickSort(arr,i+1,e);

}

int main(){

    int arr[]={2,1,8,7,9,3,6,4};
    int size=8;
    int start=0;
    int end=size-1;

    QuickSort(arr,start,end);

    for(int i=0; i<size ; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}