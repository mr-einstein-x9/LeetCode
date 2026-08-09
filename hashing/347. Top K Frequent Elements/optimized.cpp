// LeetCode 347. Top K Frequent Elements
// Difficulty: Medium

// Problem:
// We have an array and we have to retrun most frequent (repeating element) and k elements on that

// Pattern: Hash Map(frequency)
// Approach:
// - first of all if k == size of (array) , then it means return all elements(uniquely) , if not then
// - we will store frequency of each element
// - now we need to return element according to frequencies
// - so we make a vector of vector bucket of  size of(array)+1 , why because indexing starts from 0 but in array elements strat form 1
// - now in bucket using frequency as index we will store all elements having that frequency
// - for instance : [1,1,2,2,3,3,4,1] in bucket [[],[4],[2,3],[1]]
// - now ground is set we will make new ans vector and start inserting each array elements one-by-one but only k elements
// - now we have k elements we insert having most frequency ,for k = 3 , ans = [1,3 ,2]

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.size() == k)
            return nums;
        unordered_map<int, int> mp;
        for (const auto &it : nums)
        { // O(n)
            mp[it]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &it : mp)
        { // O(m) and m<=n so still O(n)
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--)
        { // O(n+m) -> O(n)
            for (const auto &num : bucket[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};