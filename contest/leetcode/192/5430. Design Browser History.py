class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.idx = 0
        self.size = 1


    def visit(self, url: str) -> None:
        self.history = self.history[0:self.idx + 1]
        self.idx += 1
        self.size = self.idx + 1
        self.history.append(url)


    def back(self, steps: int) -> str:
        if steps > self.idx:
            self.idx = 0
        else:
            self.idx -= steps
        return self.history[self.idx]


    def forward(self, steps: int) -> str:
        if self.idx + steps >= self.size:
            self.idx = self.size - 1
        else:
            self.idx += steps
        return self.history[self.idx]



# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)

if __name__ == "__main__":
    bh = BrowserHistory("leetcode.com")
    print(bh.visit("google.com"))
    print(bh.visit("facebook.com"))
    print(bh.visit("youtube.com"))

    print(bh.back(1))
    print(bh.back(1))
    print(bh.forward(1))

    print(bh.visit("linkedin.com"))
    print(bh.forward(2))
    print(bh.back(2))
    print(bh.back(7))
