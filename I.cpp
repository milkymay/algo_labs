#include <bits/stdc++.h>

using namespace std;

vector<int> used, mins, sel;
vector<pair<int, int>> coord;
int n;
float ans;

int dist(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    used.resize(n, 0);
    coord.resize(n);
    mins.resize(n, INT_MAX);
    sel.resize(n, -1);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        coord[i] = {a, b};
    }
    mins[0] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || mins[j] < mins[v])) {
                v = j;
            }
        }
        used[v] = 1;
        if (v != 0) {
            ans += sqrt(dist(coord[v], coord[sel[v]]));
        }
        for (int to = 0; to < n; to++) {
            if (dist(coord[v], coord[to]) < mins[to]) {
                mins[to] = dist(coord[v], coord[to]);
                sel[to] = v;
            }
        }
    }
    cout << setprecision(11) << ans << endl;
    return 0;
}