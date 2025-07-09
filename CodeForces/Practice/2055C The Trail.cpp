/*https://codeforces.com/problemset/problem/2055/C*/
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
    int n,m;cin >>n >> m;
    string op;cin >> op;
    vector<vector<int>> a(n + 5,vector<int>(m + 5));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int x = 1, y = 1;
    for(char i : op){
        int sum = 0;
        if(i == 'D'){
            for(int j = 1; j <= m ;j++){
                sum += a[x][j];
            }
            a[x][y] = -sum;
            x++;
        }
        else {
            for(int j = 1; j <= n; j++){
                sum += a[j][y];
                
            }
            a[x][y] = -sum;
            y++;
        }
    }
    int sum = 0;
    for(int i = 1; i <= m; i++){
        sum += a[n][i];
    }
    a[n][m] = -sum;
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= m; j++) cout << a[i][j] << " ";
        cout << endl;
    }
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