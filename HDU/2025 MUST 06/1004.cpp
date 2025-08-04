#include <bits/stdc++.h>
using namespace std;

int getLIS(const vector<int>& a) {
    vector<int> d;
    for (int x : a) {
        auto it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end()) {
            d.push_back(x);
        } else {
            *it = x;
        }
    }
    return d.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int lis = getLIS(a);
        int res = 2 * (n - lis);
        cout << res << '\n';
    }
    return 0;
}
