#include <bits/stdc++.h>

using namespace std;

int const inf = 1e9 + 7;

vector<int> used, used1, ord, comp;
int n, l, r, cnt, col;
vector<vector<pair<int, int>>> g, h;
int max_color;

void dfs1(int v, int d) {
    used[v] = 1;
    cnt++;
    for (auto to : g[v]) {
        int u = to.first;
        int w = to.second;
        if (!used[u] && w <= d) {
            dfs1(u, d);
        }
    }
    ord.push_back(v);
}

void dfs2(int v, int d) {
    used[v] = 1;
    comp[v] = col;
    cnt++;
    for (auto to : h[v]) {
        int u = to.first;
        int w = to.second;
        if (!comp[u] && w <= d) {
            dfs2(u, d);
        }
    }
}


bool ok(int d) {
    dfs1(0, d);
    if (cnt < n) {
        return false;
    }
    cnt = 0;
    used.assign(n, 0);
    col = 1;
    int v = ord[ord.size() - 1];
    dfs2(v, d);
    return cnt >= n;
}

int main() {
    freopen ("avia.in", "r", stdin);
    freopen ("avia.out", "w", stdout);
    cin >> n;
    g.resize(n, vector<pair<int, int>>());
    h.resize(n, vector<pair<int, int>>());
    used.resize(n, 0);
    comp.resize(n, 0);
    int a;
    l = inf;
    r = 0;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            cin >> a;
            if (u != v) {
                g[u].emplace_back(v, a);
                h[v].emplace_back(u, a);
                l = min(l, a);
                r = max(r, a);
            }
        }
    }
    l--;
    while (r - l > 1) {
        int m = (r + l)/2;
        if (ok(m)) {
            r = m;
        } else {
            l = m;
        }
        used.assign(n, 0);
        comp.assign(n, 0);
        ord.resize(0);
        cnt = 0;
    }
    cout << r;
    return 0;
}

