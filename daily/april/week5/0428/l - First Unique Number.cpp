#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class FirstUnique {
private:
    unordered_map<int, int> num_cnt;
    queue<int> fuq;
public:
    FirstUnique(vector<int>& nums) {
        for (auto num : nums) {
            num_cnt[num]++;
            fuq.push(num);
        }
    }
    
    int showFirstUnique() {
        int res = -1;
        while (!fuq.empty()) {
            res = fuq.front();
            if (num_cnt[res] > 1) {
                res = -1;
                fuq.pop();
            } else {
                break;
            }
        }
        return res;
    }
    
    void add(int value) {
        num_cnt[value]++;
        if (num_cnt[value] == 1) fuq.push(value);
    }
};
