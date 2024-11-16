#include<iostream>
#include<vector>
using namespace std;

void mergeSortedArray(int arr[],int sizeArr,int brr[], int sizeBrr, vector<int>&ans){
    int i=0; //i->arr
    int j=0; //j->brr

    while(i<sizeArr && j<sizeBrr){
        if(arr[i]<brr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(brr[j]);
            j++;
        }
    }

    //ab 2 cases ho skte h
    //case 1: arr mai still elements bache h
    while(i<sizeArr){
        ans.push_back(arr[i]);
        i++;
    }

    //case 2: brr mai still elements bache h
    while(j<sizeBrr){
        ans.push_back(brr[j]);
        j++;
    }

}

int main(){

    int arr[]={10,30,50,70};
    int sizeArr=4;

    int brr[]={20,40,60,80,90,100};
    int sizeBrr=6;

    vector<int>ans;

    mergeSortedArray(arr,sizeArr,brr,sizeBrr,ans);

    for(int num: ans){
        cout<<num<<" ";
    }

    return 0;
}