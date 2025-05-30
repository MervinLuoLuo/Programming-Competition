/*https://www.luogu.com.cn/problem/P2089*/
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
vector<vector<int>> ans;
void dfs(int x,int sum,vector<int> &cur){
    //边界
    if(sum > n) return;
    if(x > 10){
        if(sum == n) ans.push_back(cur);
        return;
    }
    //回溯
    for(int i = 1; i <= 3; i++){
        cur.push_back(i);
        dfs(x + 1, sum + i,cur);
        cur.pop_back();//恢复现场
    }
}
void solve(){
    cin >> n;
    vector<int> cur;
    dfs(1,0,cur);
    cout << ans.size() << endl;
    for(auto it : ans){
        for(auto p : it) cout << p << " ";
        cout << endl;
    }
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