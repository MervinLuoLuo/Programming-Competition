#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

struct BIT {
    int n;
    vector<int> t;
    BIT(int _n): n(_n), t(n+1, 0) {}

    void update(int i, int v=1) {
        for (; i <= n; i += i & -i)
            t[i] += v;
    }

    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += t[i];
        return s;
    }
};

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1),b (n + 1),vis(n + 1);
    for(int i = 1;  i<= n; i++) cin >> a[i];
    for(int i = 1;  i<= n; i++) cin >> b[i];
    
    vector<int> posB(n + 1);
    for(int i = 1;i <= n; i++){
        posB[b[i]] = i;
    }

    BIT bit(n);
    vector<int> ans (n + 1);
    for(int x = 1; x <= n;x++){
        int l = a[x];
        int pb = posB[l];

        int c = bit.query(pb - 1);
        ans[l] = (x - 1) + (pb - 1) - c;
        bit.update(pb,1);

    }
    for(int i = 1; i <= n; i++) cout << ans[i] <<  " ";
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}