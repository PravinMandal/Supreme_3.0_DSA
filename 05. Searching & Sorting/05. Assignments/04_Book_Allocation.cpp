//gfg: Allocate Minimum Number of Pages

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
  public:
    bool isPossibleSoln(vector<int>& arr, int k, int mid) {
        int pagesum = 0;
        int c = 1; // number of students
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > mid) {
                // ek bhi element agar isse zyada ho gya mtlb allocation nhi ho skta
                // atmost mid jitna sum hona chahiye 
                return false;
            }
            if(pagesum + arr[i] > mid) {
                c++;
                pagesum = arr[i];
                if(c > k) {
                    // number of students khatam ho gye but still books bacha h
                    return false;
                }
            }
            else {
                pagesum += arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int size = arr.size();
        if(k > size) return -1;
        int s = 0;
        int e = accumulate(arr.begin(), arr.end(), 0); // total sum of pages
        int ans = -1;

        while(s <= e) {
            int mid = s + ((e - s) >> 1);
            if(isPossibleSoln(arr, k, mid)) {
                ans = mid; // store and compute
                e = mid - 1;
            }
            else {
                // agar yahi possible solution nhi h toh isse chhote wale bhi nhi ho payenge
                // possible solution nhi h mtlb bacche kam padd gye
                // ab 1 bacche ko aur kam dunga toh last mai obsly books bach jayenge
                // kyuki abhi jo aaya usse hi nhi ho paaya 
                // atmost mid jitna sum hona chahiye 
                s = mid + 1;
            }
        }
        return ans;
    }
};

// Driver code
int main() {
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    Solution sol;
    int result = sol.findPages(books, students);

    cout << "Minimum number of pages: " << result << endl;

    return 0;
}
