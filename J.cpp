#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<pair<int, int>> res;
vector<pair<int, pair<int, int>>> g;
int n, m;
long long cost;

int get(int v) {
    return (v == p[v]) ? v : (p[v] = get(p[v]));
}

void unite (int a, int b) {
    a = get(a);
    b = get(b);
    if (rand() & 1) {
        swap(a, b);
    }
    if (a != b) {
        p[a] = b;
    }

}

int main() {
    cin >> n >> m;
    p.resize(n);
    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        a--;
        b--;
        g.push_back({w, {a, b}});
    }

    sort(g.begin(), g.end());
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        a = g[i].second.first;
        b = g[i].second.second;
        w = g[i].first;
        if (get(a) != get(b)) {
            cost += w;
            res.push_back (g[i].second);
            unite (a, b);
        }
    }
    cout << cost << endl;
    return 0;
}