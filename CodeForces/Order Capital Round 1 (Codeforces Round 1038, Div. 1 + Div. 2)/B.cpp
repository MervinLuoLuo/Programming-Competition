#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
class node{
    public:
    int a,b,c,d;
};

void solve(){
    int n;cin >> n;
    vector<node> a(n);
    for(int i = 0; i < n ;i++) cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    
    int ans = 0;
    for(auto it : a){
        if(it.a > it.c) ans += it.a - it.c;

        if(it.b > it.d) ans += it.b - it.d + (it.a - abs(min(it.c - it.a,0LL)));
    }
    cout << ans << endl;
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