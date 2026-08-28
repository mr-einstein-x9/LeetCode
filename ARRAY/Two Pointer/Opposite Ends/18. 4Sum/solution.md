# Problem 18: 4Sum

**Pattern:** Two Pointer — Fix Two Elements + Opposite Ends

## Intuition

The goal is to find **four numbers** whose sum is equal to `target`.

A brute-force approach would try every possible group of four numbers:

```text
i, j, k, l
```

That would take `O(n⁴)` time.

We can reduce this using the same idea we used in **3Sum**.

In 3Sum, we:

```text
Fix 1 number
    ↓
Use 2 pointers
```

For 4Sum, we simply fix **2 numbers**:

```text
Fix nums[i]
    ↓
Fix nums[j]
    ↓
Use 2 pointers for the remaining numbers
```

So:

```text
4Sum
 ↓
Fix two elements
 ↓
Two Sum using two pointers
```

## Why This Pattern?

After sorting the array, we can use the order of the elements to control the two pointers.

For every pair `nums[i]` and `nums[j]`, we set:

```cpp
left = j + 1;
right = n - 1;
```

Then calculate:

```cpp
sum = nums[i] + nums[j] + nums[left] + nums[right];
```

There are three possibilities:

```text
sum == target → found a quadruplet

sum < target  → need a larger sum → left++

sum > target  → need a smaller sum → right--
```

This is the same pointer movement logic as **Two Sum II** and **3Sum**.

## Approach

1. Sort the array.
2. Use the first loop to fix the first number `nums[i]`.
3. Skip duplicate values of `nums[i]`.
4. Use the second loop to fix the second number `nums[j]`.
5. Skip duplicate values of `nums[j]`.
6. Set:

   ```cpp
   left = j + 1
   right = n - 1
   ```
7. Calculate the sum of the four numbers.
8. If `sum == target`:

   * Store the quadruplet.
   * Skip duplicate `left` values.
   * Skip duplicate `right` values.
   * Move both pointers.
9. If `sum < target`, move `left` forward.
10. If `sum > target`, move `right` backward.
11. Continue until all valid combinations are checked.

## Example

Consider:

```text
nums = [1, 0, -1, 0, -2, 2]
target = 0
```

After sorting:

```text
[-2, -1, 0, 0, 1, 2]
```

Fix the first two numbers:

```text
 i   j
 ↓   ↓
[-2, -1, 0, 0, 1, 2]
         ↑        ↑
       left      right
```

Calculate:

```text
-2 + (-1) + 0 + 2 = -1
```

Since:

```text
-1 < 0
```

we need a larger sum:

```text
left++
```

Now:

```text
-2 + (-1) + 0 + 2
```

Eventually we find:

```text
[-2, 0, 0, 2]
```

The same process finds:

```text
[-2, -1, 1, 2]
[-1, 0, 0, 1]
```

Final result:

```text
[
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1]
]
```

## Why Use `long long`?

The four numbers can be large enough that their sum may exceed the range of a normal `int`.

For example, if the values are close to:

```text
10⁹ + 10⁹ + 10⁹ + 10⁹
```

the sum is approximately:

```text
4 × 10⁹
```

which is larger than the maximum value of a 32-bit `int`.

Therefore, we calculate:

```cpp
long long sum =
    (long long)nums[i] +
    nums[j] +
    nums[left] +
    nums[right];
```

The cast to `long long` ensures the addition is performed using `long long`.

## Handling Duplicates

The problem requires **unique quadruplets**.

For example:

```text
[-2, 0, 0, 2, 2]
```

Without duplicate handling, we could generate the same quadruplet multiple times.

### Duplicate `i`

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

If the current `nums[i]` is the same as the previous one, skip it.

### Duplicate `j`

```cpp
if (j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

The `j > i + 1` condition is important.

It means:

> Skip duplicates only after the first `j` for the current `i`.

### Duplicate `left` and `right`

After finding a quadruplet:

```cpp
while (left < right && nums[left] == nums[left + 1])
    left++;

while (left < right && nums[right - 1] == nums[right])
    right--;
```

Then move both pointers:

```cpp
left++;
right--;
```

This prevents the same quadruplet from being added again.

## Why `j > i + 1`?

Consider:

```text
[-2, -2, 0, 0, 2, 2]
```

For the first `-2`:

```text
i = 0
j = 1
```

We **must allow** this because `nums[j]` can legitimately be another `-2`.

But after that:

```text
j = 2
```

If `nums[j]` is the same as the previous `nums[j-1]`, we skip it.

That's why:

```cpp
j > i + 1
```

rather than simply:

```cpp
j > 0
```

## Algorithm

```text
sort nums

for i:

    skip duplicate i

    for j:

        skip duplicate j

        left = j + 1
        right = n - 1

        while left < right:

            sum = nums[i] + nums[j]
                 + nums[left] + nums[right]

            if sum == target:

                store quadruplet

                skip duplicate left
                skip duplicate right

                left++
                right--

            else if sum < target:
                left++

            else:
                right--
```

## Complexity

* **Time:** `O(n³)`
* **Space:** `O(1)` auxiliary space, excluding the output

Why `O(n³)`?

```text
First loop       → O(n)
Second loop      → O(n)
Two pointers     → O(n)

Total            → O(n³)
```

Sorting takes `O(n log n)`, which is smaller than `O(n³)`.

Therefore:

```text
O(n log n) + O(n³) = O(n³)
```

## Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; ++i) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; ++j) {

                // Skip duplicate second elements
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum =
                        (long long)nums[i] +
                        nums[j] +
                        nums[left] +
                        nums[right];

                    if (sum == target) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        // Skip duplicate left values
                        while (left < right &&
                               nums[left] == nums[left + 1])
                            ++left;

                        // Skip duplicate right values
                        while (left < right &&
                               nums[right - 1] == nums[right])
                            --right;

                        ++left;
                        --right;
                    }
                    else if (sum < target) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }

        return ans;
    }
};
```

## Key Takeaway

> **4Sum = Fix two elements + Two Sum with two pointers.**

The progression is:

```text
Two Sum II
    ↓
Two pointers

3Sum
    ↓
Fix 1 element
    ↓
Two pointers

4Sum
    ↓
Fix 2 elements
    ↓
Two pointers
```

The most important rules to remember:

```text
sum < target  → left++

sum > target  → right--

sum == target → store quadruplet + skip duplicates
```

And because 4Sum can produce very large sums:

```cpp
long long sum
```

should be used to avoid integer overflow.
