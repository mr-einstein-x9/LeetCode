// LeetCode 128. Longest Consecutive Sequence
// Difficulty: Medium

// Problem:
// We have given a "unsorted" array 'nums' and we have to return the 'longest consecutive array length' .

// Pattern: Brute force(using set)
// Approach:
// - We are going to count the longest consecutive array length do first we have to sort and remove redundant elements
// - first if array is empty we will return 0
// - we are going to count so we are using set to get sorted and non-redundant array
// - since set doesn't support index access so convert set->vector
// - now we will loop from vector index = 1 and stand there to look back if it is consecutive then increase len
// - now what if consecutive order breaks , then we will use else block where we will update maxlen and for new len, len=0
// - finally before returning update maxlen once,why? - what if control doesn't get into else block

// Time Complexity: O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        // to sort and remove erdundent elements at once
        set<int>s(nums.begin() , nums.end());
        // since set doesn't supports indexing so convert:  set->vector
        vector<int>lookUp(s.begin() , s.end());

        // atleast 1 element is in consecutive order so
        int len = 1;
        // now if we have several consecutive different sub-arrays so for comparision
        int maxlen = 1;

        for(int i = 1 ; i<lookUp.size() ; i++){
            // stand on element and look if it is consecutive element or not
            if(lookUp[i]-1 == lookUp[i-1]) len++;
            // now if one consecutive array ends and new consecutive array starts
            else{
                maxlen = max(maxlen , len);
                len = 1;
            }
        }
        // what if control didn't get into else block so we have to update maxlen before returning
        maxlen = max(maxlen , len);

        return maxlen;
    }
};
