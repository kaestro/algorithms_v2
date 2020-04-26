#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    for (auto prior : priorities) {
        pq.push(prior);
    }

    int idx = 0;
    while (true) {
        int first = pq.top(); pq.pop();
        auto it = find(priorities.begin() + idx, priorities.end(), first);
        if (it == priorities.end()) {
            it = find(priorities.begin(), priorities.begin() + idx, first);
        }

        *it = 0;
        answer++;
        if (it - priorities.begin() == location) break;
        idx = it - priorities.begin();
    }

    return answer;
}


int main() {
    vector<int> priorities = {2,1,3,2};
    auto ans = solution(priorities, 2);

    priorities = {1, 8, 1, 9, 1, 1, 1};
    ans = solution(priorities, 0);
    return 0;
}