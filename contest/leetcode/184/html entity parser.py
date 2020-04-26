class Solution:
    def entityParser(self, text: str) -> str:
        i = 0
        ans = ""
        while i < len(text):
            c = text[i]
            if c == '&':
                if text[i:i+4] == "&gt;":
                    ans += ">"
                    i += 4
                elif text[i:i+4] == "&lt;":
                    ans += "<"
                    i += 4
                elif text[i:i+7] == "&frasl;":
                    ans += "/"
                    i += 7
                elif text[i:i+6] == "&apos;":
                    ans += "\'"
                    i += 6
                elif text[i:i+6] == "&quot;":
                    ans += "\""
                    i += 6
                elif text[i:i+5] == "&amp;":
                    ans += "&"
                    i += 5
                else:
                    ans += c
                    i += 1
            else:
                ans += c
                i += 1
        return ans


if __name__ == "__main__":
    S = Solution()
    text = "&amp; is an HTML entity but &ambassador; is not."
    print(S.entityParser(text))
    text = "and I quote: &quot;...&quot;"
    print(S.entityParser(text))
    text = "Stay home! Practice on Leetcode :)"
    print(S.entityParser(text))
    text = "x &gt; y &amp;&amp; x &lt; y is always false"
    print(S.entityParser(text))
    text = "leetcode.com&frasl;problemset&frasl;all"
    print(S.entityParser(text))