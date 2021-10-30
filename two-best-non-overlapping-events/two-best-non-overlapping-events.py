class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        time, vals = [], []
        pre, res = 0, 0
        
        for st, et, val in sorted(events, key=lambda x: x[1]):
            pre = max(pre, val)
            idx = bisect.bisect_left(time, st) - 1
            if idx >= 0: val += vals[idx]
            res = max(res, val)
            vals.append(pre)
            time.append(et)
        return res