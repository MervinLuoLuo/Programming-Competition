#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int getVal(int n, int x, int y) {
    if (n == 1) {
        if (x == 1 and y == 1) return 1;
        if (x == 2 and y == 2) return 2;
        if (x == 2 and y == 1) return 3;
        return 4;
    }
    int h = 1LL << (n - 1);       // 半边大小
    int b = 1LL << (2 * (n - 1)); // 每块的数量
    int nx, ny, off;

    if (x <= h and y <= h) {
        nx = x; ny = y; off = 0;
    } else if (x > h and y > h) {
        nx = x - h; ny = y - h; off = b;
    } else if (x > h and y <= h) {
        nx = x - h; ny = y; off = 2 * b;
    } else {
        nx = x; ny = y - h; off = 3 * b;
    }
    return off + getVal(n - 1, nx, ny);
}

pii getPos(int n, int d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 3) return {2, 1};
        return {1, 2};
    }
    int h = 1LL << (n - 1);
    int b = 1LL << (2 * (n - 1));
    int q = (d - 1) / b;
    int d2 = d - q * b;
    auto [x, y] = getPos(n - 1, d2);

    if (q == 0) return {x, y};
    if (q == 1) return {x + h, y + h};
    if (q == 2) return {x + h, y};
    return {x, y + h};
}
void solve(){
    int n, q; cin >> n >> q;
        while (q--) {
            string op; cin >> op;
            if (op == "->") {
                int x, y; cin >> x >> y;
                cout << getVal(n, x, y) << endl;
            } else {
                int d; cin >> d;
                auto [x, y] = getPos(n, d);
                cout << x << " " << y << endl;
            }
        }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}