#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAX_CONY = 200000;

class myClass {
public:
    myClass(int st, int ps):step(st), pos(ps){};
    int step;
    int pos;
    vector<int> next_pos() {
        return {pos - 1, pos + 1, 2 * pos};
    }
};

int solve1(int conyPosition, int brownPosition) {
    queue<myClass> myQueue;
    int conyStep = 0;
    myQueue.push(myClass(0, brownPosition));
    while (conyPosition <= MAX_CONY) {
        while (myQueue.front().step == conyStep) {
            auto cur = myQueue.front(); myQueue.pop();
            if (cur.pos == conyPosition) return cur.step;
            else {
                auto next_pos = cur.next_pos();
                for (auto np : next_pos) {
                    myQueue.push(myClass(conyStep+1, np));
                }
            }
        }
        conyStep++;
        conyPosition += conyStep;
    }
    return -1;
}

int main() {
    int conyPos, brownPos;
    cin >> conyPos >> brownPos;
    cout << solve1(conyPos, brownPos) << endl;

    return 0;
}