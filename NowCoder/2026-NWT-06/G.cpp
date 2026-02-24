#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m,l;cin >> n >> m >> l;
    vector<int> a(n + 1, 0),b(m + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    vector<int> pre(n + 1, 0);
    for(int i = 1;i <= n; i++) pre[i] = pre[i - 1] + a[i];
    int L = 0,R = l;
    int cur = 1;
    while(cur <= n && pre[cur] <= L) cur++;
    if(cur <= n && pre[cur] < R){
        cout << "YES";
        return;
    }

    for(int i = 1; i <= m; i++){
        L = L + b[i], R = R + b[i];
        while(cur <= n && pre[cur] <= L) cur++;
        if(cur <= n && pre[cur] < R){
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}