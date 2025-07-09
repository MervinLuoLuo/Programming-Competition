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
    int maxx = 0, cnt = 0;
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] > maxx){
                maxx = a[i][j],cnt = 1;
            }
            else if(a[i][j] == maxx) cnt++;
        }
    
    }
    vector<int> r(n),c(m);
    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            if(a[i][j] == maxx){r[i]++;c[j]++;}
        }
    }
    for(int i  =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(r[i] + c[j] - (a[i][j] == maxx) == cnt){cout <<  maxx - 1  << endl;return;}
        }
    }
    cout << maxx << endl;
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