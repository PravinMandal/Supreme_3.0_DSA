#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int singleNumber(vector<int> nums){

    unordered_map<int,int>NumFreq; // <int,int> -> <key, freq>
    int n=nums.size();

    for(int i=0 ; i<n ; i++){
        int num=nums[i];

        NumFreq[num]= NumFreq[num]+1; // 'num' krke koi bhi key present nhi h map mai so starting mai wo zero return krega ki 0 hai
    }

    unordered_map<int,int>::iterator it;
    int ans=-1;

    for( it=NumFreq.begin() ; it!=NumFreq.end(); it++){

        int key=it->first;
        int freq=it->second;

        // cout<<"Key: "<<key<<"  "<<"freq: "<<freq<<endl;
        if(freq==1){
            ans= key;
            break;
        }
    }

    return ans;
}


int main(){

    vector<int>nums={1,2,3,1,2,3,4};

    int ans=singleNumber(nums);
    cout<<"Unique number is: "<<ans;

    return 0;
}