# Search a 2D Matrix II

## Optimal Solution — O(m + n) | O(1)

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int i = 0, j = col - 1;

        while (i < row && j >= 0) {

            int curr = matrix[i][j];

            if (curr == target)
                return true;

            if (target < curr)
                j--;
            else
                i++;
        }

        return false;
    }
};
```

### Explanation

Start from the **top-right corner**.

At this position:

- If `target < curr`, move **left** because everything below `curr` is even larger.
- If `target > curr`, move **down** because everything to the left is smaller.
- If equal, the target is found.

Each step eliminates either one row or one column, so at most `m + n` cells are visited.

---

## Brute Force — O(m × n) | O(1)

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; ++i) {

            for (int j = 0; j < col; ++j) {

                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
};
```

---

## Better Approach — O(m log n) | O(1)

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; ++i) {

            int low = 0, high = col - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (matrix[i][mid] == target)
                    return true;

                if (matrix[i][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};
```

---

## Dry Run

For:

```text
matrix =
[
  [1,  4,  7, 11, 15],
  [2,  5,  8, 12, 19],
  [3,  6,  9, 16, 22],
  [10,13, 14, 17, 24],
  [18,21, 23, 26, 30]
]

target = 5
```

Start at the top-right:

```text
15 → 11 → 7 → 4 → 5
```

- `15 > 5` → move left
- `11 > 5` → move left
- `7 > 5` → move left
- `4 < 5` → move down
- `5 == target` → found

**Answer = `true`**

---

## Time Complexity

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(m × n) | O(1) |
| Better — Binary Search | O(m log n) | O(1) |
| Optimal — Staircase Search | O(m + n) | O(1) |