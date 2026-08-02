// Contest_513 : Q2. Count Subarrays With Even Odd Ratio I
// Difficulty: Medium

// Problem:
// Given an array nums of 1 and 2  and a ,b we have to find how many valid subarray can be formed from this nums

// Constraints - 
// - number of even = x 
// - number of odd = y
// - valid only if : 
//                 - y>0
//                 - x/y <= a/b , here x/y holds raitional value no fractional

// Pattern: Brute force( check each subarray using nested loop)
// Approach:
// given conditon x/y <= a/b to be rational we better rite it as x*b <= a*y 
// now loop i= 0 to i<n then reset x = 0 and y = 0 for each subarray
// second loop from j= i to j<n incremetn one element at a time
// with each itteration check for x , y then validate that subarray if ture then count ++ other wise next itteration
// finally return count

// COncept /Idea found:
// - use long long to avoid overflow condition

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int count = 0;
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            long long x = 0 , y = 0;
            for(int j = i ; j<n ; j++){
                if(nums[j]%2 == 0) x++;
                else y++;
                if(y>0 && x*(long long)b<= y*(long long)a) count++;
            }
        }
        return count++;
    }
};