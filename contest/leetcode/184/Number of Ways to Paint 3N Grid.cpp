const int mod = 1e9 + 7;

class Solution {
public:
    long long numOfWays(int n) {
        long long type1 = 6, type2 = 6;
        for (int i = 1; i < n; ++i) {
            long long next_1 = (type1 * 2 + type2 * 2) % mod;
            long long next_2 = (type1 * 2 + type2 * 3) % mod;
            type1 = next_1;
            type2 = next_2;
        }
        return (type1 + type2) % mod;
    }
};

int main() {
    Solution S;
    auto ans = S.numOfWays(5000);

    return 0;
}