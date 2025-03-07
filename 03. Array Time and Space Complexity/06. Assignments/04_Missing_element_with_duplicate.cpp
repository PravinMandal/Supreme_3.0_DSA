//missing element of an array with duplicate
#include<iostream>
#include<vector>
using namespace std;

void findMissingElement(vector<int>& arr) {
    //visited method
    int n = arr.size();
    for(int i=0; i<n; i++){
        int index = abs(arr[i]);

        if(arr[index-1] > 0) {
            //index -1 isiliye kr rhe h kyuki zero based indexing h
            //toh -1 krenge toh sahi jahar pr pohchenge kyuki isme hum 1 based index try kr rhe h
            arr[index-1] *= -1;
        }
    }

    for(int i=0; i<n; i++) {
        if(arr[i]>0) {
            cout<<"missing element is: "<<i+1<<endl;
        }
    }
}

int main() {

    vector<int>arr = {1,3,5,3,4};

    findMissingElement(arr);

    return 0;
}