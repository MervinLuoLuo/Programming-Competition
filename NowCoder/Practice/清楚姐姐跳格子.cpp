/*https://ac.nowcoder.com/acm/problem/276689*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    queue<PII> q;
    vector<bool> vis(n + 1,0);
    q.push({1,0});
    vis[1] = 1;
    while(!q.empty()){
        auto [idx,step] = q.front();
        q.pop();

        if(idx == n){
            cout << step;
            return;
        }
        int minx = min(n,a[idx]);
        for(int i = 1; i <= minx; i++){
            if(a[idx] % i == 0){
                if(idx + i <= n && !vis[idx + i]){
                    vis[idx + i] = 1;
                    q.push({idx + i,step + 1});
                }
                if(idx - i >= 1 && !vis[idx - i]){
                    vis[idx - i] = 1;
                    q.push({idx - i,step + 1});
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}