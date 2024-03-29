class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        if n == 1: return [i for i in range(10)]
        
        queue = [digit for digit in range(1, 10)]
        
        for level in range(n - 1):
            next_queue = []
            for num in queue:
                tail = num % 10
                next_digits = set([tail + k, tail - k])
                for next_digit in next_digits:
                    if next_digit >= 0 and next_digit < 10:
                        new_num = 10 * num + next_digit
                        next_queue.append(new_num)
            queue = next_queue
        return queue