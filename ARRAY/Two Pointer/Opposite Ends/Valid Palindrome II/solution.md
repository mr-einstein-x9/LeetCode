# Problem 680: Valid Palindrome II

**Pattern:** Two Pointer — Opposite Ends

## Intuition

A **palindrome** reads the same from both ends.

For example:

```text
"racecar"

r a c e c a r
↑           ↑
left       right
```

We compare characters from both ends:

* If `s[left] == s[right]`, they match, so move both pointers inward.
* If `s[left] != s[right]`, we have found the **first mismatch**.
* We are allowed to delete **at most one character**, so we have only two useful choices:

  * Skip `left`
  * Skip `right`
* If either choice produces a palindrome, return `true`.

### Simple Example

```text
"abca"

a b c a
↑     ↑
```

`a == a`, so move inward.

```text
  b c
  ↑ ↑
```

`b != c`.

We can delete either:

```text
"bca"  → not a palindrome
"abc"  → not a palindrome
```

So the answer is `false`.

Another example:

```text
"abca"

a b c a
↑     ↑
```

If we skip `b`:

```text
a c a
↑   ↑
```

It is a palindrome, so the answer is `true`.

## Why This Pattern?

The problem asks us to compare characters from **both ends**.

That is the main clue for the **Two Pointer — Opposite Ends** pattern.

Instead of checking every possible deletion, we only need to consider a deletion when we find the **first mismatch**.

At that point, there are only **two possibilities**:

```text
Skip left  → check remaining string
Skip right → check remaining string
```

## Approach

1. Put `left` at the beginning of the string.
2. Put `right` at the end.
3. Compare `s[left]` and `s[right]`.
4. If they are equal:

   * Move `left` forward.
   * Move `right` backward.
5. If they are different:

   * Try skipping `left`.
   * Try skipping `right`.
   * If either remaining part is a palindrome, return `true`.
6. If all characters match, return `true`.

We use a helper function `isPalindrome()` to check whether a given range is a palindrome.

## Algorithm

```text
left = 0
right = n - 1

while left < right:

    if s[left] != s[right]:

        check by skipping left
        OR
        check by skipping right

        return the result

    left++
    right--

return true
```

### Why do we check only `left` or `right`?

Suppose:

```text
s[left] != s[right]
```

One character must be removed to fix this mismatch.

The removed character must be **either `s[left]` or `s[right]`**.

There is no reason to remove a character somewhere in the middle because `s[left]` and `s[right]` would still remain different.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)` auxiliary space

The helper function may scan the remaining characters, but it is called only once at the first mismatch.

## Code

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {

            if (s[left] != s[right]) {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }

    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }
};
```

## Key Takeaway

> **Palindrome + compare from both ends → Two Pointers.**

When the first mismatch appears and **one deletion is allowed**, check:

```text
skip left OR skip right
```

That is the main idea of this problem.
