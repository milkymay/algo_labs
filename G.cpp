#include <bits/stdc++.h>

using namespace std;

vector<int> used, ord, color, comp;
int n, m, col;
vector<vector<int>> g, h;
//vector<set<int>> info;
map<string, int> names;
map<int, string> nums;

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
    n = 2 * n;
    g.resize(n, vector<int>());
    h.resize(n, vector<int>());
//    info.resize(n, set<int>());
    used.resize(n, 0);
    color.resize(n, 0);
    comp.resize(n, 0);
    string name;
    for (int i = 0; i < n; i += 2) {
        cin >> name;
        names['+'+name] = i;
        names['-'+name] = i + 1;
        nums[i] = name;
        nums[i + 1] = name;
    }
    string a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> b;
        int _a = names[a] % 2 == 0 ? names[a] + 1 : names[a] - 1;
        int _b = names[b] % 2 == 0 ? names[b] + 1 : names[b] - 1;
        g[names[a]].push_back(names[b]);
        g[_b].push_back(_a);
        h[names[b]].push_back(names[a]);
        h[_a].push_back(_b);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    used.resize(n, 0);
    col = 1;
    for (int i = (int) ord.size() - 1; i >= 0; i--) {
        int v = ord[i];
        if (!comp[v]) {
            dfs2(v);
            col++;
        }
    }

    vector<string> ans;
    for (int v = 0; v < n; v += 2) {
        if (comp[v] == comp[v + 1]) {
            cout << "-1";
            return 0;
        }
        if (comp[v] > comp[v + 1]) {
            ans.push_back(nums[v]);
        }
    }

    cout << ans.size() << "\n";
    for (const auto& c : ans) {
        cout << c << "\n";
    }
    return 0;
}