#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> map;
            unordered_map<int,int> countelement;
            vector<int>ans;
    
            //map filling
            for(int index = 0; index < nums.size(); index++) {
                int value = nums[index];
                map[value] = index;
                countelement[value]++;
            }
    
            //main logic
            for(int i = 0; i<nums.size(); i++) {
                int currElement = nums[i];
                int currElementIndex = i;
                if(countelement[currElement] <= 1) {
                map.erase(currElement);
                }
                int elementTofind =(target - currElement);
    
                if(map.count(elementTofind) == 1) {
                    //required element mil gya
                    ans.push_back(currElementIndex);
                    ans.push_back(map[elementTofind]);
                    break;
                }
            }
            return ans;
        }
    };

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;

        for(int i = 0; i < nums.size(); i++) {
            int element = nums[i];
            int required = target - element;
            if(map.count(required) == 1) {
                //isse hum same element 2 baar nhi use kr skte kyuki wo element hume map mai milega hi nhi 
                //hum usse use kr rhe h toh abhi access kr rhe h but wo map mai nhi h
                //toh wo same required wale ke liye wo element nhi use hoga
                //and ye krne se agar same element 2 baar hoga alag alag index pr toh bhi manage ho jayega
                //kyuki dusre wale ke upr aayenge toh pehle wala hoga and durse wale ko abhi store nhi kiye h
                //still hum uske index ko access kr rhe h agar isko map mai abhi daal deta toh pehle wale ka index ghum jaata
                return {i, map[required]};
            }
            //baad mai hi insertion kr rha hu taaki erase krne ki zaroorat na pade jaise pehle wale method mai kiye the
            map[element] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution2 sol;
    // Example test case:
    // nums = [2, 7, 11, 15], target = 9
    // Expected output: [1, 0] or [0, 1] (depending on order, as indices of 2 and 7)
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    cout << "Indices: " << result[0] << " " << result[1] << endl;
    return 0;
}
