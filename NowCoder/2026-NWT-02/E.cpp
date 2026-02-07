#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    VII ans(n + 1,vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        // row
        for(int j = i; j <= n; j++){
            if(i % 2 == 0){
                ans[i][j] = 1;
                ans[j][i] = 1;
            }
            else{
                ans[i][j] = 0;
                ans[j][i] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << ans[i][j];
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}