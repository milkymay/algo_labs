#include <bits/stdc++.h>

using namespace std;

vector<int> used, ord, color, comp;
int n, m, col;
vector<set<int>> g, h, info;

void dfs1(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (!used[to]) {
            dfs1(to);
        }
    }
    ord.push_back(v);
}

void dfs2(int v) {
    used[v] = 1;
    comp[v] = col;
    for (auto to : h[v]) {
        if (!comp[to]) {
            dfs2(to);
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n, set<int>());
    h.resize(n, set<int>());
    info.resize(n, set<int>());
    used.resize(n, 0);
    color.resize(n, 0);
    comp.resize(n, 0);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        h[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    used.resize(n, 0);
    col = 1;
    for (int i = ord.size() - 1; i >= 0; i--) {
        int v = ord[i];
        if (!comp[v]) {
            dfs2(v);
            col++;
        }
    }
    int cnt = 0;
    for (int v = 0; v < n; v++) {
        for (auto to : g[v]) {
            if (comp[v] != comp[to] && info[comp[v]].find(comp[to]) == info[comp[v]].end()) {
                cnt++;
                info[comp[v]].insert(comp[to]);
            }
        }
    }
    cout << cnt;
    return 0;
}