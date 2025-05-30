/*https://codeforces.com/contest/2075/problem/D*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

string to_bin(int x){
    if(x == 0) return "";//处理空串
    string s;
    while(x){
        s += (x & 1) + '0';
        x >>= 1;
    }
    return s;
}
//转换为二进制数

template<typename T>
void cmin(T& x, const T& y) {
    if (x > y) x = y;
}
//方便取最小值,单独打也没事

vector<vector<int>> dp(200,vector<int>(200,INF));
void DP(){
    dp[0][0] = 0;
    for(int k = 0; k < 60; k++){//二进制最大就60位
        auto nowdp = dp;
        for(int a = 0; a < 60; a++){
            for(int b = 0; b < 60; b++){
                cmin(nowdp[a + k][b],dp[a][b] + (1LL << k));
                cmin(nowdp[a][b + k],dp[a][b] + (1LL << k));
            }
        }
        dp = nowdp;
    }
}
//dp初始化,只用一次

void solve(){
    int X,Y;cin >> X >> Y;
    string x = to_bin(X), y = to_bin(Y);
    int res = INF;
    for(int i = x.size(); i < 60; i++){
        for(int j = y.size();j < 60; j++){
            cmin(res,dp[i][j]);
        }
    }
    //取合理值
    while(!x.empty()and !y.empty() and x.back() == y.back()){
        x.pop_back();y.pop_back();
    }
    //找相等的前缀
    for(int i = 0; x.size() + i < 60 and y.size() + i < 60; i++) {
        cmin(res,dp[x.size() + i][y.size() + i]);
    }
    //得保证x,y加上i位之后不会溢出
    cout << res << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    DP();
    while(t--){
       solve();
    }
    return 0;
}