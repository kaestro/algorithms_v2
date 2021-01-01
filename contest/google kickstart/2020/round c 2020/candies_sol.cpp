#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Node {
    long long sum, sumA, size;
    void init(ll value) {
        sum = sumA = value;
        size = 1;
    }
    void merge(Node L, Node R) {
        size = L.size + R.size;
        sum = L.sum + R.sum;
        sumA = L.sumA + R.sumA + (long long) R.sum * L.size;
    }
};

void test_case(){
    int n, q;
    int total = 0;
    scanf("%d%d", &n, &q);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if (i % 2) {
            a[i] *= -1;
        }
    }
    int B = 1;
    while (B <= n) {
        B *= 2;
    }
    vector<Node> tree(2 * B);
    for (int i = 0; i < B; ++i) {
        tree[B + i].init(0);
    }
    for (int i = 1; i <= n; ++i) {
        tree[B +i].init(a[i]);
    }
    for (int i = B - 1; i >= 1; --i) {
        tree[i].merge(tree[2 * i], tree[2 * i + 1]);
    }

    while (q--) {
        char type;
        scanf(" %c", &type);
        if (type == 'U') {
            int id;
            ll value;
            scanf("%d%lld", &id, &value);
            if (id %2) value *= -1;
            tree[B + id].init(value);
            for (int i = (B + id) / 2; i >= 1; i /= 2) {
                tree[i].merge(tree[2 * i], tree[2 * i + 1]);
            }
        } else {
            int L, R;
            scanf("%d%d", &L, &R);
            bool sign = L % 2;
            L += B;
            R += B;
            Node left, right;
            left = tree[L];
            right = tree[R];
            while (L + 1 < R) {
                if (L % 2) {
                    left.merge(left, tree[L + 1]);
                }
                if (R % 2) {
                    right.merge(tree[R - 1], right);
                }
                L /= 2;
                R /= 2;
            }
            Node answer = left;
            if (!single) {
                answer.merge(left, right);
            }

            if (sign) {
                answer.sumA *= -1;
            }
            total += answer.sumA;
        }
    }
    printf("%lld\n", total);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int nr = 0; nr <= T; ++nr) {
        printf("Case #%d: ", nr);
        test_case();
    }
    return 0;
}