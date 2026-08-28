# Problem 16: 3Sum Closest

**Pattern:** Two Pointer — Fixed Element + Opposite Ends

## Intuition

This problem is very similar to **3Sum**.

In 3Sum, we look for a triplet whose sum is exactly `0`.

Here, we need a triplet whose sum is **closest to the target**.

For example:

```text
nums = [-1, 2, 1, -4]
target = 1
```

After sorting:

```text
[-4, -1, 1, 2]
```

We fix one number and use two pointers for the other two numbers.

The main idea is:

> Keep track of the sum that is currently closest to `target`.

For every triplet:

```cpp
sum = nums[i] + nums[left] + nums[right];
```

we compare:

```cpp
abs(target - sum)
```

with:

```cpp
abs(target - ans)
```

If the new sum is closer, update `ans`.

## Why This Pattern?

Just like **3Sum**, we can:

```text
Sort the array
      ↓
Fix one element
      ↓
Use two pointers for the remaining elements
```

Because the array is sorted:

* If `sum < target`, we need a **larger sum** → `left++`
* If `sum > target`, we need a **smaller sum** → `right--`

So we can search efficiently without checking every triplet.

## Approach

1. Sort the array.
2. Initialize `ans` with the sum of the first three elements.
3. Use a loop to fix `nums[i]`.
4. Set:

   ```cpp
   left = i + 1
   right = n - 1
   ```
5. Calculate the current `sum`.
6. If `sum == target`, we have the closest possible answer, so return it.
7. Otherwise, check whether `sum` is closer to `target` than `ans`.
8. If `sum < target`, move `left` forward.
9. If `sum > target`, move `right` backward.
10. Continue until all possible pointer combinations are checked.

## How Do We Know Which Sum Is Closer?

Suppose:

```text
target = 10
ans = 7
sum = 12
```

Distances from the target:

```text
|10 - 7|  = 3
|10 - 12| = 2
```

Since `12` is closer:

```cpp
ans = 12;
```

That's why we use:

```cpp
if (abs(target - sum) < abs(target - ans))
    ans = sum;
```

## Why `sum < target → left++`?

Because the array is sorted.

Suppose:

```text
sum < target
```

We need to increase the sum.

Moving `left` forward gives us a larger value:

```text
left++
```

Similarly:

```text
sum > target
```

means we need a smaller sum, so:

```text
right--
```

This is the same pointer movement rule used in **Two Sum II** and **3Sum**.

## Example

```text
nums = [-1, 2, 1, -4]
target = 1
```

After sorting:

```text
[-4, -1, 1, 2]
```

Initially:

```text
ans = -4 + (-1) + 1
    = -4
```

Fix `-4`:

```text
i
↓
[-4, -1, 1, 2]
     ↑        ↑
   left      right
```

Calculate:

```text
sum = -4 + (-1) + 2
    = -3
```

Target is `1`.

Since:

```text
-3 < 1
```

move `left`.

Next:

```text
-4 + 1 + 2 = -1
```

Still less than target, so continue.

Now fix `-1`:

```text
[-4, -1, 1, 2]
      ↑  ↑   ↑
      i left right
```

We get:

```text
-1 + 1 + 2 = 2
```

Distance from target:

```text
|1 - 2| = 1
```

So:

```text
ans = 2
```

The closest sum is `2`.

## Algorithm

```text
sort nums

ans = nums[0] + nums[1] + nums[2]

for i from 0 to n - 3:

    left = i + 1
    right = n - 1

    while left < right:

        sum = nums[i] + nums[left] + nums[right]

        if sum == target:
            return sum

        if |target - sum| < |target - ans|:
            ans = sum

        if sum < target:
            left++

        else:
            right--

return ans
```

## Complexity

* **Time:** `O(n²)`
* **Space:** `O(1)` auxiliary space

Sorting takes `O(n log n)`, followed by an `O(n²)` two-pointer search.

Therefore:

```text
O(n log n) + O(n²) = O(n²)
```

## Code

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) {
                    ans = sum;
                    break;
                }

                if (abs(target - sum) < abs(target - ans))
                    ans = sum;

                if (sum < target)
                    left++;
                else
                    right--;
            }
        }

        return ans;
    }
};
```

## Key Takeaway

> **3Sum Closest = 3Sum + keep the sum with the smallest distance from target.**

Remember the three important rules:

```text
sum == target → exact answer → stop

sum < target  → left++

sum > target  → right--
```

And after calculating every sum:

```text
smaller |target - sum| → update ans
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
Two Sum with two pointers

3Sum Closest
    ↓
Fix one element
    ↓
Two Sum with two pointers
    ↓
Keep the sum closest to target
```
