#include <algorithm>

using namespace std;

class my_class {
public:
    my_class():min_idx(10000), min_val(100){};
    int min_idx, min_val;
    void insert(int idx, int val) {
        if (idx < min_idx) {
            min_idx = idx; min_val = val;
        }
    }
};

int maxNumOfChocolates(int arr[], int n, int k) {
    my_class *my_arr = new my_class[k];
    int *arr_sum = new int[n+1];
    arr_sum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        arr_sum[i] = arr_sum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; ++i) {
        my_arr[arr_sum[i] % k].insert(i, arr_sum[i]);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        auto cur = arr_sum[i];
        if (cur % k == 0) res = max(res, cur);
        else {
            auto left_min = my_arr[cur % k].min_val;
            res = max(res, cur - left_min);
        }
    }
    delete my_arr, arr_sum;
    return res / k;
}

int main() {
    int n = 6, k = 3;
    int nums[] = {
        2, 7, 6, 1, 4, 5
    };

    maxNumOfChocolates(nums, n, k);
}