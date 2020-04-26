#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool helper(string needle, string h_substr) {
    sort(h_substr.begin(), h_substr.end());
    return needle == h_substr;
}

bool isShuffledSubstring(string needle, string haystack) 
{
    int nlen = needle.length(), hlen = haystack.length();
    if (nlen > hlen) return false;
    sort(needle.begin(), needle.end());
    for (int i = 0; i <= hlen - nlen; ++i) {
        if (helper(needle, haystack.substr(i, nlen))) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string needle, haystack;
        cin >> needle >> haystack;

        if (isShuffledSubstring(needle, haystack))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
}