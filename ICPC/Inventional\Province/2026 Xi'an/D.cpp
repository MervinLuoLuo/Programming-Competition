/*https://qoj.ac/contest/3729/problem/17345*/
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
    int n,m;cin >> n >> m;
    int x = 0,y = 1;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        q.push(x);
    }
    int cur = 0;
    while(!q.empty()){
        int time = (q.top() - x) / y;
        if((q.top() - x) % y != 0) time++;
         if(cur + time >= m){
            x += (m - cur) * y;
            cur = m;
            break;
        }
        if(q.top() > m - (cur + time)){
            x += (m - cur) * y;
            cur = m;
            break;
        }
        x += time * y - q.top();
        y++;
        q.pop();
        cur += time;
        bool flag = 1;
        while(!q.empty() && x - q.top() >= 0){
            if(q.top() > m - cur){
                x += (m - cur) * y;
                cur = m;
                flag = 0;
                break;
            }
            if(!flag) break;
            x -= q.top();
            q.pop();
            y++;
        }
        // cerr << cur << ": " << x << " " << y << " " << time << endl;
        if(!flag) break;
    }
    if(cur < m) x += (m - cur) * y;
    cout << x << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}