#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int ans;

class my_class {
public:
    my_class():less(0), bigger(0), digit_sum(0){};
    my_class(int num, int ds):less(0), bigger(num), digit_sum(ds){};
    int less, bigger;
    int digit_sum;
    int insert(int rhs) {
        if (rhs > bigger) {
            less = bigger, bigger = rhs;
        } else if (rhs > less) {
            less = rhs;
        }
        ans = max(ans, less + bigger);
    }
};

using my_map = unordered_map<int, my_class>;

int digit_sum(int rhs) {
    int res = 0;
    while (rhs > 0) {
        res += rhs % 10;
        rhs /= 10;
    }
    return res;
}

int PerfectMatch(vector<int> arr, int n) 
{
    ans = -1;
    my_map ds_to_mc;
    for (auto num : arr) {
        int ds = digit_sum(num);
        auto cur = ds_to_mc.find(ds);
        if (cur == ds_to_mc.end()) {
            ds_to_mc[ds] = my_class(num, ds);
        } else {
            cur->second.insert(num);
        }
    }
    return ans;
}

int main() {
    int n = 5;
    vector<int> nums = {
        55, 23, 32, 46, 88
    };

    PerfectMatch(nums, n);

    return 0;
}