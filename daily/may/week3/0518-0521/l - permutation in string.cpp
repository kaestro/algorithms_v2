#include <string>

using namespace std;

class Solution {
private:
    bool hash_matches(int pat_hash[], int str_hash[]) {
        bool matches = true;
        for (int i = 0; i < 26; ++i) {
            if (pat_hash[i] != str_hash[i]) {
                matches = false;
                break;
            }
        }
        return matches;
    }
public:
    bool checkInclusion(string pattern, string str) {
        int pat_len = pattern.length(), str_len = str.length();
        if (pat_len > str_len) return false;

        int pat_hash[26] = {0}, str_hash[26] = {0};

        for (int i = 0; i < pat_len; ++i) {
            pat_hash[pattern[i] - 'a']++;
            str_hash[str[i] - 'a']++;
        }

        for (int i = 0; i < str_len - pat_len; ++i) {
            if (hash_matches(pat_hash, str_hash)) return true;

            str_hash[str[i] - 'a']--;
            str_hash[str[i + pat_len] - 'a']++;
        }
        if (hash_matches(pat_hash, str_hash)) return true;

        return false;
    }
};