//2D Matrix ko rotate krne ke liye pehle transpose krenge phir saare rows ko reverse kr denge toh wo rotate ho jaata h

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotateAnMatrix(vector<vector<int>>& matrix ,int nrows ,int ncols){

    //first hume transpose krna pdega
    for(int i=0 ; i<nrows ; i++){
        for(int j=i ; j<ncols ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }

    //ab hume saare row ko reverse krna pdega fir at last 90 degree rotate ho jayega
    //rowwise reverse krna h

    for(int i=0 ; i<nrows ; i++){
        reverse(matrix[i].begin() , matrix[i].end());
    }


}

int main(){

    vector<vector<int>>matrix =
    {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    };
    int nrows=matrix.size();
    int ncols=matrix[0].size();

    cout<<"Before Rotation"<<endl;
    for(int i=0 ; i<nrows ; i++){
        for(int j=0 ; j<ncols ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    rotateAnMatrix(matrix ,nrows ,ncols);

    cout<<"After Rotation"<<endl;
    for(int i=0 ; i<nrows ; i++){
        for(int j=0 ; j<ncols ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}