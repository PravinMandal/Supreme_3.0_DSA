//leetcode: 295. Find Median from Data Stream
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        //3 cases bann skte h
        //yaha hume insertion krna h heap mai
        // 1 by 1 elements aa rhe h , like a stream
        if(maxHeap.size() == minHeap.size()) {
            if(num > findMedian()) {
                //num bada h toh right mai daal deta hu
                minHeap.push(num);
            }
            else {
                //num chhota h
                maxHeap.push(num);
            }
        }
        else if(maxHeap.size() == minHeap.size() + 1) {
            //maxHeap bada h minHeap se by 1
            if(num > findMedian()) {
                //right mai daalna h
                minHeap.push(num);
            }
            else {
                //left mai daalna h but maxHeap pehle se bada h
                // maxHeap se ek element nikal ke minHeap mai pehle daalo then maxHeap mai num ko daalo
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);

                maxHeap.push(num);

            }
        }
        else if(maxHeap.size() + 1 == minHeap.size()) {
            //minHeap bada h maxHeap se by 1
            if(num > findMedian()) {
                //right mai daalna h
                //but minHeap toh pehle se bada h
                // minHeap se ek nikal ke maxHeap mai daalo then num ko minHeap mai daaldo
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);

                minHeap.push(num);
            }
            else {
                //left mai daala h 
                //maxHeap chhota h , daal do directly
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == 0 && minHeap.size() == 0) {
            return 0;
        }
        else if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        else if(maxHeap.size() == minHeap.size() + 1) {
            //maxHeap bada h
            return maxHeap.top();
        }
        else if(maxHeap.size() + 1 == minHeap.size()) {
            //minHeap bada h
            return minHeap.top();
        }
        else {
            return -1;
        }
    }
};

int main() {
    // Create an instance of MedianFinder and test with a stream of numbers.
    MedianFinder mf;
    
    mf.addNum(1);
    cout << "Median after adding 1: " << mf.findMedian() << endl;  // Expected: 1
    
    mf.addNum(2);
    cout << "Median after adding 2: " << mf.findMedian() << endl;  // Expected: 1.5
    
    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << endl;  // Expected: 2
    
    mf.addNum(4);
    cout << "Median after adding 4: " << mf.findMedian() << endl;  // Expected: 2.5
    
    mf.addNum(5);
    cout << "Median after adding 5: " << mf.findMedian() << endl;  // Expected: 3
    
    return 0;
}
