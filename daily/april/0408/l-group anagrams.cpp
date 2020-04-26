#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

using vs = vector<string>;
using vvs = vector<vs>;
using mymap = unordered_map<string, int>;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vvs res;
        mymap anagram_to_idx;
        for (auto str : strs) {
            auto anagram = string(str);
            sort(anagram.begin(), anagram.end());
            if (anagram_to_idx.find(anagram) == anagram_to_idx.end()) {
                anagram_to_idx[anagram] = res.size();
                res.push_back({});
            }
            int idx = anagram_to_idx[anagram];
            res[idx].push_back(str);
        }
        return res;
    }
};

int main() {
    Solution S;
    vs strs =  {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = S.groupAnagrams(strs);
    return 0;
}