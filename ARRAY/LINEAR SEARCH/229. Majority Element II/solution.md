# Majority Element II

Given an array `nums` of size `n`, find all elements that appear **more than `n / 3` times**.

At most **two elements** can satisfy this condition.

---

## Optimal Solution — O(n) | O(1)

### Moore's Voting Algorithm

```cpp
class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int ele1 = 0, cnt1 = 0;
        int ele2 = 0, cnt2 = 0;

        // Find two possible candidates
        for (const auto& x : nums) {

            if (cnt1 == 0 && ele2 != x) {
                cnt1 = 1;
                ele1 = x;
            }
            else if (cnt2 == 0 && ele1 != x) {
                cnt2 = 1;
                ele2 = x;
            }
            else if (x == ele1) {
                cnt1++;
            }
            else if (x == ele2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Verify candidates
        cnt1 = 0;
        cnt2 = 0;

        for (const auto& x : nums) {
            if (x == ele1)
                cnt1++;
            else if (x == ele2)
                cnt2++;
        }

        vector<int> ans;
        int n = nums.size();

        if (cnt1 > n / 3)
            ans.push_back(ele1);

        if (cnt2 > n / 3)
            ans.push_back(ele2);

        return ans;
    }
};
```

### Explanation

For an element to appear more than `n / 3` times, there can be **at most two such elements**.

Therefore, we maintain two candidates:

* `ele1` with `cnt1`
* `ele2` with `cnt2`

When a third different element appears, all three elements can be cancelled together:

```text
ele1 + ele2 + different element → cancel
```

After finding the two possible candidates, we perform a second pass to **verify their actual frequencies**, because the voting phase only identifies potential candidates.

---

## Brute Force — O(n²) | O(n)

```cpp
class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int> s;

        for (int i = 0; i < n; ++i) {

            int count = 0;

            for (int j = 0; j < n; ++j) {

                if (nums[i] == nums[j])
                    count++;
            }

            if (count > n / 3)
                s.insert(nums[i]);
        }

        return vector<int>(s.begin(), s.end());
    }
};
```

---

## Better Approach — O(n) | O(n)

```cpp
class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> hashMap;
        unordered_set<int> s;

        for (const auto& x : nums) {

            hashMap[x]++;

            if (hashMap[x] > n / 3)
                s.insert(x);
        }

        return vector<int>(s.begin(), s.end());
    }
};
```

---

## Dry Run

For:

```text
nums = [1, 2, 1, 1, 3, 2, 2]
n = 7
n / 3 = 2
```

Candidates after voting:

```text
ele1 = 1
ele2 = 2
```

Verification:

```text
1 → 3 occurrences
2 → 3 occurrences
```

Both satisfy:

```text
frequency > 2
```

Therefore:

```text
answer = [1, 2]
```

---

## Time Complexity

| Approach                 |  Time | Space |
| ------------------------ | ----: | ----: |
| Brute Force              | O(n²) |  O(n) |
| Better — Hash Map        |  O(n) |  O(n) |
| Optimal — Moore's Voting |  O(n) |  O(1) |
