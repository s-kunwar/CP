#include <bits/stdc++.h>
using namespace std;

struct Node {
    int xr;
    int win; // 0 = left wins, 1 = right wins
};

int n, q;
int N;
vector<int> a;
vector<Node> seg;
vector<int> sz;

Node mergeNode(const Node &L, const Node &R) {
    Node res;
    res.xr = L.xr ^ R.xr;
    if (L.xr > R.xr) res.win = 0;
    else if (L.xr < R.xr) res.win = 1;
    else res.win = 0; // tie → left wins
    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx].xr = a[l];
        seg[idx].win = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(idx << 1, l, m);
    build(idx << 1 | 1, m + 1, r);
    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx].xr = val;
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m) update(idx << 1, l, m, pos, val);
    else update(idx << 1 | 1, m + 1, r, pos, val);
    seg[idx] = mergeNode(seg[idx << 1], seg[idx << 1 | 1]);
}

int queryAbove(int idx, int l, int r, int pos) {
    if (l == r) return 0;
    int m = (l + r) >> 1;
    if (pos <= m) {
        if (seg[idx].win == 1)
            return sz[idx << 1 | 1] + queryAbove(idx << 1, l, m, pos);
        else
            return queryAbove(idx << 1, l, m, pos);
    } else {
        if (seg[idx].win == 0)
            return sz[idx << 1] + queryAbove(idx << 1 | 1, m + 1, r, pos);
        else
            return queryAbove(idx << 1 | 1, m + 1, r, pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        N = 1 << n;

        a.assign(N + 1, 0);
        for (int i = 1; i <= N; i++) cin >> a[i];

        seg.assign(4 * N, {0, 0});
        sz.assign(4 * N, 0);

        for (int i = 1; i < 4 * N; i++) sz[i] = 0;
        for (int i = 0; i < N; i++) sz[N + i] = 1;
        for (int i = N - 1; i > 0; i--) sz[i] = sz[i << 1] + sz[i << 1 | 1];

        build(1, 1, N);

        while (q--) {
            int b, c;
            cin >> b >> c;
            int old = a[b];
            a[b] = c;
            update(1, 1, N, b, c);
            cout << queryAbove(1, 1, N, b) << '\n';
            a[b] = old;
            update(1, 1, N, b, old);
        }
    }
    return 0;
}
