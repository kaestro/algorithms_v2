#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0, base = 0, size = customers.size();
        if (X >= size) {
            for (int i = 0; i < size; ++i) res += customers[i];
            return res;
        }

        for (int i = 0; i < X; ++i)
            base += customers[i];
        
        for (int i = X; i < size; ++i)
            base += customers[i] * (1 - grumpy[i]);
        
        res = base;
        
        for (int i = 0; i + X < size; ++i) {
            base += customers[i + X] * grumpy[i + X];
            base -= customers[i] * grumpy[i];
            res = max(res, base);
        }

        return res;
    }
};

int main() {
    vector<int> customers =  {1,0,1,2,1,1,7,5};
    vector<int> grumpy =  {0,1,0,1,0,1,0,1};
    Solution S;
    auto ans = S.maxSatisfied(customers, grumpy, 3);
    return 0;
}