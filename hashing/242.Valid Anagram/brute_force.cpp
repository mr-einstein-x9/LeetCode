// LeetCode 242. Valid Anagram
// Difficulty: Easy
// Pattern: Hash Map
//
// Problem:
// Given two strings - s&t , return true if s & t are anagram ,otehrwise false
//
// Approach:
// Brute force ( for every charcater in s search for matching charcter in t
//
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int l1 = s.size(), l2 = t.size();
        if (l1 != l2)
            return false;

        vector<bool> visited(l2, false);

        for (int i = 0; i < l1; i++)
        {
            bool found = false;
            for (int j = 0; j < l2; j++)
            {
                if (s[i] == t[j] && !visited[j])
                {
                    visited[j] = true;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};