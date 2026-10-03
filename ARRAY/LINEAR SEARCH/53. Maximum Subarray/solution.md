# Maximum Subarray

## Optimal Solution — O(n) | O(1)

### Kadane's Algorithm

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;

        for (int i = 0; i < n; ++i) {

            sum += nums[i];

            maxSum = max(maxSum, sum);

            if (sum < 0)
                sum = 0;
        }

        return maxSum;
    }
};
```

### Explanation

Maintain `sum` as the maximum subarray sum ending at the current position.

* Add the current element to `sum`.
* Update `maxSum` with the best sum found so far.
* If `sum` becomes negative, discard it because carrying a negative sum can only reduce the sum of any future subarray.

`maxSum` is updated **before resetting `sum`**, which also handles arrays containing only negative numbers.

---

## Brute Force — O(n³) | O(1)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; ++i) {

            for (int j = i; j < n; ++j) {

                int sum = 0;

                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
```

---

## Better Approach — O(n²) | O(1)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; ++i) {

            int sum = 0;

            for (int j = i; j < n; ++j) {

                sum += nums[j];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
```

---

## Dry Run

For:

```text
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

| `x` |  `sum` | `maxSum` |
| --: | -----: | -------: |
|  -2 |      0 |       -2 |
|   1 |      1 |        1 |
|  -3 | -2 → 0 |        1 |
|   4 |      4 |        4 |
|  -1 |      3 |        4 |
|   2 |      5 |        5 |
|   1 |      6 |        6 |
|  -5 |      1 |        6 |
|   4 |      5 |        6 |

The maximum sum is:

```text
[4, -1, 2, 1] = 6
```

**Answer = 6**

---

## Time Complexity

| Approach                     |  Time | Space |
| ---------------------------- | ----: | ----: |
| Brute Force                  | O(n³) |  O(1) |
| Better                       | O(n²) |  O(1) |
| Optimal — Kadane's Algorithm |  O(n) |  O(1) |
