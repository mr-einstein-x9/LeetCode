# Problem 881: Boats to Save People

**Pattern:** Two Pointer — Opposite Ends + Greedy

## Intuition

We need to save everyone using the **minimum number of boats**.

Each boat can carry **at most two people**, and their total weight cannot exceed `limit`.

For example:

```text
people = [3, 2, 2, 1]
limit = 3
```

Sort the array:

```text
[1, 2, 2, 3]
 ↑        ↑
light    heavy
```

We always look at the **heaviest person** first.

Why?

The heaviest person must use a boat anyway.

Now we have two choices:

* Can the **lightest person** go with them?
* If yes → put both in the same boat.
* If no → the heaviest person must go alone.

This gives us a greedy strategy.

## Why This Pattern?

The key observation is:

> **The heaviest person should always be assigned a boat.**

After sorting:

```text
i → lightest person
j → heaviest person
```

We check:

```cpp
people[i] + people[j] <= limit
```

If they fit together:

```text
lightest + heaviest → one boat
```

So both people are removed:

```cpp
i++;
j--;
```

If they don't fit:

```text
lightest + heaviest > limit
```

Then the heaviest person **cannot share a boat with anyone**, because everyone else is at least as heavy as the lightest person.

Therefore, the heaviest person must go alone:

```cpp
j--;
```

In both cases, we use exactly **one boat**.

## Approach

1. Sort `people`.
2. Set `i = 0` for the lightest person.
3. Set `j = n - 1` for the heaviest person.
4. Check whether `people[i] + people[j] <= limit`.
5. If they fit:

   * Use one boat for both.
   * Move both pointers.
6. Otherwise:

   * The heaviest person goes alone.
   * Move only `j`.
7. Increment the boat count in either case.
8. Continue until everyone has been assigned a boat.

## Example

Consider:

```text
people = [3, 2, 2, 1]
limit = 3
```

After sorting:

```text
[1, 2, 2, 3]
 ↑        ↑
 i        j
```

### Step 1

```text
1 + 3 = 4
```

`4 > 3`, so they cannot share.

The heaviest person `3` must go alone:

```text
[1, 2, 2, 3]
 ↑        ↑
 i        j
```

```text
boats = 1
```

### Step 2

Now:

```text
2 + 2 = 4
```

Again, they cannot share.

The heavier `2` goes alone:

```text
boats = 2
```

### Step 3

Now:

```text
2 + 1 = 3
```

They can share:

```text
[1, 2]
```

```text
boats = 3
```

Final answer:

```text
3 boats
```

## Why Can the Heaviest Person Go Alone?

Suppose:

```text
people[j] + people[i] > limit
```

Since `people[i]` is the **lightest** remaining person, every other remaining person weighs at least as much:

```text
people[k] >= people[i]
```

Therefore:

```text
people[j] + people[k] >= people[j] + people[i] > limit
```

So the heaviest person cannot share a boat with **anyone**.

Hence:

```cpp
--j;
```

is guaranteed to be correct.

## Why Do We Move Both Pointers When They Fit?

Suppose:

```text
people[i] + people[j] <= limit
```

We can safely put them together.

Since `people[j]` is the heaviest remaining person, pairing them with the lightest person is the best use of that boat.

Once they are together:

```text
i++
j--
```

Both people are removed from consideration.

## Algorithm

```text
sort people

i = 0
j = n - 1
boats = 0

while i <= j:

    if lightest + heaviest <= limit:
        i++
        j--

    else:
        j--

    boats++
```

Notice that `boats++` happens in **both cases** because every iteration uses exactly one boat.

## Complexity

* **Time:** `O(n log n)`
* **Space:** `O(1)` auxiliary space

Sorting takes:

```text
O(n log n)
```

The two pointers then move through the array once:

```text
O(n)
```

Therefore:

```text
O(n log n) + O(n) = O(n log n)
```

## Code

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        sort(people.begin(), people.end());

        int i = 0;
        int j = n - 1;
        int ans = 0;

        while (i <= j) {

            if (people[i] + people[j] <= limit) {
                ++i;
                --j;
            }
            else {
                --j;
            }

            ++ans;
        }

        return ans;
    }
};
```

## Key Takeaway

> **Always handle the heaviest person first.**

For every heaviest person:

```text
Can heaviest + lightest fit?
        ↓
      YES                    NO
       ↓                      ↓
  Put both together     Heaviest alone
       ↓                      ↓
   i++, j--                  j--
```

The greedy idea is:

> **If the heaviest person can share with the lightest, pair them. Otherwise, the heaviest person must go alone.**

This is why sorting + two pointers gives an `O(n log n)` solution.
