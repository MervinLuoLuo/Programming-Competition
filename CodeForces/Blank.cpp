#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int gcd(int x,int y){
    if(!y) return 1;
    return gcd(y,x % y) + 1;
}

void solve(){
    int n;cin >> n;
    int ans = 0;
    int pi,pj;
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            int res = gcd(i,j);
            if(res > ans){
                ans = res;
                pi = i;pj = j;
            }
            // ans = max(ans,res);
            // cout << res << " ";
        }
        // cout << endl;
    }

    cout << ans  << " " << pi << " " << pj << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}