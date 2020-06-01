#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int num_alpha = 26;

class Solution {
public:
    vector<int> findAnagrams(string line, string pattern) {
        int l_len = line.length(), p_len = pattern.length();
        if (p_len > l_len) return {};

        vector<int> ans;
        vector<int> p_hash(num_alpha);

        for (auto ch : pattern) p_hash[ch - 'a']++;

        int ch_left = p_len;
        for (int i = 0; i < p_len; ++i) {
            int ch_idx = line[i] - 'a';
            if (p_hash[ch_idx]-- > 0) {
                ch_left--;
            }
        }

        if (ch_left == 0) ans.push_back(0);

        for (int i = p_len; i < l_len; ++i) {
            int front_ch_idx = line[i - p_len] - 'a';
            if (++p_hash[front_ch_idx] > 0) ch_left++;
            int back_ch_idx = line[i] - 'a';
            if (p_hash[back_ch_idx]-- > 0) ch_left--;
            if (ch_left == 0) ans.push_back(i + 1 - p_len);
        }

        return ans;
    }
};

int main() {
    Solution s;
    string line, pattern;
    cout << "what's the line you'll test: ";
    cin >> line;
    cout << "what's the pattern you'll test: ";
    cin >> pattern;

    auto ans = s.findAnagrams(line, pattern);

    return 0;
}