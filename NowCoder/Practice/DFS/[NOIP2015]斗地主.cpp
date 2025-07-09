/*https://ac.nowcoder.com/acm/problem/16467*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n;
vector<int> c;
int ans;

void dfs(int x,int cnt){
    if(x == 15){
        cnt = min(ans,cnt);
        
    }



}

void solve(){
    cin >> n;
    ans = maxn;
    c.assign(14,0);
    for(int i = 0;i < n;i++){
        int x,y;cin>> x >> y;
        c[x]++;
    }
    dfs(0,0);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}