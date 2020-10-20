#include <bits/stdc++.h>

using namespace std;

int const inf = 22000;

vector<int> used, in, up;
vector<int> ans;
int n, m, t;
vector<vector<pair<int, int>>> g;

void dfs(int v, int p) {
    t++;
    in[v] = t;
    up[v] = t;
    used[v] = 1;
    for (auto to_num : g[v]) {
        int u = to_num.first;
        if (u == p) {
            continue;
        }
        if (used[u]) {
            up[v] = min(up[v], in[u]);
        }
        if (used[u] == 0) {
            dfs(u, v);
            up[v] = min(up[v], up[u]);
            if (up[u] > in[v]) {
                ans.push_back(to_num.second);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<pair<int, int>>());
    used.resize(n, 0);
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
            dfs(i, i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto c : ans) {
        cout << c + 1 << " ";
    }
    return 0;
}
