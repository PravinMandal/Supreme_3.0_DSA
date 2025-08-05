//leetcode: 1753. Maximum Score From Removing Stones

#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int score = 0;
        //work krne ke liye min 2 non empty piles toh hone chahiye
        while(maxHeap.size() > 1) {
            int pile1 = maxHeap.top(); maxHeap.pop();
            int pile2 = maxHeap.top(); maxHeap.pop();

            pile1--; pile2--;
            score++;

            //ab wapas push bhi krna pdega
            if(pile1 > 0) maxHeap.push(pile1);
            if(pile2 > 0) maxHeap.push(pile2);
        }
        return score;
    }
};

// Driver code
int main() {
    int a = 2, b = 4, c = 6;

    Solution sol;
    int result = sol.maximumScore(a, b, c);

    cout << "Maximum Score From Removing Stones: " << result << endl;

    return 0;
}
