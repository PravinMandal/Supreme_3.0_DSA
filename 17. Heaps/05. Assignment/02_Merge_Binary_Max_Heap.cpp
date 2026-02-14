//gfg: Merge two binary Max heaps

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void heapify(vector<int>& c, int i, int n) {
        while(true) {
            int left = 2*i+1;
            int right = 2*i+2;
            int swapindex = i;
            if(left < n && c[left] > c[i]) {
                swapindex = left;
            }
            if(right < n && c[right] > c[swapindex]) {
                swapindex = right;
            }
            if(swapindex == i) {
                break;
            }
            swap(c[i], c[swapindex]);
            i = swapindex;
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());

        // Build max heap from the combined array
        for(int i = (c.size()/2) - 1; i >= 0; i--) {
            // c.size()/2 and uske aage ke saare leaf node rhenge
            // leaf node ko heapify krne ki koi zarurat nhi hai
            // isiliye c.size()/2 - 1 se start kr rhe hai 
            // kyuki ye first aisa node hoga jo leaf node nhi hoga(0 order indexing based)
            heapify(c, i, c.size());
        }
        return c;
    }
};

int main() {
    Solution sol;

    // Hardcoded test case
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    int n = a.size();
    int m = b.size();

    vector<int> result = sol.mergeHeaps(a, b, n, m);

    // Print merged max heap
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
