from bisect import bisect_left

class MyHashMap:

    def __init__(self):
        self.key = []
        self.value = []

    def put(self, key: int, value: int) -> None:
        if key in self.key:
            idx = bisect_left(self.key, key)
            self.value[idx] = value
        else:
            idx = bisect_left(self.key, key)
            self.key.insert(idx, key)
            self.value.insert(idx, value)

    def get(self, key: int) -> int:
        if key not in self.key: return -1
        else:
            idx = bisect_left(self.key, key)
            return self.value[idx]

    def remove(self, key: int) -> None:
        if key in self.key:
            idx = bisect_left(self.key, key)
            self.key = self.key[:idx] + self.key[idx+1:]
            self.value = self.value[:idx] + self.value[idx+1:]


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)