#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int a[35][35];

void solve(){
    int n,m;cin >> n >> m;
    a[0][1] = 1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(j == 1) a[i][j] = a[i - 1][n] + a[i - 1][2];
            else if(j == n) a[i][j] = a[i - 1][n - 1] + a[i - 1][1];
            else a[i][j] = a[i - 1][j - 1] + a[i - 1][j + 1];
        }
    }
    cout << a[m][1] << endl;
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