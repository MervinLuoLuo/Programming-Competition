/*https://www.luogu.com.cn/problem/P1118*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
int n,k;
vector<int> ans, c,vis;

bool dfs(int cnt, int num,int sum){
    if(sum > k) return 0;
    if(cnt == n){
        if(sum == k) {ans[cnt] = num;return 1;}
        else return 0;
    }
    vis[num] = 1;

    for(int i = 1; i <= n; i++){
        if(!vis[i] && dfs(cnt + 1, i ,sum + c[cnt] * i)){
            ans[cnt] = num;
            return 1;
        }
    }
    vis[num] = 0;
    return 0;
}
void solve(){
    cin >> n >> k;
    c.resize(25);ans.resize(25);vis.resize(25);
    c[0] = c[n - 1] = 1;
    if(n > 1){
        for(int i = 1; i * 2 < n; i++){
            c[i] = c[n - 1 - i] = (n - i) * c[i - 1] / i;
        }
    }
    if(dfs(0,0,0)) for(int i =1; i <= n; i++) cout << ans[i] << " ";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}