#include <bits/stdc++.h>

using namespace std;

int const inf = 22000;

vector<int> used, in, up, cnt;
set<int> ord;
int n, m, t;
vector<vector<int>> g;

void dfs(int v, int p) {
    t++;
    in[v] = t;
    up[v] = t;
    used[v] = 1;
    for (auto u : g[v]) {
        if (u == p) {
            continue;
        }
        if (used[u]) {
            up[v] = min(up[v], in[u]);
        } else {
            dfs(u, v);
            cnt[v]++;
            up[v] = min(up[v], up[u]);
            if (p != -1 && up[u] >= in[v]) {
                ord.insert(v);
            }
        }
    }
    if (p == -1 && cnt[v] >= 2) {
        ord.insert(v);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<int>());
    used.resize(n, 0);
    cnt.resize(n, 0);
    in.resize(n, inf);
    up.resize(n, inf);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    cout << ord.size() << "\n";
    for (auto c : ord) {
        cout << c + 1 << " ";
    }
    return 0;
}