#include <string>
#include <vector>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int Pillar = 0, Beam = 1;
const int Destroy = 0, Install = 1;
const int struct_pillar = 1, struct_beam = 2;

vector<vector<int>> answer;
int n;

bool is_valid_pillar(int x_pos, int y_pos);
bool is_valid_beam(int x_pos, int y_pos);
vvi solution(int, vvi);

int main() {
    vvi build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};
    int frame_size = 5;
    //auto ans = solution(frame_size, build_frame);

    build_frame = {{0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1}};
    frame_size = 5;
    auto ans = solution(frame_size, build_frame);

    return 0;
}

vector<vector<int>> solution(int frame_size, vector<vector<int>> orders) {
    n = frame_size;
    answer.resize(n + 1, vector<int>(n + 1));
    for (auto order : orders) {
        int x_pos = order[0], y_pos = order[1], structure = order[2], cmd = order[3];
        if (cmd == Install) {
            bool installable = false;
            if (structure == Pillar) installable = is_valid_pillar(x_pos, y_pos);
            else if (structure == Beam) installable = is_valid_beam(x_pos, y_pos);

            if (installable) answer[x_pos][y_pos] |= (structure + 1);
        } else if (cmd == Destroy) {
            bool destroyable = true;
            answer[x_pos][y_pos] -= (structure + 1);

            if (structure == Pillar) {
                // pillar above it
                if (y_pos < n - 1 && answer[x_pos][y_pos + 1] & struct_pillar) {
                    destroyable = is_valid_pillar(x_pos, y_pos + 1);
                }

                // left up beam
                if (destroyable && x_pos > 0 && answer[x_pos - 1][y_pos + 1] & (struct_beam)) {
                    destroyable = is_valid_beam(x_pos - 1, y_pos + 1);
                }

                // right up beam
                if (destroyable && x_pos < n && answer[x_pos][y_pos + 1] & struct_beam) {
                    destroyable = is_valid_beam(x_pos, y_pos + 1);
                }
            } else if (structure == Beam) {
                if (y_pos < n && answer[x_pos][y_pos] & struct_pillar) {
                    destroyable = is_valid_pillar(x_pos, y_pos);
                }

                if (destroyable && y_pos < n && answer[x_pos + 1][y_pos] & struct_pillar) {
                    destroyable = is_valid_pillar(x_pos + 1, y_pos);
                }

                if (destroyable && x_pos > 0 && answer[x_pos - 1][y_pos] & struct_beam) {
                    destroyable = is_valid_beam(x_pos - 1, y_pos);
                }

                if (destroyable && x_pos < n - 1 && answer[x_pos + 1][y_pos] & struct_beam) {
                    destroyable = is_valid_beam(x_pos + 1, y_pos);
                }
            }

            if (!destroyable) answer[x_pos][y_pos] |= (structure + 1);
        }
    }

    vvi result;
    for (int row = 0; row <= n; ++row) {
        for (int col = 0; col <= n; ++col) {
            if (answer[row][col] & struct_pillar) result.push_back({row, col, Pillar});
            if (answer[row][col] & struct_beam) result.push_back({row, col, Beam});
        }
    }
    return result;
}

bool is_valid_pillar(int x_pos, int y_pos) {
    bool is_valid = false;
    if (y_pos == 0) is_valid = true;
    else if (answer[x_pos][y_pos - 1] & struct_pillar) is_valid = true;
    else {
        if (x_pos > 0 && answer[x_pos - 1][y_pos] & struct_beam) is_valid = true;
        else if (x_pos < n && answer[x_pos][y_pos] & struct_beam) is_valid = true;
    }
    return is_valid;
}

bool is_valid_beam(int x_pos, int y_pos) {
    bool is_valid = false;
    if (answer[x_pos][y_pos - 1] & struct_pillar) is_valid = true;
    else if (answer[x_pos + 1][y_pos - 1] & struct_pillar) is_valid = true;
    else {
        if (x_pos > 0 && x_pos < n - 1 && answer[x_pos - 1][y_pos] & struct_beam
        && answer[x_pos + 1][y_pos] & struct_beam)
            is_valid = true;
    }
    return is_valid;
}