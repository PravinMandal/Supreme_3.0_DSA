//gfg: common is 3 sorted array
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find common elements in three arrays.
    void removeDuplicatesFromArray(vector<int>& arr) {
        vector<int> temp;
        for(int i = 0; i < arr.size(); i++) {
            if(temp.size() == 0) {
                temp.push_back(arr[i]);
            }
            else {
                if(temp.back() == arr[i]) {
                    continue;
                }
                else {
                    temp.push_back(arr[i]);
                }
            }
        }
        
        arr.clear();
        for(int i = 0; i < temp.size(); i++) {
            arr.push_back(temp[i]);
        }
    }
    
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        
        //ab array mai se duplicates delete kr deta hu
        //kyuki ans mai wo ek hi baar aana chahiye duplicate hoga toh multiple time wahi same ans aayega
        //set ka use nhi kr skta kyuki question mai mana kiya h
        removeDuplicatesFromArray(arr1);
        removeDuplicatesFromArray(arr2);
        removeDuplicatesFromArray(arr3);
        
        while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                ans.push_back(arr1[i]);
                i++;
                j++;
                k++;
            }
            else if (arr1[i] < arr2[j]) {
                i++;
            } 
            else if (arr2[j] < arr3[k]) {
                j++;
            } 
            else {
                k++;
            }
        }
        
        return ans;
        
    }
};

int main() {
    // Example Test Case:
    // arr1 = {1, 5, 5, 10, 20, 20, 40, 80}
    // arr2 = {6, 7, 20, 20, 80, 100}
    // arr3 = {3, 4, 15, 20, 20, 70, 80, 120}
    // Expected Output: {20, 80}
    vector<int> arr1 = {1, 5, 5, 10, 20, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 20, 70, 80, 120};
    
    Solution sol;
    vector<int> common = sol.commonElements(arr1, arr2, arr3);
    
    cout << "Common Elements: ";
    for(auto x : common) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
