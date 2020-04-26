#include <iostream>
#include <string>

using namespace std;

string smallest_window_st(const string str, const string txt);
void set_txtcnt(int txt_cnt[], const string& txt);
int first_window_st(const string& str, const string& txt, int str_cnt[], const int txt_cnt[]);

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str, txt;
        cin >> str >> txt;
        cout << smallest_window_st(str, txt) << endl;
    }
	return 0;
}

string smallest_window_st(const string str, const string txt) {
    if (str.length() < txt.length()) return "-1";
    int window_cnt[26] = {0};
    int txt_cnt[26] = {0};
    int win_cnt[26] = {0};
    set_txtcnt(txt_cnt, txt);
    int s_len = str.length(), t_len = txt.length();
    int end_idx;

    string res;
    if ((end_idx = first_window_st(str, txt, win_cnt, txt_cnt)) == -1) res = "-1";
    else {
        int start_idx = 0;
        res = str.substr(0, end_idx+1);
        bool is_window = true;
        while (start_idx < s_len - t_len && end_idx < s_len) {
            if (is_window) {
                int idx = str[start_idx] - 'a';
                start_idx++;
                if (txt_cnt[idx] > 0) {
                    win_cnt[idx]--;
                    if (win_cnt[idx] < txt_cnt[idx]) is_window = false;
                }

            } else {
                end_idx++;
                int char_idx = str[end_idx] - 'a';
                if (txt_cnt[char_idx] > 0) {
                    win_cnt[char_idx]++;
                    if (win_cnt[char_idx] == txt_cnt[char_idx]) is_window = true;
                }
            }

            if (is_window){
                if (end_idx - start_idx + 1 < res.length()) {
                    res = string(str.begin() + start_idx, str.begin() + end_idx + 1);
                }
            }
        }
    }

    return res;
}

void set_txtcnt(int txt_cnt[], const string &txt) {
    for (auto c : txt) {
        txt_cnt[c - 'a']++;
    }
}

int first_window_st(const string& str, const string& txt, int str_cnt[], const int txt_cnt[]) {
    int standard = 0;
    for (int i = 0; i < 26; ++i) {
        if (txt_cnt[i] > 0) {
            standard |= 1 << i;
        }
    }

    int passed = 0;
    int res;
    for (res = 0; res < str.length(); ++res){
        int idx = str[res] - 'a';
        str_cnt[idx]++;
        if (txt_cnt[idx] && str_cnt[idx] >= txt_cnt[idx]) {
            passed |= 1 << idx;
            if (standard == passed) break;
        }
    }

    return res == str.length() ? -1 : res;
}