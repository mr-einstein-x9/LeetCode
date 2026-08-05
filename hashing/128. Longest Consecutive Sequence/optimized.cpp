// LeetCode 128. Longest Consecutive Sequence
// Difficulty: Medium

// Problem:
// We have given a "unsorted" array 'nums' and we have to return the 'longest consecutive array length' .

// Pattern: Hash Set(using unordered set)
// Approach:
// - Unlike brute force we will first check if any element is start of sequence(consecutive array) or not
// - we will use unordered_set which will allow lookup in O(1) time complexity
// - now we will itterate each element 'num' and check if 'num-1' is present in hashset if ues then it is not start so skip
// - if 'num-1' is not present mean this is start of sequence loop again to check length of sequece it is reaching
// - now after completion of this sequence update maxlen and check for other esquence if there are any
// - finally return maxlen

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        // for quick lookup make unordered set , also removes redundant elements
        unordered_set<int> st(nums.begin(), nums.end());

        int maxlen = 0;
        for (const auto& it : st) {
            // 'it' is not starting of sequence since 'it-1' is present(Ex. 2 is
            // not start since 2-1 = 1 is  present)
            if (st.find(it - 1) == st.end()) {
                // so we found our sequence starting
                int len = 1;
                int current = it;
                // now we will count how long this seuence will go
                while (st.find(current + 1) != st.end()) {
                    len = len + 1;
                    current = current + 1;
                }
                // now end of sequence update maxlen
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};