#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    while (k > 0) {
        bool erased = false;
        for (int i = 0; i < number.length() - 1; ++i) {
            if (number[i] < number[i + 1]) {
                number.erase(number.begin() + i);
                k--;
                erased = true;
                break;
            }
        }

        if (!erased) break;
    }

    answer = number.substr(0, number.length() - k);
    return answer;
}