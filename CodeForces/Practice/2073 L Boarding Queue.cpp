/*https://codeforces.com/problemset/problem/2073/L*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vvector vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

void solve(){
    int r,c,n,p;cin >>r >> c >> n >> p;
    vvector a(r + 5,vector<int> (c + 5));
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++) cin >> a[i][j];
    }
    vector<int> vis(n + 5,0);
    int ans = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j] == 0 || a[i][j] > p) continue;
            for(int k = 0; k < 4; k++){
                int curx = i + dx[k], cury = j + dy[k];
                if(a[curx][cury] == 0) continue;
                int num = a[curx][cury] + p - a[i][j];
                if(num <= n && !vis[num]){
                    vis[num] = 1;
                    ans++;
                }
            }
        }
    }
    cout << ans << "/" << n - 1 << endl;
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