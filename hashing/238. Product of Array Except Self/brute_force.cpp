// LeetCode 238. Product of Array Except Self
// Difficulty: Medium

// Problem:
// given an array and we have to return resulting array , where at each index it contain roduct of all elements expect that position element

// Pattern: Brute force (nested loop)
// Approach:
// - we will take one element from array and now in next loop check if we are at smae positoin then continue otherwise
// - we will take p variable and calculate product of all elements except that position's element
// - finally return the result

// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int p = 1;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                p *= nums[j];
            }
            ans[i] = p;
        }
        return ans;
    }
};
