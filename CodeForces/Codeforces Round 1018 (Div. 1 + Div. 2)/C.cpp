/*https://codeforces.com/contest/2096/problem/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

int op(int n,vector<vector<int>> &h,vector<int> cost){
    //初始化
    vector<vector<int>> dp(n,vector<int>(2,INF));
    dp[0][0] = 0;dp[0][1] = cost[0];
    for(int i = 1; i < n; i++){
        for(int x = 0; x <= 1; x++){//h[i][j]是否操作
            for(int y = 0; y <= 1; y++){//h[i-1][j]是否操作
                //检查能否操作
                bool flag = 1;
                for(int j = 0; j < n; j++){
                    if(h[i - 1][j] + y == h[i][j] + x){flag = 0;break;}
                }
                //如果能操作
                if(flag){
                    //这次操作后的总费用为上一行/列的费用 + cost[i]
                    if(x == 0){
                        dp[i][x] = min(dp[i][x],dp[i - 1][y]);
                    }
                    else dp[i][x] = min(dp[i][x], dp[i - 1][y] + cost[i]);
                }
            }
        }
    }
    return min(dp[n - 1][0],dp[n - 1][1]);
}

//转置函数
void swapa(int n,vector<vector<int>> &h){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(h[i][j],h[j][i]);
        }
    }
}

void solve(){
    int n;cin >> n;
    vector<vector<int>> h(n,vector<int>(n));
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> h[i][j]; 
    } 
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int rowcost = op(n,h,a);
    swapa(n,h);//因为行/列操作一样,我们转置之后再调用同样函数就不用再写一次列操作函数了
    int cocost = op(n,h,b);
    int ans = rowcost + cocost;
    if(ans >= INF) no;
    else cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}