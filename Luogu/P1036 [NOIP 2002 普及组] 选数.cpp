/*https://www.luogu.com.cn/problem/P1036*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e8;
int n,k;
vector<int> sum,a;

void dfs(int cur,int cnt,int res){
    if(cnt == k){
        sum.push_back(res);
        return;
    }
    if(n - cur < k - cnt) return;

    for(int i = cur; i < n; i++){
        dfs(i + 1,cnt + 1,res + a[i]);   
    }
}

bool isp(int x){
    if(x < 2) return 0;
    if(x == 2 || x == 3) return 1;
    if(x % 2 == 0 || x % 3 == 0) return 0;
    for(int i = 5; i * i <= x; i += 6){
        if(x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

void solve(){
    cin >> n >> k;
    a.assign(n,0);
    for(int &x : a) cin >> x;
    dfs(0,0,0);
    int ans = 0;
    for(int x : sum){
        if(isp(x)) ans++;
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}