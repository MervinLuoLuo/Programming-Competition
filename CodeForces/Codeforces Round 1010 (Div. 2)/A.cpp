/*https://codeforces.com/contest/2082/problem/A*/
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
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> rc(n,0),cc(m,0);
    for(int i = 0;i < n; i++){
        string s;cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
            rc[i] ^= a[i][j];
            cc[j] ^= a[i][j];
        }
    }
    int rcnt = 0, ccnt = 0;
    for(auto it : rc){
        if(it != 0) rcnt++;
    }
    for(auto it : cc){
        if(it != 0) ccnt++;
    }
    cout << max(rcnt,ccnt) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}