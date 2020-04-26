#include <string>
#include <iostream>

using namespace std;

string LCP(string ar[], int n)
{
    int idx = 0;
    bool end_not_found = true;
    while (end_not_found && idx < ar[0].length()) {
        auto c = ar[0][idx];
        for (int i = 0; i < n; ++i) {
            if (ar[i][idx] != c) {
                idx--;
                end_not_found = false;
                break;
            }
        }
        ++idx;
    }
    int LCP_length = idx;
    return LCP_length > 0 ? ar[0].substr(0,LCP_length) : "-1";
}

int main() {
    string test = "test";
    string test_sub = test.substr(0,0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string *arr = new string[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << LCP(arr, n) << endl;
        delete [] arr;
    }
}