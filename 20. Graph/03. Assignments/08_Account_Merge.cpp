//leetcode: 721. Accounts Merge

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Find Ultimate Parent with Path Compression
    int findParent(vector<int>& parent, int node) {

        // Root node found
        if(parent[node] == node)
            return node;

        // Path Compression:
        // Make every node directly point to its ultimate parent.
        return parent[node] = findParent(parent, parent[node]); // path compression
    }

    // Union by Rank
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

        // Find ultimate parents first, VERY IMPORTANT, iske wajah se hi
        /*
            ["John", "a", "b"]
            ["John", "c", "d"]
            ["John", "b", "c"]
        */ 
       // iske wajah se ye upar wala test case chal paa rha hai warna nhi chalta
       // BOHOT IMPORTANT TEST CASE HAI YE WALA
        u = findParent(parent, u);
        v = findParent(parent, v);

        /*
            Merge the smaller ranked tree
            under the larger ranked tree.
        */
        if(rank[u] < rank[v]) {

            rank[v]++;
            parent[u] = v;

        } else {

            rank[u]++;
            parent[v] = u;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        // DSU initialization
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        /*
            Maps every email to the account index
            where it was first seen.
        */
        unordered_map<string, int> mp;

        /*
            If an email already exists,
            both accounts belong to the same person,
            so merge them using DSU.
        */
        for(int i = 0; i < n; i++) {

            auto account = accounts[i];

            for(int j = 1; j < account.size(); j++) {

                string mail = account[j];

                auto it = mp.find(mail);

                if(it == mp.end()) {

                    mp[mail] = i;

                } else {

                    unionSet(i, it->second, parent, rank);
                }
            }
        }

        /*
            Group all emails according to their
            ultimate parent account.
        */
        unordered_map<int, set<string>> preAns;

        for(auto it : mp) {

            auto accountNo = it.second;
            auto mail = it.first;

            // Find representative account
            accountNo = findParent(parent, accountNo);

            preAns[accountNo].insert(mail);
        }

        /*
            Build final answer.

            Each merged account contains:
            - Account holder's name
            - All unique emails in sorted order
              (set keeps them automatically sorted)
        */
        vector<vector<string>> ans;

        for(auto it : preAns) {

            string account = accounts[it.first][0];

            auto st = it.second;

            vector<string> v;

            v.push_back(account);

            for(auto mail : st)
                v.push_back(mail);

            ans.push_back(v);
        }

        return ans;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Case 1
    vector<vector<string>> accounts1 = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    // Hardcoded Test Case 2
    vector<vector<string>> accounts2 = {
        {"Alex","a@mail.com","b@mail.com"},
        {"Alex","b@mail.com","c@mail.com"},
        {"Alex","d@mail.com"},
        {"Alex","c@mail.com","e@mail.com"}
    };

    // Hardcoded Test Case 3
    vector<vector<string>> accounts3 = {
        {"David","d1@mail.com"},
        {"David","d2@mail.com"},
        {"David","d3@mail.com"}
    };

    vector<vector<string>> ans1 = obj.accountsMerge(accounts1);
    vector<vector<string>> ans2 = obj.accountsMerge(accounts2);
    vector<vector<string>> ans3 = obj.accountsMerge(accounts3);

    cout << "Test Case 1:\n";
    for(auto &acc : ans1) {
        for(auto &s : acc)
            cout << s << " ";
        cout << endl;
    }

    cout << "\nTest Case 2:\n";
    for(auto &acc : ans2) {
        for(auto &s : acc)
            cout << s << " ";
        cout << endl;
    }

    cout << "\nTest Case 3:\n";
    for(auto &acc : ans3) {
        for(auto &s : acc)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}