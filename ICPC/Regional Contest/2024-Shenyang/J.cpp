#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
#define psi pair<string,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

bool cmp(const psi &a,const psi &b){
    return a.second > b.second;
}

void solve(){
    vector<psi> l(4),r(4);
    for(int i = 0;  i < 4; i++) cin >> l[i].first >> l[i].second;
    sort(l.begin(),l.end(),cmp);
    for(int i = 0; i < 4; i++) cin >> r[i].first >> r[i].second;
    sort(r.begin(),r.end(),cmp);

    if(l[0].second > r[0].second) cout << l[0].first << " beats " << r[0].first;
    else cout << r[0].first << " beats " << l[0].first;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}