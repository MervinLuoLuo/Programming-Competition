#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 1,0),b(m + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    int suma = accumulate(a.begin() + 1,a.end(), 0ll);
    int sumb = accumulate(b.begin() + 1,b.end(), 0ll);
    sort(a.begin() + 1,a.end(),greater<int>());
    sort(b.begin()+ 1,b.end(),greater<int>());

    if(suma == sumb){
        cout << 1 << endl;
    }
    else if(suma > sumb){
        int p = 1;
        while(suma > sumb){
            suma -= a[p];
            p++;
        }
        cout << p - 1 << endl;
    }
    else {
        int p = 1;
        while(sumb > suma){
            sumb -= b[p];
            p++;
        }
        cout << p - 1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}