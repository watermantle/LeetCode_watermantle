1. Define state: length of increasing subarray to ith item (count # of nums that are less than ith item)
2. Come up with recurrence relation: compare dp[i] and dp[j] + 1 if nums[i] > nums[j] (count one more increasing item)
3. Get the base case: base cases should be 1 for every state as it is the increasing item for themselves