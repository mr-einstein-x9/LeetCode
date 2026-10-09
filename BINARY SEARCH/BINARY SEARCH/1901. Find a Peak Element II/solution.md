# Find a Peak Element II

## Optimal Solution — O(m log n) | O(1)

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = n - 1;

        while (low <= high) {
            int col = low + (high - low) / 2;
            int row = findIndex(mat, m, col);

            int left = col > 0 ? mat[row][col - 1] : -1;
            int right = col < n - 1 ? mat[row][col + 1] : -1;

            if (mat[row][col] > left && mat[row][col] > right)
                return {row, col};

            if (left > mat[row][col])
                high = col - 1;
            else
                low = col + 1;
        }

        return {-1, -1};
    }

    int findIndex(vector<vector<int>>& mat, int m, int col) {
        int maxValue = -1;
        int index = -1;

        for (int i = 0; i < m; ++i) {
            if (mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }

        return index;
    }
};
```

### Explanation

Binary search is performed on columns. For each middle column, find its maximum element, which is guaranteed to be greater than its vertical neighbors.

- If it is also greater than its left and right neighbors, it is a peak.
- If the left neighbor is greater, search the left half.
- Otherwise, search the right half.

Each column search takes `O(m)` time, and binary search examines `O(log n)` columns.

---

## Brute Force — O(m × n) | O(1)

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool peak = true;

                if (i > 0 && mat[i][j] <= mat[i - 1][j])
                    peak = false;

                if (i < m - 1 && mat[i][j] <= mat[i + 1][j])
                    peak = false;

                if (j > 0 && mat[i][j] <= mat[i][j - 1])
                    peak = false;

                if (j < n - 1 && mat[i][j] <= mat[i][j + 1])
                    peak = false;

                if (peak)
                    return {i, j};
            }
        }

        return {-1, -1};
    }
};
```

---

## Dry Run

For:

```text
mat = [
    [10, 20, 15],
    [21, 30, 14],
    [ 7, 16, 32]
]
```

1. `low = 0`, `high = 2`, so `col = 1`.
2. The maximum element in column `1` is `30` at `(1, 1)`.
3. Its neighbors are `21` (left), `14` (right), `20` (up), and `16` (down).
4. Since `30` is greater than all four neighbors, it is a peak.

**Answer = `[1, 1]`**

---

## Time Complexity

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(m × n) | O(1) |
| Optimal — Binary Search on Columns | O(m log n) | O(1) |