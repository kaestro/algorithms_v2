#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


vector<int> str_to_hash(const string& str) {
    vector<int> res = vector<int>(26);
    for (auto c : str) {
        res[c - 'a']++;
    }
    return res;
}

unordered_map<char, int> str_to_hash2(const string& str) {
    unordered_map<char, int> res;
    for (auto c : str) {
        res[c]++;
    }
    return res;
}

bool helper2(unordered_map<char, int> needle_hash, string h_substr) {
    for (auto c : h_substr) {
        if (needle_hash[c]-- == 0) return false;
    }
    return true;
}

bool helper(vector<int> needle_hash, string h_substr) {
    for (auto c : h_substr) {
        if (needle_hash[c - 'a']-- == 0) return false;
    }
    return true;
}

bool isShuffledSubstring(string needle, string haystack) 
{
    int hlen = haystack.length(), nlen = needle.length();
    if (hlen < nlen) return false;

    vector<int> needle_hash = str_to_hash(needle);
    unordered_map<char, int> needle_map = str_to_hash2(needle);

    for (int i = 0; i < hlen - nlen; ++i) {
        //if (helper(needle_hash, haystack.substr(i, nlen))) return true;
        if (helper2(needle_map, haystack.substr(i,nlen))) return true;
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
    return 0;
}