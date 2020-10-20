#include <bits/stdc++.h>

using namespace std;

vector<int> used;
vector<int> ord;
int n, m;
vector<vector<int>> g;

void dfs(int v) {
    used[v] = 1;
    for (auto to : g[v]) {
        if (used[to] == 0) {
            dfs(to);
        } else if (used[to] == 1) {
            cout << -1;
            exit(0);
        }
    }
    used[v] = 2;
    ord.push_back(v);
}

void top_sort() {
    for (int v = 0; v < n; v++) {
        if (used[v] == 0) {
            dfs(v);
        }
    }
    reverse(ord.begin(), ord.end());
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<int>());
    used.resize(n, 0);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    top_sort();
    for (auto c : ord) {
        cout << c + 1 << " ";
    }
    return 0;
}
