/*https://codeforces.com/contest/2090/problem/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<string> a(n + 5);
    vector<vector<int>> flag (n +5,vector<int>(m + 5,0));
    for(int i = 1; i <= n; i++){
        string s;cin >> s;
        a[i] = ' ' + s;
    }
    for(int i = 1; i <= n; i++){
        if(a[i][1] == '1'){
            for(int j = 1; j <= m; j++){
                if(a[i][j] == '0') break;;
                flag[i][j] = 1;
            }
        }
    }
    for(int j = 1; j <= m; j++){
        if(a[1][j] == '1'){
            for(int i = 1; i <= n; i++){
                if(a[i][j] == '0') break;
                flag[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '1' and flag[i][j] == 0){no;return;}
        }
    }
    yes;
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