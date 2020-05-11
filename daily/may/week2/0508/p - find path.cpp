#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

class node {
public:
    node(int x, int y, int num):
        x_pos(x), y_pos(y), idx(num), left(NULL), right(NULL){}
    int x_pos, y_pos;
    int idx;
    node *left, *right;

    void insert(node *rhs) {
        if (rhs->y_pos < y_pos) {
            if (rhs->x_pos < x_pos) {
                if (!left) left = rhs;
                else left->insert(rhs);
            } else {
                if (!right) right = rhs;
                else right->insert(rhs);
            }
        }
    }
};

bool comp(const vector<int> &lhs, const vector<int> &rhs) {
    if (lhs[1] > rhs[1]) return true;
    return false;
}

bool comp_node(const node *lhs, const node *rhs) {
    if (lhs->y_pos > rhs->y_pos) return true;
    return false;
}

void preorder(node *root, vector<int>& ans);
void postorder(node *root, vector<int>& ans);
vector<vector<int>> solution(vector<vector<int>> node_info);

int main() {
    vvi node_info = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    auto ans = solution(node_info);
    return 0;
}

vector<vector<int>> solution(vector<vector<int>> node_info) {
    vector<vector<int>> answer;
    vector<node*> nodes;
    int num_node = node_info.size();
    nodes.reserve(num_node);
    for (int i = 0; i < num_node; ++i) {
        nodes.push_back(new node(node_info[i][0], node_info[i][1], i + 1));
    }

    sort(nodes.begin(), nodes.end(), comp_node);
    node *root = nodes[0];
    for (int i = 1; i < num_node; ++i)
        root->insert(nodes[i]);

    vi preorder_vec; preorder(root, preorder_vec);
    vi postorder_vec; postorder(root, postorder_vec); 

    answer = {preorder_vec, postorder_vec};

    return answer;
}

void preorder(node *root, vector<int>& ans) {
    if (!root) return;
    ans.push_back(root->idx);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

void postorder(node *root, vector<int>& ans) {
    if (!root) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->idx);
}