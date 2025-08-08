#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,H;

bool cmp(pii a, pii b){
    int x = a.first,y = b.first;
    return (x * H - x * x) < (y * H - y * y);
}
void solve(){
    cin >> n >> H;
    vector<pii> a(n);
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        a[i - 1] = {x,i};
    }
    sort(a.begin(),a.end(),cmp);
    for(auto it : a) cout << it.second << " ";
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