#include <string>
#include <iostream>

using namespace std;

string compress(string& s)
{
    string cur = s;
    string rest = "";
    while (cur.length() > 1) {
        auto clen = cur.length();
        int i;
        for (i = clen/2; i > 0; --i) {
            if (cur.substr(0,i) == cur.substr(i, i)) {
                if (2*i < clen) rest.insert(0,cur.substr(2*i));
                rest.insert(0,"*");
                cur = cur.substr(0,i);
                break;
            }
        }
        if (i == 0) break;
    }

    return cur + rest;
}

int main() {
    string input = "ababcababcd";
    input = "zzzzzzz";
    auto ans = compress(input);
    cout << ans << endl;
    return 0;
}