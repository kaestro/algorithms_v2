#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<int> s_ctr, g_ctr;
public:
    string getHint(string secret, string guess) {
        s_ctr.resize(10, 0);
        g_ctr.resize(10, 0);
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                s_ctr[secret[i] - '0']++;
                g_ctr[guess[i] - '0']++;
            }
        }
        
        for (int i = 0; i < 10; ++i) {
            cows += min(s_ctr[i], g_ctr[i]);
        }
        string ans = "";
        ans += to_string(bulls);
        ans.push_back('A');
        ans += to_string(cows);
        ans.push_back('B');
        return ans;
    }
};

int main() {
    Solution S;
    string secret = "1123", guess = "0111";

    auto ans = S.getHint(secret, guess);
    return 0;
}