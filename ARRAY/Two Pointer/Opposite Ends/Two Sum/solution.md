# Problem: 977. Squares of a Sorted Array

**Pattern:** Two Pointer — Opposite Ends

## Intuition

The array is **sorted in non-decreasing order**, but squaring can change the order because negative numbers become positive.

For example:

```text
[-4, -1, 0, 3, 10]

After squaring:
[16, 1, 0, 9, 100]
```

The key observation is that the **largest absolute values are at the two ends**.

So the largest square must come from either:

* `nums[left]`
* `nums[right]`

We compare their squares and put the **larger square at the end** of the answer.

## Why This Pattern?

The key clue is that the input array is **sorted**.

With two pointers at opposite ends:

* `left` points to the smallest value.
* `right` points to the largest value.
* The largest square must come from one of these two positions.

Therefore, we can find the squares in sorted order without using `sort()`.

## Approach

1. Set `left = 0` at the beginning.
2. Set `right = n - 1` at the end.
3. Set `k = n - 1` to fill the answer from the back.
4. Calculate `leftSquare` and `rightSquare`.
5. If `leftSquare > rightSquare`:

   * Store `leftSquare` at `ans[k]`.
   * Move `left` forward.
6. Otherwise:

   * Store `rightSquare` at `ans[k]`.
   * Move `right` backward.
7. Decrease `k`.
8. Continue until `left > right`.

> **Why fill from the back?**
> At every step, we find the **largest remaining square**, so it belongs at the end of the answer.

## Simple Example

```text
nums = [-4, -1, 0, 3, 10]

left                    right
 ↓                         ↓
-4  -1   0   3   10

-4² = 16
10² = 100
```

`100` is larger, so:

```text
[_, _, _, _, 100]
```

Move `right`.

```text
-4² = 16
 3² = 9
```

Put `16`:

```text
[_, _, _, 16, 100]
```

Continue until the array is complete:

```text
[0, 1, 9, 16, 100]
```

## Algorithm

1. Initialize `left` at the beginning.
2. Initialize `right` at the end.
3. Initialize `k` at the end of `ans`.
4. Compare `nums[left]²` and `nums[right]²`.
5. Put the larger square at `ans[k]`.
6. Move the corresponding pointer.
7. Move `k` backward.
8. Continue until all elements are processed.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

## Code

```cpp
class Solution {

public:

    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int k = n - 1;

        while (left <= right) {

            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {

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
```

## Key Takeaway

> **Sorted array + squaring → compare both ends and fill the answer from the back.**

```code
Sorted input
     ↓
Largest absolute values are at the ends
     ↓
Compare left² and right²
     ↓
Put larger square at the back
     ↓
Move pointer inward
     ↓
O(n) Two Pointer
```
