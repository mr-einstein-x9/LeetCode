# Trapping Rain Water

## Optimal Solution — O(n) | O(1)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {

        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int total = 0;

        while (l < r) {

            if (height[l] <= height[r]) {

                if (lmax > height[l])
                    total += lmax - height[l];
                else
                    lmax = height[l];

                l++;
            }
            else {

                if (rmax > height[r])
                    total += rmax - height[r];
                else
                    rmax = height[r];

                r--;
            }
        }

        return total;
    }
};
```

### Explanation

Water above an index is:

```text
min(leftMax, rightMax) - height[i]
```

The two-pointer approach avoids storing both `leftMax` and `rightMax` arrays.

- If `height[l] <= height[r]`, the left side can be processed because the right boundary is at least as high as the current left boundary.
- Otherwise, process the right side.
- `lmax` and `rmax` store the highest bars encountered from each side.

This calculates the trapped water in one pass using constant extra space.

---

## Brute Force — O(n²) | O(1)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int total = 0;

        for (int i = 0; i < n; ++i) {

            int lmax = 0;
            int rmax = 0;

            for (int j = 0; j <= i; ++j)
                lmax = max(lmax, height[j]);

            for (int j = i; j < n; ++j)
                rmax = max(rmax, height[j]);

            total += min(lmax, rmax) - height[i];
        }

        return total;
    }
};
```

---

## Better Approach — O(n) | O(n)

```cpp
class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<int> rmax(n);
        rmax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; --i)
            rmax[i] = max(height[i], rmax[i + 1]);

        int lmax = height[0];
        int total = 0;

        for (int i = 1; i < n; ++i) {

            if (height[i] < lmax && height[i] < rmax[i])
                total += min(lmax, rmax[i]) - height[i];

            lmax = max(lmax, height[i]);
        }

        return total;
    }
};
```

---

## Dry Run

For:

```text
height = [4, 2, 0, 3, 2, 5]
```

Water trapped at each index:

```text
index:   0  1  2  3  4  5
height:  4  2  0  3  2  5
water:   0  2  4  1  2  0
```

Total:

```text
2 + 4 + 1 + 2 = 9
```

**Answer = 9**

---

## Time Complexity

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(n²) | O(1) |
| Better — Prefix/Suffix Maximum | O(n) | O(n) |
| Optimal — Two Pointers | O(n) | O(1) |