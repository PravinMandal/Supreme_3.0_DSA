//leetcode: 1079. Letter Tile Possibilities

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;

    // This recursive function generates all possible sequences
    // using backtracking and stores them in a set to avoid duplicates.
    void solve(string& tiles, vector<bool>& used, unordered_set<string>& result, string& curr) {

        // Insert the current sequence into the set
        // This includes the empty string initially
        result.insert(curr);

        // Try picking each tile that has not been used
        for(int i=0; i<n; i++) {

            // If this tile is already used in the current sequence, skip it
            if(used[i]) continue;

            // Mark tile as used
            used[i] = true;

            // Add the tile character to the current sequence
            curr.push_back(tiles[i]);

            // Recursively build further sequences
            solve(tiles, used, result, curr);

            // Backtracking step:
            // undo the choice to explore other possibilities
            used[i] = false;
            curr.pop_back();
        }
    }

    int numTilePossibilities(string tiles) {

        // Store number of tiles
        n = tiles.size();

        // Track which characters are used in current sequence
        vector<bool> used(n, false);

        // Set to store unique sequences
        unordered_set<string> result;

        // Current building string
        string curr = "";

        // Start recursive generation
        solve(tiles, used, result, curr);

        return result.size()-1; //exclude "" empty case
    }
};

class Solution2 {
public:
    int count;

    // This recursive function generates all possible sequences using
    // frequency counting instead of tracking individual tile positions.
    // vec[i] represents how many tiles of character ('A' + i) are still available.
    void solve(vector<int>& vec) {

        // Every call represents one possible sequence (including empty initially)
        count++;

        // Try using every possible character from A to Z
        for(int i=0; i<26; i++) {

            // If no tile of this character remains, skip it
            if(vec[i] == 0) continue;

            // Choose this character by reducing its available count
            vec[i]--;

            // Continue building sequences recursively
            solve(vec);

            // Backtrack: restore the tile count
            vec[i]++;
        }
    }

    int numTilePossibilities(string tiles) {

        // Reset global counter
        count = 0;

        // Frequency vector for characters A-Z
        vector<int> vec(26, 0);

        // Count how many times each character appears
        for(char& ch : tiles) {
            vec[ch-'A']++;
        }

        // Start recursion with frequency vector
        solve(vec);

        return count-1; //exclude empty case
    }
};

int main() {

    // Hardcoded test case
    string tiles = "AAB";

    Solution2 obj;

    int result = obj.numTilePossibilities(tiles);

    cout << "Number of possible tile sequences: " << result << endl;

    return 0;
}