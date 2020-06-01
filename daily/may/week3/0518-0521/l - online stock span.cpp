#include <vector>

using namespace std;

class StockSpanner {
private:
    vector<pair<int,int>> nums;
public:
    StockSpanner() {
        nums.clear();
    }
    
    int next(int price) {
        int bigger_idx = nums.size() - 1;
        while (bigger_idx > -1 && nums[bigger_idx].first <= price) {
            bigger_idx = nums[bigger_idx].second;
        }
        nums.push_back({price, bigger_idx});
        
        return nums.size() - nums.back().second - 1;
    }
};