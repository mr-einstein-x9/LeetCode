// LeetCode 1. Two Sum
// Difficulty: Easy
// Problem: Given an array nums and an integer target,
// return the indices of the two numbers such that they add up to target.

// Constraints:
// - Exactly one valid answer exists.
// - Return the answer in any order.

// Appraoch: HashMap

#include <bits/stdc++.h>
using namespace std;

// Optimised HashMap solution
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // HashMap
        unordered_map<int , int>mp;
        vector<int>ans;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans = {i,mp[target-nums[i]]};
                break;
                
            }
            mp[nums[i]] = i; 
        }
        return ans;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)