// LeetCode 49. Group Anagrams
// Difficulty: Medium

// Problem:
// We have given a strs array of strings and we have to return array of array in which anagram strings are grouped together

// Pattern: Optimized (Pairwise Comparison)
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
