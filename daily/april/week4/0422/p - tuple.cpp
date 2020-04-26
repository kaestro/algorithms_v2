#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(string s) {
    set<string> tuples;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j < s.length() - i; ++j) {
            tuples.insert(s.substr(i, j));
        }
    }
    return tuples.size();
}