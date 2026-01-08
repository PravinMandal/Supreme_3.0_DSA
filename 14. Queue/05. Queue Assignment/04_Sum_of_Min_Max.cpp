#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays of size k
int SumOfKsubArray(vector<int> nums, int k) {
    deque<int> maxi, mini;
    int sum = 0;
    
    for(int i=0; i<k; i++) {
        int curr = nums[i];
        while(!maxi.empty() && nums[maxi.back()] < curr) {
            maxi.pop_back();
        }
        maxi.push_back(i);
        while(!mini.empty() && nums[mini.back()] > curr) {
            mini.pop_back();
        }
        mini.push_back(i);
    }
    sum += nums[maxi.front()] + nums[mini.front()];

    for(int i=k; i<nums.size(); i++) {
        while(!maxi.empty() && maxi.front() < i-k+1) {
            maxi.pop_front();
        }
        while(!mini.empty() && mini.front() < i-k+1) {
            mini.pop_front();
        }

        int curr = nums[i];
        while(!maxi.empty() && nums[maxi.back()] < curr) {
            maxi.pop_back();
        }
        maxi.push_back(i);
        while(!mini.empty() && nums[mini.back()] > curr) {
            mini.pop_back();
        }
        mini.push_back(i);

        sum += nums[maxi.front()] + nums[mini.front()];;
    }
    return sum;
}


int main() {
    vector<int> nums = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    int ans = SumOfKsubArray(nums, k);
    cout<<ans<<endl;
}
