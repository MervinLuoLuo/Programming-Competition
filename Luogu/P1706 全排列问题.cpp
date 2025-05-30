/*https://www.luogu.com.cn/problem/P1706*/
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
vector<int> ans, vis;

//dfs
void dfs(int x){
    if(x > n){
        for(int i = 1; i <= n; i++){
            cout << "    " << ans[i];
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            ans[x] = i;
            dfs(x + 1);
            vis[i] = 0;
            ans[x] = 0;
        }
    }

}
void solve(){
    cin >> n;
    ans.resize(n + 5);vis.resize(n + 5);
    dfs(1);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
//next_permutation写法
/*void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    do{
        for(int i = 0; i < n; i++) cout << "    " << a[i];
        cout << endl;
    }while(next_permutation(a.begin(),a.end()));
}*/