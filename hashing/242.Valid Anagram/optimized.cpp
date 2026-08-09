// LeetCode 242. Valid Anagram
// Difficulty: Easy

// Problem:
// Given two strings - s&t , return true if s & t are anagram ,otehrwise false

// Pattern : Hash Map (frequency count)
// Approach 1:
// - Check if (size of s != size of t), return false
// - store frequency of each character in HashMap
// - Loop again & Decrease frequency of each character from mp
// - At last check if all frequency become 0 then true , otherwise false

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

// using hash map

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mp;

        for (char i : s)
        {
            mp[i]++;
        }
        for (char i : t)
        {
            mp[i]--;
        }
        for (const auto &f : mp)
        {
            if (f.second != 0)
                return false;
        }
        return true;
    }
};

// Pattern : Frequency count (using array) -> since all symbols are lowercase letters
// Approach 2:
// - Check if (size of s != size of t) return false
// - make array of size 26 , arr[26]
// - loop 1 to increase frequency of each cahracter index of s
// - loop 2 to decrease frequency on occurence of character in t
// - lastly loop 3 check if all frequencies are 0 then true , otherwise false

// using array
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        // since all character are lowercase
        int arr[26] = {};

        for (char i : s)
        {
            arr[i - 'a']++;
        }
        for (char i : t)
        {
            arr[i - 'a']--;
        }
        for (const auto &f : arr)
        {
            if (f != 0)
                return false;
        }
        return true;
    }
};

/*IMPORTANT CONCEPT LEARNED*/
/*

    # auto f
      - Makes a copy.
      - You can modify the copy.
      - Changes do not affect the map.

    # auto& f
      - No copy.
      - f refers to the original element.
      - Changes affect the map.

    # const auto& f
      - No copy.
      - Cannot modify the original.
      - Fastest and safest when only reading.

*/