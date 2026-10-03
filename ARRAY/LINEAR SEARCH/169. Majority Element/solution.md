# Majority Element

## Optimal Solution — O(n) | O(1)

### Moore's Voting Algorithm

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (const auto& x : nums) {

            if (count == 0)
                candidate = x;

            if (x == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};
```

### Explanation

The majority element appears **more than `n / 2` times**, so it occurs more often than all other elements combined.

We maintain:

* `candidate` → current possible majority element.
* `count` → its current vote balance.

Same element increases the count, while a different element decreases it. When `count` becomes `0`, we select a new candidate.

Because the majority element cannot be completely cancelled by all other elements, the final candidate is the answer.

---

## Brute Force — O(n²) | O(1)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (nums[i] == nums[j])
                    count++;
            }

            if (count > n / 2)
                return nums[i];
        }

        return -1;
    }
};
```

---

## Better Approach — O(n) | O(n)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> hashMap;

        for (const auto& x : nums)
            hashMap[x]++;

        for (const auto& it : hashMap) {

            if (it.second > n / 2)
                return it.first;
        }

        return -1;
    }
};
```

---

## Dry Run

For:

```text
nums = [2, 2, 1, 1, 1, 2, 2]
```

| `x` | `candidate` | `count` |
| --: | ----------: | ------: |
|   2 |           2 |       1 |
|   2 |           2 |       2 |
|   1 |           2 |       1 |
|   1 |           2 |       0 |
|   1 |           1 |       1 |
|   2 |           1 |       0 |
|   2 |           2 |       1 |

Final:

```text
candidate = 2
```

**Answer = 2**

---

## Time Complexity

| Approach                 |  Time | Space |
| ------------------------ | ----: | ----: |
| Brute Force              | O(n²) |  O(1) |
| Better — Hash Map        |  O(n) |  O(n) |
| Optimal — Moore's Voting |  O(n) |  O(1) |
