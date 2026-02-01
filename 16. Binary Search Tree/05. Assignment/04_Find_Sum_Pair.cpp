// gfg: Count pairs from two BSTs whose sum is equal to X

#include <bits/stdc++.h>
using namespace std;

// Actual Node definition required for compilation
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void makemap(unordered_map<int, int> &mp, Node *root)
    {
        if (!root)
            return;

        // Store frequency of each node value
        mp[root->data]++;

        makemap(mp, root->left);
        makemap(mp, root->right);
    }

    int countPairs(Node *root1, Node *root2, int x)
    {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        int count = 0;

        // Store all values of both BSTs in maps
        makemap(mp1, root1);
        makemap(mp2, root2);

        // For each value in first tree, check if (x - value) exists in second tree
        for (auto i : mp1)
        {
            if (mp2.find(x - i.first) != mp2.end())
            {
                count++;
            }
        }

        return count;
    }
};

class Solution
{
public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        int ans = 0;

        // Two stacks for inorder traversal of root1 and reverse inorder traversal of root2
        stack<Node *> s1, s2;

        Node *a = root1;
        Node *b = root2;

        while (1)
        {

            // Push all left nodes of BST1 (inorder gives ascending order)
            while (a)
            {
                s1.push(a);
                a = a->left;
            }

            // Push all right nodes of BST2 (reverse inorder gives descending order)
            while (b)
            {
                s2.push(b);
                b = b->right;
            }

            // If any stack becomes empty, traversal is complete
            if (s1.empty() || s2.empty())
                break;

            Node *atop = s1.top();
            Node *btop = s2.top();

            // If sum matches target, count the pair
            if (atop->data + btop->data == x)
            {
                ans++;

                s1.pop();
                s2.pop();

                // Move forward in inorder and reverse inorder
                a = atop->right;
                b = btop->left;
            }

            // If sum is smaller, move inorder forward (increase sum)
            else if (atop->data + btop->data < x)
            {
                s1.pop();
                a = atop->right;
            }

            // If sum is larger, move reverse inorder forward (decrease sum)
            else
            {
                s2.pop();
                b = btop->left;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    // Hardcoded test case
    // Tree 1:        Tree 2:
    //     5              10
    //    / \            /  \
    //   3   7          6    15
    //
    // x = 13
    // Pairs: (3,10), (7,6)

    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);

    Node *root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);

    int x = 13;

    cout << "Count of pairs with sum " << x << " = "
         << sol.countPairs(root1, root2, x) << endl;

    return 0;
}
