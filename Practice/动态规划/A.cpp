#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
   int n;cin >> n;
   vector<vector<int>> a(n + 1,vector<int> (n + 1));
   for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
        cin >> a[i][j];
    }
   }
   for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
        a[i][j] += max(a[i- 1][j], a[i-1][j - 1]);
    }
   }
   int ans = 0;
   for(int i = 1; i <= n; i++){
    ans = max(ans,a[n][i]);
   }
   cout << ans << endl;
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
/*void solve(){
   int r;cin >> r;
   vector<vector<int>> a(r,vector<int> (r));
   for(int i = 0; i < r;i++){
        for(int j = 0; j <= i ; j++){
            cin >> a[i][j];
        }
   }
    for(int i = r - 2;i >= 0; i--){
        for(int j = 0;j <= i; j++){
            a[i][j] += max(a[i + 1][j],a[i + 1][j+1]);
        }
    }
    cout << a[0][0] << endl;
}*///下往上推