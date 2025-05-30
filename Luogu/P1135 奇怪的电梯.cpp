/*https://www.luogu.com.cn/problem/P1135*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int n,a,b;
vector<int> k;
vector<int> ans;

void dfs(int pos,int cnt){
    ans[pos] = cnt;
    if(pos + k[pos] <= n and cnt + 1 < ans[pos + k[pos]]) dfs(pos + k[pos],cnt + 1);
    if(pos - k[pos] > 0 and cnt + 1 < ans[pos - k[pos]]) dfs(pos - k[pos], cnt + 1);
}

void solve(){
    cin >> n >> a >> b;
    k.resize(n + 1);
    ans.assign(n + 1, -1);
    for(int i = 1; i <= n; i++) cin>> k[i];
    dfs(a,0);
    cout << ans[b] << endl;   
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