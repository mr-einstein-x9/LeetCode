// LeetCode 238. Product of Array Except Self
// Difficulty: Medium

// Problem:
// given an array and we have to return resulting array , where at each index it contain roduct of all elements expect that position element

// Pattern: Prefix Sum
// Approach:
// - we will create an array of nums size and intialise it with 1
// - now using prefix technique we will find left prefix sum and right prefix sum then on multipying we will get desired result
// - logically at each index we are calculating product of all left & right elements which omit that element itself
// - here we are directly taking ans array and using as left array we will start form 1
// - at each ans position i we will store result of nums[i-1] with ans[i-1]
// - now our ans array contain left prefix sum
// - now we will initialise right = 1(empty) and at each ans[i] we will store result ans[i](contain left prefix) * right(current right sufix sum product)
// - now by doing this we have updated ans array with correct result
// - return ans array

// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
