class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self._time = timeToLive
        self._dict = collections.OrderedDict()
        
    def _clean(self, currentTime):
        while self._dict and next(iter(self._dict.values())) <= currentTime:
            self._dict.popitem(last=False)
            
    def generate(self, tokenId: str, currentTime: int) -> None:
        self._clean(currentTime)
        self._dict[tokenId] = currentTime + self._time
        
    def renew(self, tokenId: str, currentTime: int) -> None:
        self._clean(currentTime)
        
        if tokenId not in self._dict:
            return
        self._dict.move_to_end(tokenId)
        self._dict[tokenId] = currentTime + self._time

    def countUnexpiredTokens(self, currentTime: int) -> int:
        self._clean(currentTime)
        return len(self._dict)


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId,currentTime)
# obj.renew(tokenId,currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)