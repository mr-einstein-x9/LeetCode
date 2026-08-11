// LeetCode 347. Top K Frequent Elements
// Difficulty: Medium

// Problem:
// We have an array and we have to retrun most frequent (repeating element) and k elements on top of that

// Pattern: Brute force
// Approach:
// - first of all if k == size of (array) , then it means return all elements(uniquely) , if not then
// -
// - now we need to return element according to frequencies
// - so we make a vector of vector bucket of  size of(array)+1 , why because indexing starts from 0 but in array elements strat form 1
// - now in bucket using frequency as index we will store all elements having that frequency
// - for instance : [1,1,2,2,3,3,4,1] in bucket [[],[4],[2,3],[1]]
// - now ground is set we will make new ans vector and start inserting each array elements one-by-one but only k elements
// - now we have k elements we insert having most frequency ,for k = 3 , ans = [1,3 ,2]

// Time Complexity: O(n)
// Space Complexity: O(n)
