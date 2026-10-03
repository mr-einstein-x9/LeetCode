# Maximum Product Subarray

## Optimal Solution — O(n) | O(1)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int maxi = nums[0];
        int mini = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i];

            int oldMax = maxi;
            int oldMin = mini;

            maxi = max({x, oldMax * x, oldMin * x});
            mini = min({x, oldMax * x, oldMin * x});

            ans = max(ans, maxi);
        }

        return ans;
    }
};
```

---

## Intuition

For every index, maintain:

* `maxi` → maximum product of a subarray ending at current index.
* `mini` → minimum product of a subarray ending at current index.
* `ans` → maximum product found so far.

We need `mini` because:

```text
negative × negative = positive
```

So a previous minimum can become the next maximum.

For every `x`, there are 3 possibilities:

```text
x                  → start new subarray
oldMax × x         → extend maximum
oldMin × x         → extend minimum
```

---

## Brute Force — O(n³) | O(1)

Generate every subarray and calculate its product using a third loop.

```cpp
int ans = INT_MIN;

for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
        int product = 1;

        for (int k = i; k <= j; ++k)
            product *= nums[k];

        ans = max(ans, product);
    }
}
```

---

## Better Approach — O(n²) | O(1)

Avoid recalculating the product. Carry the product forward as `j` moves.

```cpp
int ans = INT_MIN;

for (int i = 0; i < n; ++i) {
    int product = 1;

    for (int j = i; j < n; ++j) {
        product *= nums[j];
        ans = max(ans, product);
    }
}
```

---

## Dry Run

For:

```text
nums = [2, 3, -2, 4]
```

| `x` | `maxi` | `mini` | `ans` |
| --- | -----: | -----: | ----: |
| 2   |      2 |      2 |     2 |
| 3   |      6 |      3 |     6 |
| -2  |     -2 |    -12 |     6 |
| 4   |      4 |    -48 |     6 |

**Answer = 6**

```text
[2, 3] → 2 × 3 = 6
```

---

## Complexity

| Approach    |  Time | Space |
| ----------- | ----: | ----: |
| Brute Force | O(n³) |  O(1) |
| Better      | O(n²) |  O(1) |
| Optimal     |  O(n) |  O(1) |
