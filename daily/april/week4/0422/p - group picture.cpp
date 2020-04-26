#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> datum) {
    int answer = 0;
    string perm = "ACFJMNRT";
    do {
        int flag = true;
        for (auto data : datum) {
            char one = data[0], two = data[2];
            int one_pos = perm.find(one), two_pos = perm.find(two);
            int distance = abs(one_pos - two_pos) - 1;
            char equality = data[3];
            int limit = data[4] - '0';
            if (equality == '=') {
                if (distance != limit) {
                    flag = false;
                    break;
                }
            } else if (equality == '<') {
                if (distance >= limit) {
                    flag = false;
                    break;
                }
            } else if (equality == '>') {
                if (distance <= limit) {
                    flag = false;
                    break;
                }
            }
        }
        answer += flag;
    } while(next_permutation(perm.begin(), perm.end()));
    return answer;
}

int main() {
    vector<string> datum = {"N~F=0", "R~T>2"};
    auto ans = solution(2, datum);
    return 0;
}