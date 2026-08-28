# Problem 11: Container With Most Water

**Pattern:** Two Pointer — Opposite Ends

## Intuition

We have vertical lines, and we need to find **two lines that can hold the maximum amount of water**.

The amount of water between two lines depends on:

```text
Area = height × width
```

The height is limited by the **shorter line**:

```text
Area = min(h[left], h[right]) × (right - left)
```

We start with the widest possible container:

```text
h = [1, 8, 6, 2, 5, 4, 8, 3, 7]

     ↑                       ↑
     left                   right
```

Now we have to decide which pointer to move.

### Which Pointer Should We Move?

Suppose:

```text
h[left] < h[right]
```

The left line is shorter, so it is limiting the amount of water.

If we move `right` inward, the width becomes smaller but the limiting height is still `h[left]`.

So there is **no chance of getting a larger area** by moving `right`.

Therefore, we move the **shorter line**:

```cpp
if (h[left] < h[right])
    left++;
else
    right--;
```

This gives us a simple rule:

> **Always move the pointer pointing to the shorter line.**

## Why This Pattern?

The problem requires choosing two positions, and the area depends on the distance between them.

So we can place two pointers at the **opposite ends** and gradually move them inward.

The important observation is:

> The shorter line limits the container, so we move the shorter line to search for a potentially taller one.

This allows us to avoid checking every possible pair.

## Approach

1. Set `left = 0` at the beginning.
2. Set `right = n - 1` at the end.
3. Calculate the current area:

   ```cpp
   min(h[left], h[right]) * (right - left)
   ```
4. Update `maxArea`.
5. Compare the two heights:

   * If `h[left] < h[right]`, move `left`.
   * Otherwise, move `right`.
6. Continue until `left >= right`.
7. Return `maxArea`.

## Algorithm

```text
left = 0
right = n - 1
maxArea = 0

while left < right:

    width = right - left
    height = min(h[left], h[right])

    currentArea = width × height
    update maxArea

    if left height < right height:
        move left forward
    else:
        move right backward

return maxArea
```

## Example

For:

```text
[1, 8, 6, 2, 5, 4, 8, 3, 7]
```

Initially:

```text
left = 0     right = 8

height = min(1, 7) = 1
width  = 8

area = 1 × 8 = 8
```

Since `1 < 7`, move `left`:

```text
left → 1
```

Now:

```text
height = min(8, 7) = 7
width  = 7

area = 7 × 7 = 49
```

Continue moving the pointer corresponding to the shorter line.

The maximum area found is:

```text
49
```

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`

Each pointer moves only toward the other pointer, so we make at most `n` moves.

## Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0, j = h.size() - 1;
        int maxArea = INT_MIN;

        while (i < j) {
            int currArea = min(h[i], h[j]) * (j - i);
            maxArea = max(currArea, maxArea);

            if (h[i] < h[j])
                i++;
            else
                j--;
        }

        return maxArea;
    }
};
```

## Key Takeaway

> **Container area = shorter height × distance.**

Since the **shorter line limits the area**, always move the pointer at the shorter line.

```text
shorter line → move it
```

This reduces the solution from checking every pair (`O(n²)`) to a single two-pointer pass (`O(n)`).
