remember, the **columns** and **rows** are sorted. Hence, the first element is the smallest and the last element is the largest.
​
**Binary search**:
1. every time, get the mid number of the two bounds, the mid number is not necessary the real mid point of the arry, but we can detect if every half is enough for k
2.  If the length of left part is *greater* than k, we need to update right bound to reduce the size of left
3.  If the length of left part is *samller* than k, we need to update left bound to extend the size of left
4.  During the time, we need to keep track of the **samllest number greater than the middle** as R, and **the largest number samller than the middle**.