#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    string cpy1(name.length(), 'A');
    string cpy2(name.length(), 'A');
    int num1 = 0, num2 = 0;
    for (int i = 0; i < name.length(); ++i) {
        num1 += min(name[i] - 'A', 'Z' - name[i] + 1);
        cpy1[i] = name[i];
        if (cpy1 == name) {
            break;
        }
        num1++;
    }

    int j = 0;
    while (true) {
        num2 += min(name[j] - 'A', 'Z' - name[j] + 1);
        cpy2[j] = name[j];
        if (cpy2 == name) break;
        num2++;
        j = j == 0 ? name.length() - 1 : j - 1;
    }

    return min(num1, num2);
}