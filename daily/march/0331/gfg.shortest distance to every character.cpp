#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector <int> shortestDistance(string S, char X) 
{
    int prev = S.find(X);
    vector<int> ans;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == X) {
            if (i == prev) {
                for (int j = 0; j <= prev; ++j) {
                    ans.push_back(i - j);
                }
            } else {
                for (int j = prev+1; j <= i; ++j) {
                    int dist = min(j - prev, i - j);
                    ans.push_back(dist);
                }
            }
            prev = i;
        }
    }

    if (S.back() != X) {
        for (int i = prev+1; i < S.length(); ++i) {
            ans.push_back(i - prev);
        }
    }


    return ans;
}

int main() {
    string str;
    char X;
    cin >> str >> X;
    auto ans = shortestDistance(str, X);
    for (auto num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}