#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n;
class Emp {
public:
    int a, b, id;
};
vector<Emp> e;
vector<int> pos, ans, tmp;

bool check(int mid) {
    if (mid == 0) return 1;

    tmp.clear();
    int cnt = 0;
    int lcnt = 0;

    size_t i = 0;
    while (i < e.size() && cnt < mid) {
        vector<Emp> cur;
        size_t j = i;
        while (j < e.size() && e[j].a == e[i].a) {
            cur.push_back(e[j]);
            ++j;
        }

        int fin = 0;
        int res = min((int)cur.size(), mid - cnt);

        for (int t = res; t >= 1; --t) {
            int need = mid - lcnt - t;
            if (need < 0) need = 0;
            if (need <= cur[t - 1].b) {
                fin = t;
                break;
            }
        }

        for (int k = 0; k < fin; ++k) {
            tmp.push_back(cur[k].id);
        }

        cnt += fin;
        lcnt += fin;

        i = j;
    }

    return cnt == mid;
}

void solve() {
    cin >> n;
    e.clear(); e.resize(n);
    int maxl = 0;

    for (int i = 0; i < n; i++) {
        cin >> e[i].a >> e[i].b;
        maxl = max(maxl, e[i].a);
        e[i].id = i + 1;
    }

    sort(e.begin(), e.end(), [](Emp x, Emp y) {
        if (x.a != y.a) return x.a < y.a;
        return x.b > y.b;
    });

    ans.clear();
    int l = 0, r = n + 1;
    while (l != r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
            ans = tmp;
        } else {
            r = mid;
        }
    }

    cout << l << endl;
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
