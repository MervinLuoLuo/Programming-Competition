/*https://codeforces.com/problemset/problem/2086/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),d(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n ;i++) cin >> d[i];

    set<int> st;
    for(int i = 1; i <= n; i++){
        while(st.find(d[i]) == st.end()){
            st.insert(d[i]);
            d[i] = a[d[i]];
        }
        cout << st.size() << " ";
    }
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