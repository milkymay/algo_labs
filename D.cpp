#include <bits/stdc++.h>

using namespace std;

int const inf = 22000;

vector<int> used, in, up, colors;
vector<int> ord;
int n, m, t;
vector<vector<pair<int, int>>> g;

int max_color;

void dfs_init(int v, int e) {
    t++;
    in[v] = t;
    up[v] = t;
    used[v] = 1;
    for (auto to_num : g[v]) {
        int u = to_num.first;
        if (to_num.second == e) {
            continue;
        }
        if (used[u]) {
            up[v] = min(up[v], in[u]);
        }
        if (used[u] == 0) {
            dfs_init(u, to_num.second);
            up[v] = min(up[v], up[u]);
            if (up[u] > in[v]) {
                ord.push_back(to_num.second);
            }
        }
    }
}

void paint(int v, int color) {
    colors[v] = color;
    for (auto u_p : g[v]) {
        int u = u_p.first;
        if (colors[u] == 0) {
            if (up[u] > in[v]) {
                max_color++;
                paint(u, max_color);
            } else {
                paint(u, color);
            }
        }
    }
}

void solve() {
    max_color = 0;
    for (int v = 0; v < n; v++) {
        if (colors[v] == 0) {
            max_color++;
            paint(v, max_color);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<pair<int, int>>());
    used.resize(n, 0);
    colors.resize(n, 0);
    in.resize(n, inf);
    up.resize(n, inf);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs_init(i, -1);
        }
    }
    solve();
    cout << max_color << "\n";
    for (auto c : colors) {
        cout << c << " ";
    }
    return 0;
}
