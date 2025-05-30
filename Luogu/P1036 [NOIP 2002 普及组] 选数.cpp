/*https://www.luogu.com.cn/problem/P1036*/
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
vector<int> a,vis,isp,ans;

void dfs(int cur,int cnt,int sum){
    if(cnt == k){
        ans.push_back(sum);
        return; 
    }

    for(int i = cur; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i + 1,cnt + 1,sum + a[i]);
            vis[i] = 0;
        }
    }

}
void solve(){
    cin >> n >> k;
    a.resize(n + 5);vis.resize(n + 5, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1,0,0);
    //埃氏筛法
    int m = *max_element(ans.begin(),ans.end());
    isp.resize(m + 5,1);
    isp[0]=isp[1] = 0;
    for(int i = 2; i <= m / i; i++){
        if(isp[i]){
            for(int j = i * i; j <= m; j+= i){
                isp[j] = 0;
            }
        }
    }
    int cnt = 0;
    for(auto it : ans){
        if(isp[it]) cnt++;
    }
    cout << cnt << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}