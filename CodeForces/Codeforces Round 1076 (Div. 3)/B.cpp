#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mark = 1;
    while(mark <= n && a[mark] == n - mark + 1) mark++;
    int p = -1;
    for(int i = mark; i <= n; i++){
        if(a[i] == n - mark + 1) p = i;
    }
    for(int i = 1; i < mark; i++) cout << a[i] << " ";
    if(p != -1){
        for(int i = p; i >= mark; i--) cout << a[i] << " ";
        for(int i = p + 1; i <= n; i++) cout << a[i] << " ";
    }

    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}