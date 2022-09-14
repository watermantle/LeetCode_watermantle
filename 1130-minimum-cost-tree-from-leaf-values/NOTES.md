similar to [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/).
​
The question is equal to:
​
Given an array A, choose two neighbors in the array a and b,
we can remove the smaller one min(a,b) and the cost is a * b.
What is the minimum cost to remove the whole array until only one left?
​
To remove a number a, it needs a cost a * b, where b >= a.
So a has to be removed by a bigger number.
We want minimize this cost, so we need to minimize b.
​
b has two candidates, the first bigger number on the left,
the first bigger number on the right.
​
The cost to remove a is a * min(left, right).