#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int time_start_idx = 11;
const int time_length = 12;
const int dura_start_idx = 24;

double time_str_to_int(string time_str) {
    double res = 0;
    time_str = time_str.substr(time_start_idx, time_length);
    res += stod(time_str.substr(0, 2)) * 3600;
    res += stod(time_str.substr(3, 2)) * 60;
    res += stod(time_str.substr(6));
    return res;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<double>> conv_lines;
    for (const auto& line : lines) {
        double start = time_str_to_int(line);
        conv_lines.push_back({start, start + stod(line.substr(dura_start_idx))});
    }
    sort(conv_lines.begin(), conv_lines.end());

    for (int i = 0; i < conv_lines.size(); ++i) {
        double cur_start = conv_lines[i][0];
        int res;
        while (cur_start < conv_lines[i][1]) {
            res = 1;
            for (int j = i + 1; j < conv_lines.size(); ++j) {
                if (cur_start <= conv_lines[j][1] && conv_lines[j][0] <= cur_start + 1) {
                    res++;
                }
            }

            answer = max(answer, res);
            cur_start += 1;
        }
    }
    return answer;
}

int main() {

    vector<string> lines;
    lines = {
        "2016-09-15 01:00:04.001 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };
    auto ans = solution(lines);

    lines = {
        "2016-09-15 01:00:04.002 2.0s",
        "2016-09-15 01:00:07.000 2s"
    };
    ans = solution(lines);

    lines = 
     {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
    };
    ans = solution(lines);
    return 0;
}