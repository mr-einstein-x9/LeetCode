// LeetCode 49. Group Anagrams
// Difficulty: Medium

// Problem:
// Given an array of strings, group all anagrams together and return them as a 2D vector.

// Pattern: Hash Map

// Key Idea:
// All anagrams become identical after sorting.
// Use the sorted string as the hash map key and store the original strings as its value.

// Approach:
// - Create an unordered_map<string, vector<string>>.
// - For each string, create a sorted copy.
// - Use the sorted string as the key and push the original string into the map.
// - Collect all map values into the answer vector.

// Time Complexity: O(n × k log k)
// Space Complexity: O(n × k)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (const auto& x : strs) {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        for (const auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};