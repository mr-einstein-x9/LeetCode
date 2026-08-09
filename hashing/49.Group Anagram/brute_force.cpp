// LeetCode 49. Group Anagrams
// Difficulty: Medium

// Problem:
// We have given a strs array of strings and we have to return array of array in which anagram strings are grouped together

// Pattern: Brute Force (Pairwise Comparison)
// Approach:
// - Create a visited array to avoid regrouping strings.
// - Pick an unvisited string and sort it.
// - Compare it with every remaining unvisited string after sorting.
// - If the sorted strings are equal, they are anagrams.
// - Group all matching strings together.
// - Repeat until all strings are processed.

// Time Complexity: O(n^2*klogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        vector<bool> stored(strs.size(), false);

        for (int i = 0; i < strs.size(); i++)
        {
            if (stored[i])
                continue;
            vector<string> temp = {strs[i]};
            string s = strs[i];
            sort(s.begin(), s.end());
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (stored[j])
                    continue;
                string t = strs[j];
                sort(t.begin(), t.end());
                if (s == t)
                {
                    temp.push_back(strs[j]);
                    stored[j] = true;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};