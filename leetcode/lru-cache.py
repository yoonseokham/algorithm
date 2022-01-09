class LRUCache:
    
    def __init__(self, capacity: int):
        self._size = capacity
        self._data = OrderedDict()
    
    def get(self, key: int) -> int:
        if key in self._data:
            value = self._data[key]
            del self._data[key]
            self._data[key] = value
            return value
        return -1

    def put(self, key: int, value: int) -> None:
        if len(self._data) < self._size or key in self._data:
            if key in self._data:
                del self._data[key]
            self._data[key] = value
        else:
            least_used_key = list(self._data.keys())[0]
            del self._data[least_used_key]
            self._data[key] = value
            

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
