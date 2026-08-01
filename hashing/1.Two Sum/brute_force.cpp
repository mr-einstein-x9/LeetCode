// LeetCode 1. Two Sum
// Difficulty: Easy

// Problem: Given an array nums and an integer target,
// return the indices of the two numbers such that they add up to target.

// Constraints:
// - Exactly one valid answer exists.
// - Return the answer in any order.

// Approach: Brute Force ( nested loop)

#include <bits/stdc++.h>
using namespace std;

// Brute force Approach
class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i = 0 ; i<nums.size()-1 ; i++){
            for(int j = i+1 ; j<nums.size() ; j++){
                if(nums[i]+nums[j] == target){
                    ans = {i,j};
                    break;
                } 
            }
        }
        return ans;
    }
};

// Time Complexity: O(n²)
// Space Complexity: O(1)
