#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Trie {
private:
    unordered_map<char, Trie*> ct_map;
    string max_prefix = "";
    bool isPrefix = false;
public:
    string get_max_prefix() {
        return max_prefix;
    }

    void first_Trie(string input) {
        auto cur = this;
        for (int i = 0; i < input.length(); ++i) {
            auto c = input[i];
            cur->ct_map[c] = new Trie();
            cur = cur->ct_map[c];
            cur->isPrefix = true;
        }
        max_prefix = input;
    }

    void create_Trie(string input) {
        auto cur = this;
        bool checked_pref = false;
        for (int i = 0; i < input.length(); ++i) {
            auto c = input[i];
            if (cur->ct_map.find(c) == cur->ct_map.end()) {
                cur->ct_map[c] = new Trie();
            }
            cur = cur->ct_map[c];
            if (!checked_pref && !cur->isPrefix) {
                checked_pref = true;
                if (max_prefix.length() > input.substr(0,i).length()) {
                    max_prefix = input.substr(0,i);
                }
            }
        }
    }
};

bool comp_strlen(string& lhs, string &rhs) {
    return lhs.length() < rhs.length();
}

string LCP(string ar[], int n)
{
    sort(ar, ar + n, comp_strlen);
    Trie *root = new Trie();
    root->first_Trie(ar[0]);
    for (int i = 0; i < n; ++i) {
        root->create_Trie(ar[i]);
    }
    auto ans = root->get_max_prefix();
    return ans != "" ? ans : "-1";
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