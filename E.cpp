#include <bits/stdc++.h>

using namespace std;

int const inf = 22000;

vector<int> used, used1, in, up, cnt, colors;
set<int> ans;
int n, m, t;
vector<vector<pair<int, int>>> g;
int max_color;


void dfs(int v, int e) {
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
        } else {
            dfs(u, to_num.second);
            cnt[v]++;
            up[v] = min(up[v], up[u]);
            if (e != -1 && up[u] >= in[v]) {
                ans.insert(v);
            }
        }
    }
    if (e == -1 && cnt[v] >= 2) {
        ans.insert(v);
    }
}

void paint(int v, int color, int p) {
    used1[v] = 1;
    for (auto u_p : g[v]) {
        int u = u_p.first;
        int e = u_p.second;
        if (e == p) {
            continue;
        }
        if (!used1[u]) {
            if (up[u] >= in[v]) {
                int new_color = ++max_color;
                colors[e] = new_color;
                paint(u, new_color, e);
            } else {
                colors[e] = color;
                paint(u, color, e);
            }
        } else if (in[u] < in[v]) {
            colors[e] = color;
        }
    }
}

void solve() {
    for (int v = 0; v < n; v++) {
        if (!used1[v]) {
            paint(v, max_color, -1);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<pair<int, int>>());
    colors.resize(m, 0);
    used.resize(n, 0);
    cnt.resize(n, 0);
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
            dfs(i, -1);
        }
    }
    used1.resize(n, 0);
    solve();
    cout << max_color << "\n";
    for (auto c : colors) {
        cout << c << " ";
    }
    return 0;
}