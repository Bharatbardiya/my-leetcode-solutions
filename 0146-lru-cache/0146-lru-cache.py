class LRUCache:
    d = dict()
    cap = 0
    li = list()

    def __init__(self, capacity: int):
        self.d = dict()
        self.li = list()
        self.cap = capacity

    def get(self, key: int) -> int:
        # print(self.d, self.li, self.cap)
        if key in self.d:
            val = self.d[key]
            self.li.remove(key)
            self.li.append(key)
            return val
        return -1

    def put(self, key: int, value: int) -> None:
        # print("put : ", self.d, self.li, self.cap)
        if key in self.d:
            self.li.remove(key)
            self.li.append(key)
            self.d[key] = value
            return
        if len(self.li)>=self.cap:
            first = self.li.pop(0)
            self.d.pop(first)
        self.li.append(key)
        self.d[key] = value
            

        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)