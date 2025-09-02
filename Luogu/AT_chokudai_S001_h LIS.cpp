#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
const int maxn = 1e9;
const int INF = 1e18;


void solve() {
    int n;cin >> n;
    vector<int> a(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> st(n + 1);
    int ans = 1;
    st[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] > st[ans]) st[++ans] = a[i];
        else{
            int tmp = lower_bound(st.begin() + 1,st.begin() + 1 + ans, a[i]) - st.begin();
            st[tmp] = a[i];
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;//cin >> t;
    while (t--) solve();
    return 0;
}