// Contest_513 : Q1. Maximize Pair Strength Using GCD
// Difficulty: Easy

// Problem:
// Form the given array , we have to choose exactly a pair which will give maximum strength and here strength for 
// any i and j will be calculated , strength = (nums[i] * nums[j]) / gcd(nums[i], nums[j])^2
                                    

// Pattern: Brute force( Check for each pair using nested loop)
// Approach:
// Since given nums.length()<=2000 , we will be checking each pair and comapring for maximum, initailly max = 0
// if nums[i] = a and nums[j] = b then strength = (a*b)/gcd^2
// Let g = gcd(a, b).
// Then a = g * p and b = g * q, where p and q are coprime.
// Therefore,
// strength = (a * b) / (g * g)
//          = (a / g) * (b / g)     -> to avoid overflow
// we will use 1st loop from i=0 to i=n-2 and secong loop from j=i+1 and j=n-1
// we will find strength for each pair and compare with max if greater then allocate it to max other wise continue
// we will also check edge case before finding strength , if g==0 conitue that itteration

// Concept/Idea  learned :
// - while finding strength we saw instead of (a*b)/g^2 we did (a/g)*(b/g) -> to avoid overflow
// - why overflow - let a = 100000 and b=900000 then a*b = 9000000000 which will overflow so first divide then multiply 

// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
      int n = nums.size();
        long long best = 0;

        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                int g = __gcd(nums[i], nums[j]);
                if(g==0) continue;
                long long strength = (long long)(nums[i] / g) * (nums[j] / g);
                best = max(best, strength);
            }
        }

        return best;
      
    }
};
