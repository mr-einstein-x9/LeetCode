# Problem: 977. Squares of a Sorted Array

**Pattern:** Two Pointer — Opposite Ends

## Intuition

The array is already sorted:

```text
[-7, -3, 2, 3, 11]
```

But after squaring, the order can change:

```text
[49, 9, 4, 9, 121]
```

So we **cannot simply square every element and keep the same order**.

The important observation is:

> The **largest square** will always come from either the **leftmost** or the **rightmost** element.

Why?

The array is sorted, so the values with the largest absolute value are at the ends.

```text
[-7, -3, 2, 3, 11]
 ↑              ↑
left           right
```

Their squares are:

```text
49              121
```

So we compare the squares of both ends and put the **larger square at the end of `ans`**.

## Why This Pattern?

The array is sorted, but negative numbers make the squared array unsorted.

For example:

```text
[-4, -1, 0, 3, 10]

squares → [16, 1, 0, 9, 100]
```

The largest square is at one of the two ends.

Therefore, we use **two pointers**:

```text
i → left side
j → right side
```

And another pointer:

```text
k → position where we put the next largest square
```

Since we are finding the largest value first, we fill `ans` **from right to left**.

## Approach

1. Create an answer array `ans` of the same size.
2. Set `i = 0` at the beginning.
3. Set `j = n - 1` at the end.
4. Set `k = n - 1` at the last position of `ans`.
5. Calculate the square of `nums[i]` and `nums[j]`.
6. Compare both squares:

   * If `left square > right square`, put it at `ans[k]` and move `i`.
   * Otherwise, put the right square at `ans[k]` and move `j`.
7. Move `k` backward.
8. Continue until all elements are processed.

## Example

Consider:

```text
nums = [-7, -3, 2, 3, 11]
```

Initially:

```text
i                   j
↓                   ↓
-7  -3   2   3    11
```

Squares:

```text
49                  121
```

`121` is larger, so put it at the last position:

```text
ans = [_, _, _, _, 121]
```

Move `j` and `k`:

```text
i              j
↓              ↓
-7  -3   2    3   11
```

Now:

```text
49              9
```

`49` is larger:

```text
ans = [_, _, _, 49, 121]
```

Continue the same process.

Final result:

```text
[4, 9, 9, 49, 121]
```

## Why Fill `ans` From Right to Left?

At every step, we find the **largest remaining square**.

So it belongs at the current largest empty position.

```text
Largest → ans[n-1]
Next largest → ans[n-2]
Next → ans[n-3]
...
```

That's why:

```cpp
k--;
```

after every insertion.

## Why Are We Comparing Only the Two Ends?

Consider:

```text
[-7, -3, 2, 3, 11]
```

The absolute values increase toward one of the ends.

The middle elements cannot have a larger absolute value than both relevant ends.

Therefore, the largest remaining square must come from:

```cpp
nums[i]
```

or

```cpp
nums[j]
```

Once we choose the larger one, we remove it from consideration by moving that pointer.

## Algorithm

```text
i = 0
j = n - 1
k = n - 1

while i <= j:

    leftSquare  = nums[i]²
    rightSquare = nums[j]²

    if leftSquare > rightSquare:
        ans[k] = leftSquare
        i++
    else:
        ans[k] = rightSquare
        j--

    k--

return ans
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

We visit each element once.

The `ans` array requires `O(n)` extra space.

## Code

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        int i = 0;
        int j = n - 1;
        int k = n - 1;

        while (i <= j) {
            int l_sqr = nums[i] * nums[i];
            int r_sqr = nums[j] * nums[j];

            if (l_sqr > r_sqr) {
                ans[k] = l_sqr;
                i++;
            } else {
                ans[k] = r_sqr;
                j--;
            }

            k--;
        }

        return ans;
    }
};
```

## Key Takeaway

> **In a sorted array, the largest square must come from one of the two ends.**

So:

```text
Compare left square and right square
            ↓
Take the larger one
            ↓
Put it at the end of ans
            ↓
Move that pointer
```

This avoids:

```cpp
square every element + sort
```

which takes `O(n log n)` time, and gives us an **`O(n)` two-pointer solution**.
