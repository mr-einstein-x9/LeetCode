# Problem 15: 3Sum

**Pattern:** Two Pointer — Fixed Element + Opposite Ends

## Intuition

We need to find **three numbers** whose sum is `0`.

For example:

```text
nums = [-1, 0, 1, 2, -1, -4]
```

A simple brute-force solution would try every possible group of 3 numbers, which takes `O(n³)` time.

Instead, we can use **sorting + two pointers**.

First, sort the array:

```text
[-4, -1, -1, 0, 1, 2]
```

Now we **fix one number** and use two pointers to find the other two numbers.

For example, fix `-1`:

```text
      i
      ↓
[-4, -1, -1, 0, 1, 2]
          ↑        ↑
         left     right
```

Now the problem becomes:

> Find two numbers whose sum is `-nums[i]`.

This is basically the **Two Sum II** problem.

## Why This Pattern?

3Sum can be converted into repeated **Two Sum** problems.

For every `nums[i]`:

```text
nums[i] + nums[left] + nums[right] = 0
```

Because the array is sorted, we can decide which pointer to move:

```text
sum < 0 → left++
sum > 0 → right--
sum == 0 → found a triplet
```

So the overall pattern is:

```text
Sort
  ↓
Fix one element
  ↓
Use two pointers for remaining elements
```

## Approach

1. Sort the array.
2. Use a `for` loop to fix the first number `nums[i]`.
3. Set:

   * `left = i + 1`
   * `right = n - 1`
4. Calculate:

   ```cpp
   sum = nums[i] + nums[left] + nums[right]
   ```
5. If `sum == 0`:

   * Store the triplet.
   * Skip duplicate values from both sides.
   * Move both pointers inward.
6. If `sum < 0`:

   * Move `left` forward because we need a larger sum.
7. If `sum > 0`:

   * Move `right` backward because we need a smaller sum.
8. Skip duplicate `nums[i]` values to avoid duplicate triplets.

## Example

Consider:

```text
nums = [-1, 0, 1, 2, -1, -4]
```

After sorting:

```text
[-4, -1, -1, 0, 1, 2]
```

### Fix `-4`

```text
  i
  ↓
[-4, -1, -1, 0, 1, 2]
      ↑           ↑
    left         right
```

```text
sum = -4 + (-1) + 2
    = -3
```

`sum < 0`, so move `left`:

```text
[-4, -1, -1, 0, 1, 2]
          ↑        ↑
        left      right
```

We continue until no more pairs are possible for `-4`.

### Fix `-1`

Now:

```text
      i
      ↓
[-4, -1, -1, 0, 1, 2]
          ↑        ↑
        left      right
```

Try:

```text
-1 + (-1) + 2 = 0
```

We found:

```text
[-1, -1, 2]
```

Continue moving the pointers.

Eventually we also find:

```text
[-1, 0, 1]
```

Final answer:

```text
[[-1, -1, 2], [-1, 0, 1]]
```

## Why `sum < 0 → left++`?

Because the array is sorted.

Suppose:

```text
sum = nums[i] + nums[left] + nums[right] < 0
```

We need a **larger sum**.

Since everything after `left` is greater than or equal to `nums[left]`, moving `left` forward can increase the sum.

Therefore:

```cpp
left++;
```

Similarly:

```text
sum > 0 → right--
```

because moving `right` backward gives us a smaller value and can decrease the sum.

## Handling Duplicates

The problem does not allow duplicate triplets.

For example:

```text
[-1, -1, -1, 2, 2]
```

We should not return the same triplet multiple times.

### Duplicate `i`

If the current fixed value is the same as the previous one:

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

We skip it.

### Duplicate `left` and `right`

After finding a valid triplet:

```cpp
while (left < right && nums[left] == nums[left + 1])
    left++;

while (left < right && nums[right - 1] == nums[right])
    right--;
```

This skips repeated values before moving both pointers:

```cpp
left++;
right--;
```

## Algorithm

```text
sort nums

for each i:

    if nums[i] is same as previous:
        skip

    left = i + 1
    right = n - 1

    while left < right:

        sum = nums[i] + nums[left] + nums[right]

        if sum == 0:

            store the triplet

            skip duplicate left values
            skip duplicate right values

            left++
            right--

        else if sum < 0:
            left++

        else:
            right--
```

## Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)` auxiliary space, excluding the output

Sorting takes `O(n log n)`, and for each fixed element we perform a two-pointer scan of `O(n)`.

Therefore:

```text
O(n log n) + O(n²) = O(n²)
```

## Code

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    while (left < right &&
                           nums[left] == nums[left + 1])
                        left++;

                    while (left < right &&
                           nums[right - 1] == nums[right])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};
```

## Key Takeaway

> **3Sum = Fix one number + solve Two Sum with two pointers.**

The main pattern is:

```text
Sort
 ↓
Fix nums[i]
 ↓
left = i + 1
right = n - 1
 ↓
sum < 0 → left++
sum > 0 → right--
sum == 0 → store + skip duplicates
```

### Pattern Connection

```text
Two Sum II
    ↓
Two Pointers

3Sum
    ↓
Fix one element
    ↓
Two Sum II with remaining elements
```

So once you understand **Two Sum II**, 3Sum is essentially the same two-pointer idea with **one extra fixed element and duplicate handling**.
