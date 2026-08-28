ary
/
977-squares-of-a-sorted-array.md


Problem 977. Squares of a Sorted Array
Pattern: Two Pointer — Opposite Ends

Intuition
The array is already sorted in non-decreasing order, but squaring can change the order because negative numbers become positive.

For example:

[-4, -1, 0, 3, 10]

Squares:
[16, 1, 0, 9, 100]
The key observation is:

The largest absolute values are always at the two ends of a sorted array.

So the largest square must be either:

nums[left]²
     OR
nums[right]²
We compare them and put the larger square at the end of the answer.

Simple Example
nums = [-4, -1, 0, 3, 10]

 ↑                 ↑
left              right

-4² = 16
10² = 100
100 is larger, so:

[_, _, _, _, 100]
Move right inward.

Next:

-4² = 16
 3² = 9
So:

[_, _, _, 16, 100]
Continue until all elements are processed.

Final:

[0, 1, 9, 16, 100]
Why This Pattern?
The input is sorted, and we need to find the largest square repeatedly.

Because the largest absolute value must be at one of the two ends, we only need to compare:

left ↔ right
This gives the Two Pointer — Opposite Ends pattern.

Approach
Set left at the beginning and right at the end.

Create an answer array of the same size.

Compare nums[left]² and nums[right]².

Put the larger square at the back of ans.

Move the pointer whose square was used.

Move the answer index backward.

Repeat until left > right.

Algorithm
left = 0
right = n - 1
k = n - 1

while left <= right:

    leftSquare  = nums[left]²
    rightSquare = nums[right]²

    if leftSquare > rightSquare:
        ans[k] = leftSquare
        left++
    else:
        ans[k] = rightSquare
        right--

    k--

return ans
Brute Force
Square every element and then sort the array.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++)
            nums[i] *= nums[i];

        sort(nums.begin(), nums.end());

        return nums;
    }
};
Time: O(n log n)
Space: O(1) auxiliary

Optimised — Two Pointers
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> ans(nums.size());

        int left = 0;
        int right = nums.size() - 1;
        int k = nums.size() - 1;

        while(left <= right) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if(leftSquare > rightSquare) {
                ans[k] = leftSquare;
                left++;
            }
            else {
                ans[k] = rightSquare;
                right--;
            }

            k--;
        }

        return ans;
    }
};
Time: O(n)
Space: O(n)

Key Takeaway
Sorted array + need sorted squares → compare both ends.

Sorted array
     ↓
Largest absolute values are at the ends
     ↓
Compare left² and right²
     ↓
Put larger square at the back
     ↓
Move pointer inward
     ↓
O(n) Two Pointer solution