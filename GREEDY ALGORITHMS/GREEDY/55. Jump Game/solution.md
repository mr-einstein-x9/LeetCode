# Jump Game

## Optimal Solution — O(n) | O(1)

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return true;

        int maxIdx = 0;

        for (int i = 0; i < n - 1; ++i) {

            if (maxIdx >= i) {
                maxIdx = max(maxIdx, i + nums[i]);
            }

            if (maxIdx >= n - 1)
                return true;
        }

        return false;
    }
};
```

### Explanation

`maxIdx` stores the **farthest index reachable** so far.

At each index:

- If `i <= maxIdx`, the current index is reachable.
- Update `maxIdx` using `i + nums[i]`.
- If `maxIdx >= n - 1`, the last index is reachable.

If we encounter an index where `i > maxIdx`, that index cannot be reached, so the answer is `false`.

---

## Brute Force — O(2ⁿ) | O(n)

```cpp
class Solution {
public:
    bool solve(vector<int>& nums, int i) {

        if (i >= nums.size() - 1)
            return true;

        for (int jump = 1; jump <= nums[i]; ++jump) {

            if (solve(nums, i + jump))
                return true;
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};
```

---

## Better Approach — O(n²) | O(n)

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<bool> reachable(n, false);

        reachable[0] = true;

        for (int i = 0; i < n; ++i) {

            if (!reachable[i])
                continue;

            for (int jump = 1; jump <= nums[i] && i + jump < n; ++jump) {
                reachable[i + jump] = true;
            }
        }

        return reachable[n - 1];
    }
};
```

---

## Dry Run

For:

```text
nums = [2, 3, 1, 1, 4]
```

| `i` | `nums[i]` | `maxIdx` |
|---:|---:|---:|
| 0 | 2 | 2 |
| 1 | 3 | 4 |

At `i = 1`:

```text
i + nums[i] = 1 + 3 = 4
```

Since:

```text
maxIdx >= n - 1
4 >= 4
```

we can reach the last index.

**Answer = `true`**

---

## Time Complexity

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(2ⁿ) | O(n) |
| Better — DP | O(n²) | O(n) |
| Optimal — Greedy | O(n) | O(1) |