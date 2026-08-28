# Problem: Two Sum II

**Pattern:** Two Pointer — Opposite Ends

## Intuition

The array is **sorted**, so we can use the order of elements to decide which pointer to move.

- If `numbers[left] + numbers[right] == target`, we found the answer.
- If the sum is **less than** `target`, we need a larger sum → move `left` forward.
- If the sum is **greater than** `target`, we need a smaller sum → move `right` backward.

This avoids checking every possible pair.

## Why This Pattern?

The key clue is that the input array is **sorted**.

With two pointers at opposite ends:

- Moving `left` rightward increases the sum.
- Moving `right` leftward decreases the sum.

Therefore, every comparison lets us eliminate a range of impossible pairs.

## Approach

1. Set `i = 0` at the beginning.
2. Set `j = n.size() - 1` at the end.
3. Calculate `sum = n[i] + n[j]`.
4. If `sum == target`, store `i + 1` and `j + 1`.
5. If `sum < target`, increment `i` because we need a larger value.
6. If `sum > target`, decrement `j` because we need a smaller value.
7. Continue until `i < j`.

> **Why `i + 1` and `j + 1`?**  
> The problem uses **1-based indexing**, while C++ vectors use **0-based indexing**.

## Algorithm

1. Initialize `left` at the beginning.
2. Initialize `right` at the end.
3. Calculate the sum of `numbers[left]` and `numbers[right]`.
4. If the sum equals the target, return their **1-based indices**.
5. If the sum is less than the target, move `left` forward.
6. If the sum is greater than the target, move `right` backward.
7. Continue until the answer is found.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int len = n.size();

        int i = 0, j = len - 1;
        vector<int> ans;

        while (i < j) {
            int sum = n[i] + n[j];

            if (sum == target) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return ans;
    }
};