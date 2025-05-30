/*https://ac.nowcoder.com/acm/contest/20960/1010*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp (pii &a,pii &b){
    return a.first < b.first;
}
void solve(){
    int n, q;cin >> n >> q;
    vector<pii> a(q);
    for(int i = 0; i < q; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end(),cmp);
    //for(int i = 0; i < q; i++) cout << a[i].first << ' ' << a[i].second << endl;
    int l = a[0].first, r = a[0].second, res = 0;
    for(int i = 1; i < q; i++){
        if(a[i].first <= r) r = max(r, a[i].second);
        else{
            res += r + 1 - l;
            l = a[i].first;
            r = a[i].second;
        }
    }
    res += r - l + 1;
    cout << n + 1 -res << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}