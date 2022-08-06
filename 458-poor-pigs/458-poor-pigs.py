class Solution(object):
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        return int(math.ceil(math.log(buckets) / math.log(minutesToTest / minutesToDie + 1)))
        