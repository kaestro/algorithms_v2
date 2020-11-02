#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> mypair;
vector<int> petya;

bool comparator (const mypair& lhs, const mypair& rhs) {
    if (lhs.second > rhs.second) return true;

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int numDishes;
        cin >> numDishes;
        petya.clear();

        vector<mypair> dishes = vector<mypair>(numDishes, mypair({0, 0}));
        int minDish = 0;
        for (int i = 0; i < numDishes; ++i) {
            cin >> dishes[i].second;
            dishes[i].first = i;

            if (i == 0 || minDish > dishes[i].second) 
                minDish = dishes[i].second;
        }

        petya.resize(numDishes);
        int maxPetyaSum = 0;
        for (int i = 0; i < numDishes; ++i) {
            cin >> petya[i];
            maxPetyaSum += petya[i];
        }

        if (maxPetyaSum < minDish) {
            cout << maxPetyaSum << endl;
            continue;
        }

        sort(dishes.begin(), dishes.end(), comparator);

        int i = 0;
        int petyaSum = 0;
        int result = dishes[i].second;
        while (i < numDishes - 1) {
            petyaSum += petya[dishes[i].first];
            if (petyaSum < dishes[i + 1].second) {
                i++;
                result = dishes[i].second;
            } else {
                result = min(petyaSum, dishes[i].second);
                break;
            }
        }

        cout << result << endl;
    }
    return 0;
}