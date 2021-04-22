# Dynamic Programming

Dynamic Programming is the programming paradigm where problems with high time complexity, are optimized where there are __Overlapping Sub-Problems__.

These type of DP problems, can be solved using either:
- Memoization: Recursively, storing visited data.
- Tabulation: Iteratively, constructing unvisited data.

The key difference between Memoization and Tabulation, is not just in how we explore the problem, but it is also the way in which we explore the recursion tree.

Memoization uses Top-Down approach. Where base cases, are required to solve a subproblem, which is hanging from a bigger subproblem and so on and so forth.
Whereas in Tabulation, we preemptively use the base case, to create the solution for the next plausible subproblem.


## Memoization Recipe

Step 1: Making a __Working__ Solution.
- Visualize the Problem as a Tree.
- Implement the tree using Recursion.
- Test it for Accuracy, and Large Sample Tests.

Step 2: Making it __Efficient__.
- Adding a _Memoization_ object.
- Add base case to return memoized values.
- Store returned values into the memo.

Following the above rules, and then after enough practice, one can do both simultaneously.