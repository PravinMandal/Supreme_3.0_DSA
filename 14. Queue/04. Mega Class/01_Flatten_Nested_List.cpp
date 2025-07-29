// leetcode: 341. Flatten Nested List Iterator
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Mock version of NestedInteger for testing
class NestedInteger {
    bool isInt;
    int value;
    vector<NestedInteger> list;

public:
    // Constructor for integer
    NestedInteger(int val) : isInt(true), value(val) {}

    // Constructor for list
    NestedInteger(vector<NestedInteger> nestedList) : isInt(false), list(nestedList) {}

    // Return true if this NestedInteger holds a single integer
    bool isInteger() const {
        return isInt;
    }

    // Return the single integer that this NestedInteger holds
    int getInteger() const {
        return value;
    }

    // Return the nested list
    const vector<NestedInteger> &getList() const {
        return list;
    }
};

// NestedIterator class implementation
class NestedIterator {
    queue<int> flattenQ;

    void flatten(const vector<NestedInteger> &nestedList) {
        for (const auto &item : nestedList) {
            if (item.isInteger()) {
                // item ek instance hai NestedInteger class ka
                flattenQ.push(item.getInteger());
            } else {
                flatten(item.getList());
            }
        }
    }

public:
    // Initializes the iterator with the nested list nestedList
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    // Returns the next integer in the nested list
    int next() {
        int front = flattenQ.front();
        flattenQ.pop();
        return front;
    }

    // Returns true if there are still some integers in the nested list
    bool hasNext() {
        return !flattenQ.empty();
    }
};

// Main function to test the NestedIterator
int main() {
    // Creating a nested list: [1,[4,[6]]]
    NestedInteger n6(6);
    NestedInteger n4_list({n6});
    NestedInteger n4(4);
    NestedInteger nestedList1({n4, n4_list});
    NestedInteger n1(1);
    vector<NestedInteger> input = {n1, nestedList1};

    // Initialize iterator
    NestedIterator i(input);
    vector<int> res;

    // Flatten the nested list
    while (i.hasNext()) {
        res.push_back(i.next());
    }

    // Output result
    cout << "Flattened list: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
