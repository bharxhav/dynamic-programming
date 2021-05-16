# Dynamic Programming

## Types of DP

Before we swell onto types of optimization techniques. There are many ways in which DP can be implemented. There are the following I know:
- Iterative Method (Also known as __Bottom Up__ Approach)
- Recursive Methods

### Recursive Sub Classification (My Subclassifications)
#### **Type 1** 
Using Possibility based recursion (Fastest when memory is at stake, since takes O(n ** k), where k is (2, 3, ... 7)). Here only possibilities are taken into account. And we return the result, as a result of reaching successful ENDING. Example for a list `[1, 2, 3, 4]`. We can have a function variable `i` , tracking position of the position in the list. We can have possibilities like :
    - Don't choose the `ith` variable.
    - Choose the `ith` variable, and recurse to next.
    - Choose the `ith` variable, and recurse to same `ith` position.

```python
# Simple Subsequence Sum (Repeat Allowed)
def dp(lst: list, target: int, i: int, stk: list):
    if (i >= len(lst)):
        return False

    if (target == 0)
        return True

    if (target < 0)
        return False

    return dp(lst, target, i, stk) and dp(lst, target-lst[i], i, stk+[lst[i]]) and dp(lst, target-lst[i], i+1, stk+[lst[i]])
```
#### **Type 2**
Using Brute Force method of choosing all elements recurse-iteratively. In each function call, we can loop over the `lst` of numbers, and 

## Optimization Methods

Dynamic Programming is the programming paradigm where problems with high time complexity, are optimized where there are __Overlapping Sub-Problems__.

These type of DP problems, can be solved using either:
- Memoization: Recursively, storing visited data.
- Tabulation: Iteratively, constructing unvisited data.

The key difference between Memoization and Tabulation, is not just in how we explore the problem, but it is also the way in which we explore the recursion tree.



### 1. Memoization

Memoization uses Top-Down approach. Where base cases, are required to solve a subproblem, which is hanging from a bigger subproblem and so on and so forth.
Whereas in Tabulation, we preemptively use the base case, to create the solution for the next plausible subproblem.

Step 1: Making a __Working__ Solution.
- Visualize the Problem as a Tree.
- Implement the tree using Recursion.
- Test it for Accuracy, and Large Sample Tests.

Step 2: Making it __Efficient__.
- Adding a _Memoization_ object.
- Add base case to return memoized values.
- Store returned values into the memo.

Following the above rules, and then after enough practice, one can do both simultaneously.