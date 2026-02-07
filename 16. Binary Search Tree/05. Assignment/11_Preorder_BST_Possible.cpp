//gfg: Check if array can represent preorder traversal of BST

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    Node* ispossible(int arr[], int& i, int mini, int maxi, int& N) {
        if(i >= N) return NULL;

        Node* root = NULL;
        int curr = arr[i];

        // Check whether current value can be placed in the valid BST range
        if(curr > mini && curr < maxi) {
            root = new Node(curr);
            i++;

            // Left subtree must have values in (mini, curr)
            root->left = ispossible(arr, i, mini, curr, N);

            // Right subtree must have values in (curr, maxi)
            root->right = ispossible(arr, i, curr, maxi, N);
        }
        return root;
    }

    int canRepresentBST(int arr[], int N) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;

        // Try to construct BST from preorder array
        ispossible(arr, index, mini, maxi, N);

        // If all elements are consumed, preorder is valid
        return index >= N ? 1 : 0;
    }
};

// BST banane ki zaroorat nhi hai just mimic kro
class Solution2 {
  public:
    void ispossible(int arr[], int& i, int mini, int maxi, int& N) {
        if(i >= N) return;
        int curr = arr[i];
        if(curr>mini && curr<maxi) {
            i++;
            ispossible(arr, i, mini, curr, N);
            ispossible(arr, i, curr, maxi, N);
        }
        return;
    }
    int canRepresentBST(int arr[], int N) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;
        ispossible(arr, index, mini, maxi, N);
        return index>=N ? 1 : 0;
    }
};

int main() {
    Solution2 sol;

    // Hardcoded test case 1 (valid preorder of BST)
    int arr1[] = {40, 30, 35, 80, 100};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);

    cout << sol.canRepresentBST(arr1, N1) << endl;  // Expected: 1

    // Hardcoded test case 2 (invalid preorder of BST)
    int arr2[] = {40, 30, 35, 20, 80, 100};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << sol.canRepresentBST(arr2, N2) << endl;  // Expected: 0

    return 0;
}
